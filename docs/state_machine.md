# Finite State Machine (FSM)

## Overview

The watering system operates as a cyclic sensing-and-control loop. It can be described as a finite state machine.

---

## States

### 1. READ SENSOR
- ADC reading (0–1024)
- Store humidity value
- Value is mapped to range 1-5 for simplicity

### 2. DISPLAY STATUS
- Update LCD display to show reading

### 3. CHECK THRESHOLD
- Activate corresponding LED
- If humidity >= 2 → return to READ SENSOR
- If humidity < 2 → transition to WATERING

### 3.1 WATERING
- Servo opens (valve ON)
- Buzzer beeps once
- Wait fixed duration
- Servo closes
- Buzzer beeps twice
- Return to READ SENSOR

---

## State Diagram

READ SENSOR → DISPLAY STATUS → CHECK THRESHOLD → humidity<2/humidity>=2 → WATERING/READ SENSOR → READ SENSOR

---

## Timing Behavior

- Sensor reading occurs periodically
- Watering duration is fixed
- System runs continuously in loop
