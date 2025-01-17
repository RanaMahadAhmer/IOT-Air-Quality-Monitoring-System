
--Air Quality Monitoring System--


1.	Project Description
Introduction
The IoT Air Quality Monitoring System represents a robust integration of modern IoT technology and environmental monitoring tools, designed to tackle the increasing concern of air pollution. With real-time capabilities, the system aims to empower users with actionable insights into air quality in their surroundings, whether indoors or outdoors.
Leveraging the ESP32 microcontroller, known for its powerful processing capabilities and built-in Wi-Fi, the system incorporates MQ135 and MQ7 sensors. These sensors are specifically chosen for their sensitivity to air pollutants, including general air quality indicators and carbon monoxide (CO) levels. The project emphasizes accessibility, reliability, and the use of cutting-edge technologies like cloud integration for seamless data management.
Key features include real-time monitoring, automated alerts for hazardous conditions, and remote access to historical data for comprehensive analysis. This solution targets individuals, organizations, and governmental bodies aiming to monitor and respond to air quality issues effectively.

Figure 1: Overview
Objectives
The primary goals of the project are outlined below:
1.	Cost-Effective Design:
Develop a low-cost air quality monitoring system that ensures high accuracy and reliability without compromising functionality.
2.	Real-Time Data Acquisition:
Implement sensors to provide instantaneous readings of Air Quality Index (AQI) and carbon monoxide (CO) levels.
3.	Automated Alert System:
Program alerts, such as buzzer sounds, to notify users of critical air quality thresholds, enabling timely action.
4.	Cloud-Based Integration:
Use ThingSpeak for logging, storing, and visualizing air quality data to facilitate user-friendly, cloud-based accessibility.
5.	Remote Monitoring:
Create a web-based platform allowing users to view current and historical data from anywhere, enhancing the system's convenience.
Expected Outcomes
Upon successful completion, the project will deliver:
1.	A Fully Functional Monitoring System:
o	Accurate real-time AQI and CO level measurements via reliable sensors.
2.	Local Display:
o	LCD or LED display showcasing real-time readings and system status updates for immediate feedback.
3.	Automated Alerts:
o	A buzzer system that activates within 30 seconds of detecting dangerous air quality levels, ensuring prompt warnings.
4.	Historical Data Analysis:
o	Comprehensive storage and graphical representation of data, enabling trends and patterns to be observed.
5.	Mobile/Web Access:
o	Intuitive interfaces for users to remotely monitor air quality data in real-time.
6.	Portability:
o	Battery-powered system ensuring at least 24 hours of uninterrupted operation, promoting flexibility.
2.	Application Requirements
Hardware Requirements
1. Processing Unit
The project employs the ESP WROOM-32 microcontroller, known for its reliability and advanced features:
•	Dual-Core Processor: Handles parallel tasks effectively, ensuring smooth system operations.
•	Memory: A minimum of 4MB flash memory for firmware and data storage.
•	Connectivity: Integrated WiFi and Bluetooth capabilities for seamless communication and cloud integration.
2. Sensors
The system uses two types of sensors for air quality monitoring:
•	MQ135: An air quality sensor designed to measure a wide range of pollutants, including ammonia, smoke, and benzene.
•	MQ7: A carbon monoxide sensor that provides accurate detection of CO levels, crucial for identifying health risks.
3. Display and Notification
The system provides real-time data visualization and alerts using:
•	20x4 I2C LCD Display: Initially used during simulations for enhanced visibility of air quality parameters.
•	16x2 I2C LCD Display: Deployed in the actual hardware setup due to availability, ensuring compact and clear data presentation.
•	Active Buzzer: Emits alerts when air quality thresholds are exceeded, providing immediate notifications.
4. Power Supply
The system operates on a 5V DC power supply, ensuring stable and efficient operation.
Software Requirements
1.	Development Environment
The development and debugging process utilized the Arduino IDE, supplemented with the following:
•	ESP32 Board Support Package: Enables seamless programming and uploading of code to the ESP32 microcontroller.
•	Essential Libraries:
o	Wire.h: Facilitates I2C communication for LCD operation.
o	WiFi.h: Handles internet connectivity for cloud integration.
o	ThingSpeak.h: Provides functions to interact with the ThingSpeak cloud platform.
o	LiquidCrystal_I2C.h: Enables control of the 20x4 LCD for displaying data.
o	PubSubClient: Manages MQTT communication for data transmission.
o	ESP32 Power Management Libraries: Optimizes power consumption for efficient operation.
2. Cloud Platform
The project integrates with ThingSpeak, a cloud-based IoT analytics platform:
•	ThingSpeak Account: Configured with a private channel to store and analyze sensor data securely.
•	API Key: Ensures secure data transmission between the ESP32 and the cloud.
•	Custom Dashboard: Designed for intuitive visualization of air quality trends and historical data.
3. Testing and Simulation
To validate the system and debug effectively, the following tools were employed:
•	Wokwi Simulator: Used for initial hardware and software testing in a virtual environment.
•	Serial Monitor: Observed real-time outputs and debugged the system via the Arduino IDE’s built-in debugging tools.
•	Network Analysis Tools: Analyzed internet connectivity and ensured efficient data transmission to the cloud platform.
3.	Details of Sensors and Related Electronic Equipment
MQ135 Air Quality Sensor
The MQ135 is a versatile sensor designed to measure air quality and detect a range of gases.
•	Technical Specifications:
o	Operating Voltage: 5V ± 0.1V
o	Power Consumption: 800mW
o	Detectable Gases: Ammonia (NH3), nitrogen oxides (NOx), alcohol, benzene, smoke, carbon dioxide (CO2)
o	Detection Range: 10–1000 ppm (parts per million)
•	Features:
o	High sensitivity to multiple gases for comprehensive air quality measurement
o	Fast response time (<10 seconds) for real-time monitoring
o	Supports both digital and analog outputs, enhancing compatibility with microcontrollers
MQ7 Carbon Monoxide Sensor
The MQ7 is specialized for detecting carbon monoxide (CO) levels, crucial for identifying health hazards.
•	Technical Specifications:
o	Operating Voltage: 5V ± 0.1V
o	Power Consumption: 350mW
o	Detection Range: 10–10000 ppm
o	Response Time: <60 seconds
•	Features:
o	High sensitivity to CO, ensuring accurate detection even at low concentrations
o	Excellent resistance to interference, reducing the impact of external environmental factors
LCD Display (20x4 I2C) - Simulation
Used during the initial development phase for a broader display area.
•	Technical Specifications:
o	Operating Voltage: 5V
o	Current Consumption: 25mA with backlight enabled
•	Features:
o	Built-in I2C interface for simplified wiring and communication
o	Adjustable backlight for better readability in various lighting conditions
o	Low power consumption mode for energy efficiency
LCD Display (20x4 I2C) – Actual Hardware
Used in the final implementation due to availability.
•	Technical Specifications:
o	Operating Voltage: 5V
o	Current Consumption: 20mA with backlight
•	Features:
o	Compact size for portability
o	I2C interface with a dedicated converter, ensuring compatibility with the ESP32
o	Clear and concise display of key parameters
Active Buzzer
The buzzer is a critical component for audible alerts in case of hazardous air quality levels.
•	Technical Specifications:
o	Operating Voltage: 3.3–5V
o	Sound Level: ~85 dB at 10cm
o	Current Consumption: <30mA
•	Features:
o	Immediate response (<1 second) to alert users of critical conditions
o	Compact and lightweight design for seamless integration into the system
o	Adjustable frequency range for varied alert tones
ESP32 
The ESP32 WROOM-32 is a high-performance microcontroller with powerful processing and connectivity capabilities.
•	Technical Specifications:
o	Processor: Dual-core Xtensa LX6, clocked up to 240 MHz
o	Memory: 520 KB SRAM, 4 MB Flash storage
o	WiFi: 2.4 GHz, 802.11 b/g/n standards
o	Bluetooth: v4.2, supports both BR/EDR and BLE protocols
o	Operating Voltage: 3.3V
o	GPIO Pins: 34 programmable for versatile interfacing
•	Features:
o	Built-in hall and temperature sensors for additional environmental monitoring capabilities
o	Ultra-low power co-processor for efficient energy management
o	Hardware cryptography support for secure data transmission
o	Multiple power modes for optimized performance based on system requirements
4.	Circuit

