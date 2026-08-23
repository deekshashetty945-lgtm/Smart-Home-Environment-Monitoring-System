# Smart Home Environment Monitoring System

## YuvaIntern – Week 1 Task

### System Requirements Analysis and Block Diagram Design

This project presents the design of a Smart Home Environment Monitoring System developed as part of the YuvaIntern Week 1 task.

## Project Overview

The proposed embedded system monitors important indoor environmental parameters such as:

- Temperature
- Humidity
- Air quality
- Ambient light

The system uses an ESP32 microcontroller to collect and process sensor data. The measured values are displayed on an OLED display. A buzzer and LED provide alerts when predefined environmental limits are exceeded. Wi-Fi connectivity is included for future remote monitoring and IoT integration.

## Hardware Components

- ESP32 Microcontroller
- DHT22 Temperature and Humidity Sensor
- MQ-135 Air Quality Sensor
- LDR Light Sensor
- OLED Display
- Buzzer
- LED
- Regulated Power Supply

## Software

- Arduino IDE
- Embedded C/C++
- ESP32 Arduino Framework
- DHT Sensor Library
- Adafruit GFX Library
- Adafruit SSD1306 Library

## System Architecture

The system follows this basic flow:

**Sensors → ESP32 → Processing → OLED Display / Alert → Wi-Fi**

The ESP32 acts as the central controller and manages sensor data, display output, alerts, and wireless communication.

## Project Files

| File | Description |
|---|---|
| `YuvaIntern_Week1_Task_Report.docx` | Complete Week 1 system requirements report |
| `environment_monitor.ino` | ESP32 monitoring program |
| `smart_home_environment_monitor_block_diagram.png` | System block diagram |
| `README.md` | Project documentation |

## Key Features

- Real-time environmental monitoring
- Temperature and humidity measurement
- Air-quality indication
- Ambient-light monitoring
- OLED-based local display
- Buzzer and LED alerts
- ESP32-based processing
- Wi-Fi connectivity for future IoT expansion

## Future Enhancements

- Cloud-based data logging
- Mobile application
- Web dashboard
- Additional environmental sensors
- Battery-powered operation
- Power-saving modes

## Conclusion

The Smart Home Environment Monitoring System demonstrates the planning and architecture of a practical embedded system. The project combines multiple sensors, an ESP32 microcontroller, local outputs, and wireless communication to provide a scalable platform for environmental monitoring.

**Developed for: YuvaIntern – Week 1 Task**
