# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

---

## [1.3.0] – 2026-02-02

### Added
- **WebSocket control for servo motors** with six sliders to control the angles of 5 servos.
- **LittleFS support** to serve the web interface (`index.html`) and other static assets.
- **PWM control** for five servos using **ESP32 LEDC**:
  - Servos connected to GPIO pins 16, 17, 18, 19, 21.
  - Frequency: 50Hz, Resolution: 16-bit.

### Changed
- **WebSocket communication** to handle six slider values for each of the servo motors.
- **Duty cycle calculations** are now converted from 0–180° to 0–65536 using the **LED PWM** mechanism.
- The synchronization of all motors through the **sixth slider** (dutyCycle6), which applies the same duty cycle to all servos.

### Web Interface
- The web interface allows real-time control of servos using sliders, with changes reflected instantly on the motor control.
- `getSliderValues()` sends JSON-formatted updates of the current slider values for all six channels.

### Motor Control
- Servo angle control for 5 servos is mapped from 0–180° to the appropriate PWM signal.
- When dutyCycle6 > 0, all servos are synchronized with the same angle.

### Networking
- Wi-Fi setup with static credentials (SSID and password) for connecting to the network.
- WebSocket communication is used for control messages between the web interface and the ESP32.

### Notes
- Future versions should consider non-blocking logic for the synchronized servo movement to allow real-time updates.
- WebSocket broadcasts send the state for each slider after any changes.

---

## [Unreleased]

### Planned
- Move Wi-Fi credentials to a configuration file or use a captive portal setup.
- Refactor synchronized-servo logic for non-blocking execution.
- Implement per-servo calibration for angular limits or fine-tuning.
- Add basic authentication for the web interface.
