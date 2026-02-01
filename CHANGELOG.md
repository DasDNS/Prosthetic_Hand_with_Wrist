# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project aims to follow **Semantic Versioning**.

---

## [0.1.0] - 2026-02-01

### Added
- Initial implementation of **wrist differential drive** using **two DC motors** (Motor A + Motor B).
- **Joystick-based control**:
  - Y-axis controls forward/backward motion with a dead zone.
  - X-axis controls left/right turning by applying a speed difference between the two motors.
- Motor speed mapping from joystick analog range to PWM range (**0–255**) using `map()`.
- Motor driver interface using six pins:
  - Direction pins: `IN1`, `IN2`, `IN3`, `IN4`
  - Speed pins (PWM): `ENA`, `ENB`

### Hardware
- Designed for use with:
  - **ESP32-WROOM-32** (Arduino framework)
  - **L298N** dual H-bridge motor driver
  - 2 × DC motors (wrist differential drive)
  - Analog joystick module (VRx/VRy)

### Notes
- Finger control servos (5 individual + 1 group servo) are described in comments but **not yet implemented** in this code.
- A joystick center “dead zone” is used (approximately **470–550**) to reduce jitter.

---

## [Unreleased]

### Planned
- Finger servo control:
  - 5 × finger servos controlled via 5 potentiometers.
  - 1 × “all fingers” servo controlled via a potentiometer.
- Add configurable constants for joystick dead zone and PWM limits.
- Add safety limits (ramping / soft-start) to reduce current spikes.
- Add documentation for wiring and recommended power supply setup.
