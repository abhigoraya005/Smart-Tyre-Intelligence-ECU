# 🚗 Smart Tyre Intelligence ECU using STM32

> **An Automotive-Inspired Embedded ECU for Real-Time Tyre Health Monitoring, Fault Detection, Warning Generation and Predictive Maintenance**

![STM32](https://img.shields.io/badge/STM32F103C8T6-Blue_Pill-blue)
![Language](https://img.shields.io/badge/Language-Embedded_C-success)
![IDE](https://img.shields.io/badge/IDE-STM32CubeIDE-orange)
![Simulation](https://img.shields.io/badge/Simulation-PICSimLab-red)
![Status](https://img.shields.io/badge/Project-In_Progress-brightgreen)

---

# 📖 Project Overview

Modern vehicles rely on Electronic Control Units (ECUs) to continuously monitor the condition of critical systems. Tyres directly affect vehicle safety, stability, braking efficiency, and fuel economy. A damaged or unhealthy tyre can lead to severe accidents.

This project develops a **Smart Tyre Intelligence ECU** using the **STM32F103C8T6** microcontroller. The ECU continuously monitors tyre parameters, evaluates tyre health, detects abnormal operating conditions, generates warnings, and recommends maintenance actions in real time.

The project is designed following an **Automotive ECU Software Architecture**, where each functionality is implemented as an independent software module to improve scalability, maintainability, and code reusability.

---

# 🎯 Objectives

* Monitor tyre temperature
* Monitor tyre pressure
* Monitor tyre vibration
* Monitor tyre load
* Detect tyre faults
* Calculate tyre health score
* Classify tyre condition
* Generate safety warnings
* Recommend predictive maintenance
* Display live ECU dashboard through UART

---

# 🛠 Hardware

* STM32F103C8T6 Blue Pill
* PICSimLab
* Virtual Terminal
* Potentiometers (ADC simulation)
* UART Communication

---

# 💻 Software

* STM32CubeIDE
* STM32 HAL Drivers
* Embedded C
* Git
* GitHub

---

# ⚙️ Features

✅ Temperature Monitoring

✅ Pressure Monitoring

✅ Vibration Monitoring

✅ Load Monitoring

✅ ADC Sensor Management

✅ Modular Driver Architecture

✅ Tyre Health Analysis

✅ Fault Detection

✅ Warning Management

✅ Predictive Maintenance

✅ Professional UART Dashboard

---

# 🏗 Project Architecture

```
Smart Tyre Intelligence ECU
│
├── ECU Manager
│
├── Sensor Manager
│   ├── Temperature
│   ├── Pressure
│   ├── Vibration
│   └── Load
│
├── Tyre Health Manager
│
├── Fault Manager
│
├── Warning Manager
│
├── Predictive Maintenance
│
└── UART Dashboard
```

---

# 🔄 System Flowchart

```text
                  START
                    │
                    ▼
            Initialize STM32
                    │
                    ▼
         Initialize ECU Modules
                    │
                    ▼
       Read All ADC Sensor Values
                    │
                    ▼
     Convert ADC to Physical Values
                    │
                    ▼
       Update Sensor Manager
                    │
                    ▼
      Calculate Tyre Health Score
                    │
                    ▼
        Detect Tyre Faults
                    │
                    ▼
      Generate Safety Warnings
                    │
                    ▼
 Predict Predictive Maintenance
                    │
                    ▼
      Display UART Dashboard
                    │
                    ▼
              Repeat Forever
```

---

# 🧩 Software Modules

## ECU Manager

* Initializes all ECU modules
* Controls complete execution flow

---

## Sensor Manager

Responsible for

* ADC Reading
* Data Conversion
* Sensor Storage

---

## Temperature Module

* Reads ADC Channel
* Converts ADC into Celsius

---

## Pressure Module

* Reads ADC Channel
* Converts ADC into PSI

---

## Vibration Module

* Converts ADC into g-force

---

## Load Module

* Converts ADC into Load Percentage

---

## Tyre Health Module

Calculates tyre health based on

* Temperature
* Pressure
* Vibration
* Load

Outputs

* Health Score
* Tyre Status

---

## Fault Manager

Detects

* Over Temperature
* Low Pressure
* High Pressure
* High Vibration
* Over Load

---

## Warning Manager

Generates

* Critical Alerts
* Warning Alerts
* Normal Status

---

## Predictive Maintenance

Provides recommendations

* Replace Tyre
* Wheel Balancing
* Suspension Inspection
* Pressure Inspection

---

# 📊 UART Dashboard

Displays

* ECU Status
* Health Score
* Sensor Values
* Fault Status
* Active Warnings
* Maintenance Recommendation
* Firmware Information

---

# 📂 Project Structure

```
Smart_Tyre_Intelligence_ECU
│
├── Smart_Tyre_ECU_Day01
├── Smart_Tyre_ECU_Day02
├── Smart_Tyre_ECU_Day03
├── Smart_Tyre_ECU_Day04
├── Smart_Tyre_ECU_Day05
├── Smart_Tyre_ECU_Day06
├── Smart_Tyre_ECU_Day07
├── Smart_Tyre_ECU_Day08
├── Smart_Tyre_ECU_Day09
├── Smart_Tyre_ECU_Day10
├── Smart_Tyre_ECU_Day11
├── Smart_Tyre_ECU_Day12
├── Smart_Tyre_ECU_Day13
├── Smart_Tyre_ECU_Day14
└── README.md
```

---

# 🚀 Development Progress

| Day | Task                    | Status |
| --- | ----------------------- | ------ |
| 1   | Project Setup           | ✅      |
| 2   | UART Driver             | ✅      |
| 3   | Temperature Sensor      | ✅      |
| 4   | ADC Driver              | ✅      |
| 5   | Pressure Sensor         | ✅      |
| 6   | Vibration Sensor        | ✅      |
| 7   | Load Sensor             | ✅      |
| 8   | Sensor Manager          | ✅      |
| 9   | Tyre Health Module      | ✅      |
| 10  | Fault Manager           | ✅      |
| 11  | Warning Manager         | ✅      |
| 12  | Predictive Maintenance  | ✅      |
| 13  | Dashboard Improvements  | ✅      |
| 14  | Architecture Refinement | ✅      |
| 15+ | Advanced ECU Features   | 🚧     |

---

# 📸 Results

The UART dashboard provides real-time information including:

* Temperature
* Pressure
* Vibration
* Load
* Health Score
* ECU Status
* Active Faults
* Active Warnings
* Maintenance Recommendations

---

# 📈 Future Enhancements

* CAN Bus Communication
* FreeRTOS Integration
* EEPROM Storage
* SD Card Logging
* OLED/LCD Dashboard
* BLE Connectivity
* IoT Cloud Monitoring
* TPMS Sensor Integration
* Automotive Diagnostics (UDS)
* AUTOSAR-inspired Software Layers

---

# 👨‍💻 Author

**Abhiney Kumar**

B.Tech Electronics & Communication Engineering

Dr. B. R. Ambedkar National Institute of Technology Jalandhar

---

# ⭐ Support

If you found this project useful:

⭐ Star the repository

🍴 Fork the repository

🛠 Contribute to the project

---

## 📄 License

This project is intended for educational, research, and embedded systems learning purposes.
