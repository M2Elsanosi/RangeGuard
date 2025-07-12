# Ultrasonic Distance Alert System Using STM32

This embedded systems project implements a distance-based proximity alert mechanism using an **HC-SR04 ultrasonic sensor** interfaced with an **STM32F103C8T6 ("Blue Pill")** microcontroller. It features a **piezo buzzer**, **dual LED indicators**, and a **push-button** to acknowledge and reset alerts.

The project is developed using **STM32 HAL (Hardware Abstraction Layer) libraries**, and demonstrates the use of GPIOs, hardware timers, and real-time decision-making in embedded applications.

---

## Features

- **Audible Alert System**: A piezo buzzer activates when an object is detected within a critical proximity range.
- **Visual Indication**: Dual LEDs provide status indication:
  - Red LED for alert (proximity detected)
  - Green LED for safe distance
- **Accurate Distance Measurement**: Measures the distance to nearby objects using ultrasonic pulses.
- **User Interaction**: A push-button enables the user to acknowledge and clear the alert condition.
- **Hardware Timer Precision**: Utilizes TIM1 for microsecond-level timing of echo pulses to ensure accurate measurement.

---

## Hardware Requirements

|              Component                |  Quantity  |
|---------------------------------------|------------|
| STM32F103C8T6 Microcontroller ("Blue Pill") | 1 |
| HC-SR04 Ultrasonic Sensor             |      1     |
| Piezo Buzzer                          |      1     |
| Red LED                               |      1     |
| Green LED                             |      1     |
| Push Button                           |      1     |
| 330Ω Resistors                        |      2     |
| Breadboard and Jumper Wires           |    1 set   |

---

## Circuit Connections

| Device        | STM32 Pin | Description               |
|---------------|-----------|---------------------------|
| HC-SR04 TRIG  | PA9       | Output trigger signal     |
| HC-SR04 ECHO  | PA8       | Input echo signal         |
| Piezo Buzzer  | PA1       | Audible alert output      |
| Green LED     | PA0       | Indicates safe condition  |
| Red LED       | PA2       | Indicates alert condition |
| Push Button   | PB12      | Acknowledges alert        |

**Note**: Ensure proper pull-up or pull-down configuration for the push-button to avoid floating input states.

---

## Functional Overview

### 1. Ultrasonic Distance Measurement

The STM32 generates a 10-microsecond pulse on the TRIG pin. The HC-SR04 sensor responds by sending an echo pulse on the ECHO pin. The width of this pulse is proportional to the distance of the object. TIM1 is configured to measure the duration of this pulse with microsecond accuracy.

### 2. Alert Logic

- If the measured distance is less than or equal to 25 centimeters:
  - The buzzer is activated.
  - The red LED is illuminated.
- When the user presses the push-button:
  - The alert state is cleared.
  - The buzzer is turned off.
  - The green LED is activated.
- If the distance exceeds 25 centimeters:
  - The green LED remains active.
  - The buzzer remains off.

### 3. Alert Debouncing

To avoid repeated alerts from transient or unchanged proximity events, the system uses a `redState` variable to track the current alert condition and suppress redundant activations until acknowledged.

---

## Software Structure

This project is developed using the STM32 HAL library framework. The code is modularized for clarity and maintainability.

### `main.c`

Contains:
- System initialization routines (`HAL_Init()`, `SystemClock_Config()`, etc.)
- Timer and GPIO configuration
- Main execution loop to:
  - Trigger ultrasonic pulse
  - Measure echo pulse duration
  - Compute distance
  - Handle LED/buzzer logic
  - Read push-button status

### `main.h`

Defines:
- Pin macros for GPIOs
- External variables
- Function prototypes

### `MX_TIM1_Init()`

- Configures TIM1 for microsecond-level resolution
- Used to accurately measure the echo pulse width returned by the ultrasonic sensor

### `MX_GPIO_Init()`

- Initializes all GPIOs for output or input, depending on their role
- Configures appropriate modes and pull-up/down resistors

### Summary of Execution Flow

1. Send trigger pulse to ultrasonic sensor
2. Measure echo duration using TIM1
3. Convert echo duration to distance
4. Activate alert indicators if threshold is crossed
5. Allow user to acknowledge and reset alert

---
