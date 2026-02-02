# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [0.6.0] – 2026-02-02

### Added
- Web-controlled **two-DC-motor differential drive** sketch for ESP32.
- **Asynchronous Web Server** using `ESPAsyncWebServer` on port 80.
- **WebSocket (`/ws`) command handling** to toggle directional states in real time.
- **LittleFS filesystem support** to serve the web UI and static assets.

### Web Interface
- Web UI served from LittleFS:
  - `index.html` – directional control interface
  - Static assets served via `server.serveStatic("/", LittleFS, "/")`
- Template variable rendering via `processor()` to show state labels (`ON` / `OFF`) for:
  - Up / Down / Left / Right

### Motor Control
- Dual motor control using enable + direction pins (H-bridge style):
  - Motor A: `enA` (GPIO 14), `in1` (GPIO 26), `in2` (GPIO 25)
  - Motor B: `enB` (GPIO 27), `in3` (GPIO 33), `in4` (GPIO 32)
- Direction behaviors:
  - Forward (`toggleUp`)
  - Reverse (`toggleDown`)
  - Turn Left (`toggleLeft`)
  - Turn Right (`toggleRight`)
  - Stop (no state active)
- Speed control via `analogWrite()`:
  - Full speed: 255
  - Stop: 0

### Networking
- Wi-Fi connection using predefined SSID and password.
- Serial output for Wi-Fi connection progress and local IP address.
- WebSocket connect/disconnect logging over Serial.

### Notes
- Designed for **ESP32 (Arduino framework)** with a dual DC motor driver (e.g., L298N / similar).
- WebSocket broadcast currently sends each state as a separate text message.
- Direction priority in the main loop: up → down → left → right → stop.

---

## [Unreleased]

### Planned
- Send a single structured WebSocket message containing all states (instead of four separate messages).
- Make direction states mutually exclusive (auto-disable other toggles when one is enabled).
- Add variable speed control (PWM slider).
- Add safety timeout / auto-stop when the client disconnects.
- Add authentication and configurable Wi-Fi setup.
