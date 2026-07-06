# RTOS-Based Environmental Monitoring Node

## Overview

An ESP32-based Environmental Monitoring System developed using **FreeRTOS**. The project demonstrates multitasking by separating sensor acquisition and display into independent RTOS tasks while monitoring multiple environmental parameters.

---

## Features

## Features

- ESP32 Development Board
- FreeRTOS Multitasking
- Multi-Sensor Environmental Monitoring
- DHT22 Temperature & Humidity Sensor
- LDR Light Sensor
- BMP280 Pressure Sensor
- PIR Motion Sensor
- Gas Sensor
- Rain Sensor
- SSD1306 OLED Display
- Serial Debug Output
- Wokwi Simulation
---

## Sensors Monitored

| Parameter | Sensor |
|---|---|
| Temperature | DHT22 |
| Humidity | DHT22 |
| Light Intensity | LDR |
| Pressure | BMP280 |
| Altitude | BMP280 |
| Motion | PIR Sensor |
| Air Quality | Gas Sensor |
| Rain Level | Rain Sensor |

## Hardware Components

- ESP32 DevKit V1
- DHT22 Temperature & Humidity Sensor
- LDR Light Sensor
- BMP280 Pressure & Altitude Sensor
- PIR Motion Sensor
- Gas Sensor
- Rain Sensor
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
- Reads Temperature
- Reads Humidity
- Reads Light Intensity
- Reads Pressure
- Reads Altitude
- Reads Gas Level
- Reads Rain Level
- Reads Motion Status

### Display Task
- Displays sensor values on OLED
- Updates display periodically

---

## Current Sensor Monitoring

- 🌡 Temperature
- 💧 Humidity
- ☀ Light Intensity
- 🌍 Atmospheric Pressure
- ⛰ Altitude
- 🌫 Air Quality
- 🌧 Rain Detection
- 🚶 Motion Detection

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

## Future Improvements

- LED & Buzzer Alert System
- FreeRTOS Queue
- FreeRTOS Semaphore
- FreeRTOS Mutex
- Wi-Fi Connectivity
- MQTT Cloud Dashboard
- SD Card Data Logging

---

## Author

**Midhun Kumar**

B.E. Electronics and Communication Engineering

Anna University
