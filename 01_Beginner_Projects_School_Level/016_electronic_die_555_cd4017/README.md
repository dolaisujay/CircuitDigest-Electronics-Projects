# Project 016: Electronic Die Circuit Using 555 Timer and CD4017

## 📌 Difficulty Tier & Category
* **Tier**: Beginner (School Level)
* **Category**: Digital Electronics
* **Source Reference**: CircuitDigest Electronics Projects Collection

---

## 🛠️ Bill of Materials (Components List)

| Component Name | Quantity | Circuit Function |
| :--- | :---: | :--- |
| Core IC / Transistor | 1 | Main active switching element |
| Sensor Probe / Diodes | 2 | Signal sensing and rectification |
| Biasing Resistors | 4 | Current limiters and voltage dividers |
| Timing Capacitors | 2 | Oscillation and noise filtering |
| Output Load (LED / Speaker) | 1 | Visual or acoustic output |
| DC Power Source | 1 | 5V to 12V DC input |

---

## 🔬 Methodology & System Architecture
The Electronic Die Circuit Using 555 Timer and CD4017 is designed using discrete components and active silicon ICs. Input signals pass through conditioning networks to switch output loads cleanly and reliably.

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
V_{\text{out}} = f(V_{\text{in}}, R, C)
$$
$$
P = I \cdot V
$$

---

## 🚀 Practical Applications & Engineering Utility
* School science fairs, electronics laboratory exercises, home automation, and basic digital electronics.

---

## 📄 Formal LaTeX Technical Report
The full academic project report is available in two formats within this directory:
* **LaTeX Source**: [`project_report.tex`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/016_electronic_die_555_cd4017/project_report.tex)
* **Compiled PDF Report**: [`project_report.pdf`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/016_electronic_die_555_cd4017/project_report.pdf)


---

## 💻 Source Code & Firmware Implementation
The source code for this project is available in the [`src/`](src/simulate_circuit.py) directory:
* **Firmware / Script**: [`simulate_circuit.py`](src/simulate_circuit.py)
