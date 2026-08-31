# Smart Home Environment Monitoring System

## YuvaIntern – Week 1 Task

### System Requirements Analysis and Block Diagram Design

This project presents the design of a Smart Home Environment Monitoring System developed as part of the YuvaIntern Week 1 task.

## Project Overview

The Smart Home Environment Monitoring System is designed to monitor important environmental parameters inside a home. The system uses sensors to collect information such as temperature, humidity, air quality, and light intensity. An ESP32 microcontroller is used to process the sensor data and provide the monitoring functionality.

## Objectives

- Monitor temperature and humidity.
- Detect changes in indoor air quality.
- Monitor light intensity.
- Display sensor readings to the user.
- Develop a simple and efficient smart home monitoring system.
- Understand the hardware and software requirements of the system.

## Main Components

- ESP32 Development Board
- DHT22 Temperature and Humidity Sensor
- MQ-135 Air Quality Sensor
- LDR (Light Dependent Resistor)
- OLED Display
- Connecting wires and supporting components

## System Functions

### Temperature and Humidity Monitoring
The DHT22 sensor measures the temperature and humidity of the surrounding environment.

### Air Quality Monitoring
The MQ-135 sensor is used to detect changes in air quality and harmful gases.

### Light Intensity Monitoring
The LDR senses the intensity of surrounding light.

### Display
An OLED display is used to show the collected sensor readings to the user.

### Microcontroller
The ESP32 collects data from all sensors, processes the readings, and controls the display.

## System Workflow

The sensors continuously collect environmental data. The ESP32 receives and processes the sensor values. The processed information is then displayed on the OLED display for easy monitoring.

```text
DHT22 ───────┐
             │
MQ-135 ──────┤
             ├──> ESP32 ───> OLED Display
LDR ─────────┘
