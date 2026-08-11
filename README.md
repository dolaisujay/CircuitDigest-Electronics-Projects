# Electronics Projects Collection - CircuitDigest Implementations

Welcome to the **Electronics Projects Collection**. This repository contains complete project-level documentation, components lists, methodologies, assembly steps, circuit theory, working principles, and formal LaTeX engineering project reports (`.tex` and compiled `.pdf`) for six classic electronic circuit designs sourced from CircuitDigest.

---

## 📁 Repository Structure & Projects Directory

```
Bigyanlabs Projects/
├── 01_led_chaser_555_cd4017/
│   ├── README.md
│   └── report/
│       ├── report.tex
│       └── report.pdf
├── 02_reverse_polarity_protection_mosfet/
│   ├── README.md
│   └── report/
│       ├── report.tex
│       └── report.pdf
├── 03_simple_joule_thief_circuit/
│   ├── README.md
│   └── report/
│       ├── report.tex
│       └── report.pdf
├── 04_wireless_audio_transfer_laser/
│   ├── README.md
│   └── report/
│       ├── report.tex
│       └── report.pdf
├── 05_led_on_off_555_bc557/
│   ├── README.md
│   └── report/
│       ├── report.tex
│       └── report.pdf
├── 06_simple_boost_converter_555/
│   ├── README.md
│   └── report/
│       ├── report.tex
│       └── report.pdf
└── README.md (Master Index)
```

---

## 🚀 Projects Index & Technical Reports

### 1. [LED Chaser Circuit with 555 Timer IC and CD4017](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/01_led_chaser_555_cd4017/README.md)
* **Directory**: [`01_led_chaser_555_cd4017`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/01_led_chaser_555_cd4017/README.md)
* **Project Documentation**: [README.md](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/01_led_chaser_555_cd4017/README.md)
* **Formal Project Report**: [LaTeX Source (`report.tex`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/01_led_chaser_555_cd4017/report/report.tex) | [Compiled PDF (`report.pdf`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/01_led_chaser_555_cd4017/report/report.pdf)
* **Summary**: Configures an NE555 timer as an astable multivibrator generating square wave clock pulses to drive a CD4017 decade counter, sequentially lighting 10 LEDs in a running / chasing light pattern. Features speed control via a 50 kΩ potentiometer.

---

### 2. [Reverse Polarity Protection Circuit Using P-Channel MOSFET](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/02_reverse_polarity_protection_mosfet/README.md)
* **Directory**: [`02_reverse_polarity_protection_mosfet`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/02_reverse_polarity_protection_mosfet/README.md)
* **Project Documentation**: [README.md](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/02_reverse_polarity_protection_mosfet/README.md)
* **Formal Project Report**: [LaTeX Source (`report.tex`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/02_reverse_polarity_protection_mosfet/report/report.tex) | [Compiled PDF (`report.pdf`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/02_reverse_polarity_protection_mosfet/report/report.pdf)
* **Summary**: Replaces inefficient series protection diodes with a P-channel MOSFET to eliminate voltage drop ($< 0.05\text{V}$) and thermal loss ($< 0.4\%$). Automatically disconnects power when DC polarity is reversed while offering near-zero loss under normal operation. Includes gate Zener clamping for $V_{in} > 15\text{V}$.

---

### 3. [Simple Joule Thief Circuit - Low Power Voltage Booster](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/03_simple_joule_thief_circuit/README.md)
* **Directory**: [`03_simple_joule_thief_circuit`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/03_simple_joule_thief_circuit/README.md)
* **Project Documentation**: [README.md](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/03_simple_joule_thief_circuit/README.md)
* **Formal Project Report**: [LaTeX Source (`report.tex`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/03_simple_joule_thief_circuit/report/report.tex) | [Compiled PDF (`report.pdf`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/03_simple_joule_thief_circuit/report/report.pdf)
* **Summary**: A self-oscillating inductive flyback boost converter that extracts residual energy from "dead" $1.5\text{V}$ batteries (drained down to $0.8\text{V}$). Uses mutual inductance feedback between primary and secondary toroid windings to generate high-frequency $3\text{V}-15\text{V}$ voltage spikes to power an LED.

---

### 4. [Wireless Audio Transfer Using LASER Light (Li-Fi System)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/04_wireless_audio_transfer_laser/README.md)
* **Directory**: [`04_wireless_audio_transfer_laser`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/04_wireless_audio_transfer_laser/README.md)
* **Project Documentation**: [README.md](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/04_wireless_audio_transfer_laser/README.md)
* **Formal Project Report**: [LaTeX Source (`report.tex`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/04_wireless_audio_transfer_laser/report/report.tex) | [Compiled PDF (`report.pdf`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/04_wireless_audio_transfer_laser/report/report.pdf)
* **Summary**: Implements Visible Light Communication (VLC / Li-Fi) to transmit live audio over a focused laser beam. Voice captured by an electret microphone modulates the current of a 650nm laser diode; a solar panel detects the light intensity fluctuations, converting them back into audio played through a 10W speaker. Tested over $50\text{m}$ indoors and $> 100\text{m}$ outdoors.

---

### 5. [LED ON and OFF / Fading Dimmer Circuit Using 555 & BC557](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/05_led_on_off_555_bc557/README.md)
* **Directory**: [`05_led_on_off_555_bc557`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/05_led_on_off_555_bc557/README.md)
* **Project Documentation**: [README.md](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/05_led_on_off_555_bc557/README.md)
* **Formal Project Report**: [LaTeX Source (`report.tex`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/05_led_on_off_555_bc557/report/report.tex) | [Compiled PDF (`report.pdf`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/05_led_on_off_555_bc557/report/report.pdf)
* **Summary**: Uses an NE555 astable oscillator to drive a BC557 PNP bipolar junction transistor configured as a high-side power switch. Incorporates an RC network at the base node to create smooth fading, dimming, and pulsing effects across an array of LEDs.

---

### 6. [Simple DC-DC Boost Converter Circuit Using 555 Timer IC](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/06_simple_boost_converter_555/README.md)
* **Directory**: [`06_simple_boost_converter_555`](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/06_simple_boost_converter_555/README.md)
* **Project Documentation**: [README.md](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/06_simple_boost_converter_555/README.md)
* **Formal Project Report**: [LaTeX Source (`report.tex`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/06_simple_boost_converter_555/report/report.tex) | [Compiled PDF (`report.pdf`)](file:///c:/Users/Sujay/Desktop/Bigyanlabs%20Projects/06_simple_boost_converter_555/report/report.pdf)
* **Summary**: A switch-mode power supply (SMPS) step-up converter. The 555 IC generates a high-frequency PWM signal to switch an IRFZ44N MOSFET. Energy stored in a $100\mu\text{H}$ inductor during MOSFET ON phase is discharged through a Schottky diode during OFF phase, stepping up $3.4\text{V}-3.7\text{V}$ input from a Li-ion cell to $7.5\text{V}-12\text{V}$ output with up to 30W capability.
