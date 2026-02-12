# Hardware Design

## Main Controller

- **Board:** Arduino Uno R3
- **Microcontroller:** ATmega328P
- **Operating Voltage:** 5V
- The Arduino Uno R3 was selected due to its availability, simplicity, and compatibility with educational simulation tools such as Tinkercad.

## Soil Humidity Sensor
- Analog output (values from 0 to 1024 - 10 bits)
- Measures soil moisture level
- Connected to Arduino analog input pin

## LEDs (Humidity Indicator)

Five LEDs represent humidity levels:

|  LED  | Humidity Range | Color  |
|-------|----------------|--------|
| LED 1 | Very Dry       | Red    |
| LED 2 | Dry            | Orange |
| LED 3 | Moderate       | Yellow |
| LED 4 | Humid          | Green  |
| LED 5 | Just watered   | Blue   |

Each LED corresponds to a specific ADC range, equally divided and mapped to values from 0 to 5

## LCD Display

- Displays numeric humidity value (0–5)
- Provides real-time feedback
- Uses SPI communication in Arduino Uno R3, pins 11 and 12.

## Servo Motor (Water Valve Simulation)

- Acts as an automated tap
- Opens when humidity reaches Very Dry levels
- Closes after watering duration

## Buzzer

- Audible alert system
- 1 long beep → watering started
- 2 short beeps → watering finished

---

## Hardware Connections Summary

|    Component    |         Function         |
|-----------------|--------------------------|
| Humidity Sensor | Analog input measurement |
| LEDs            | Visual humidity level    |
| LCD             | Numeric level display    |
| Servo           | Water flow control       |
| Buzzer          | Alert signaling          |

---

## Simulation Environment

The system is designed using components available in Tinkercad to allow easy replication and validation without physical hardware.
