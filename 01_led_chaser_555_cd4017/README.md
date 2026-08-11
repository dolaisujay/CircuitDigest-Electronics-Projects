# LED Chaser Circuit with 555 Timer IC and CD4017

> **Reference Tutorial**: [CircuitDigest - LED Chaser Circuit with 555 Timer IC and CD4017](https://circuitdigest.com/electronic-circuits/led-chaser-circuit-with-555-timer-ic-and-cd4017)

---

## 1. Project Overview

An **LED Chaser Circuit** (also known as a sequential LED flasher or running light) creates a visual effect where LEDs turn ON one after another in a repeating sequence, giving the impression that light is "chasing" along a line.

This project uses two fundamental ICs:
1. **NE555 Timer IC**: Configured as an **Astable Multivibrator** to generate continuous clock pulses (square wave signal).
2. **CD4017 Decade Counter IC**: Receives clock pulses and sequentially activates 10 output pins (Q0 to Q9) one by one.

Speed control is achieved using a **50 kΩ variable resistor (potentiometer)** that modifies the pulse frequency of the 555 timer.

---

## 2. Components List

| Component | Quantity | Value / Specification | Description & Function in Circuit |
| :--- | :---: | :--- | :--- |
| **Timer IC** | 1 | NE555 / LM555 | Clock pulse generator in Astable Multivibrator mode |
| **Counter IC** | 1 | CD4017 | CMOS 5-stage Johnson Decade Counter with 10 decoded outputs |
| **Fixed Resistor** | 1 | 1 kΩ (1/4W) | $R_1$ limiting resistor connected between $V_{CC}$ and Pin 7 of NE555 |
| **Variable Resistor** | 1 | 50 kΩ Potentiometer | $R_2$ speed adjustment resistor between Pin 7 and Pins 6/2 of NE555 |
| **Timing Capacitor** | 1 | 10 µF (25V) | $C_1$ electrolytic capacitor setting astable oscillation frequency |
| **Noise Capacitor** | 1 | 0.1 µF (104) / 0.01 µF | $C_2$ ceramic capacitor connected between Pin 5 of NE555 and GND |
| **LEDs** | 10 | 5mm Blue / Red / Green | Sequentially illuminated output indicators |
| **Power Supply** | 1 | 9V Battery / DC Source | System power supply (Operating range: 5V – 12V DC) |
| **Prototyping** | 1 | Breadboard & Jumper Wires | Interconnection hardware |

---

## 3. IC Pin Configurations

### 555 Timer IC Pinout
| Pin No. | Pin Name | Function | Connection in Circuit |
| :---: | :--- | :--- | :--- |
| **1** | GND | Ground reference | Connected to Power GND rail |
| **2** | Trigger | Initiates pulse cycle when $V < \frac{1}{3}V_{CC}$ | Tied to Pin 6 and top of $C_1$ |
| **3** | Output | Square wave clock output ($\le 200\text{mA}$) | Connected to CD4017 Pin 14 (Clock) |
| **4** | Reset | Active-LOW reset | Tied to $V_{CC}$ (Pin 8) to prevent reset |
| **5** | Control | Control voltage / noise filtering | Connected to GND via 0.1 µF capacitor |
| **6** | Threshold | Resets output LOW when $V > \frac{2}{3}V_{CC}$ | Tied to Pin 2 and top of $C_1$ |
| **7** | Discharge | Discharges timing capacitor $C_1$ | Connected between $R_1$ (1k) and $R_2$ (50k pot) |
| **8** | VCC | Positive supply input | Connected to +9V rail |

### CD4017 Decade Counter Pinout
| Pin No. | Pin Name | Function | Connection in Circuit |
| :---: | :--- | :--- | :--- |
| **3** | Q0 | 1st Sequential Output | Anode of LED 1 |
| **2** | Q1 | 2nd Sequential Output | Anode of LED 2 |
| **4** | Q2 | 3rd Sequential Output | Anode of LED 3 |
| **7** | Q3 | 4th Sequential Output | Anode of LED 4 |
| **10** | Q4 | 5th Sequential Output | Anode of LED 5 |
| **1** | Q5 | 6th Sequential Output | Anode of LED 6 |
| **5** | Q6 | 7th Sequential Output | Anode of LED 7 |
| **6** | Q7 | 8th Sequential Output | Anode of LED 8 |
| **9** | Q8 | 9th Sequential Output | Anode of LED 9 |
| **11** | Q9 | 10th Sequential Output | Anode of LED 10 |
| **8** | VSS (GND) | Ground pin | Connected to Power GND rail |
| **12** | Carry Out (CO) | Goes HIGH every 10 counts | Unconnected (used for cascading ICs) |
| **13** | Clock Enable (CE)| Active-HIGH inhibit pin | Tied to GND (enables continuous counting) |
| **14** | Clock Input (CLK) | Advances counter on rising edge | Connected to 555 Timer Pin 3 (Output) |
| **15** | Reset (RST) | Active-HIGH reset pin | Tied to GND for 10-step full cycle |
| **16** | VDD ($V_{CC}$) | Positive supply voltage pin | Connected to +9V rail |

---

## 4. How to Make the Circuit (Assembly Steps)

1. **Place ICs on Breadboard**:
   - Insert NE555 and CD4017 across the center divider notch of the breadboard.
2. **Power Connections**:
   - Connect Pin 8 ($V_{CC}$) and Pin 4 (Reset) of NE555 to +9V rail. Connect Pin 1 (GND) to GND rail.
   - Connect Pin 16 ($V_{DD}$) of CD4017 to +9V rail. Connect Pin 8 ($V_{SS}$), Pin 13 (CE), and Pin 15 (Reset) to GND rail.
3. **Set Up 555 Astable Oscillator**:
   - Connect 1 kΩ resistor ($R_1$) between +9V rail and Pin 7 of NE555.
   - Connect 50 kΩ potentiometer ($R_2$) between Pin 7 and Pin 6/2 of NE555.
   - Connect short jumper between Pin 2 and Pin 6 of NE555.
   - Connect positive terminal of 10 µF capacitor ($C_1$) to Pin 2/6 and negative terminal to GND.
   - Connect 0.1 µF ceramic capacitor ($C_2$) between Pin 5 of NE555 and GND.
4. **Connect Clock Line**:
   - Run a jumper wire from Pin 3 (Output) of NE555 to Pin 14 (CLK) of CD4017.
5. **Connect LEDs**:
   - Connect the anodes of 10 LEDs to CD4017 output pins:
     - LED 1 Anode $\rightarrow$ Pin 3 (Q0)
     - LED 2 Anode $\rightarrow$ Pin 2 (Q1)
     - LED 3 Anode $\rightarrow$ Pin 4 (Q2)
     - LED 4 Anode $\rightarrow$ Pin 7 (Q3)
     - LED 5 Anode $\rightarrow$ Pin 10 (Q4)
     - LED 6 Anode $\rightarrow$ Pin 1 (Q5)
     - LED 7 Anode $\rightarrow$ Pin 5 (Q6)
     - LED 8 Anode $\rightarrow$ Pin 6 (Q7)
     - LED 9 Anode $\rightarrow$ Pin 9 (Q8)
     - LED 10 Anode $\rightarrow$ Pin 11 (Q9)
   - Connect cathodes of all 10 LEDs to GND rail.
6. **Apply Power**:
   - Connect 9V battery terminals to +9V and GND rails. Adjust 50k pot to vary chasing speed.

---

## 5. Working Principle & Circuit Theory

### Phase 1: 555 Astable Clock Generation
The 555 timer operates in free-running (astable) mode.
- **Charging Path**: Current flows from $V_{CC} \rightarrow R_1 \rightarrow R_2 \rightarrow C_1$. $C_1$ charges until voltage reaches $\frac{2}{3}V_{CC}$, causing Pin 6 (Threshold) to trigger internal flip-flop. Pin 3 output goes LOW and Pin 7 (Discharge transistor) turns ON.
- **Discharging Path**: $C_1$ discharges through $R_2 \rightarrow Pin\ 7 \rightarrow GND$. When voltage drops below $\frac{1}{3}V_{CC}$, Pin 2 (Trigger) trips, Pin 3 output goes HIGH, and Pin 7 turns OFF.

$$\text{HIGH Time } (T_{\text{high}}) = 0.693 \cdot (R_1 + R_2) \cdot C_1$$
$$\text{LOW Time } (T_{\text{low}}) = 0.693 \cdot R_2 \cdot C_1$$
$$\text{Total Period } (T) = 0.693 \cdot (R_1 + 2R_2) \cdot C_1$$
$$\text{Frequency } (f) = \frac{1.44}{(R_1 + 2R_2) \cdot C_1}$$

Adjusting the 50 kΩ potentiometer ($R_2$) directly changes $T$ and $f$, modulating the chasing speed.

### Phase 2: CD4017 Sequential Decoding
The CD4017 is a 5-stage Johnson decade counter with decoded 1-of-10 outputs:
- At initial power-on (or after reset), output Q0 is HIGH (+9V) while Q1–Q9 are LOW (0V).
- On each LOW-to-HIGH transition (rising edge) of the clock signal at Pin 14 from the 555 output:
  1. Q0 goes LOW, Q1 goes HIGH $\rightarrow$ LED 2 lights up.
  2. Next pulse: Q1 goes LOW, Q2 goes HIGH $\rightarrow$ LED 3 lights up.
  3. This sequence continues step-by-step up to Q9.
- Upon reaching Q9, the next clock pulse wraps around back to Q0, producing a smooth, non-overlapping running light sequence.

---

## 6. Troubleshooting & Modifications

- **LEDs Stays Lit Solid / No Chasing**: Check Pin 14 connection from 555 Pin 3. Verify 555 astable oscillation with a meter or single LED.
- **Counter Skips / Stays Stuck**: Ensure Pin 13 (CE) and Pin 15 (RESET) of CD4017 are tied to GND.
- **Fewer LED Steps (e.g., 6-Step Chaser)**: Connect the output pin of the desired last step (e.g. Q6 Pin 5) to Pin 15 (Reset). The counter will reset immediately to Q0 when Q6 triggers.
- **High Power Load Driving**: To drive high-power 12V LED strips, connect NPN transistors (e.g., BC547 or 2N2222) or MOSFETs (2N7000 / IRFZ44N) to the outputs Q0–Q9 of CD4017.