MQ135 Sensor:
AO (Signal) → GPIO 34 (ESP32)
VCC → 3.3V (ESP32)
GND → GND (ESP32)
MQ7 Sensor:
AO (Signal) → GPIO 35 (ESP32)
VCC → 3.3V (ESP32)
GND → GND (ESP32)	20x4 LCD Display (I2C):
SDA → GPIO 23 (ESP32)
SCL → GPIO 22 (ESP32)
VCC → 5V (ESP32)
GND → GND (ESP32)
Buzzer:
Positive Terminal → GPIO 33 (ESP32)
Negative Terminal → GND (ESP32)

 
Figure 2: Circuit Diagram
5.	Circuit Connections
This section explains the connections required to build the air quality monitoring system using the MQ135 and MQ7 sensors, an ESP32 microcontroller, a buzzer, and a 16x2 LCD display with an I2C interface. The setup is designed to monitor air quality and carbon monoxide levels, alert users with warnings via a buzzer, and display real-time data on the LCD.
Connection Details
1.	MQ135 Air Quality Sensor
o	Signal Pin (AO): Connect to GPIO 34 on the ESP32.
o	VCC: Connect to the 3.3V pin of the ESP32.
o	GND: Connect to the GND pin of the ESP32.
2.	MQ7 Carbon Monoxide Sensor
o	Signal Pin (AO): Connect to GPIO 35 on the ESP32.
o	VCC: Connect to the 3.3V pin of the ESP32.
o	GND: Connect to the GND pin of the ESP32.
3.	16x2 LCD Display with I2C Interface
o	SDA: Connect to GPIO 23 on the ESP32.
o	SCL: Connect to GPIO 22 on the ESP32.
o	VCC: Connect to the 5V pin of the ESP32.
o	GND: Connect to the GND pin of the ESP32.
4.	Buzzer
o	Positive Terminal: Connect to GPIO 33 on the ESP32.
o	Negative Terminal: Connect to the GND pin of the ESP32.
Note:
•	The I2C interface simplifies the connection for the LCD, requiring only two wires (SDA and SCL) for communication.
•	The sensors' analog outputs are read using the ESP32’s ADC (Analog-to-Digital Converter) to obtain air quality and carbon monoxide levels.
•	The buzzer provides auditory feedback in hazardous conditions, activated through GPIO control.
  
