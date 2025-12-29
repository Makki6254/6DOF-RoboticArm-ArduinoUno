# 6 DOF Robotic Arm Control (Arduino Uno + PCA9685)

This project provides code to control a 6-axis robotic arm using two analog joysticks and an Arduino Uno. It utilizes the PCA9685 PWM driver to handle high-torque servos (MG996R/MG946R) while maintaining smooth, incremental movement.

## 🛠 Hardware Used
* **Microcontroller:** Arduino Uno
* **Servo Driver:** PCA9685 16-Channel 12-bit PWM Driver
* **Servos:** 5x MG 996R, 1x MG 946R
* **Input:** 2x Analog Joysticks
* **Switch:** 1x Rotary Encoder Button (used for mode switching)
* **Power:** External 5V 5A DC Power Supply (Mandatory)

## ⚡ Features
* **Mode Switching:** Use a single button to toggle Joystick 1 between controlling the "Base/Shoulder" and the "Wrist/Gripper."
* **Incremental Movement:** The arm stays in position when you release the joystick.
* **Speed Control:** Adjustable movement increments (currently set to 0.5).
* **Self-Calibration:** Automatically reads joystick center positions at startup.

## 🔌 Wiring Diagram

| Component | Pin Type | Arduino Pin |
| :--- | :--- | :--- |
| **PCA9685 SDA** | I2C | A4 |
| **PCA9685 SCL** | I2C | A5 |
| **Joystick 1 VRx** | Analog | A0 |
| **Joystick 1 VRy** | Analog | A1 |
| **Joystick 2 VRx** | Analog | A2 |
| **Joystick 2 VRy** | Analog | A3 |
| **Encoder Button** | Digital | D2 |

## 🚀 Installation
1. Install the **Adafruit PWM Servo Driver Library** via the Arduino Library Manager.
2. Upload the code found in `6DOF.ino`.
3. Power the PCA9685 terminal block with a high-current 5V supply.
