# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [0.7.0] – 2026-02-02

### Added
- Integrated **I2C-based servo control** using `Adafruit_PWMServoDriver` (PCA9685-compatible).
- Added `Wire` (I2C) initialization and PWM driver setup:
  - `board1.begin()`
  - `board1.setPWMFreq(60)`
- Added `angleToPulse()` helper to convert **0–180°** angles into PCA9685 pulse values.

### Changed
- Migrated servo output from ESP32 GPIO/LEDC PWM to an **external PWM servo driver board** (PCA9685).
- WebSocket slider handling now applies **direct integer angle values** (no additional mapping step).
- Servo initialization now sets channels 0–4 to a neutral minimum pulse at startup.

### Web Interface
- Continues serving the web UI from **LittleFS** (`index.html` and static assets via `serveStatic`).
- WebSocket (`/ws`) continues to receive **six slider channels** using prefixes `1s`..`6s`.
- JSON aggregation via `Arduino_JSON` retained for serial debugging output (`getSliderValues()`).

### Servo Control
- Controls **five servo channels** on the PWM driver:
  - Channels 0–4 mapped to slider values 1–5.
- Sixth slider provides a **synchronized override** to drive all five channels together while its value is > 0.
- PWM pulse mapping:
  - Angle 0° → pulse ~125
  - Angle 180° → pulse ~625

### Networking
- Wi-Fi station mode (`WIFI_STA`) with Serial output showing connection progress and IP address.
- WebSocket client connect/disconnect logging over Serial.

### Notes
- The synchronized override uses a blocking `while (dutyCycle6 > 0)` loop, which can prevent other updates; consider refactoring to non-blocking logic in a future release.
- Designed for ESP32 + **PCA9685 servo driver** (or compatible board) connected over I2C.

---

## [Unreleased]

### Planned
- Refactor synchronized-servo override to be non-blocking.
- Add per-servo calibration limits (min/max pulses) and inversion options.
- Add WebSocket message validation and optional UI state broadcasting.
- Move Wi-Fi credentials into a config file or captive portal setup.