Figure 3: Hardware Connections

6.	Output

 
Figure 4: Arduino IDE Serial Monitor
 
Figure 5: Wokwi Serial Monitor
 
Figure 6: Wokwi Chip Console
 
Figure 7: ThingSpeak Dashboard
7.	Implementation
Wokwi Implementation
1.	Platform Selection and Initial Setup
•	Development Platform: Wokwi was chosen for the ESP32 development as other alternatives were unavailable.
•	Custom Chip Creation: The MQ135 and MQ7 sensors were not available in the Wokwi library, so custom chips were created using the Wokwi Custom Chip option.
2. Custom Sensor Chip Design
MQ7 Sensor
•	Chip JSON Configuration:
{
  "name": "mq7",
  "author": "Misbah Juwayriyyah",
  "pins": ["VCC", "GND", "D0", "A0", "", "", ""],
  "controls": [{
    "id": "co_ppm",
    "label": "PPM",
    "type": "slider",
    "min": 10,
    "max": 10000
  }]
}
•	Explanation: The chip includes one analog pin (A0) for output and a digital pin (D0) for other sensor actions. The sensor control interface provides a slider for adjusting the CO concentration in ppm between 10 and 10,000.
•	MQ7 Sensor Code (mq7.chip.c):
o	The sensor code simulates the output of the MQ7 sensor. The CO concentration (ppm) is read via the control slider, and the value is converted into a corresponding voltage.
o	The chip_timer_callback function processes the ppm value, converts it into a voltage, and writes the result to the output pin A0.
void chip_timer_callback(void *data) {
  chip_data_t *chip_data = (chip_data_t*)data;
  int co_ppm = attr_read(chip_data->co_ppm);
  printf("CO-ppm:%d\n", co_ppm);
  float volts = co_ppm * 5.0 / 1000;
  printf("CO-volts:%f\n", volts);
  pin_dac_write(chip_data->pin, volts);
}
MQ135 Sensor
•	Chip JSON Configuration:
{
  "name": "mq135",
  "author": "Misbah Juwayriyyah",
  "pins": ["VCC", "GND", "A0", "D0", "", "", ""],
  "controls": [{
    "id": "ppm",
    "label": "PPM",
    "type": "slider",
    "min": 10,
    "max": 1000
  }]
}
•	Explanation: Similar to the MQ7 sensor, the MQ135 chip also uses one analog pin (A0) for output. The ppm slider allows adjusting the concentration of AQI (Air Quality Index) between 10 and 1,000.
•	MQ135 Sensor Code (mq135.chip.c):
o	The MQ135 sensor code performs similarly to the MQ7 sensor. The ppm value is read from the slider, and it is converted into a corresponding voltage that is written to the A0 pin.
void chip_timer_callback(void *data) {
  chip_data_t *chip_data = (chip_data_t*)data;
  int ppm = attr_read(chip_data->ppm);
  printf("AQI-ppm:%d\n", ppm);
  float volts = ppm * 5.0 / 1000;
  printf("AQI-volts:%f\n", volts);
  pin_dac_write(chip_data->pin, volts);
}
3. System Integration
•	Sensor Ranges:
o	MQ135 Range: 10-1,000 ppm for air quality monitoring.
o	MQ7 Range: 10-10,000 ppm for CO monitoring.
•	Both sensors are programmed to output analog voltage corresponding to their respective ppm values.
4. Sensor Calibration and Testing
•	The system was tested on Wokwi with these custom chips to simulate real-world behavior, and the sensors' readings were observed on the platform's serial monitor.
Source Code
This code implements an air quality monitoring system using an ESP32 microcontroller, which reads values from air quality sensors (MQ135 for air quality and MQ7 for carbon monoxide), calculates Air Quality Index (AQI) and CO levels, and displays these values on an LCD screen. It also uploads the data to ThingSpeak, and triggers a buzzer when dangerous levels of air pollutants are detected. The code works both in Wokwi and Arduino IDE, with minimal adjustments required for both environments.
1. Libraries and Configuration
At the start of the code, several essential libraries are included:
•	Wire.h: This library is used to communicate with I2C devices such as the LCD.
•	Arduino.h: A core library for Arduino-specific functionality.
•	WiFi.h: Enables Wi-Fi connectivity on the ESP32.
•	ThingSpeak.h: This library is used to send sensor data to ThingSpeak, an IoT platform.
•	LiquidCrystal_I2C.h: Manages the LCD screen via I2C communication.
The Config struct stores various configuration settings:
•	WiFi Settings: The ssid (network name) and password are used to connect the ESP32 to the Wi-Fi network.
•	ThingSpeak Settings: The channelID and apiKey are used for authenticating and uploading data to ThingSpeak.
•	Pin Definitions: Specifies the pins for the MQ135 sensor (for air quality), MQ7 sensor (for CO), and the buzzer.
•	LCD Settings: Defines the dimensions of the LCD and its I2C address.
•	ADC Settings: Adjusts the resolution for analog-to-digital conversion and sensor reading settings.
2. AirQualityMonitor Class
The AirQualityMonitor class encapsulates all functionality for initializing the hardware, reading sensor values, updating displays, and uploading data.
Private Members:
•	Config config: Holds the configuration settings for Wi-Fi, sensors, etc.
•	WiFiClient client: Establishes a Wi-Fi connection.
•	LiquidCrystal_I2C lcd: Controls the LCD display.
•	Various variables like previousMillis, buzzerState, and warningDisplayState are used to manage the timing of updates, buzzer control, and warning messages on the LCD.
Methods:
Sensor Reading Methods:
•	readMQ135() and readMQ7() read values from the respective sensors. Each sensor is read multiple times (10 readings) to get an average and reduce noise. This helps in obtaining more stable readings.
updateThingSpeak():
This function uploads the AQI and CO readings to ThingSpeak. The data is sent using the ThingSpeak.setField() method to assign values to fields, followed by ThingSpeak.writeFields() to push the data to the platform. The status of the upload (success or failure) is logged to the Serial Monitor.
updateLCD():
This method manages the LCD display:
•	Displays AQI and CO levels on the screen.
•	Checks if the air quality or CO levels have reached dangerous thresholds and blinks a warning message.
•	The warning message alternates visibility using a timed blink function.
calculateAQI():
The AQI is calculated using the sensor reading. It converts the analog value from the MQ135 sensor to a resistance value and classifies it into categories such as Good, Moderate, Unhealthy, etc., based on predefined thresholds.
calculateCOPPM():
Converts the analog reading from the MQ7 sensor to a CO concentration (in parts per million, PPM). The calculation is based on voltage conversion, where the output is scaled to match typical CO detection levels.
getAirQualityStatus() and getCOLevelStatus():
These methods convert the calculated AQI and CO values into human-readable strings that indicate the air quality and CO levels (e.g., "Good", "Moderate", "Unhealthy").
controlBuzzer():
The buzzer is controlled based on the sensor readings. If the air quality or CO levels reach dangerous thresholds (AQI > 200 or CO > 15 PPM), the buzzer is turned on; otherwise, it remains off.
update():
This method orchestrates the entire process. It:
•	Reads the sensor values.
•	Calculates the AQI and CO levels.
•	Displays them on the Serial Monitor.
•	Updates the LCD display with the current readings.
•	Sends data to ThingSpeak if the specified interval has passed.
•	Controls the buzzer and manages the warning message on the LCD.
3. Setup and Loop Functions
setup():
•	Initializes Serial communication for debugging.
•	Initializes the LCD, Wi-Fi connection, ADC, and the buzzer.
•	Connects to Wi-Fi using the provided SSID and password. The ESP32 keeps trying to connect until successful, displaying connection status on the LCD.
loop():
•	Calls the monitor.update() method in a continuous loop, which runs the main logic of reading sensors, displaying results, and uploading data.
4. Detailed Behavior and Flow
1.	Initialization:
o	The system initializes the LCD to display "Air Quality Monitor" and starts by connecting to the Wi-Fi network.
o	Once connected, the LCD will display "WiFi Connected!" and the system prepares for sensor readings.
2.	Sensor Readings:
o	The system periodically reads values from the MQ135 (air quality) and MQ7 (CO) sensors.
o	The analog readings are averaged to improve accuracy.
3.	AQI and CO Level Calculation:
o	The AQI is calculated based on the resistance value of the MQ135 sensor, and the CO level is calculated from the MQ7 sensor’s voltage output.
4.	Display Updates:
o	The LCD displays real-time AQI and CO levels, with appropriate statuses like "Good", "Moderate", or "Unhealthy".
o	If the levels cross a threshold, a blinking warning message "WARNING!" will appear on the screen.
5.	Data Upload:
o	Every 2 seconds (as defined in updateInterval), the AQI and CO values are uploaded to ThingSpeak for cloud monitoring.
6.	Buzzer Alert:
o	If the AQI exceeds 200 or CO exceeds 15 PPM, the buzzer emits a tone to alert the user about dangerous air quality levels.
5. Conclusion
This project demonstrates how to build a comprehensive air quality monitoring system using the ESP32, which is capable of reading environmental data, displaying it on an LCD, sending it to the cloud, and providing real-time alerts via a buzzer. The design of the code allows it to work seamlessly on both the Wokwi simulator and Arduino IDE, with minimal changes required between the two environments. The system is adaptable, making it suitable for real-world applications in monitoring and improving air quality.
ThingSpeak

