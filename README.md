# Automatic Plant Watering System

An embedded systems project that monitors soil humidity and automatically waters a plant when moisture levels drop below a critical threshold.

This system integrates analog sensing, ADC processing, real-time control logic, and multiple actuators (LEDs, LCD, servo motor, and buzzer) using an Arduino Uno R3.

---

## Repository Structure

plant-watering-system/

├── firmware/

├── hardware/

├── docs/

├── simulation/

└── README.md

This repository contains:

- Embedded firmware source code
- Simulation files
- Hardware documentation
- System architecture and state machine design

---

## Demo

A short simulation demo is available in:
simulation/tinkercad/plant_watering_system_demo.mp4

Screenshots and diagrams are located in:
simulation/tinkercad/plant_watering_system.png
diagrams/plant_watering_system_fsm.png

---

## Simulation

The project is fully simulated using **Tinkercad**, allowing easy replication without physical hardware.

Simulation files and instructions can be found in:
simulation/

---

## System Architecture

The system is divided into three main layers:

### Input Layer

* Soil Moisture Sensor (Analog)

### Processing Layer

* Arduino Uno R3

  * ADC Reading
  * Threshold Evaluation
  * Control Logic
  * Actuator Coordination

### Output Layer

* 5 LEDs (Moisture Level Indicator)
* 16x2 LCD Display
* Servo Motor (Water Tap)
* Buzzer (Audible Feedback)

Architecture diagram:
diagrams/plant_watering_system_system_architecture.png

---

## System Behavior

1. **Moisture Reading**
- Sensor provides analog value (0–1024) later mapped to 0-5
- Displayed on LCD in real time

2. **LED Level Indication**

| Moisture Level |   LED Indication  |
| -------------- | ----------------- |
| 0              | Critical (Red)    |
| 1              | Very Dry (Orange) |
| 2              | Moderate (Yellow) |
| 3              | Moist (Green)     |
| 4              | Very Wet (Blue)   |

Only one LED corresponding to the level remains active.

3. Automatic Watering Logic

If moisture level < **1**:
1. Servo motor opens tap
2. Buzzer beeps once (watering start)
3. Water flows for predefined duration
4. Servo closes tap
5. Buzzer beeps twice (watering stop)
6. System waits before next measurement cycle

---

## Hardware Components

| Component             | Description                         |
| --------------------- | ----------------------------------- |
| Arduino Uno R3        | Main microcontroller                |
| Soil Humidity Sensor  | Analog soil moisture sensor         |
| 5x LEDs               | Moisture level indicators           |
| 16x2 LCD              | Real-time humidity display          |
| Servo Motor           | Controls water flow (tap mechanism) |
| Buzzer                | Audible alert during watering       |
| Resistors             | 220 Ω (LEDs), 1 kΩ (buzzer),        |
|                       | 10 kΩ potentiometer (LCD contrast)  |
|                       | 220 Ω (LCD)                         |

A schematic diagram for the system is provided in:
hardware/schematics/plant_watering_system_schematic.pdf

The BOM can be found in:
hardware/bom.csv

---

## Design Decisions & Limitations

Detailed discussion available in:
docs/limitations_and_design_decisions.md

---

## License

This project is provided for educational and portfolio purposes.

---

## Learning Outcomes

This project reinforces:
* Hardware-software integration
* Sensor-to-actuator pipelines
* Embedded architecture design
* Practical threshold-based automation systems
* Clean firmware structuring for professional portfolios
