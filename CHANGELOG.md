# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [0.1.0] – 2026-02-01

### Added
- Initial implementation of an **ESP32-based web-controlled PWM system**.
- **Asynchronous Web Server** using `ESPAsyncWebServer` running on port 80.
- **WebSocket (`/ws`) support** for real-time communication between ESP32 and web client.
- **LittleFS filesystem support** for serving web files.
- **JSON-based messaging** using `Arduino_JSON` for slider value exchange.

### Web Interface
- `data/` folder containing:
  - `index.html` – web UI with sliders
  - `style.css` – UI styling
  - `script.js` – WebSocket client logic
- Three sliders to control PWM outputs in real time.
- Automatic synchronization of slider values for newly connected clients.

### PWM & GPIO Control
- PWM control using **ESP32 LEDC hardware timers**.
- Three independent PWM outputs:
  - GPIO 12
  - GPIO 13
  - GPIO 14
- PWM configuration:
  - Frequency: 5 kHz
  - Resolution: 8-bit
- Slider input mapped from **0–100% → 0–255 duty cycle**.

### Networking
- Wi-Fi station mode (`WIFI_STA`) with hardcoded SSID and password.
- Serial output showing connection status and IP address.

### Notes
- Designed for **ESP32-WROOM-32** using the Arduino framework.
- Suitable for controlling LEDs, motor drivers, or other PWM-based actuators.
- External power is required for non-LED loads.

---

## [Unreleased]

### Planned
- Move Wi-Fi credentials to configuration or captive portal.
- Add authentication for the web interface.
- Expand WebSocket protocol with command validation.
- Integrate motor drivers or servo controllers.
- Improve UI feedback and status indicators.