In our air quality monitoring system, we needed a reliable and simple way to collect, store, and visualize the data from our sensors, specifically the MQ135 and MQ7 sensors for measuring air quality and carbon monoxide (CO) levels. ThingSpeak emerged as the ideal solution for several reasons:
•	Ease of Integration: ThingSpeak provides an easy-to-use API that allows seamless data uploading from our ESP32 microcontroller, which collects the readings from the sensors. This eliminates the need for complex server-side setups and allows us to focus on the core functionality of the project—monitoring and analyzing air quality.
•	Real-Time Data Collection: One of the most important aspects of our project is continuous monitoring of air quality. ThingSpeak allows us to send sensor data to the cloud in real-time, providing us with up-to-date information on air quality and CO levels.
 
Figure 8: Realtime data collection/display on dashboard
•	Data Storage and Accessibility: With ThingSpeak, all the data collected from our sensors is stored securely in the cloud, and we can access it at any time via the ThingSpeak API. This makes it easy to track trends in air quality over time and retrieve historical data when necessary.
•	Built-In Visualization Tools: ThingSpeak offers built-in tools to visualize the data, which was a key requirement for our project. We can create live graphs, charts, and dashboards to display the air quality and CO levels. This feature allows us to monitor the data visually in a meaningful way, making it easier to interpret sensor readings and assess the air quality in different environments.
•	MATLAB Compatibility: Since MATLAB is already integrated into the ThingSpeak platform, it provides an efficient way to analyze and visualize the collected data. MATLAB's advanced graphing capabilities and analytical tools enable us to not only visualize the data but also apply complex analysis techniques when needed. This integration streamlines the process and allows for enhanced data insights without needing separate software solutions.
% Template MATLAB code for visualizing data using the STEM function.
% Prior to running this MATLAB code template, assign the channel variables.
% Set 'readChannelID' to the channel ID of the channel to read from. 
% Also, assign the read field ID to 'fieldID1'. 
% TODO - Replace the [] with channel ID to read data from:
readChannelID = [2785876];
% TODO - Replace the [] with the Field ID to read data from:
fieldID = [2];
% Channel Read API Key 
% If your channel is private, then enter the read API
% Key between the '' below: 
readAPIKey = '';
%% Read Data %%
[data, time] = thingSpeakRead(readChannelID, 'Field', fieldID, 'NumPoints', 30, 'ReadKey', readAPIKey);
%% Visualize Data %%
% Create a stem plot
stem(time, data, 'LineWidth', 1.5);
% Add labels and title
xlabel('Time (Date and Time)');
ylabel('Data Values');
title('CO level');
% Format x-axis to show detailed date and time
datetick('x', 'dd-mmm-yyyy HH:MM:SS', 'keeplimits', 'keepticks');
% Add grid for better readability
grid on;
% Add legend
legend('Data Points', 'Location', 'best');
% Enhance the axis font size
set(gca, 'FontSize', 12);
% Display the graph
disp('Graph plotted successfully!');
 
