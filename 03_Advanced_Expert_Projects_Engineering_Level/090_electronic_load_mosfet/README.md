# Project 090: Electronic Load Circuit for Power Supply Testing Using Power MOSFETs

## 📌 Difficulty Tier & Category
* **Tier**: Advanced / Expert (Engineering Level)
* **Category**: Bench Test Instrumentation
* **Source Reference**: CircuitDigest Electronics Projects Collection

---

## 🛠️ Bill of Materials (Components List)

| Component Name | Quantity | Circuit Function |
| :--- | :---: | :--- |
| Power Transistors / High-End MCU | 2 | Power MOSFETs / IGBTs / STM32 / ESP32 |
| High-Frequency Transformers | 1 | Ferro-magnetic energy storage core |
| Gate Drivers / Fast Diodes | 2 | IR2110 gate driver and Ultrafast diodes |
| Sensing Amplifiers / CT Sensors | 2 | Current sensors (ACS712/SCT-013) and Differential amps |
| Filter Capacitors (Low ESR) | 2 | Low ESR electrolytic and Polypropylene film caps |
| Auxiliary Power & Protection | 1 Set | Auxiliary SMPS, heatsinks, and snubber networks |

---

## 🔬 Methodology & System Architecture
The Electronic Load Circuit for Power Supply Testing Using Power MOSFETs is an advanced engineering implementation featuring high-frequency switching, closed-loop feedback algorithms, or high-speed DSP processing for maximum efficiency and precision.

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
V_{\text{out}} = \frac{V_{\text{in}}}{1 - D}
$$
$$
\eta = \frac{P_{\text{out}}}{P_{\text{in}}} \times 100\%
$$
$$
f_r = \frac{1}{2\pi \sqrt{L C}}
$$

---

## 🚀 Practical Applications & Engineering Utility
* Industrial automation, renewable energy systems, electric vehicle power trains, aerospace electronics, and high-performance bench test instrumentation.

---

## 📄 Formal LaTeX Technical Report
The full academic project report is available in two formats within this directory:
* **LaTeX Source**: [`project_report.tex`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/090_electronic_load_mosfet/project_report.tex)
* **Compiled PDF Report**: [`project_report.pdf`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/090_electronic_load_mosfet/project_report.pdf)
