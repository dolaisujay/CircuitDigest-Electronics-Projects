# Project 049: Instrumentation Amplifier Circuit Using 3 Op-Amps

## 📌 Difficulty Tier & Category
* **Tier**: Intermediate (College Level)
* **Category**: Sensor Signal Conditioning
* **Source Reference**: CircuitDigest Electronics Projects Collection

---

## 🛠️ Bill of Materials (Components List)

| Component Name | Quantity | Circuit Function |
| :--- | :---: | :--- |
| Microcontroller / Op-Amp | 1 | Arduino UNO / ESP8266 / ESP32 / LM358 |
| Transducers / Sensors | 2 | Interface sensor modules |
| LCD / OLED Display | 1 | Visual data display (16x2 / I2C) |
| Relays / Driver MOSFETs | 2 | Actuator control interface |
| Passives and Connectors | 1 Set | Resistors, capacitors, breadboard / PCB |
| Power Module | 1 | 5V / 12V regulated DC source |

---

## 🔬 Methodology & System Architecture
The Instrumentation Amplifier Circuit Using 3 Op-Amps integrates hardware sensors and microcontrollers/op-amps. Sensor signals are processed through custom firmware or analog conditioning stages and displayed locally or streamed over Wi-Fi/Bluetooth.

---

## ⚙️ Circuit Design & Assembly Steps
1. **Component Inspection**: Inspect all active silicon devices, ICs, passives, and breadboard/Perfboard trace paths.
2. **Power Rail Wiring**: Connect the main DC power rails (+VCC and GND) ensuring proper decoupling capacitors are placed near active IC VCC pins.
3. **Core Processing & Sensing Stage**: Assemble the primary sensor/oscillator/microcontroller stage according to standard schematic pinouts.
4. **Driver & Switching Output Stage**: Interface the output signal lines to switching transistors, gate drivers, or relay modules.
5. **Power On & Parameter Testing**: Apply input DC power, calibrate sensitivity potentiometers or software thresholds, and verify output waveforms with a multimeter/oscilloscope.

---

## 📐 Mathematical Formulation & Working Principle
$$
V_{\text{ADC}} = \frac{\text{ADC\_Value}}{1023} \cdot 5.0\,\text{V}
$$
$$
\text{Distance} = \frac{\text{Time} \times 0.0343\,\text{cm/s}}{2}
$$

---

## 🚀 Practical Applications & Engineering Utility
* Engineering laboratory projects, IoT sensor nodes, automated environmental monitoring, and embedded sensor signal conditioning.

---

## 📄 Formal LaTeX Technical Report
The full academic project report is available in two formats within this directory:
* **LaTeX Source**: [`project_report.tex`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/049_instrumentation_amplifier_3opamp/project_report.tex)
* **Compiled PDF Report**: [`project_report.pdf`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/049_instrumentation_amplifier_3opamp/project_report.pdf)


---

## 💻 Source Code & Firmware Implementation
The source code for this project is available in the [`src/`](src/simulate_circuit.py) directory:
* **Firmware / Script**: [`simulate_circuit.py`](src/simulate_circuit.py)
