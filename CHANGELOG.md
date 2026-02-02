# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [0.2.0] – 2026-02-02

### Added
- Initial implementation of a **web-controlled differential drive system** for two DC motors using an ESP32.
- **Asynchronous Web Server** using `ESPAsyncWebServer` running on port 80.
- **WebSocket (`/ws`) control channel** for real-time directional commands.
- **LittleFS filesystem support** for serving static web UI files.
- Four directional control states with toggle commands:
  - `toggleUp` (forward)
  - `toggleDown` (reverse)
  - `toggleLeft` (turn left)
  - `toggleRight` (turn right)

### Web Interface
- Web UI served from LittleFS:
  - `index.html` – directional control interface
  - Additional static assets served via `server.serveStatic("/", LittleFS, "/")`
- Template variable processing via `processor()` to display button states (`ON` / `OFF`).

### Motor Control
- Two DC motors controlled via H-bridge style pins:
  - Motor A: `enA` (GPIO 14), `in1` (GPIO 26), `in2` (GPIO 25)
  - Motor B: `enB` (GPIO 27), `in3` (GPIO 33), `in4` (GPIO 32)
- Directional behaviors implemented:
  - Forward: both motors forward
  - Reverse: both motors reverse
  - Left: motor A reverse, motor B forward
  - Right: motor A forward, motor B reverse
- Speed control using `analogWrite()` with full-scale enable (255) and stop (0).

### Networking
- Wi-Fi connection using hardcoded SSID and password.
- Serial output for Wi-Fi connection progress and assigned IP address.
- WebSocket connect/disconnect logging over Serial.

### Notes
- Designed for **ESP32 (Arduino framework)** and a dual DC motor driver (e.g., L298N / similar).
- Control logic prioritizes commands in order: up → down → left → right → stop.
- WebSocket broadcast sends each state as a separate text message.

---

## [Unreleased]

### Planned
- Send a single structured WebSocket message containing all states (instead of four separate messages).
- Add mutually exclusive direction handling (auto-disable other toggles when one is enabled).
- Add PWM speed control for variable motor speed.
- Add safety timeout / auto-stop if the client disconnects.
- Add authentication and Wi-Fi configuration options.
