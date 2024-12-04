# Obstacle-Avoiding-Robot

## Introduction
- What does it do?
  - The robot detects obstacles in its path and dynamically adjusts its direction to avoid collisions.

- What is its purpose?
  - The purpose of this project is to showcase how embedded systems can be used to build simple, autonomous robots while providing a hands-on learning experience in robotics, electronics, and programming.

- What inspired the idea?
  - The idea originated from the desire to create a cost-effective and efficient robot capable of navigating independently.

- Why is it useful?
  - This project serves as an excellent introduction to robotics concepts, such as sensor integration and motor control. It is easy to extend for more complex tasks like line following, mapping, or obstacle classification.

## General Description
<div style="background-color: #e8f5e9; padding: 10px; border: 1px solid #c8e6c9; border-radius: 5px;"> The obstacle-avoiding robot is designed to move autonomously in an environment filled with obstacles. It uses an HC-SR04 ultrasonic sensor to measure distances and determine when to avoid obstacles by turning left, right, or stopping.
The robot is powered by a motor driver module (L298N) that controls two DC motors connected to wheels, allowing movement.

A servo motor (SG90) is used to rotate the ultrasonic sensor, enabling the robot to scan its surroundings for obstacles in multiple directions. The entire system is controlled by an Arduino UNO, which processes data from the sensor and executes appropriate movement commands.

</div>

## Hardware Design
- Components: 
  - Arduino UNO board 
  - L298N motor driver 
  - HC-SR04 ultrasonic sensor 
  - SG90 servo motor 
  - Two DC motors with wheels 
  - Battery pack (4x AA with on/off switch) 
  - Jumper wires

## Software Design

## Conclusion

## Results

## References/Resources
