# Obstacle-Avoiding-Robot

## Introduction
- **What does it do?**
  - The robot detects obstacles in its path and dynamically adjusts its direction to avoid collisions.

- **What is its purpose?**
  - The goal of this project is to create a simple, autonomous robot while gaining hands-on experience with robotics, electronics, and programming.
    
- **What inspired the idea?**
  - The idea came from the desire to create an efective robot car that simulates the movement principle of a robotic vacuum cleaner, navigating and avoiding obstacles while covering the area.

- **Why is it useful?**
  - This project serves as an excellent introduction to robotics concepts, such as sensor integration and motor control. It is easy to extend for more complex tasks like line following, mapping, or obstacle classification.

## General Description
<div style="background-color: #e8f5e9; padding: 10px; border: 1px solid #c8e6c9; border-radius: 5px;">   The obstacle-avoiding robot is designed to move autonomously in an environment filled with obstacles. It uses an HC-SR04 ultrasonic sensor to measure distances and determine when to avoid obstacles by turning left, right, or stopping.
The robot is powered by a motor driver module (L298N) that controls two DC motors connected to wheels, allowing movement.

A servo motor (SG90) is used to rotate the ultrasonic sensor, enabling the robot to scan its surroundings for obstacles in multiple directions. The entire system is controlled by an Arduino UNO, which processes data from the sensor and executes appropriate movement commands.

</div>

### Block Diagram

![Block Diagram](images/BlockDiagram.png)

### Hardware Functionality

**1. Arduino Uno**
- The microcontroller acts as the brain of the project, controlling all other components based on sensor inputs and programmed logic.
- It receives data from the HC-SR04 Ultrasonic Sensor and processes it to decide motor movements using the L298N Motor Driver Board.

**2. HC-SR04 Ultrasonic Sensor**
- **Purpose:** Measures the distance to an obstacle using ultrasonic waves.
- **Pins Used:**
  - VCC: Connected to 5V pin of Arduino (Power supply).
  - GND: Connected to the GND of Arduino (Ground reference).
  - TRIG (Trigger Pin): Connected to Arduino Pin 9. It sends out a pulse to start distance measurement.
  - ECHO (Echo Pin): Connected to Arduino Pin 8. It receives the reflected ultrasonic pulse to calculate distance.
    
**3. Servo Motor**
- **Purpose:** Rotates the ultrasonic sensor (left and right) to scan for obstacles in different directions.
- **Pins Used:**
  - Signal Pin: Connected to Arduino Pin 10. It sends PWM (Pulse Width Modulation) signals to control the servo’s angle.
  - VCC and GND: Connected to a 5V power supply and ground.

**4. L298N Motor Driver Board**
- **Purpose:** Controls the two geared motors based on commands from the Arduino. It allows the robot to move forward, backward, left, and right.
- **Pins Used:**
  - IN1 and IN2: Connected to Arduino Pins 4 and 5. Control the direction of Motor 1.
  - IN3 and IN4: Connected to Arduino Pins 6 and 7. Control the direction of Motor 2.
  - OUT1 and OUT2: Connected to Motor 1 terminals.
  - OUT3 and OUT4: Connected to Motor 2 terminals.
  - ENA and ENB: Connected to the 5V PWM pins for motor speed control.
  - VCC (12V Input): Connected to the 9V DC Power Supply. Powers the motors.
  - GND: Common ground for the power supply, motors, and Arduino.

**5. Geared Motors (2x)**
- Controlled via the L298N Motor Driver for directional and speed control.
- Connected to the motor outputs (OUT1, OUT2, OUT3, and OUT4).

**6. 9V DC Power Supply**
- Powers the motors and the L298N motor driver. The Arduino can be powered either through its USB port or a separate power source.

## Hardware Design
 ### BOM (Bill Of Materials)

| **Component**               | **Description**                                      | **Quantity** | **Datasheet / Link**                                                                 |
|-----------------------------|------------------------------------------------------|--------------|-----------------------------------------------------------------------------------|
| **Arduino Uno**             | Microcontroller board for controlling the components | 1            | [Arduino Uno Datasheet](https://www.alldatasheet.com/datasheet-pdf/view/241077/ATMEL/ATMEGA328P.html)       |
| **HC-SR04 Ultrasonic Sensor** | Distance measurement using ultrasonic waves          | 1            | [HC-SR04 Datasheet](https://www.alldatasheet.com/datasheet-pdf/pdf/1132204/ETC2/HCSR04.html) |
| **Servo Motor (SG90)**      | Small servo motor for rotating the ultrasonic sensor | 1            | [SG90 Servo Datasheet](https://www.alldatasheet.com/datasheet-pdf/pdf/1572383/ETC/SG90.html) |
| **L298N Motor Driver Module** | Dual H-Bridge motor driver for controlling motors    | 1            | [L298N Datasheet](https://www.alldatasheet.com/datasheet-pdf/pdf/22440/STMICROELECTRONICS/L298N.html)              |
| **Geared DC Motors**        | Motors for driving the robot wheels                  | 2            | - |
| **Wheels (Compatible)**     | Wheels compatible with geared motors                 | 2            | -                                                                                 |
| **9V Battery + Battery Clip** | Power supply for motors and L298N driver             | 1            | -                                                                                 |
| **Jumper Wires (Male-Male)** | Wires for connecting components                      | 10-15        | -                                                                                 |
| **Jumper Wires (Male-Female)** | Wires for connecting sensor and servo motor          | 4-6          | -                                                                                 |


## Software Design
**TBD**
## Conclusion
**TBD**
## Results
**TBD**
## References/Resources
**TBD**

## License

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)