Figure 9: AQI graph using Matlab Visualisation
 
Figure 10: CO graph using Matlab Visualisation
Why It Was Essential for Our Project
•	Simplicity: Our goal was to create a system that could automatically send sensor data to the cloud, without requiring extensive backend development. ThingSpeak's simple setup and easy integration with the ESP32 allowed us to achieve this efficiently.
•	Visualization for Real-Time Monitoring: The ability to monitor air quality data in real-time through ThingSpeak’s visualization tools has been critical for our project. By having live charts and graphs, we can immediately see changes in the environment (e.g., when the CO levels increase), helping us make timely decisions or trigger alerts if necessary. We can even export the data and automatically visualise in whatever shape or form we want.
 
Figure 11: CO data exported in excel
 
Figure 12: AQI data exported in excel
•	Scalability: As our project progresses, ThingSpeak allows for easy expansion, such as adding more sensors or scaling up data storage. This is important for future iterations of the system or if we choose to monitor additional environmental factors.
8.	Power Consumption Analysis and Optimization
Detailed Power Consumption Breakdown
1.	ESP32 (WROOM-32)
•	Active mode: 80mA @ 3.3V (264mW)
•	Light sleep mode: 0.8mA @ 3.3V (2.64mW)
2.	MQ135 Sensor
•	Heating current: 150mA @ 5V (750mW)
•	Signal output: 5mA @ 5V (25mW)
•	Total power: 775mW (continuous)
3.	MQ7 Sensor
•	Heating current: 150mA @ 5V (750mW)
•	Signal output: 5mA @ 5V (25mW)
•	Total power: 775mW (continuous)
4.	LCD Display (16x2 I2C)
•	With backlight: 25mA @ 5V (125mW)
•	Without backlight: 5mA @ 5V (25mW)
•	I2C communication: 2mA @ 5V (10mW)
5.	Buzzer
•	Active: 30mA @ 5V (150mW)
•	Standby: 0mA (0mW)
Total Power Consumption
•	Maximum (all active): 2089mW
•	Typical operation: 1500mW
Power Optimization Approaches
1.	Sensor Power Management
•	Approach: Implement dynamic duty cycling for sensors and optimize sensor warm-up times.
•	Expected Saving: 30-40%
2.	Microcontroller Optimization
•	Approach: Utilize ESP32's sleep modes, implement task scheduling, and optimize WiFi connection management.
•	Expected Saving: 40-50%
3.	Display and Alert Optimization
•	Approach: Control the backlight dynamically, use event-driven display updates, and set adaptive alert thresholds.
•	Expected Saving: 20-25%
4.	Communication Optimization
•	Approach: Implement batch data transmission, use adaptive sampling rates, and adopt a compressed data format for transmission.
•	Expected Saving: 15-20%

