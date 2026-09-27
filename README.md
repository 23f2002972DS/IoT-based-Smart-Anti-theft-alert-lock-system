# IoT-based Smart Anti-theft Alert Lock System

An intelligent vehicle security system designed to detect unauthorized motion or tampering on a parked two-wheeler and trigger an alert. The system aims to notify the owner in real time and provide location-based information for theft prevention.

## Project Overview

This project uses an ESP8266 microcontroller connected to motion/vibration sensors and an LCD display. It monitors the vehicle for suspicious activity and can activate an alarm output when abnormal movement is detected.

The system also hosts a small web page through the ESP8266 so the status can be checked remotely over Wi-Fi.

## Features

- Wi-Fi connectivity using ESP8266
- Vibration detection
- Mishandling detection
- LCD display status updates
- Alarm output using digital pin D0
- Basic web dashboard served by the ESP8266
- Real-time status monitoring

## Hardware Components

- ESP8266 NodeMCU
- Vibration sensor
- Mishandling / tamper sensor
- 16x2 I2C LCD display
- Buzzer or alarm device
- Power supply and wiring accessories

## Pin Mapping

- D6: vibration sensor input
- D7: mishandling sensor input
- D0: alarm output

## Software Requirements

Install the following in the Arduino IDE or VS Code Arduino environment:

- ESP8266WiFi
- ESP8266WebServer
- LiquidCrystal_I2C
- Wire

Also install the ESP8266 board package from the Board Manager:

- ESP8266 by ESP8266 Community

## Wi-Fi Configuration

Edit the following lines in the sketch before uploading:

```cpp
const char* ssid = "admin";
const char* password = "123456789";
```

Replace them with your own router credentials.

## Upload and Run

1. Open the sketch in Arduino IDE or VS Code.
2. Select the correct ESP8266 board and COM port.
3. Install the required libraries.
4. Upload the code to the ESP8266.
5. Connect to the device's IP address in a browser to view status.

## Notes

This project is a prototype/security alert system and can be expanded with:

- GPS tracking
- GSM or cloud-based notifications
- mobile app integration
- stronger alarm logic
- database logging

## License

This project is for educational and prototype use.
