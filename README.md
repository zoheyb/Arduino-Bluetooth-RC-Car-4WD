# 🏎️ Android-Controlled 4WD Rover (Embedded C++)

![Build Status](https://img.shields.io/badge/Build-Stable-success)
![Hardware](https://img.shields.io/badge/Hardware-Arduino%20Uno%20%7C%20L298N-blue)
![Communication](https://img.shields.io/badge/Protocol-UART%20%2F%20Bluetooth-yellow)
![License](https://img.shields.io/badge/License-MIT-green)

## ⚡ Technical Abstract
This project implements a **wireless differential-drive robotic system** controlled via Bluetooth (HC-05). Unlike standard autonomous obstacle-avoiding robots, this iteration focuses on **low-latency teleoperation** using the UART serial protocol. 

The firmware is written in **Embedded C++**, utilizing direct PWM manipulation for precise motor speed control and an H-Bridge architecture for bi-directional torque distribution.

## 🌟 Key Features
* **Zero-Turn Radius:** Implements differential steering logic (counter-rotating wheels) for agility in tight environments.
* **Variable Speed Control:** Dynamic PWM mapping (0-255) allowing real-time throttle adjustment from the controller.
* **Fail-Safe Architecture:** Default state-machine logic ensures the rover halts immediately upon signal loss or invalid command packets.
* **Modular Design:** The `turnLeft()` and `turnRight()` functions are decoupled from the main loop for easy integration of future sensors (Gyros/Ultrasonic).

## 🧠 System Architecture (Logic Flow)
This diagram represents the decision-making process inside the microcontroller:

```mermaid
graph LR
    A[Smartphone App] -- Bluetooth (UART) --> B(HC-05 Receiver)
    B -- Serial Data --> C{Arduino UNO}
    C -- PWM Signals --> D[L298N Driver]
    D -- High Current --> E((4x DC Motors))
    
    subgraph Decision Logic
    C -->|'F'| Forward
    C -->|'L'| Differential Spin
    C -->|'0-9'| Adjust Duty Cycle
    end
