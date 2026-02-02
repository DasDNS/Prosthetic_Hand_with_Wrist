# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [1.2.0] – 2026-02-02

### Added
- **PCA9685-based servo control** using **Adafruit PWM Servo Driver** library.
- **I2C servo control** with the PCA9685, supporting **five servos**.
- **WebSocket (`/ws`) slider control** via six slider channels for PWM control.
- **Angle-to-pulse conversion** via `angleToPulse()` to map 0–180° values to servo PWM pulse width.

### Web Interface
- **Web UI** served from **LittleFS** (`index.html` + static assets).
- **WebSocket control** with six channels:
  - Sliders for 5 servos, and one synchronized slider to move all servos together.

### PWM Control
- Servo control now utilizes **Adafruit PWM Servo Driver** (PCA9685) with I2C communication.
- **PWM frequency** set to 60Hz, with servo pulse width mapping for 0–180° range.
- Synchronized slider to control all servos together when dutyCycle6 is non-zero.

### Networking
- **Wi-Fi station mode** (`WIFI_STA`) with Serial output showing connection status and IP address.
- WebSocket logging for client connection and disconnection.

### Notes
- The synchronized override loop for all servos (dutyCycle6) uses a blocking `while (dutyCycle6 > 0)` loop, which should be refactored for non-blocking control in future releases.

---

## [Unreleased]

### Planned
- Refactor synchronized-servo loop to non-blocking logic.
- Add per-servo limits, calibration, and inversions.
- Improve message validation and error handling.
- Move Wi-Fi credentials to a configuration file or captive portal setup.
