
# Ignition Coil Tester (Coil On Plug)

A simple tester for ignition coils using an Arduino. This project allows you to control the dwell time and RPM using buttons.

## Configuration

| Pin  | Function |
|------|------------|
| D8   | Signal output |
| D9   | Dwell time change button |
| D10  | RPM change button |

## Required Components

- **Resistors:**
  - 10kΩ pull-down resistors (2 pcs: between coil signal & GND, between MOSFET source & gate)
  - 1kΩ resistor between Arduino and transistor
- **Transistors:**
  - NPN power transistor (e.g., BD139 used in this case)
  - P-channel MOSFET (e.g., IRFR5305)
- **Other Components:**
  - Rectifier diode
  - 12-14V power supply
  - DC-DC buck converter (e.g., LM2596 or similar)
![Screenshot 2025-03-12 at 22 40 08](https://github.com/user-attachments/assets/4ca2fedf-8698-445b-9eb6-0b41740cfd73)


## Features

- Adjustable **dwell time** (controlled via button)
- Adjustable **RPM** (controlled via button)
![IMG_7003](https://github.com/user-attachments/assets/996e71ed-60d5-489a-bed8-fb81ea444ebf)

## Additional Notes

To control the level of the control signal, the key is powered by an **LM2596**. If the control signal is **0-12V**, then a converter may not be necessary.

---

### How It Works
- The Arduino outputs a control signal to drive the ignition coil.
- A MOSFET and transistor are used to handle the switching.
- The dwell time and RPM can be adjusted using buttons.
- The buck converter ensures stable power delivery if needed.

### Usage
1. Connect the components as described in the configuration.
2. Power the system with 12-14V.
3. Adjust dwell time and RPM using the buttons.
4. Observe the ignition coil operation.

## License
This project is open-source. Feel free to modify and improve it!
