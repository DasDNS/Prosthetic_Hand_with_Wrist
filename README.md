# Prosthetic Hand (ESP32 + Arduino Platform)

## 📌 Project Description

This repository documents a **3D‑printed prosthetic hand built using PLA material**, developed as a hobby and learning project in embedded systems and robotics.

The prosthetic hand is controlled using:
- **Five servo motors** for individual finger movement  
- **Two DC motors** for wrist motion  
- **ESP32‑WROOM‑32** as the main microcontroller  
- **Arduino platform** for firmware development  

This project focuses on understanding **motor control, embedded firmware design, and hardware integration** using low‑cost, easily available components.

---

## 🦾 Key Features

- Independent control of **five fingers**
- Wrist movement using **dual DC motors**
- Modular motor control using driver boards
- ESP32‑based control (Wi‑Fi & Bluetooth capable)
- Open‑source, educational, and hobby‑friendly

---

## 🧠 System Overview

| Component | Description |
|---------|------------|
| Microcontroller | ESP32‑WROOM‑32 |
| Platform | Arduino |
| Finger Actuation | 5 × MG90S metal‑gear servo motors |
| Wrist Actuation | 2 × DC gear motors |
| Servo Driver | PCA9685 (16‑channel I2C PWM) |
| DC Motor Driver | L298N dual H‑bridge |
| Mechanical Structure | 3D‑printed PLA prosthetic hand |

---

## 🔩 Hardware Components

### 🧠 Microcontroller
**ESP32‑WROOM‑32**
- Dual‑core MCU
- Integrated Wi‑Fi and Bluetooth
- Handles motor control and logic

---

### 🎛 Servo Driver
**PCA9685**
- 16‑channel, 12‑bit PWM controller
- Communicates via I2C
- Used to drive all servo motors reliably

---

### 🦾 Servo Motors (Fingers)
**MG90S Metal Gear Servo Motors**
- High torque
- Durable metal gears
- One servo per finger (5 total)

Product link:  
https://tronic.lk/product/servo-motor-metal-wheel-mg90-full-set

---

### ⚙️ DC Motors (Wrist)
DC gear motors (no wheel)  
Used for wrist rotation and movement

Product link:  
https://tronic.lk/product/gear-motor-no-wheel

---

### 🔌 DC Motor Driver
**L298N Dual H‑Bridge Motor Driver**
- Controls two DC motors
- Supports direction and speed control via PWM

Product link:  
https://tronic.lk/product/l298n-motor-driver-module-for-arduino-normal

---

## 🔌 Control Architecture

- The **PCA9685** generates PWM signals for all servo motors
- The **ESP32** communicates with the PCA9685 over I2C
- The **L298N** controls wrist DC motors using GPIO and PWM
- Motor power is supplied separately from logic where required

---

## 🚀 Getting Started

1. Install **Arduino IDE**
2. Add **ESP32 board support**
3. Install required libraries:
   - Adafruit PCA9685 PWM Servo Driver
4. Connect hardware according to wiring diagrams
5. Upload firmware to ESP32
6. Test finger and wrist movement

---

## ⚠️ Notes & Limitations

- This is an **experimental and educational project**
- Not intended for medical or clinical use
- Mechanical calibration is required
- Ensure adequate power supply for motors

---

## 🔮 Future Improvements

- EMG or sensor‑based control
- Wireless control via Bluetooth or Wi‑Fi
- Force or position feedback
- Battery‑powered operation
- Improved mechanical design

---

## 📜 License

Released under the **MIT License**.

---
