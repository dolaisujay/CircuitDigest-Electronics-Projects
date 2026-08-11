# Simple Joule Thief Circuit - Low Power Voltage Booster

> **Reference Tutorial**: [CircuitDigest - Simple Joule Thief Circuit Voltage Booster](https://circuitdigest.com/electronic-circuits/simple-joule-thief-circuit-voltage-booster)

---

## 1. Project Overview

A **Joule Thief** is a minimalist self-oscillating voltage booster circuit that extracts leftover electrical energy from "dead" or nearly discharged batteries (e.g., AA or AAA cells depleted down to $0.8\text{V} - 1.1\text{V}$). 

Standard LEDs require a minimum forward voltage ($V_F \approx 2.0\text{V} - 3.4\text{V}$) to illuminate, which a weak $1.5\text{V}$ battery cannot supply directly. The Joule Thief circuit boosts input voltages as low as **$0.7\text{V} - 0.8\text{V}$** up to **$3\text{V} - 5\text{V}$ high-voltage high-frequency pulses**, allowing an LED to glow brightly using energy that would otherwise be discarded.

---

## 2. Components List

| Component | Quantity | Value / Specification | Description & Function in Circuit |
| :--- | :---: | :--- | :--- |
| **NPN Transistor** | 1 | 2N2222 / 2N3904 / BC547 | High-speed switching transistor controlling coil current |
| **Toroidal Inductor** | 1 | Ferrite Ring Core | Small ferrite ring with 2 custom bifilar windings (Primary & Feedback) |
| **Magnet Wire** | 2 strands | 28 AWG – 30 AWG Enamelled | Wire used to wind $10-15$ turns on the toroidal core |
| **Base Resistor** | 1 | 1 kΩ (1/4W) | Limits base current to transistor, setting oscillation frequency |
| **LED** | 1 | 5mm White / Blue LED | Load output ($V_F \approx 3.0\text{V} - 3.2\text{V}$) |
| **Low-Voltage Battery**| 1 | 1.5V AA / AAA (Drained $\sim 0.8\text{V}-1.2\text{V}$) | Weak power source |
| **Prototyping** | 1 | Breadboard & Jumpers | Assembly hardware |

---

## 3. Toroid Winding & Wiring Guide

Proper winding of the toroidal core is critical to ensure positive feedback and self-sustained oscillation.

### Winding Steps:
1. Take **two equal lengths of enamelled copper wire** (e.g., Red wire for Primary, Yellow wire for Feedback).
2. Pass both wires together through the center of the ferrite ring core, wrapping them in parallel (**bifilar winding**).
3. Wind approximately **10 to 15 complete turns** around the toroid.
4. Strip the enamel insulation off all 4 wire ends.
5. **Cross-Connect the Windings**:
   - Label the ends of the Red coil as **R1** (start) and **R2** (finish).
   - Label the ends of the Yellow coil as **Y1** (start) and **Y2** (finish).
   - Connect **R2 (finish of Primary)** together with **Y1 (start of Feedback)**. This junction forms the **Common Center Tap** connected to the positive battery terminal ($+V_{in}$).
   - End **R1** (other end of Primary) connects to the **Collector** of the NPN transistor.
   - End **Y2** (other end of Feedback) connects through the **1 kΩ resistor** to the **Base** of the NPN transistor.

---

## 4. Circuit Diagram & Schematic

```
          +-----------------------+ (Battery Positive: +0.8V to +1.5V)
          |                       |
          |                 Center Tap (R2 + Y1 connected)
          |                       |
          +----------+------------+
                     |
            +--------+--------+
            | Toroidal Core   |
            |                 |
     Feedback Winding    Primary Winding
        (Yellow)             (Red)
            |                 |
         1k Resistor          |
            |                 |
            v                 v
          Base            Collector
       +----------------------------+
       |   NPN Transistor (2N2222)   |
       +----------------------------+
            |                 |
         Emitter              +------> (Anode of LED)
            |                            |
            |                           [LED]
            |                            |
            +----------------------------+-----> (Cathode of LED & Battery Negative GND)
```

---

## 5. How It Works (5-Phase Oscillation Cycle)

The Joule Thief operates as a **self-oscillating inductive flyback converter** running at high frequencies ($50\text{kHz} - 500\text{kHz}$):

### Phase 1: Initial Turn-ON
- When a weak battery ($0.8\text{V}$) is connected, small current flows through the Feedback coil (Yellow) and the 1 kΩ resistor into the transistor Base.
- This turns the transistor slightly ON, allowing current to begin flowing through the Primary coil (Red) into the Collector.

### Phase 2: Positive Feedback Amplification
- As primary current increases, it expands a magnetic flux inside the ferrite toroidal core.
- This changing magnetic flux induces a positive voltage in the Feedback winding (due to mutual inductance).
- Because of the reversed winding connections, this induced voltage raises the Base voltage, turning the transistor **fully ON into saturation**.

### Phase 3: Magnetic Core Saturation
- The primary current rapidly rises to a peak value, causing the magnetic flux in the ferrite core to reach its maximum physical limit (**magnetic saturation**).
- Once saturated, the rate of change of magnetic flux drops to zero ($\frac{d\Phi}{dt} = 0$).
- Consequently, the induced voltage in the feedback winding vanishes, cutting off base current.

### Phase 4: Magnetic Collapse & High-Voltage Spike
- Lacking base drive, the transistor abruptly turns **OFF**.
- The current through the primary coil suddenly drops to zero.
- The energy stored in the magnetic field collapses rapidly. According to Faraday's Law of Induction ($V_L = -L \frac{di}{dt}$), the collapsing field generates a **high-voltage back-EMF pulse** across the primary winding.
- This voltage pulse (typically $3\text{V} - 15\text{V}$) adds to the battery voltage, easily exceeding the $3.0\text{V}$ threshold of the LED. Current surges through the LED, making it flash brightly.

### Phase 5: Cycle Reset & Continuous Oscillation
- Once the magnetic energy is fully dissipated into the LED, the coil voltage collapses to zero.
- Small battery current once again flows into the base through the 1 kΩ resistor, restarting Phase 1.
- This cycle repeats **tens of thousands of times per second**, producing high-frequency light pulses that appear as a steady, continuous glow to the human eye.

---

## 6. Advantages, Limitations & Applications

### Advantages
- Operates from extremely low input voltages (down to $\sim 0.7\text{V}$).
- Utilizes residual energy in discarded batteries.
- Uses minimal, ultra-low-cost discrete components.
- Self-oscillating design requires no IC controllers or PWM chips.

### Technical Limitations
- **Unregulated Output Voltage**: High voltage spikes can damage sensitive ICs if connected without a filtering capacitor/Zener regulator.
- **Low Output Current**: Suitable primarily for low-power loads like LEDs.
- **Winding Sensitivity**: Will fail to oscillate if toroid windings are connected out of phase.

### Practical Applications
- Emergency nightlights and flashlights using depleted batteries.
- Science fair demonstrations of inductive energy storage and flyback conversion.
- Low-power energy harvesting from solar micro-cells or Peltier elements.
