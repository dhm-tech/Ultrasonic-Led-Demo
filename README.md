# 🚗 Arduino Distance-Based LED Indicator

A simple project that uses an **ultrasonic sensor (SRF05)** to detect distance and turn on **up to 4 LEDs** depending on how close an object is.
Perfect for beginners exploring sensor input and conditional output with Arduino.

---

## 🎯 What You Will Learn

- How to use an **ultrasonic sensor** to measure distance
- Read distance using `pulseIn()`
- Light up LEDs based on object proximity
- Use `Serial Monitor` to debug sensor readings
- Understand basic `if-else` logic in Arduino

---

## 🔧 Components

| Qty | Component                    |
|-----|-------------------------------|
| 1   | Arduino Uno R3               |
| 1   | SRF05 Ultrasonic Sensor      |
| 4   | LEDs (Red, Blue, etc.)       |
| 4   | Resistors (220–330Ω)         |
| 1   | Breadboard                   |
| 10+ | Jumper Wires                 |

---

## 🛠️ Tools & Libraries

- Arduino IDE 1.8+ or 2.x
- Serial Monitor for debugging
- Tinkercad Circuits (for virtual simulation, optional)

---

## ⚙️ How It Works

1. The **SRF05** sensor sends a trigger pulse (TRIG).
2. It receives the echo reflected back (ECHO).
3. The Arduino calculates distance using the duration of echo.
4. Depending on how close an object is:
   - Turn ON LED1 if closer than 7cm
   - LED2 for 14cm
   - LED3 for 21cm
   - LED4 for 28cm

```cpp
const int trig = 12;
const int echo = 11;
const int LED1 = 7;
const int LED2 = 6;
const int LED3 = 5;
const int LED4 = 4;
int duration = 0;
int distance = 0;

void setup() {
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig , LOW);
  delayMicroseconds(2);
  digitalWrite(trig , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig , LOW);

  duration = pulseIn(echo , HIGH);
  distance = (duration * 0.034 / 2);
  Serial.println(distance);

  digitalWrite(LED1, distance <= 7 ? HIGH : LOW);
  digitalWrite(LED2, distance <= 14 ? HIGH : LOW);
  digitalWrite(LED3, distance <= 21 ? HIGH : LOW);
  digitalWrite(LED4, distance <= 28 ? HIGH : LOW);

  delay(200);
}
```

---

## 🚀 Getting Started

### Hardware
1. Connect SRF05:
   - VCC → 5V
   - GND → GND
   - TRIG → D12
   - ECHO → D11
   - OUT → (not used)
2. Connect each LED (with resistor) to D7, D6, D5, and D4
3. Make sure all grounds are connected

### Software
1. Open Arduino IDE
2. Paste the code above
3. Select board: **Arduino Uno**
4. Select correct COM port
5. Upload and test with hand or object

---

## 📸 Demo Media
https://github.com/user-attachments/assets/ultrasonic-led-demo.gif

---

## 👤 Author
> Designed by: [Abdulrahman Qutah]  
> Date: [30 Jul 2025]
