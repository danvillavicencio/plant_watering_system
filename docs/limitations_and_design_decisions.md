# Limitations and Design Decisions

## Platform Constraints

### Arduino Uno Limitations
- 10-bit ADC resolution (0–1024)
- Limited memory
- Basic timing control (no RTOS)

---

### Sensor Limitations

- Soil humidity sensors can degrade over time (to counter, the system controls the sensor's voltage)
- Readings may vary depending on soil composition
- No calibration routine implemented

---

### Threshold Design

- Critical threshold fixed at < ~200
- No dynamic adjustment
- No hysteresis implemented (may cause repeated watering in noisy signals)

---

## Design Decisions

### Educational and Simulation-Based
- Designed using Tinkercad components
- Focused on demonstrating embedded sensing and actuation
- Not designed for agricultural-scale deployment

---

### Servo as Valve
- Servo motor used to simulate a water tap
- Simplifies mechanical modeling

---

### Simple Control Loop
- No multitasking
- No real-time scheduling
- Blocking delays used for watering duration

---

## Known Limitations

- No water flow measurement
- No soil-type compensation
- No power optimization
- No data logging
- No wireless monitoring

---

## Future Improvements

- Replace blocking delays with non-blocking timing
- Add calibration routine
- Implement hysteresis to avoid oscillation
- Add water reservoir level detection
- Add WiFi monitoring (IoT extension)
