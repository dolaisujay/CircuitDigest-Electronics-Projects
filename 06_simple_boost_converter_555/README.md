# Simple DC-DC Boost Converter Circuit Using 555 Timer IC

> **Reference Tutorial**: [CircuitDigest - Simple Boost Converter Circuit Using 555 Timer IC](https://circuitdigest.com/electronic-circuits/a-simple-boost-converter-circuit-using-555-timer-ic)

---

## 1. Project Overview

A **DC-DC Boost Converter** (Step-Up Converter) is a non-isolated Switch-Mode Power Supply (SMPS) topology that converts a lower DC input voltage to a higher DC output voltage.

This project uses an **NE555 Timer IC** operating in Astable Multivibrator mode to generate a high-frequency Pulse Width Modulation (PWM) signal. This PWM signal drives an **IRFZ44N N-Channel Power MOSFET** to rapidly switch current through a **$100\mu\text{H}$ energy storage inductor**. When tested with a single Li-ion cell ($3.4\text{V} - 3.7\text{V}$ input), the circuit successfully steps up the voltage to **$7.5\text{V} - 12\text{V} DC$**, delivering power levels up to **30 Watts**.

---

## 2. Components List

| Component | Quantity | Value / Specification | Description & Function in Circuit |
| :--- | :---: | :--- | :--- |
| **PWM Generator IC** | 1 | NE555N / LM555 | Astable multivibrator producing high-frequency PWM switching signal |
| **Power MOSFET** | 1 | IRFZ44N ($55\text{V}, 49\text{A}, 17.5\text{m}\Omega$) | Low $R_{DS(\text{on})}$ N-Channel MOSFET acting as high-speed power switch |
| **Power Inductor** | 1 | $100\mu\text{H}$ Toroidal / Drum Core | Energy storage element (high saturation current rating $\ge 3\text{A}$) |
| **Fast Recovery Diode**| 1 | 1N5822 (Schottky $40\text{V}, 3\text{A}$) | Fast rectifier preventing output capacitor discharge into MOSFET |
| **Feedback Diodes** | 2 | 1N4001 / 1N4148 | Steering diodes in 555 astable duty-cycle control network |
| **Output Capacitor** | 1 | $100\mu\text{F}$ (35V / 50V) Electrolytic | Smooths high-voltage output pulses to stable DC voltage |
| **Timing Capacitors** | 2 | 1 nF (102) & 100 nF (104) Ceramic | 555 timing capacitor ($C_1$) and noise filtering capacitor ($C_2$) |
| **Potentiometer** | 1 | 50 kΩ Trimpot | Varies duty cycle ($D$) to adjust boosted output voltage |
| **Base / Gate Resistor**| 1 | 1 kΩ (1/4W) | 555 astable pull-up resistor |
| **Terminal Blocks** | 2 | 2-Pin Screw Terminals | Connectors for DC Input ($V_{in}$) and Boosted Output ($V_{out}$) |

---

## 3. Circuit Schematic & Diagram

```
         +---------+--------------------+-----------------------------+ (V_in: 3.7V - 5V)
         |         |                    |                             |
        [R1]      [1k]               [100uH Inductor]                 |
        1k        |                    |                              |
         |        +----+--[1N4001]--+  +----------+ (Drain)           |
         |        |    |            |  |          |                   |
         +-----+  |  [1N4001]       |  |     [1N5822 Schottky Diode]  |
         |     |  |    |            |  |          | (Anode -> Cathode)|
        [50k Pot] |    +------------+  |          +--------+----------+-----> (V_out: +7.5V to +12V)
         |     |  |                 |  |                   |          |
         +-----+  |                 |  |                [100uF]     [LOAD]
         |        |                 |  |                Capacitor     |
      Pin 7    Pin 8              Pin 3| (Gate)            |          |
    +----------------------------------+                   |          |
    |          NE555 TIMER IC          |                   |          |
    +----------------------------------+                   |          |
      Pin 1    Pin 2/6            Pin 5                    |          |
         |        |                 |                      |          |
         |      [1nF]           [100nF]                    |          |
         |        |                 |                      |          |
  GND ---+--------+-----------------+-------(Source)-------+----------+-----> GND Rail
```

---

## 4. How to Make the Circuit (Assembly Steps)

1. **Safety & Board Consideration**:
   - Because boost converters process peak currents up to $3\text{A}-5\text{A}$, assemble this circuit on a **soldered Perfboard or PCB**. Breadboards have high contact resistance and may melt under high currents.
2. **555 PWM Oscillator Setup**:
   - Connect Pin 8 ($V_{CC}$) and Pin 4 (Reset) of NE555 to input power rail ($V_{in} = 3.7\text{V}-5\text{V}$).
   - Connect Pin 1 (GND) to Ground rail.
   - Connect 100 nF ceramic capacitor between Pin 5 (Control) and GND for noise immunity.
   - Wire steering diodes (1N4001) and 50 kΩ pot between Pin 7, Pin 2/6, and Pin 8 to achieve adjustable PWM duty cycle ($D \approx 10\% - 90\%$).
   - Connect 1 nF capacitor between Pin 2/6 and GND to set switching frequency ($f \approx 20\text{kHz} - 40\text{kHz}$).
3. **MOSFET & Power Stage Wiring**:
   - Connect Pin 3 (Output) of NE555 directly to the **Gate** pin of the IRFZ44N MOSFET.
   - Connect the **Source** pin of the IRFZ44N to GND rail.
   - Connect one end of the **$100\mu\text{H}$ Inductor** to $V_{in}+$, and the other end to the **Drain** pin of the IRFZ44N MOSFET.
4. **Output Rectifier & Filter Stage**:
   - Connect the **Anode of 1N5822 Schottky Diode** to the MOSFET Drain / Inductor junction.
   - Connect the **Cathode of 1N5822 Diode** to the positive terminal of the $100\mu\text{F}$ (35V) output capacitor.
   - Connect the negative terminal of the $100\mu\text{F}$ capacitor to GND rail.
5. **Testing Output**:
   - Connect a multimeter across the $100\mu\text{F}$ output capacitor. Apply 3.7V Li-ion battery at input. Rotate 50k pot to observe output voltage stepping up from $3.7\text{V}$ to $> 12\text{V}$.

---

## 5. How It Works (Theoretical Derivations & Physics)

The boost converter operates in two distinct cyclical stages controlled by the MOSFET switch:

### Stage 1: MOSFET ON (Inductor Charging Phase)
- When 555 Pin 3 output goes HIGH, the IRFZ44N MOSFET turns ON, shorting the right side of the inductor directly to GND.
- Current flows from $V_{in} \rightarrow \text{Inductor} \rightarrow \text{MOSFET Drain-to-Source} \rightarrow \text{GND}$.
- The Schottky diode (1N5822) is reverse-biased, preventing the output capacitor from discharging back into the MOSFET.
- Energy is stored in the inductor's magnetic field:
  $$E_L = \frac{1}{2} L I^2$$
- Inductor current rises linearly at rate:
  $$\frac{di}{dt} = \frac{V_{in}}{L}$$

### Stage 2: MOSFET OFF (Inductor Discharging / Flyback Phase)
- When 555 Pin 3 output goes LOW, the MOSFET turns OFF abruptly.
- The inductor opposes the sudden drop in current by reversing its voltage polarity, creating a high-voltage inductive flyback pulse ($V_L = L \frac{di}{dt}$).
- This flyback voltage adds in series with the input voltage ($V_{\text{total}} = V_{in} + V_L$).
- The combined voltage forward-biases the 1N5822 Schottky diode, charging the $100\mu\text{F}$ output capacitor to $V_{out}$.

### Mathematical Formulas
- **Time Period**: $T = T_{\text{on}} + T_{\text{off}}$
- **Duty Cycle ($D$)**:
  $$D = \frac{T_{\text{on}}}{T}$$
- **Ideal Voltage Transfer Ratio**:
  $$\frac{V_{out}}{V_{in}} = \frac{1}{1 - D} \implies V_{out} = \frac{V_{in}}{1 - D}$$
- *Example*: For $V_{in} = 3.7\text{V}$ and Duty Cycle $D = 65\%$ ($0.65$):
  $$V_{out} = \frac{3.7}{1 - 0.65} = \frac{3.7}{0.35} \approx \mathbf{10.57\text{V}}$$

---

## 6. Practical Test Results & Technical Limitations

### Laboratory Test Bench Results
- **Input Voltage**: $3.4\text{V}$ (Single Li-ion cell)
- **Measured No-Load Output Voltage**: $7.5\text{V} - 15\text{V}$ (Adjustable via 50k pot)
- **Short-Circuit Peak Current**: Up to $3.2\text{A}$ ($\sim 30\text{Watts}$ peak handling capacity)

### Key Technical Limitations & Improvements
- **Open-Loop Design (No Voltage Feedback)**: Since the 555 timer operates at a fixed duty cycle set by the potentiometer, output voltage will sag when a heavy load is connected.
- **Microcontroller Closed-Loop Feedback Upgrade**: To maintain a steady regulated output (e.g. fixed 12V), add a feedback voltage divider to an Arduino / ESP32 ADC pin to dynamically adjust PWM duty cycle based on load changes.
