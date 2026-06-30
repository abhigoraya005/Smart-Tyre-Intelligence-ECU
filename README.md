# 🚗 Smart Tyre Intelligence ECU using STM32

> **An Automotive-Inspired Embedded ECU for Real-Time Tyre Health Monitoring, Fault Detection, Warning Generation, Predictive Maintenance, and Interactive Dashboard Visualization**

<p align="center">

![STM32](https://img.shields.io/badge/STM32F103C8T6-Blue_Pill-blue)
![Language](https://img.shields.io/badge/Language-Embedded_C-success)
![IDE](https://img.shields.io/badge/IDE-STM32CubeIDE-orange)
![Simulation](https://img.shields.io/badge/Simulation-PICSimLab-red)
![Dashboard](https://img.shields.io/badge/Dashboard-HTML5%20%7C%20CSS3%20%7C%20JavaScript-purple)
![Architecture](https://img.shields.io/badge/Architecture-Modular%20ECU-brightgreen)
![Status](https://img.shields.io/badge/Status-In%20Development-success)

</p>

---

# 📖 Project Overview

Modern automobiles contain dozens of **Electronic Control Units (ECUs)** responsible for monitoring, controlling, and protecting critical vehicle systems.

Tyres are among the most important safety components because they directly influence:

- Vehicle Stability
- Braking Performance
- Ride Comfort
- Fuel Efficiency
- Handling
- Driver Safety

A damaged or unhealthy tyre can significantly increase stopping distance, reduce grip, and lead to catastrophic failures.

This project develops a **Smart Tyre Intelligence ECU** using the **STM32F103C8T6 Blue Pill** microcontroller.

The ECU continuously monitors multiple tyre-related parameters through ADC inputs, processes sensor data using modular embedded software, evaluates tyre health, detects faults, generates warnings, predicts maintenance requirements, and visualizes the complete system through both a UART terminal and a professional HTML dashboard.

The firmware is designed using an **Automotive-Inspired Layered Software Architecture**, making it scalable, reusable, and easy to extend with future automotive technologies such as CAN, FreeRTOS, AUTOSAR-inspired layers, TPMS, and IoT connectivity.

---

# 🎯 Project Objectives

The primary objectives of this project are:

- Real-Time Temperature Monitoring
- Real-Time Pressure Monitoring
- Real-Time Vibration Monitoring
- Real-Time Load Monitoring
- ADC-Based Sensor Acquisition
- Tyre Health Score Calculation
- Tyre Status Classification
- Fault Detection
- Safety Warning Generation
- Predictive Maintenance Recommendation
- UART Diagnostic Dashboard
- Interactive HTML Dashboard
- Modular Embedded Software Architecture

---

# ✨ Project Highlights

✔ Modular Embedded Software Design

✔ Automotive-Inspired ECU Architecture

✔ STM32 HAL Driver Development

✔ ADC Multi-Sensor Monitoring

✔ Sensor Manager Framework

✔ Tyre Health Calculation Engine

✔ Fault Detection System

✔ Warning Generation Module

✔ Predictive Maintenance Engine

✔ UART Diagnostic Dashboard

✔ Interactive HTML Dashboard

✔ PICSimLab Simulation

✔ Professional GitHub Documentation

---

# 🛠 Hardware Components

| Component | Description |
|-----------|-------------|
| STM32F103C8T6 | Main ECU Controller |
| PICSimLab | Embedded Simulation Platform |
| Potentiometers | Simulated ADC Sensors |
| UART Virtual Terminal | Serial Dashboard |
| ADC Channels | Sensor Inputs |

---

# 💻 Software Stack

| Software | Purpose |
|----------|---------|
| STM32CubeIDE | Firmware Development |
| STM32 HAL Drivers | Peripheral Drivers |
| Embedded C | Firmware Programming |
| PICSimLab | Hardware Simulation |
| Git | Version Control |
| GitHub | Repository Management |
| HTML | Dashboard UI |
| CSS | Dashboard Styling |
| JavaScript | Interactive Dashboard |

---

# 🚀 Features

## Sensor Monitoring

- Temperature Monitoring
- Pressure Monitoring
- Vibration Monitoring
- Load Monitoring

---

## ECU Processing

- ADC Sampling
- Sensor Conversion
- Sensor Manager
- Tyre Health Analysis
- Health Score Calculation

---

## Safety System

- Fault Detection
- Warning Generation
- Critical Alert Detection

---

## Predictive Maintenance

- Tyre Replacement Suggestion
- Pressure Inspection
- Wheel Balancing Recommendation
- Suspension Inspection

---

## Dashboard

- Professional UART Dashboard
- Interactive HTML Dashboard
- Live Sensor Visualization
- Vehicle Health Monitoring

---

# 🏗 Software Architecture

```text
                      Smart Tyre Intelligence ECU

                                │
                                │
        ┌──────────────────────────────────────────────┐
        │                  ECU Manager                 │
        └──────────────────────────────────────────────┘
                                │
 ┌──────────────┬───────────────┬───────────────┬──────────────┐
 │              │               │               │              │
 ▼              ▼               ▼               ▼              ▼

Sensor       Tyre          Fault           Warning      Predictive
Manager      Health        Manager         Manager      Maintenance

 │
 │
 ├──────────────┐
 │              │
 ▼              ▼

Temperature    Pressure
Vibration      Load

 │
 ▼

UART Dashboard

 │
 ▼

HTML Dashboard
```

---

# 📊 Automotive ECU Layered Architecture

```text
+------------------------------------------------------------+
|                 HTML Dashboard Layer                       |
+------------------------------------------------------------+

                 UART Communication Layer

+------------------------------------------------------------+
|               ECU Application Layer                        |
|------------------------------------------------------------|
| ECU Manager                                                |
| Sensor Manager                                             |
| Tyre Health Manager                                        |
| Fault Manager                                              |
| Warning Manager                                            |
| Predictive Maintenance                                     |
+------------------------------------------------------------+

+------------------------------------------------------------+
|                    Driver Layer                            |
|------------------------------------------------------------|
| ADC Driver                                                 |
| UART Driver                                                |
| GPIO Driver                                                |
| STM32 HAL Drivers                                          |
+------------------------------------------------------------+

+------------------------------------------------------------+
|                   Hardware Layer                           |
|------------------------------------------------------------|
| STM32F103C8T6                                              |
| ADC Sensors                                                |
| UART                                                       |
| GPIO                                                       |
| PICSimLab                                                  |
+------------------------------------------------------------+
```

---

# 🔄 Runtime Execution Flow

```text
                     POWER ON

                         │
                         ▼

                STM32 Initialization

                         │
                         ▼

                 Driver Initialization

                         │
                         ▼

                 ECU Module Initialization

                         │
                         ▼

                 Read ADC Sensor Values

                         │
                         ▼

              Convert Physical Parameters

                         │
                         ▼

                  Update Sensor Manager

                         │
                         ▼

               Calculate Tyre Health Score

                         │
                         ▼

                 Detect Active Faults

                         │
                         ▼

               Generate Safety Warnings

                         │
                         ▼

            Predict Maintenance Requirement

                         │
                         ▼

               Update UART Dashboard

                         │
                         ▼

             Update HTML Dashboard

                         │
                         ▼

                  Repeat Forever
```

---

# 📌 STM32 Pin Configuration

| Peripheral | STM32 Pin |
|------------|-----------|
| Temperature Sensor | PA0 |
| Pressure Sensor | PA1 |
| Vibration Sensor | PA2 |
| Load Sensor | PA3 |
| UART TX | PA9 |
| UART RX | PA10 |
| Status LED | PC13 |

---
# 🧩 Software Modules

The firmware is designed using a modular architecture where every subsystem is implemented independently for better scalability and maintainability.

---

## 🖥 ECU Manager

The ECU Manager acts as the main controller of the firmware.

### Responsibilities

- Initializes all software modules
- Executes the main application loop
- Controls complete firmware execution
- Coordinates communication between modules

---

## 🌡 Temperature Module

### Responsibilities

- Reads ADC Channel
- Converts ADC values into Celsius
- Filters noisy values
- Provides temperature data to Sensor Manager

### Output

- Temperature (°C)

---

## 🛞 Pressure Module

### Responsibilities

- Reads ADC Channel
- Converts ADC values into PSI
- Validates sensor range

### Output

- Pressure (PSI)

---

## 📳 Vibration Module

### Responsibilities

- Reads ADC value
- Converts into vibration level (g)

### Output

- Vibration (g)

---

## 🚚 Load Module

### Responsibilities

- Reads ADC value
- Calculates tyre load percentage

### Output

- Load (%)

---

## 📡 Sensor Manager

The Sensor Manager combines all sensor readings into one centralized data structure.

### Responsibilities

- Store latest sensor values
- Update every ECU cycle
- Provide data to upper software layers

### Managed Sensors

- Temperature
- Pressure
- Vibration
- Load

---

## ❤️ Tyre Health Manager

This module evaluates the current tyre condition.

### Inputs

- Temperature
- Pressure
- Vibration
- Load

### Outputs

- Health Score (0–100%)
- Tyre Status

### Status Levels

- Excellent
- Good
- Warning
- Critical

---

## ⚠ Fault Manager

Detects abnormal operating conditions.

### Supported Faults

- Over Temperature
- Low Pressure
- High Pressure
- High Vibration
- Over Load

---

## 🚨 Warning Manager

Generates user-friendly warnings based on detected faults.

### Warning Levels

- Normal
- Warning
- Critical

---

## 🔧 Predictive Maintenance

Analyzes the overall tyre condition and recommends maintenance.

### Possible Recommendations

- Replace Tyre
- Pressure Inspection
- Wheel Balancing
- Suspension Inspection
- Continue Monitoring

---

# 📡 UART Diagnostic Dashboard

The firmware continuously transmits ECU information over UART.

The dashboard displays

- ECU Status
- Health Score
- Temperature
- Pressure
- Vibration
- Load
- Active Faults
- Active Warnings
- Predictive Maintenance
- Firmware Information

---

## Sample UART Output

```text
========================================================

SMART TYRE INTELLIGENCE ECU

========================================================

ECU STATUS : GOOD

Health Score : 92 %

Temperature : 41.8 C

Pressure : 32.4 PSI

Vibration : 0.82 g

Load : 38 %

Faults : NONE

Warnings : NONE

Maintenance : Continue Monitoring

========================================================
```

---

# 🖥 Interactive HTML Dashboard

In addition to the UART dashboard, the project also includes a browser-based interactive dashboard.

## Dashboard Features

- Live Sensor Cards
- Animated Vehicle Visualization
- Health Gauge
- Active Fault Panel
- Active Warning Panel
- Predictive Maintenance Panel
- Real-Time Charts
- Professional Automotive UI

---

## Vehicle Visualization

The dashboard includes an animated vehicle scene.

Vehicle animations include

- Wheel Rotation
- Temperature Based Tyre Color
- Pressure Based Tyre Size
- Suspension Movement
- Vehicle Shake
- Smoke Effects
- Highway Animation
- Live Sensor Callouts

---

# 📷 Project Gallery

## UART Dashboard

> *(Insert UART Dashboard Screenshot Here)*

```
images/uart_dashboard.png
```

---

## HTML Dashboard

> *(Insert HTML Dashboard Screenshot Here)*

```
images/html_dashboard.png
```

---

## Vehicle Animation

> *(Insert Vehicle Visualization Screenshot Here)*

```
images/vehicle_dashboard.png
```

---

# 📂 Repository Structure

```text
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

├── Final_Dashboard
│   ├── index.html
│   ├── css
│   ├── js
│   ├── assets
│   └── images

├── README.md

└── LICENSE
```

---

# 🚀 Development Progress

| Day | Module | Status |
|-----:|---------------------------|:------:|
| 01 | Project Setup | ✅ |
| 02 | UART Driver | ✅ |
| 03 | Temperature Sensor | ✅ |
| 04 | ADC Driver | ✅ |
| 05 | Pressure Sensor | ✅ |
| 06 | Vibration Sensor | ✅ |
| 07 | Load Sensor | ✅ |
| 08 | Sensor Manager | ✅ |
| 09 | Tyre Health Module | ✅ |
| 10 | Fault Manager | ✅ |
| 11 | Warning Manager | ✅ |
| 12 | Predictive Maintenance | ✅ |
| 13 | UART Dashboard | ✅ |
| 14 | Architecture Refinement | ✅ |
| 15 | HTML Dashboard | 🚧 |
| 16 | Live Charts | 🚧 |
| 17 | Vehicle Animation | 🚧 |
| 18 | CAN Communication | ⏳ |
| 19 | FreeRTOS | ⏳ |
| 20 | TPMS Integration | ⏳ |

---

# 📊 Current Project Status

| Feature | Status |
|-----------------------------|:------:|
| ADC Driver | ✅ |
| UART Communication | ✅ |
| Sensor Manager | ✅ |
| Tyre Health Calculation | ✅ |
| Fault Detection | ✅ |
| Warning Generation | ✅ |
| Predictive Maintenance | ✅ |
| UART Dashboard | ✅ |
| HTML Dashboard | 🚧 |
| Vehicle Animation | 🚧 |
| CAN Communication | ⏳ |
| FreeRTOS | ⏳ |
| Cloud Monitoring | ⏳ |

---
# 🛣️ Future Enhancements

The current implementation focuses on a modular STM32-based tyre monitoring ECU. The following features are planned for future versions:

## Embedded Features

- CAN Bus Communication (CAN 2.0)
- FreeRTOS Task Scheduling
- EEPROM Data Logging
- SD Card Event Storage
- DMA-Based ADC Acquisition
- Watchdog Timer Integration
- Low Power Modes
- Bootloader Support

---

## Automotive Features

- TPMS Sensor Integration
- Wheel Speed Sensor Support
- Vehicle Speed Estimation
- GPS Integration
- OBD-II Diagnostics
- UDS Diagnostic Services
- ISO-TP Communication
- AUTOSAR-Inspired Software Layers

---

## IoT Features

- ESP32 Wi-Fi Gateway
- MQTT Cloud Communication
- Firebase Integration
- AWS IoT Core
- OTA Firmware Updates
- Mobile Application
- Remote Diagnostics

---

## Dashboard Features

- Live Serial Communication
- CAN Frame Visualization
- Real-Time Sensor Graphs
- Historical Data Logging
- Dark / Light Theme
- Vehicle Animation
- Rain & Weather Effects
- Night Driving Mode

---

# 📊 Skills Demonstrated

This project demonstrates practical experience in multiple Embedded Systems domains.

## Embedded Systems

- Embedded C Programming
- STM32 HAL Driver Development
- ADC Programming
- UART Communication
- GPIO Programming
- Interrupt Handling
- Embedded Debugging

---

## Automotive Software

- ECU Software Design
- Sensor Fusion
- Fault Detection
- Health Monitoring
- Predictive Maintenance
- Automotive State Machine
- Layered Software Architecture

---

## Software Engineering

- Modular Programming
- Driver Development
- Software Documentation
- Version Control
- Git Workflow
- GitHub Repository Management

---

## Frontend Dashboard

- HTML5
- CSS3
- JavaScript
- Interactive Dashboard Design
- Automotive UI Development
- Data Visualization

---

# 📚 Learning Outcomes

Through this project I gained practical experience in

- Embedded Firmware Development
- STM32 Microcontroller Programming
- Automotive ECU Architecture
- ADC Sensor Interfaces
- UART Communication
- Modular Software Design
- Driver Development
- Real-Time Embedded Systems
- Professional GitHub Documentation
- Dashboard Development

---

# 🔧 Build Instructions

## Requirements

- STM32CubeIDE
- STM32 HAL Drivers
- PICSimLab
- Git
- VS Code (for Dashboard)

---

## Clone Repository

```bash
git clone https://github.com/abhigoraya005/Smart-Tyre-Intelligence-ECU.git

cd Smart-Tyre-Intelligence-ECU
```

---

## Build Firmware

1. Open STM32CubeIDE

2. Import Existing Project

3. Select

```
Smart_Tyre_ECU_Day14
```

4. Build Project

5. Run PICSimLab Simulation

6. Open UART Virtual Terminal

7. Observe Live ECU Output

---

## Run HTML Dashboard

Navigate to

```
Final_Dashboard/
```

Open

```
index.html
```

or

Run using Live Server in VS Code.

---

# 📸 Project Screenshots

## STM32 Firmware

```
images/stm32_project.png
```

---

## UART Dashboard

```
images/uart_dashboard.png
```

---

## HTML Dashboard

```
images/html_dashboard.png
```

---

## Vehicle Animation

```
images/vehicle_animation.png
```

---

## PICSimLab

```
images/picsimlab.png
```

---

# 🎥 Demo

Future releases will include

- Firmware Demonstration
- Dashboard Demonstration
- PICSimLab Simulation
- GitHub Walkthrough

---

# 📈 Project Statistics

| Metric | Value |
|---------|------:|
| Programming Language | Embedded C |
| Platform | STM32F103C8T6 |
| Drivers Implemented | 6+ |
| ECU Modules | 8 |
| Sensor Types | 4 |
| Dashboard Types | 2 |
| Development Days | 14+ |
| Architecture | Modular |
| IDE | STM32CubeIDE |
| Version Control | Git |

---

# 🤝 Contribution

Contributions are welcome.

If you have suggestions or improvements:

1. Fork the repository

2. Create a new branch

```bash
git checkout -b feature/new-feature
```

3. Commit your changes

```bash
git commit -m "Add new feature"
```

4. Push to your fork

```bash
git push origin feature/new-feature
```

5. Open a Pull Request

---

# 📄 License

This project is released for

- Educational Purposes
- Embedded Systems Learning
- Automotive Software Practice
- Research & Development

Feel free to use the project for learning while retaining appropriate attribution.

---

# 👨‍💻 Author

## Abhiney Kumar

**B.Tech – Electronics & Communication Engineering**

**Dr. B. R. Ambedkar National Institute of Technology Jalandhar**

### Areas of Interest

- Embedded Systems
- Automotive Embedded Software
- Firmware Development
- STM32
- Device Drivers
- Automotive ECU Design
- VLSI
- Semiconductor Systems

---

# 🌟 Support the Project

If you found this repository useful,

⭐ Star the repository

🍴 Fork the repository

🐛 Report issues

💡 Suggest improvements

📢 Share it with others

---

<p align="center">

## 🚗 Smart Tyre Intelligence ECU

**Building the Foundation for Automotive Embedded Systems**

Designed & Developed by **Abhiney Kumar**

Made with ❤️ using **STM32**, **Embedded C**, and **Automotive Software Architecture**

</p>