9.	Communication Technology and Protocols
Physical Layer
1.	WiFi Communication
•	Protocol: IEEE 802.11 b/g/n
•	Frequency: 2.4GHz
•	Maximum Range: 50m indoor, 100m outdoor
•	Data Rate: Up to 150 Mbps
•	Security: WPA2-PSK
2.	I2C Communication
•	Clock Speed: 100kHz
•	Addressing: 7-bit
•	Pull-up Resistors: 4.7kΩ
•	Maximum Bus Length: 50cm
•	Devices: LCD display, sensors
3.	Analog/Digital Interfaces
•	ADC Resolution: 12-bit
•	Sampling Rate: 10 samples/second
•	Input Range: 0-3.3V
•	Digital Output: 3.3V logic level
Internet Layer
1.	TCP/IP Stack
•	Protocol: IPv4
•	TCP Port: 80 (HTTP)
•	UDP Port: 1883 (MQTT)
•	Connection Timeout: 30 seconds
2.	Security Measures
•	TLS Encryption: Automatic
•	Certificate-based Authentication: Automatic
•	API Key Validation: Automatic
Application Layer
•	ThingSpeak Protocol
1.	REST API
2.	JSON Data Format
3.	Update Interval: 15 seconds
4.	Batch Size: 8 readings
Scaling Network Topologies
1.	Star Topology
•	Central Hub Configuration
•	Direct Connection to Cloud
•	Advantages:
o	Simple management
o	Low latency
o	Easy troubleshooting
•	Disadvantages:
o	Limited range
o	Single point of failure
o	Higher power consumption
2.	Mesh Network
•	ESP32 Nodes with ESP-MESH
•	Multi-hop Communication
•	Advantages:
o	Extended coverage
o	Self-healing capability
o	Load distribution
•	Disadvantages:
o	Complex routing
o	Higher latency
o	More processing overhead
3.	Hierarchical Structure
•	Multiple Layers of Nodes
•	Local Data Aggregation
•	Advantages:
o	Scalable architecture
o	Efficient data management
o	Reduced network load
•	Disadvantages:
o	Complex setup
o	Higher initial cost
o	Maintenance challenges
10.	Tools and Technologies Required
Development Tools
1.	Hardware Development 
o	Arduino IDE 2.0 or later
o	ESP32 development board
o	USB-TTL converter
2.	Software Development 
o	Visual Studio Code with PlatformIO
o	Git for version control
o	Arduino CLI
o	ESP32 SDK
o	ThingSpeak API client
3.	Testing Tools 
o	Wokwi simulator
11.	Expected Impact
Environmental Impact
1.	Direct Environmental Benefits 
o	Early detection of air pollution
o	Support for environmental research
o	Contribution to air quality databases
o	Enhanced understanding of pollution patterns
2.	Long-term Environmental Effects 
o	Improved urban planning
o	Better pollution control measures
o	Support for clean air initiatives
o	Reduced carbon footprint through optimization
o	Enhanced environmental awareness
Societal Impact
1.	Public Health Benefits 
o	Real-time air quality awareness
o	Early warning system for hazardous conditions
o	Improved indoor air quality management
o	Support for respiratory health
o	Enhanced workplace safety
2.	Economic Benefits 
o	Reduced healthcare costs
o	Improved workplace productivity
o	Support for smart city initiatives

