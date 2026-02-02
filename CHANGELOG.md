# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [0.1.0] – 2026-02-01

### Added
- Initial implementation of an **ESP32-based web-controlled servo system**.
- **Asynchronous Web Server** using `ESPAsyncWebServer` running on port 80.
- **WebSocket (`/ws`) communication** for real-time bidirectional control.
- **LittleFS filesystem support** for serving static web content.
- **JSON-based messaging** using `Arduino_JSON` to synchronize slider values across clients.

### Web Interface
- Web UI served from LittleFS:
  - `index.html` – browser-based control interface
  - `style.css` – UI styling
  - `script.js` – WebSocket client logic
- **Six independent sliders** for real-time actuator control.
- Automatic synchronization of slider states for newly connected WebSocket clients.

### Servo & PWM Control
- Servo motor control using **ESP32 LEDC hardware PWM**.
- PWM configuration:
  - Frequency: **50 Hz**
  - Resolution: **16-bit**
- Slider values mapped from **0–100 → 0–180 degrees**.
- Duty cycle conversion implemented for standard hobby servos.
- Support for **five individual servo outputs**:
  - GPIO 16
  - GPIO 17
  - GPIO 18
  - GPIO 19
  - GPIO 21
- Sixth slider enables **simultaneous movement of all servos**.

### Networking
- Wi-Fi station mode (`WIFI_STA`) with predefined SSID and password.
- Serial output for:
  - Wi-Fi connection status
  - Assigned IP address
  - Incoming slider values and mapped angles

### WebSocket Features
- Real-time slider updates without page refresh.
- Broadcast of slider states to all connected clients.
- Support for `"getValues"` command to sync UI state on client connect.

### Notes
- Designed for **ESP32 (Arduino framework)**.
- Intended for **servo-based applications** such as robotic hands or wrist mechanisms.
- External power supply is recommended for driving multiple servos.
- Servo control logic assumes standard 0–180° hobby servos.

---

## [Unreleased]

### Planned
- Improve servo motion smoothing and timing control.
- Add configurable servo limits and calibration.
- Move Wi-Fi credentials to a configuration file or captive portal.
- Add authentication to the web interface.
- Improve WebSocket message validation and error handling.
- Refactor blocking `while` loop for slider 6 into a non-blocking control logic.
