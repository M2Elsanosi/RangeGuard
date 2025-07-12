# Ultrasonic Distance Alert System Using STM32

This embedded systems project employs an **HC-SR04 ultrasonic sensor** interfaced with an **STM32 microcontroller** to accurately measure distances and provide proximity alerts. The alert mechanism utilizes a **piezo buzzer**, **LED indicators**, and a **push-button** to acknowledge and reset alerts.

Implemented using the **STM32 Hardware Abstraction Layer (HAL) libraries**, the project exemplifies real-time coordination of multiple STM32F103 (Blue Pill) peripherals.

---

## Features

- **Audible Proximity Alerts:** Piezo buzzer signals when an object is detected within a specified range.  
- **Visual Indicators:** Dual LED configuration with red indicating alert state and green indicating a safe state.  
- **Precise Distance Measurement:** Utilizes an ultrasonic sensor to measure object proximity in centimeters.  
- **User Interaction:** Push-button to acknowledge and silence alerts.  
- **Hardware Timer Utilization:** Employs TIM1 for high-precision timing of echo pulses.

---

## Hardware Requirements

|          Component           | Quantity |
|------------------------------|----------|
| STM32F103C8T6 ("Blue Pill")  |    1     |
| HC-SR04 Ultrasonic Sensor    |    1     |
| Piezo Buzzer                 |    1     |
| Red LED                      |    1     |
| Green LED                    |    1     |
| Push Button                  |    1     |
| 330Ω Resistors (for LEDs)    |    2     |
| Breadboard and Jumper Wires  |   1 set  |

---

## Circuit Connections

|      Device      | STM32 Pin |       Description      |
|------------------|-----------|------------------------|
| HC-SR04 TRIG     |    PA9    |   Trigger output pulse |
| HC-SR04 ECHO     |    PA8    |     Echo input signal  |
| Piezo Buzzer     |    PA1    |  Audible alert output  |
| Green LED        |    PA0    |  Indicates safe status |
| Red LED          |    PA2    | Indicates alert status |
| Push Button      |    PB12   |  Alert acknowledgment  |

![Circuit Diagram](docs/circuit_diagram.png) <!-- Replace with your actual image -->

---

## Functional Overview

1. **Ultrasonic Distance Measurement:**  
   The STM32 generates a 10 microsecond trigger pulse on the TRIG pin. The sensor returns an echo pulse on the ECHO pin whose duration corresponds to the distance of the detected object. TIM1 hardware timer captures this duration and converts it into a distance measurement in centimeters.

2. **Alert Logic:**  
   - When the measured distance is less than or equal to 25 cm, the system activates the red LED and buzzer to signal a proximity alert.  
   - Pressing the push-button acknowledges the alert, deactivating the buzzer and switching the green LED on to indicate a safe state.  
   - If the distance exceeds 25 cm, the system maintains the green LED active and ensures the buzzer is off.

3. **Alert Debounce:**  
   The system implements logic to prevent repeated alerts unless a new proximity event occurs.

---

## Software Structure

