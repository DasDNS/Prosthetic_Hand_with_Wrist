# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [0.5.0] – 2026-02-02

### Added
- Maintained an **ESP32-based web-controlled multi-servo system** using an asynchronous web server and WebSocket input.
- **LittleFS static file hosting** for the web interface (`index.html` and related assets).
- **JSON slider state builder** via `Arduino_JSON` (`getSliderValues()`).

### Changed
- WebSocket flow remains **receive-only** (ESP32 processes incoming slider messages without broadcasting state back to clients):
  - `notifyClients()` and `"getValues"` response are intentionally disabled (commented out).
- Wi-Fi credentials configured for the current network.
- Slider parsing supports **six channels** using message prefixes (`1s`..`6s`) with direct **0–180°** value handling.

### Servo & PWM Control
- PWM output uses **ESP32 LEDC** with:
  - Frequency: **50 Hz**
  - Resolution: **16-bit**
- Controls **five individual servo outputs**:
  - GPIO 16
  - GPIO 17
  - GPIO 18
  - GPIO 19
  - GPIO 21
- Sixth slider applies a **synchronized override** to move all servos together while non-zero.
- Duty cycle conversion implemented for standard hobby servo pulse widths.

### Networking
- Wi-Fi station mode (`WIFI_STA`) with Serial output for connection progress and assigned IP.
- WebSocket client connect/disconnect logs over Serial.

### Notes
- Blocking `while (dutyCycle6 != 0)` behavior is retained and can stall other updates; consider refactoring to non-blocking logic in a future release.

---

## [Unreleased]

### Planned
- Replace blocking synchronized-servo loop with a non-blocking approach.
- Optionally re-enable WebSocket state broadcasts (single JSON payload) for UI synchronization.
- Add servo calibration, per-channel limits, and input validation.
- Externalize Wi-Fi credentials (config file / captive portal) and add basic authentication.
