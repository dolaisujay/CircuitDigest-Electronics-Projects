# LED ON and OFF / Dimmer Circuit Using 555 Timer IC and BC557 Transistor

> **Reference Tutorial**: [CircuitDigest - Building a LED Dimmer Circuit using 555 Timer IC and BC557 Transistor](https://circuitdigest.com/electronic-circuits/led-on-and-off-circuit-using-555-timer-ic-and-bc557-transistor)

---

## 1. Project Overview

This project demonstrates how to build an **LED ON and OFF / Fading Dimmer Circuit** using an **NE555 Timer IC** and a **BC557 PNP Bipolar Junction Transistor (BJT)**.

The circuit utilizes the 555 timer in an **Astable Multivibrator** configuration to generate a low-frequency square wave signal. This pulse output drives the base of the BC557 PNP transistor acting as a high-side electronic switch, controlling power flow to an array of LEDs. By adjusting RC timing networks, the circuit creates smooth pulse transitions, flashing, or sequential ON/OFF visual effects.

---

## 2. Components List

| Component | Quantity | Value / Specification | Description & Function in Circuit |
| :--- | :---: | :--- | :--- |
| **Timer IC** | 1 | NE555N | Master pulse/timing generator |
| **PNP Transistor** | 1 | BC557 | PNP BJT acting as high-side driver switch for LED array |
| **Resistors** | 6 | 1 kΩ (1/4W) | Current-limiting resistors for individual LEDs in array |
| **Resistor** | 1 | 56 kΩ | Base drive current limiting resistor for BC557 |
| **Resistor** | 1 | 47 kΩ | RC timing / biasing network resistor |
| **Resistors** | 2 | 100 kΩ & 200 kΩ | Astable timing feedback network connected to Pins 6 & 7 |
| **Capacitors** | 2 | 10 µF (16V) & 470 µF (16V) | Electrolytic timing and smoothing capacitors |
| **LEDs** | 6 | Standard 5mm LEDs | Light-emitting array output indicators |
| **Power Source** | 1 | 12V DC Adapter / Battery | Circuit supply voltage |
| **Prototyping** | 1 | Breadboard & Wires | Circuit connections |

---

## 3. IC & Transistor Pin Configurations

### 555 Timer IC Pinouts
- **Pin 1 (GND)**: System ground reference.
- **Pin 2 (Trigger)**: Connected to 10 µF capacitor and Pin 6 (Threshold).
- **Pin 3 (Output)**: Delivers square wave output connected through 56 kΩ resistor to BC557 Base.
- **Pin 4 (Reset)** & **Pin 5 (Control)**: Floating / tied as required by astable setup.
- **Pin 6 (Threshold)**: Tied to Pin 2 and 100 kΩ / 200 kΩ timing resistors.
- **Pin 7 (Discharge)**: Connected between 100 kΩ and 200 kΩ resistors.
- **Pin 8 (VCC)**: Connected to +12V positive power rail.

### BC557 PNP Transistor Pinout (TO-92 Package)
- **Pin 1 (Collector)**: Connects to the positive anodes of the LED array via 1 kΩ limiting resistors.
- **Pin 2 (Base)**: Connects to 56 kΩ resistor from 555 Pin 3 output.
- **Pin 3 (Emitter)**: Connected directly to the +12V positive supply rail.

---

## 4. How to Make the Circuit (Assembly Steps)

1. **Place IC & Transistor**:
   - Insert NE555 timer IC onto breadboard.
   - Insert BC557 PNP transistor (flat face facing front: Emitter, Base, Collector).
2. **Power Rail Wiring**:
   - Connect Pin 8 ($V_{CC}$) of NE555 to +12V rail. Connect Pin 1 (GND) to GND rail.
   - Connect Emitter of BC557 to +12V rail.
3. **555 Astable Oscillating Network**:
   - Connect a 200 kΩ resistor between +12V rail (Pin 8) and Pin 7 (Discharge).
   - Connect a 100 kΩ resistor between Pin 7 and Pin 6 (Threshold).
   - Connect a short jumper wire between Pin 6 and Pin 2 (Trigger).
   - Connect the positive leg of a 10 µF (16V) capacitor to Pin 2/6, and negative leg to GND rail.
4. **Transistor High-Side Driver Wiring**:
   - Connect a 56 kΩ resistor from 555 Pin 3 (Output) to the **Base** of BC557.
   - Connect a parallel network ($47\text{k}\Omega$ resistor and $470\mu\text{F}$ capacitor) between +12V rail and BC557 base node for smooth rise/fall fading transition.
5. **LED Array Connections**:
   - Connect the **Collector** of BC557 to the positive terminal of 6 parallel LED branches.
   - Each LED branch consists of a 1 kΩ current limiting resistor in series with an LED.
   - Connect all LED cathodes to the common GND rail.
6. **Power Application**:
   - Apply 12V DC power to the rails. Watch LEDs flash / pulse ON and OFF in rhythm.

---

## 5. How It Works (Circuit Theory & Dynamics)

### Astable Pulse Generation
The 555 timer IC is wired as an astable multivibrator. The 10 µF capacitor charges through $(200\text{k} + 100\text{k})\Omega$ resistors up to $\frac{2}{3}V_{CC}$ and discharges through the $100\text{k}\Omega$ resistor into Pin 7 down to $\frac{1}{3}V_{CC}$. This creates a continuous low-frequency square wave at Pin 3 (Output).

### PNP Transistor Switching Dynamics
Unlike NPN transistors (which turn ON when base voltage is HIGH), a **PNP transistor (BC557)** operates as a high-side switch controlled by a LOW base voltage:

1. **State 1: 555 Output Pin 3 is LOW (0V)**
   - The Base of BC557 drops lower than its Emitter ($V_B < V_E = +12\text{V}$).
   - $V_{BE} \approx -0.7\text{V}$, forward-biasing the PNP base-emitter junction.
   - The BC557 **turns ON (saturates)**, conducting current from Emitter to Collector into the LED array $\rightarrow$ **LEDs turn ON**.

2. **State 2: 555 Output Pin 3 is HIGH (+12V)**
   - The Base voltage rises close to Emitter voltage ($V_B \approx V_E = +12\text{V}$).
   - $V_{BE} \approx 0\text{V}$, reverse-biasing the base-emitter junction.
   - The BC557 **turns OFF (cutoff)**, stopping current flow to Collector $\rightarrow$ **LEDs turn OFF**.

3. **RC Fading Effect (Dimmer Action)**:
   - The $470\mu\text{F}$ capacitor connected to the Base node charges and discharges gradually during state changes, creating a soft exponential rise and decay in base current. This produces a smooth **LED fading / dimming transition** rather than abrupt digital blinking.
