# System Architecture

## Overview

This project implements an automated plant watering system using an Arduino Uno R3.

The system measures soil humidity using an analog humidity sensor and determines whether irrigation is required. Visual and audible feedback is provided to the user, and an automatic watering mechanism is activated when humidity levels fall below a defined threshold.

The system is based on a simple control loop that performs periodic sensor readings and executes actions based on threshold conditions.

---

## High-Level Architecture

Main components:

- **Controller:** Arduino Uno R3
- **Input:**
  - Soil moisture sensor (analog input)
- **Outputs:**
  - 5 LEDs (humidity level indication)
  - LCD display (numerical humidity value)
  - Servo motor (water valve control)
  - Buzzer (watering alert)

---

## Execution Flow

1. System initializes
2. Soil moisture sensor is read (0–1024 ADC scale, turned into scale 1-5 for simplicity)
3. LCD displays the humidity value
4. LED corresponding to humidity level is activated
   -If humidity < 2:
     Servo opens (watering)
     Buzzer beeps once (tap opened)
     Watering duration elapses
     Servo closes
     Buzzer beeps twice (tap closed)
5. System waits and restarts measurement cycle

---

## Design Characteristics

The system operates in a periodic sensing and actuation loop:
- Analog acquisition
- Threshold-based decision
- Actuator control
- User feedback
- Repeat cycle
