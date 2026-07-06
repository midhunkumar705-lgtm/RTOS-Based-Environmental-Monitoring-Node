# RTOS-Based Environmental Monitoring Node

## Overview

This project is an ESP32-based environmental monitoring system developed using **FreeRTOS**. It demonstrates multitasking by separating sensor acquisition and OLED display into independent RTOS tasks.

---

## Features

- ESP32 Development Board
- FreeRTOS Multitasking
- DHT22 Temperature & Humidity Sensor
- SSD1306 OLED Display
- Real-Time Sensor Monitoring
- Serial Debug Output
- Wokwi Simulation

---

## Hardware

- ESP32 DevKit V1
- DHT22 Sensor
- SSD1306 OLED Display

---

## Software

- Arduino IDE
- FreeRTOS
- Wokwi Simulator
- GitHub

---

## RTOS Tasks

### Sensor Task
- Reads temperature
- Reads humidity
- Updates sensor data every 2 seconds

### Display Task
- Displays sensor values on OLED
- Refreshes display every 1 second

---

## Folder Structure

```text
RTOS-Based-Environmental-Monitoring-Node
│
├── code
├── circuit
├── README.md
├── LICENSE
└── .gitignore
```

---

## Current Project Status

✅ ESP32 Setup

✅ FreeRTOS Task Creation

✅ DHT22 Sensor

✅ OLED Display

🔄 More sensors will be added in future commits.

---

## Future Improvements

- LDR Sensor
- BMP280 Pressure Sensor
- PIR Motion Sensor
- Gas Sensor
- Rain Sensor
- LED & Buzzer Alerts
- Wi-Fi Connectivity
- MQTT Cloud Integration
- Data Logging

---

## Author

**Midhun Kumar**

Electronics and Communication Engineering

Anna University
