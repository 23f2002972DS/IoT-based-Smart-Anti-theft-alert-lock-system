# IoT-based Smart Anti-theft Alert Lock System

An intelligent vehicle security system designed to detect unauthorized motion or tampering on a parked two-wheeler and trigger an alert. The system aims to notify the owner in real time and provide location-based information for theft prevention.

## Problem statement

Traditional anti-theft mechanisms for two-wheelers rely primarily on mechanical locks and basic acoustic alarms, suffering from two critical flaws:
- High False Alarm Rates: Passive vibration sensors often trigger due to environmental noise (like heavy rain or passing trucks), leading owners to ignore alerts.
- Lack of Active Prevention & Real-Time Tracking: Standard alarms are only effective within earshot, provide no remote notification, and fail to physically prevent the vehicle from being hot-wired and driven away.

## Proposed solution

This project introduces an IoT-based digital perimeter around the vehicle's physical state using a NodeMCU (ESP8266). By leveraging dual-sensor verification and active immobilization, the system stops thieves in their tracks while immediately notifying the owner globally via a real-web dashboard.

## Project Overview

This project uses an ESP8266 microcontroller connected to motion/vibration sensors and an LCD display. It monitors the vehicle for suspicious activity and can activate an alarm output when abnormal movement is detected.

The system also hosts a small web page through the ESP8266 so the status can be checked remotely over Wi-Fi.

## Key Features

- Dual-Sensor Verification logic: Combines an active Joystick-based steering sensor with an SW520D Vibration/Tilt sensor to distinguish between genuine theft attempts (like handle turning or lifting) and harmless environmental disturbances.
- Active Engine Immobilization: Employs a 5V Relay-based "kill-switch" to physically disconnect the ignition circuit (simulated via a DC motor), making the vehicle impossible to start during a security breach.
- Global IoT Connectivity: Hosts a local web server to send instant push notifications and real-time status updates directly to a mobile browser, removing the "earshot" limitation.
- Live GPS Tracking: Integrates a NEO-6M GPS Module to parse exact NMEA coordinate data, allowing the owner to track the vehicle on a global map for rapid recovery.
- Local Audio-Visual Deterrents: Features a high-decibel Piezo Buzzer for immediate on-site audio warnings and a 16x2 I2C LCD Display for localized diagnostic feedback. 

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

```cppz
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

## System Architecture & Workflow

- Input & Calibration: Upon activation, the NodeMCU reads the default states of the digital input pins (D6 and D7). The joystick establishes a physical baseline for the steering column.
- Continuous Processing: The microcontroller actively compares live sensor feeds against predefined threshold limits. It looks for sustained deviations like the handle being forced or the chassis being tilted beyond 15 degrees.
- Output & Immobilization: If a breach is confirmed, the system pulls the relay coil to an open circuit state, cutting power to the DC motor (engine). Simultaneously, it triggers the buzzer and LCD alerts.
- Remote Communication: The NEO-6M module acquires a satellite fix and transmits UART coordinate strings to the NodeMCU, which refreshes the ESP8266WebServer interface with live GPS data and threat diagnostics.

## Operational States

The system actively updates the localized LCD and the remote Web UI based on the following logic conditions:
- NORMAL: No disturbances detected. The relay is closed (engine operable), and the buzzer is silent.
- MISHANDLE: Joystick sensor detects unauthorized steering movement. The LCD/Web UI updates to "MISHANDLE", and the buzzer emits a warning beep.
- VIBRATION: SW520D sensor detects physical shocks or lifting. The UI updates to "VIBRATION", accompanied by a warning beep.
- CRITICAL ALERT (Both Detected): Simultaneous triggering of both sensors confirms a high-risk theft event. The system forces a continuous high-decibel alarm, immediately immobilizes the engine, and broadcasts live GPS coordinates.

## Notes

This project is a prototype/security alert system and can be expanded with:

- GPS tracking
- GSM or cloud-based notifications
- mobile app integration
- stronger alarm logic
- database logging

## License

This project is for educational and prototype use.