12.	Advantages and Disadvantages
Advantages
1.	Real-Time Monitoring and Data Upload
o	Advantage: The system continuously monitors the air quality, updating real-time data from sensors to the cloud via ThingSpeak. This allows immediate detection of changes in air quality levels, such as increases in pollutants or CO levels. Having real-time data accessible online ensures that users can monitor environmental conditions at any time, which is critical for timely interventions or analysis.
o	Why it Matters: Air quality is a dynamic parameter that fluctuates throughout the day. With real-time updates, we can identify and respond to dangerous levels of pollutants, ensuring better protection for individuals in sensitive environments.
2.	Cloud Integration with ThingSpeak
o	Advantage: The integration with ThingSpeak ensures that data is securely stored and easily accessible from anywhere. ThingSpeak’s cloud infrastructure is both robust and scalable, meaning that even as the amount of data collected increases, the system remains reliable without the need for additional infrastructure or heavy maintenance.
o	Why it Matters: Cloud storage also removes the need for local data management, making the system more reliable and easy to scale. We don’t have to worry about managing local storage devices, which may fail or get lost. Additionally, the data can be accessed from anywhere with an internet connection, offering flexibility in monitoring and managing the system.
3.	Built-in Visualization for Data Analysis
o	Advantage: ThingSpeak’s built-in visualization tools allow easy graphing and charting of data. This capability enables users to view trends in air quality (such as changes in AQI or CO levels) over time, offering valuable insights into patterns and anomalies.
o	Why it Matters: Visualization plays a crucial role in making data comprehensible and actionable. By using visual representations, users (or environmental analysts) can quickly understand the health of the air quality, track pollution levels over different times of the day or seasons, and identify areas or times that may require further intervention.
4.	Ease of Integration with ESP32
o	Advantage: The ESP32 microcontroller used in this project is a low-cost, versatile hardware that integrates easily with the sensors (MQ135 for air quality and MQ7 for CO detection) and ThingSpeak. The open-source Arduino IDE allows for easy programming and customizations, while the ESP32 provides excellent WiFi connectivity for cloud-based data uploading.
o	Why it Matters: The ease of integration with the ESP32 reduces development time, making the project accessible even for those with limited hardware experience. Furthermore, the ESP32 offers an efficient and affordable solution, keeping the project cost-effective.
5.	MATLAB Compatibility for Advanced Analysis
o	Advantage: ThingSpeak’s compatibility with MATLAB makes it easy to perform advanced data analysis, such as statistical tests, machine learning, or more complex visualizations. This functionality is particularly beneficial if the project needs to scale or incorporate predictive modeling for future air quality conditions.
o	Why it Matters: Advanced analysis can reveal deeper insights that simple monitoring might miss. For example, it can predict potential air quality issues based on trends or identify specific factors contributing to high pollution levels. MATLAB’s analytical tools give users the power to go beyond just monitoring, enabling more informed decisions.
6.	Simplicity and Cost-Effectiveness
o	Advantage: This project leverages affordable and readily available hardware (ESP32, MQ135, and MQ7 sensors) and uses an open-source platform (Arduino IDE) for programming. ThingSpeak offers a free tier for basic data storage and monitoring, reducing costs for users.
o	Why it Matters: The affordability and simplicity of the solution make it suitable for a wide range of applications, from educational projects to small-scale monitoring systems. It also reduces the barrier to entry for those interested in environmental monitoring, making this technology more accessible.
7.	Environmental Impact
o	Advantage: By continuously monitoring air quality, this system can help raise awareness about environmental pollution. It can also be used in areas that suffer from poor air quality, potentially aiding in local efforts to reduce pollution or improve air quality standards.
o	Why it Matters: Air quality is an essential indicator of environmental health. This project empowers individuals or organizations to take action by providing timely, accurate data that can inform policy, guide public health initiatives, or encourage behavioral changes.
Disadvantages (Limitations)
1.	Limited Sensor Accuracy
o	Disadvantage: The MQ135 and MQ7 sensors used in this project, while effective for general air quality and CO detection, have certain limitations in terms of accuracy and calibration. These sensors are designed for low-cost solutions and may not provide highly precise measurements, especially in environments with fluctuating or complex air composition.
o	Why It Matters: While the sensors provide a general idea of air quality, they may not be suitable for highly precise measurements required in industrial or scientific applications. Users should be aware that the readings may need calibration over time or under different environmental conditions.
2.	Dependence on Wi-Fi Connectivity
o	Disadvantage: Since the ESP32 relies on Wi-Fi to send data to ThingSpeak, the system is dependent on the availability and stability of the Wi-Fi network. Any disruptions in Wi-Fi connectivity could prevent data from being uploaded in real-time, potentially causing gaps in the data or incomplete monitoring.
o	Why It Matters: In environments where Wi-Fi connectivity is unstable or unavailable, the system may fail to transmit data to the cloud, reducing its effectiveness. For remote areas with poor internet infrastructure, this could be a significant limitation.
3.	Limited Data Storage on ThingSpeak Free Tier
o	Disadvantage: While ThingSpeak provides a free service for small-scale applications, it comes with limitations, such as a cap on the number of updates per day and storage. As the number of users or the amount of data increases, the free tier may no longer be sufficient, requiring an upgrade to a paid plan.
o	Why It Matters: For small-scale projects, the free plan may be adequate. However, for large-scale deployments or systems that require high-frequency updates or extensive historical data storage, the cost of upgrading to a higher-tier service may become a concern.
4.	Energy Consumption
o	Disadvantage: While the ESP32 is power-efficient compared to many other microcontrollers, continuous data transmission and sensor readings can still consume significant energy, especially in battery-powered systems. For remote or off-grid systems, this could require additional power solutions like solar panels or large battery banks.
o	Why It Matters: The system’s energy consumption may limit its application in remote or mobile monitoring environments where power supply is a constraint. Ensuring that the system remains powered over extended periods could add complexity and cost to the project.
5.	Scalability and Maintenance Complexity
o	Disadvantage: While the system is scalable in terms of adding more sensors or devices, the complexity of managing and maintaining multiple ESP32 units or ensuring proper calibration across a network of sensors can become challenging. As the project scales up, issues such as sensor drift, network congestion, or cloud data management may arise.
o	Why It Matters: Maintaining accuracy and consistency across multiple devices or locations may require additional efforts, such as regular recalibration of sensors or ensuring stable network configurations. For large-scale implementations, additional hardware or software management tools may be needed.
6.	Limited to Air Quality and CO Monitoring
o	Disadvantage: The project focuses on air quality and carbon monoxide detection. While these are critical parameters, they do not cover other important environmental factors, such as temperature, humidity, particulate matter (PM), or ozone. This limits the comprehensive nature of the environmental monitoring system.
o	Why It Matters: Expanding the scope to include additional environmental parameters would provide a more holistic picture of the air quality. However, this would require additional sensors and potentially more complex data analysis, making the system more expensive and difficult to manage.
7.	Sensor Lifespan and Calibration
o	Disadvantage: The lifespan of the MQ135 and MQ7 sensors is finite, and over time, their accuracy may degrade. These sensors also require periodic calibration to maintain their reliability. Without proper maintenance, the data accuracy could deteriorate, leading to false readings.
o	Why It Matters: Sensor degradation and calibration are natural challenges with any environmental monitoring system. Regular maintenance is needed to ensure accurate readings, which may require additional resources and effort.

13.	References 
ESP32 Power Consumption and Specifications: https://www.electronicshub.org/getting-started-with-esp32/
MQ-7: https://robu.in/product/mq-7-co-carbon-monoxide-coal-gas-sensor-module/
MQ-135: https://www.elprocus.com/mq135-air-quality-sensor/
Github link: https://github.com/RanaMahadAhmer/IOT-Air-Quality-Monitoring-System
Wokwi link: https://wokwi.com/projects/417365302990711809
ThingSpeak link: https://thingspeak.mathworks.com/channels/2785876
