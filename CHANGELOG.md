# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [0.3.0] – 2026-02-02

### Added
- Updated implementation of an **ESP32-based web-controlled multi-servo system**.
- **Asynchronous Web Server** using `ESPAsyncWebServer` on port 80.
- **WebSocket (`/ws`) input handling** for receiving real-time slider updates.
- **LittleFS filesystem support** for serving the web interface.
- **JSON-based slider value aggregation** using `Arduino_JSON`.

### Changed
- Slider input range updated to **0–180 degrees** for direct servo-angle control.
- WebSocket logic refactored to **receive-only mode** (client → ESP32).
- Wi-Fi credentials updated.
- Internal duty-cycle mapping adjusted to align with **servo angle input**.

### Servo & PWM Control
- Servo control implemented using **ESP32 LEDC hardware PWM**.
- PWM configuration:
  - Frequency: **50 Hz**
  - Resolution: **16-bit**
- Support for **five individual servo outputs**:
  - GPIO 16
  - GPIO 17
  - GPIO 18
  - GPIO 19
  - GPIO 21
- Sixth slider enables **simultaneous movement of all servos**.
- Duty cycle calculated for standard hobby servo pulse widths.

### Networking
- Wi-Fi station mode (`WIFI_STA`) with predefined SSID and password.
- Serial logging for Wi-Fi connection status and incoming slider data.
- WebSocket client connect/disconnect logging.

### Notes
- Designed for **ESP32 (Arduino framework)**.
- Intended for **robotic hand / wrist servo control** applications.
- External power supply is recommended when driving multiple servos.
- Blocking loop for slider 6 is retained and should be refactored.

---

## [Unreleased]

### Planned
- Replace blocking `while` loop with non-blocking servo control logic.
- Re-enable optional WebSocket state broadcasting.
- Add servo calibration and per-channel limits.
- Improve message validation and error handling.
- Externalize Wi-Fi configuration.
