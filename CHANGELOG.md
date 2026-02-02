# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [1.6.0] – 2026-02-02

### Added
- **WebSocket-controlled motor direction** toggles: Up, Down, Left, Right.
- **Web interface** with direction toggles for controlling motors, served from **LittleFS** (`index.html` + static assets).
- **PWM control** for 5 servos using the **Adafruit PWM Servo Driver** with **angle-to-pulse conversion**.
- **PWM control for two DC motors** with full direction control (forward, backward, left, right).

### Web Interface
- **Direction control** toggles for **forward**, **backward**, **left**, and **right** movements.
- WebSocket connection updates the motor state across all clients.

### Motor Control
- **PWM control** using **Adafruit PWM Servo Driver** for 5 servos (PCA9685).
- **Dual DC motor control** using motor driver pins and PWM control via ESP32 `digitalWrite` and `analogWrite`.

### Networking
- **Wi-Fi connection** with static credentials for network access.
- **WebSocket event logging** for client connections and motor state updates.

### Notes
- **Servo angle-to-pulse conversion** is based on the range of 0-180 degrees to the respective pulse width range.
- Future releases will focus on improving message validation and adding more advanced motor control features.

---

## [Unreleased]

### Planned
- Add **per-motor speed control** via PWM sliders.
- Improve **WebSocket message validation** and error handling.
- Add **motor limits and safety checks** for extreme motor angles.
