# 🚗 Smartphone-Controlled Bluetooth RC Car

![Project Status](https://img.shields.io/badge/Status-Completed-success)
![Platform](https://img.shields.io/badge/Platform-Arduino-blue)
![Language](https://img.shields.io/badge/Language-C%2B%2B-orange)

## 📖 Overview
This project is a 4-Wheel Drive (4WD) robotic vehicle controlled wirelessly via an Android smartphone application. It utilizes the **HC-05 Bluetooth Module** to receive serial commands and the **L298N Motor Driver** to execute high-torque movements. 

The system shifts from autonomous logic to a manual **Command-Response model**, allowing real-time control for Forward, Backward, and Spin-Turn maneuvers.

## 🎥 Project Demo
Click the link below to watch the video demonstration of the project in action:
> 🎬 **[Watch the Video Demonstration]((https://youtu.be/79BT1Ii-yuY?si=E-drzVtk6_IyqZPk))**

## 🛠️ Hardware Components
| Component | Specification | Quantity |
|-----------|--------------|----------|
| **Microcontroller** | Arduino Uno R3 | 1 |
| **Communication** | HC-05 / HC-06 Bluetooth Module | 1 |
| **Motor Driver** | L298N Dual H-Bridge | 1 |
| **Motors** | TT Gear Motors (Yellow) | 4 |
| **Power** | 2x 18650 Li-ion Batteries (7.4V) | 1 |
| **Chassis** | 4WD Acrylic Chassis Kit | 1 |

## 🔌 Wiring Configuration
The system uses Serial Communication (UART) for control and PWM for speed regulation.

| L298N Pin | Arduino Pin | Description |
| :--- | :--- | :--- |
| **ENA** | Pin 3 | Speed Control (Left) |
| **IN1** | Pin 5 | Left Forward |
| **IN2** | Pin 6 | Left Backward |
| **IN3** | Pin 9 | Right Forward |
| **IN4** | Pin 10 | Right Backward |
| **ENB** | Pin 11 | Speed Control (Right) |

*(Note: Bluetooth TX connects to Arduino RX, and RX connects to TX. **Unplug Bluetooth while uploading code!**)*

## 💻 Software Logic
The robot listens for incoming ASCII characters via the Serial Port:
* **'F'** -> Forward
* **'B'** -> Backward
* **'L'** -> Spin Left (Zero Radius Turn)
* **'R'** -> Spin Right (Zero Radius Turn)
* **'S'** -> Stop
* **'0'-'9'** -> Adjust Speed (PWM 0-255)

## 🚀 How to Run
1. **Upload:** Connect Arduino via USB (Ensure Bluetooth is unplugged). Upload `src/Bluetooth_RC_Car_Code.ino`.
2. **Wiring:** Connect the Bluetooth module and Battery.
3. **App:** Download "Arduino Bluetooth RC Car" from Play Store.
4. **Connect:** Pair with `HC-05` (Pin: 1234) and connect in the app.
5. **Drive:** Use the controller interface to drive the bot.

## 👥 Developers
* **Zohaib Hassan** - *System Integration & Coding*
* **Zuhaib Khan** - *Hardware Assembly & Circuit Design*

---
*University Semester Project - Fall 2025*
