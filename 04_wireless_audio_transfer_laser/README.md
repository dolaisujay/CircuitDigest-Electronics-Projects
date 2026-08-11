# Wireless Audio Transfer Using LASER Light (Li-Fi Audio System)

> **Reference Tutorial**: [CircuitDigest - Wireless Audio Transfer Using Laser Light](https://circuitdigest.com/electronic-circuits/wireless-audio-transfer-using-laser-light)

---

## 1. Project Overview

This project demonstrates **Visible Light Communication (VLC)** and **Li-Fi (Light Fidelity)** technology by transmitting analog audio signals wirelessly over a focused laser beam. 

In this system:
1. **Transmitter**: Captures voice/audio via an electret microphone, amplifies it using a **MAX4466 module**, and intensity-modulates a $650\text{nm}$ Red Laser Diode using a **PAM8403 Class-D Audio Amplifier**.
2. **Optical Medium**: Focused laser light beam traveling through free space (tested up to $50\text{m}$ indoors / $>100\text{m}$ outdoors).
3. **Receiver**: A mini solar panel acts as an optical photodetector, converting fluctuating light intensity back into an AC electrical signal. A second **PAM8403 amplifier** boosts the signal to drive a 4Ω 10W speaker.

---

## 2. Components List

| Component | Quantity | Specification | Description & Function in Circuit |
| :--- | :---: | :--- | :--- |
| **Microphone Module** | 1 | MAX4466 | Electret microphone with adjustable gain op-amp pre-amplifier |
| **Audio Amplifiers** | 2 | PAM8403 Modules | 3W+3W Class-D dual-channel audio amplifiers with potentiometers |
| **Laser Diode** | 1 | 650nm Red Laser (5V, 5mW) | Optical transmitter emitting intensity-modulated beam |
| **Laser Current Resistor**| 1 | 30 Ω (1/4W) | Limits laser diode current (internal or external) |
| **Optical Receiver** | 1 | Mini Solar Panel (5V - 6V) | Large-surface photovoltaic receiver acting as photodetector array |
| **Speaker** | 1 | 4 Ω, 10 Watt | Output transducer reproducing audio signal |
| **Voltage Regulators** | 2 | LM7805 | Regulates 9V battery voltage down to stable 5V DC for modules |
| **DC Power Supply** | 2 | 9V Heavy Duty Batteries | Independent power sources for transmitter and receiver circuits |
| **Input Potentiometer** | 1 | 100 kΩ Trimpot | Provides adjustable DC bias offset for receiver input |
| **Prototyping** | 2 | Breadboards & Jumpers | Assembly boards |

---

## 3. System Block Diagram & Architecture

```
+-----------------------------------------------------------------------------------+
|                               TRANSMITTER SECTION                                 |
|                                                                                   |
|  [Voice/Audio] --> [MAX4466 Mic PreAmp] --> [PAM8403 Amp] --> [Modulated Laser]  |
+-----------------------------------------------------------------------------------+
                                                                   |
                                                       Laser Light Beam (Optical)
                                                                   |
                                                                   v
+-----------------------------------------------------------------------------------+
|                                RECEIVER SECTION                                   |
|                                                                                   |
|  [Solar Panel Photodetector] --> [Bias Pot] --> [PAM8403 Amp] --> [4Ω 10W Speaker] |
+-----------------------------------------------------------------------------------+
```

---

## 4. How to Build the Circuit (Assembly Steps)

### A. Transmitter Construction
1. **Power Regulation**:
   - Connect a 9V battery to the input of an **LM7805** linear voltage regulator.
   - Place a $0.1\mu\text{F}$ capacitor on input and output to ground for stability. This supplies clean 5V DC to transmitter modules.
2. **Pre-Amplifier Connections**:
   - Connect MAX4466 $V_{CC}$ to 5V and $GND$ to GND.
   - Connect MAX4466 $OUT$ pin to the Left/Right audio input channel of the first **PAM8403** module.
3. **Laser Driver Connections**:
   - Connect PAM8403 power pins ($V_{CC}, GND$) to the 5V regulator output.
   - Connect the **Laser Diode** positive wire to PAM8403 speaker output positive ($L+$), and negative wire to speaker output negative ($L-$).
   - If using a bare laser diode without internal resistor, insert a $30\Omega$ resistor in series with the laser anode.

### B. Receiver Construction
1. **Power Regulation**:
   - Connect a second 9V battery to a second **LM7805** regulator to establish an isolated 5V DC rail for the receiver.
2. **Photodetector Wiring**:
   - Connect the negative terminal of the **Mini Solar Panel** to common GND.
   - Connect the positive terminal of the solar panel through a $100\text{k}\Omega$ biasing potentiometer to the audio input ($L_{in}$) of the second **PAM8403** module.
3. **Speaker Output**:
   - Connect the **4Ω 10W speaker** across the $L+$ and $L-$ output terminals of the receiver PAM8403 module.
   - Adjust the PAM8403 potentiometer to set desired volume.

---

## 5. How It Works (Detailed Physics & Electronics)

### Step 1: Acoustic to Electrical Conversion
When sound waves hit the electret capsule on the MAX4466 module, the internal diaphragm vibrates, causing capacitance changes that generate a millivolt-level AC audio voltage. The integrated MAX4466 op-amp amplifies this signal to line level.

### Step 2: Intensity Modulation (Optical Transmitter)
The line-level AC signal enters the PAM8403 audio amplifier module. The output of the amplifier acts as a dynamic voltage driver:
- Instead of driving a speaker coil, the changing audio voltage varies the forward current ($I_F$) passing through the **650nm Laser Diode**.
- Because laser brightness is proportional to forward current, the optical power output of the laser fluctuates rapidly in direct proportion to the audio waveform. This process is called **Analog Optical Intensity Modulation**.

### Step 3: Optical Transmission
The focused laser beam travels through free space carrying the high-frequency amplitude variations of the audio signal.

### Step 4: Photoelectric Conversion (Optical Receiver)
When the laser beam strikes the mini solar panel:
- Photons impinging on the semiconductor material generate electron-hole pairs via the **photoelectric effect**.
- The static ambient light produces a constant DC base current, while the laser intensity variations produce an AC photocurrent ripple superimposed on the DC output.

### Step 5: Demodulation & Audio Amplification
The AC photocurrent passes into the input of the second PAM8403 amplifier. The amplifier strips the DC component, boosts the AC audio signal, and drives the 4Ω 10W speaker cone, reproducing the original voice cleanly.

---

## 6. Performance Comparison & Field Testing

### Wireless Technology Comparison
| Feature | Li-Fi (Laser Audio) | Wi-Fi | Bluetooth |
| :--- | :--- | :--- | :--- |
| **Signal Medium** | Visible / Infrared Light | 2.4 GHz / 5 GHz RF | 2.4 GHz RF |
| **Line-of-Sight Required** | **Yes** (Strict LOS) | No (Penetrates walls) | No (Penetrates walls) |
| **RF Interference** | **Zero** (Safe for hospitals/aircraft) | Moderate / High | High |
| **Latency** | **$< 1\text{ms}$** (Speed of light) | $5\text{ms} - 20\text{ms}$ | $20\text{ms} - 100\text{ms}$ |
| **Security** | High (Cannot penetrate walls) | Requires Encryption | Requires Pairing |

### Field Range Testing Results
- **Indoor Range (Low Ambient Light)**: $10\text{m} - 50\text{m}$ (Crystal clear audio).
- **Outdoor Range (Clear Sight Line)**: $> 100\text{m}$ (Requires steady mounting alignment).
- **Optimization Tip**: Shield the solar panel receiver with a dark tube/lens hood to eliminate ambient sunlight interference.
