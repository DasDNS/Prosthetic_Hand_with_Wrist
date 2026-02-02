# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [0.4.0] – 2026-02-02

### Added
- Implemented an **ESP32-based web-controlled differential drive** for two DC motors.
- **Asynchronous Web Server** using `ESPAsyncWebServer` running on port 80.
- **WebSocket (`/ws`) command handling** for real-time directional control.
- **LittleFS filesystem support** for serving the web UI and static assets.
- Directional toggle commands handled over WebSocket:
  - `toggleUp` (forward)
  - `toggleDown` (reverse)
  - `toggleLeft` (turn left)
  - `toggleRight` (turn right)

### Web Interface
- Web UI served from LittleFS:
  - `index.html` – directional control interface
  - Additional static assets served via `server.serveStatic("/", LittleFS, "/")`
- Template variable support via `processor()` to render button states (`ON` / `OFF`).

### Motor Control
- Two DC motors controlled using H-bridge style direction pins and enable pins:
  - Motor A: `enA` (GPIO 14), `in1` (GPIO 26), `in2` (GPIO 25)
  - Motor B: `enB` (GPIO 27), `in3` (GPIO 33), `in4` (GPIO 32)
- Movement logic:
  - Forward: both motors forward
  - Reverse: both motors reverse
  - Left: motor A reverse, motor B forward
  - Right: motor A forward, motor B reverse
  - Stop: PWM disabled on both motors
- Speed control uses `analogWrite()` with full enable (255) and stop (0).

### Networking
- Wi-Fi connection using predefined SSID and password.
- Serial logging for Wi-Fi connection progress and assigned IP address.
- WebSocket client connect/disconnect logging.

### Notes
- Designed for **ESP32 (Arduino framework)** with a dual DC motor driver (e.g., L298N / similar).
- Control logic prioritizes commands in order: up → down → left → right → stop.
- WebSocket broadcast currently sends each state as a separate text message.

---

## [Unreleased]

### Planned
- Send a single structured WebSocket message containing all states (instead of four separate messages).
- Add mutually exclusive direction handling (auto-disable other toggles when one is enabled).
- Add PWM speed control for variable motor speed.
- Add safety timeout / auto-stop on disconnect.
- Add authentication and configurable Wi-Fi setup.
