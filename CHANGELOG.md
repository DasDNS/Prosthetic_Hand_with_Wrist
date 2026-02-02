# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [0.8.0] – 2026-02-02

### Added
- Re-enabled **WebSocket broadcasting** so all connected clients receive synchronized slider states.
- Implemented `"getValues"` WebSocket command to send the current slider JSON to newly connected or refreshed clients.

### Changed
- WebSocket flow updated from receive-only to **bidirectional sync** (ESP32 ↔ browser clients):
  - Incoming slider updates are applied and then broadcast to all clients via `notifyClients(getSliderValues())`.
- Maintained slider input handling for six channels using message prefixes (`1s`..`6s`) with direct **0–180°** angle mapping.

### Web Interface
- Web UI continues to be served from **LittleFS** (`index.html` plus static assets via `serveStatic`).
- JSON payload (`getSliderValues()`) used as the single source of truth for UI synchronization across clients.

### Servo & PWM Control
- Servo control uses **ESP32 LEDC hardware PWM** with:
  - Frequency: **50 Hz**
  - Resolution: **16-bit**
- Drives **five servo outputs**:
  - GPIO 16
  - GPIO 17
  - GPIO 18
  - GPIO 19
  - GPIO 21
- Sixth slider provides a synchronized override to move all servos together while non-zero.
- Duty-cycle conversion retained for standard hobby servo pulse widths.

### Networking
- Wi-Fi station mode (`WIFI_STA`) with Serial output for connection progress and assigned IP.
- WebSocket client connect/disconnect logging over Serial.

### Notes
- The synchronized override uses a blocking `while (dutyCycle6 != 0)` loop, which can stall other updates; refactor to non-blocking logic in a future release.

---

## [Unreleased]

### Planned
- Replace blocking synchronized-servo loop with non-blocking logic.
- Send explicit per-slider updates (or throttling) to reduce WebSocket traffic.
- Add servo calibration limits and input validation.
- Externalize Wi-Fi configuration and add basic authentication.
