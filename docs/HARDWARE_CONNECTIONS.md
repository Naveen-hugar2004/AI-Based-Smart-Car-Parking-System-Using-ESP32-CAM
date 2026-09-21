# Hardware Connections

> Pin assignments can vary with the exact ESP32-CAM board and LCD module. Verify your hardware before powering the circuit.

| Component | Example ESP32 Pin | Purpose |
|---|---:|---|
| Entry IR sensor | GPIO 14 | Detect vehicle at entrance |
| Slot 1 IR sensor | GPIO 2 | Detect slot occupancy |
| Slot 2 IR sensor | GPIO 4 | Detect slot occupancy |
| Servo signal | GPIO 13 | Open/close gate |
| ESP32-CAM camera | Built-in | Capture vehicle image |
| I2C LCD | I2C pins | Display parking status |

## Important
GPIO availability and boot behavior can differ on ESP32-CAM boards. Test the selected pins with your specific board before final hardware assembly.
