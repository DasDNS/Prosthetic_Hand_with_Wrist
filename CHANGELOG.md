# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [1.1.0] – 2026-02-02

### Added
- Re-implemented **WebSocket control** for real-time servo angle updates via **six sliders**.
- Integrated **ESP32 LEDC PWM control** for **five servo motors**:
  - Servo motor pins: GPIO 16, 17, 18, 19, 21.
- **Web interface** served from **LittleFS** (`index.html` + static assets).
- **Slider control range** updated to **0–180 degrees**.
- JSON string conversion and real-time slider updates via `getSliderValues()`.

### Changed
- **WebSocket flow** adjusted: Incoming slider updates now applied to servo control.
- Servo duty cycle now directly mapped from **0–180 degrees**.

### Web Interface
- Web UI served from LittleFS, with sliders to control PWM for each servo.

### Servo Control
- PWM configured using **ESP32 LEDC**:
  - Frequency: **50 Hz**
  - Resolution: **16-bit**
- Five servo motor channels:
  - GPIO 16, 17, 18, 19, 21.
- Sixth slider provides a synchronized override to control all servos at once.

### Networking
- Wi-Fi station mode (`WIFI_STA`) with Serial output for connection progress and local IP address.
- WebSocket client connect/disconnect logging over Serial.

### Notes
- The synchronized override uses a blocking `while (dutyCycle6 != 0)` loop, which can stall other updates. Future release will refactor this logic for non-blocking behavior.

---

## [Unreleased]

### Planned
- Replace blocking synchronized-servo loop with non-blocking logic.
- Send a single structured WebSocket message containing all states (instead of four separate messages).
- Add servo calibration limits and input validation.
- Externalize Wi-Fi configuration and add basic authentication.
