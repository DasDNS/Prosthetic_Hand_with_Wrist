# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [1.4.0] – 2026-02-02

### Added
- **WebSocket-controlled motor control** for directional control of motors (up, down, left, right).
- Added **Web interface** with direction control toggles (forward, backward, left, right) served from **LittleFS** (`index.html` and static assets).
- **WebSocket (`/ws`) message handling** for directional control (`toggleUp`, `toggleLeft`, `toggleRight`, `toggleDown`).

### Changed
- Introduced **mutually exclusive direction control** for the dual DC motors:
  - Up → Forward
  - Down → Backward
  - Left → Turn Left
  - Right → Turn Right
  - Stop → All motors off
- **Motor speed** is controlled by `analogWrite()` with a max value of 255 for full speed.

### Motor Control
- Motor control logic for **dual DC motors** using `enable` and `input` pins:
  - Motor A: `enA` (GPIO 14), `in1` (GPIO 26), `in2` (GPIO 25)
  - Motor B: `enB` (GPIO 27), `in3` (GPIO 33), `in4` (GPIO 32)
- Directional states updated from WebSocket messages:
  - Up → Forward
  - Down → Backward
  - Left → Turn Left
  - Right → Turn Right

### Web Interface
- Web interface allows toggling direction states of motors.
- Direction states are displayed in real time and updated on all connected clients using WebSocket.

### Networking
- **Wi-Fi connection** using static credentials for network access.
- WebSocket client connection logging, with disconnect handling.
- WebSocket broadcast messages sent to all clients when direction states change.

### Notes
- The motor direction control is currently blocking, preventing other state updates during movement; future releases will consider non-blocking updates.

---

## [Unreleased]

### Planned
- Add per-motor speed control (variable PWM sliders).
- Move Wi-Fi credentials to a configuration file or use a captive portal.
- Add per-direction limits (to prevent motor conflicts).
- Implement WebSocket message validation and improve error handling.
