#include <Wire.h>
#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>
#include <LiquidCrystal_I2C.h>

// Configuration
struct Config {
  // WiFi Settings
  const char* ssid = "Transworld Enterprise";
  const char* password = "HG8M1018245";
  
  // ThingSpeak Settings
  unsigned long channelID = 2785876;
  const char* apiKey = "SGYM5GZHTN9GW05H";
  const unsigned long updateInterval = 2000;  // Update interval in ms
  
  // Pin Definitions
  const uint8_t MQ135_PIN = 34;
  const uint8_t MQ7_PIN = 35;
  const uint8_t BUZZER_PIN = 33;
  
  // LCD Settings
  const uint8_t LCD_COLS = 16;
  const uint8_t LCD_ROWS = 2;
  const uint8_t LCD_ADDRESS = 0x27;
  
  // ADC Settings
  const uint8_t ADC_RESOLUTION = 10;
  const uint8_t SENSOR_READINGS = 10;
  const uint8_t READING_DELAY = 10;
};

class AirQualityMonitor {
private:
  Config config;
  WiFiClient client;
  LiquidCrystal_I2C lcd;
  unsigned long previousMillis = 0;
  unsigned long displayToggleMillis = 0;
  bool buzzerState = false;
  bool displayToggle = false;
  const unsigned long DISPLAY_TOGGLE_INTERVAL = 3000;  // Toggle display every 3 seconds

  int readMQ135() {
    int total = 0;
    for(int i = 0; i < config.SENSOR_READINGS; i++) {
      total += analogRead(config.MQ135_PIN);
      delay(config.READING_DELAY);
    }
    return total / config.SENSOR_READINGS;
  }

  int readMQ7() {
    int total = 0;
    for(int i = 0; i < config.SENSOR_READINGS; i++) {
      total += analogRead(config.MQ7_PIN);
      delay(config.READING_DELAY);
    }
    return total / config.SENSOR_READINGS;
  }

  void updateThingSpeak(int aqi, float coPpm) {
    ThingSpeak.setField(1, aqi);
    ThingSpeak.setField(2, coPpm);
    
    int status = ThingSpeak.writeFields(config.channelID, config.apiKey);
    Serial.println(status == 200 ? "✓ Data uploaded" : "✗ Upload failed");
  }

  void updateLCD(int aqi, float coPpm, String airQuality, String coLevel, bool dangerLevel) {
    unsigned long currentMillis = millis();
    
    // Toggle display between AQI and CO readings
    if (currentMillis - displayToggleMillis >= DISPLAY_TOGGLE_INTERVAL) {
      displayToggleMillis = currentMillis;
      displayToggle = !displayToggle;
      lcd.clear();
      
      if (displayToggle) {
        // Display AQI information
        lcd.setCursor(0, 0);
        lcd.print("AQI: ");
        lcd.print(aqi);
        lcd.setCursor(0, 1);
        // Truncate status if too long
        String truncAQ = airQuality.substring(0, 16);
        lcd.print(truncAQ);
      } else {
        // Display CO information
        lcd.setCursor(0, 0);
        lcd.print("CO: ");
        lcd.print(coPpm, 1);
        lcd.print(" PPM");
        lcd.setCursor(0, 1);
        // Truncate status if too long
        String truncCO = coLevel.substring(0, 16);
        lcd.print(truncCO);
      }
      
      // If in danger level, make the display blink
      if (dangerLevel) {
        lcd.noBacklight();
        delay(200);
        lcd.backlight();
      }
    }
  }

public:
  AirQualityMonitor() : lcd(config.LCD_ADDRESS, config.LCD_COLS, config.LCD_ROWS) {}

  void begin() {
    Serial.begin(115200);
    Serial.println("\n=== Air Quality Monitor ===");
    
    Wire.begin(23, 22);
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.print("Air Quality");
    lcd.setCursor(0, 1);
    lcd.print("Monitor v2.0");
    
    setupADC();
    setupBuzzer();
    connectWiFi();
    ThingSpeak.begin(client);
    delay(2000);
  }

  void setupADC() {
    analogReadResolution(config.ADC_RESOLUTION);
    analogSetAttenuation(ADC_11db);
  }

  void setupBuzzer() {
    pinMode(config.BUZZER_PIN, OUTPUT);
    digitalWrite(config.BUZZER_PIN, LOW);
  }

  void connectWiFi() {
    Serial.print("Connecting to WiFi...");
    lcd.clear();
    lcd.print("Connecting WiFi");
    
    WiFi.begin(config.ssid, config.password);
    int dots = 0;
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      lcd.setCursor(dots % 16, 1);
      lcd.print(".");
      dots++;
    }
    Serial.println(" Connected!");
    lcd.clear();
    lcd.print("WiFi Connected!");
    delay(1000);
  }

  int calculateAQI(int sensorValue) {
    float resistance = (1023.0 / sensorValue) - 1.0;
    resistance *= 10;

    if (resistance > 10) return 0;   // Good
    if (resistance > 5) return 50;   // Moderate
    if (resistance > 3) return 100;  // Unhealthy for Sensitive Groups
    if (resistance > 2) return 150;  // Unhealthy
    if (resistance > 1) return 200;  // Very Unhealthy
    return 300;                      // Hazardous
  }

  float calculateCOPPM(int sensorValue) {
    float voltage = sensorValue * (3.3 / 1023.0);
    float ppm = (voltage - 0.1) * 100;
    return ppm > 0 ? ppm : 0;
  }

  String getAirQualityStatus(int aqi) {
    if (aqi <= 50) return "Good";
    if (aqi <= 100) return "Moderate";
    if (aqi <= 150) return "Unhealthy-Sens";
    if (aqi <= 200) return "Unhealthy";
    if (aqi <= 300) return "Very Unhealthy";
    return "Hazardous";
  }

  String getCOLevelStatus(float coPpm) {
    if (coPpm <= 4) return "Good";
    if (coPpm <= 9) return "Moderate";
    if (coPpm <= 12) return "Unhealthy-Sens";
    if (coPpm <= 15) return "Unhealthy";
    return "Hazardous";
  }

  void controlBuzzer(bool shouldBeOn) {
    if (shouldBeOn && !buzzerState) {
      tone(config.BUZZER_PIN, 262);  // 262 Hz = middle C
      buzzerState = true;
    } else if (!shouldBeOn && buzzerState) {
      noTone(config.BUZZER_PIN);
      buzzerState = false;
    }
  }

  void update() {
    int mq135Value = readMQ135();
    int mq7Value = readMQ7();

    int aqi = calculateAQI(mq135Value);
    float coPpm = calculateCOPPM(mq7Value);

    String airQuality = getAirQualityStatus(aqi);
    String coLevel = getCOLevelStatus(coPpm);

    Serial.printf("\nAir Quality (AQI): %d (%s)\n", aqi, airQuality.c_str());
    Serial.printf("CO Level: %.1f PPM (%s)\n", coPpm, coLevel.c_str());

    bool dangerLevel = (aqi > 200 || coPpm > 15);
    controlBuzzer(dangerLevel);

    updateLCD(aqi, coPpm, airQuality, coLevel, dangerLevel);

    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= config.updateInterval) {
      previousMillis = currentMillis;
      updateThingSpeak(aqi, coPpm);
    }
  }
};

AirQualityMonitor monitor;

void setup() {
  monitor.begin();
}

void loop() {
  monitor.update();
}