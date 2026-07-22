# Chapter 8: Tilt Ball Switch

<img width="700" height="auto" alt="IMG_20260722_141656" src="https://github.com/user-attachments/assets/9c40acc7-553c-446b-8a17-eabc363040cf" />

This is my eighth Arduino project, following along with the PDF guide. I built a circuit with a tilt ball switch that controls an LED.

**This is the first project where I designed the circuit myself.**

## Circuit Overview

- One tilt ball switch connected to pin 3
- One red LED connected to pin 2 (with 220Ω resistor)
- The tilt switch acts like a simple on/off switch

*Note: Tilt ball switches are not polarized.*

## Wiring

<img width="380" height="340" alt="circuit" src="https://github.com/user-attachments/assets/957723f8-43c9-4e81-b18a-b9bf02f29fb9" />

<small>*First designed circuit and illustration might be wrong.*</small>

- **Tilt Switch Leg 1** -> Pin 3
- **Tilt Switch Leg 2** -> GND
- **LED Anode (long leg)** -> 220Ω Resistor -> Pin 2
- **LED Cathode (short leg)** -> GND

## What I Learned

This project taught me how to use a tilt ball switch as a digital input. It works similarly to the button from Chapter 5, but instead of pressing, you tilt it.

I also learned about `Serial.begin()` and `Serial.println()` for debugging. 

**The biggest win:** This is the first project where I designed the circuit myself, without just copying the PDF diagram. I had to think about how the tilt switch connects and how to wire the LED properly. I chose to use `INPUT_PULLUP` instead of an external resistor, which simplified the circuit.

### Understanding the Code

#### 1. Defining the Pins

```cpp
const int ledPin = 2;
const int tiltPin = 3;
```

I define two constant variables. `ledPin` is connected to pin 2 and `tiltPin` is connected to pin 3. Using `const int` means these values cannot be changed later in the program.

#### 2. The Setup Function

```cpp
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(tiltPin, INPUT_PULLUP);
  Serial.begin(9600);
}
```

- `pinMode(ledPin, OUTPUT)`: Sets the LED pin to output mode.
- `pinMode(tiltPin, INPUT_PULLUP)`: Sets the tilt switch pin to input with the internal pull-up resistor enabled. This prevents the pin from "floating" and gives reliable readings.
- `Serial.begin(9600)`: Starts serial communication at 9600 bits per second. This allows the Arduino to send messages to my computer.

#### 3. Reading the Tilt Switch

```cpp
int tiltState = digitalRead(tiltPin);
```

I create a variable called `tiltState` and use `digitalRead()` to check if the tilt switch is HIGH or LOW. Since I'm using `INPUT_PULLUP`, the pin reads HIGH when the switch is open (tilted) and LOW when it's closed (upright).

#### 4. The Logic

```cpp
if (tiltState == HIGH) {
  digitalWrite(ledPin, HIGH);
  Serial.println("Tilted → LED ON");
} else {
  digitalWrite(ledPin, LOW);
  Serial.println("Upright → LED OFF");
}
```

This is a simple `if` / `else` statement:
- If the tilt switch is HIGH (tilted / open circuit): turn the LED on.
- Else (upright / closed circuit): turn the LED off.

**Note:** The LED turns ON when `digitalWrite(ledPin, HIGH)` is called. This is standard "active-high" logic where HIGH means ON and LOW means OFF.

#### 5. Serial Communication (Optional)

`Serial.begin(9600)` starts communication between the Arduino and my computer. `Serial.println()` sends messages that I can read in the Serial Monitor. This is very useful for troubleshooting and understanding what the code is doing.

**Note:** The code works perfectly without the Serial lines. They are optional debugging tools that help you see what's happening in real-time.

#### 6. Debouncing

```cpp
delay(100);
```

The tilt switch can physically bounce, just like a button. The small delay at the end of the loop prevents flickering and unreliable readings by giving the switch time to settle.

### Troubleshooting

When I first wrote the code, I had the logic inverted. I originally wrote:

```cpp
if (tiltState == LOW) {
  digitalWrite(ledPin, HIGH);
} else {
  digitalWrite(ledPin, LOW);
}
```

But when I tested it, the LED turned on when upright and off when tilted. I realized that with `INPUT_PULLUP`, the pin reads HIGH when the circuit is open (tilted) and LOW when it's closed (upright). 

After testing and thinking about it, I realized I needed to check for `HIGH` in the `if` statement instead of `LOW`:

```cpp
if (tiltState == HIGH) {      // Tilted = ON
  digitalWrite(ledPin, HIGH);
} else {                      // Upright = OFF
  digitalWrite(ledPin, LOW);
}
```

Now it works exactly as I want: **Tilted = LED ON, Upright = LED OFF.**

### The Serial Monitor

To see the messages from `Serial.println()`:
1. Upload the code to the Arduino
2. Open the Serial Monitor (Tools → Serial Monitor)
3. Make sure the baud rate is set to 9600
4. Tilt the switch and watch the messages appear!

## Code

```cpp
const int ledPin = 2;     // LED connected to pin 2
const int tiltPin = 3;    // Tilt switch connected to pin 3

void setup() {
  pinMode(ledPin, OUTPUT);              // LED as output
  pinMode(tiltPin, INPUT_PULLUP);       // Tilt switch with internal pull-up
  Serial.begin(9600);                   // Start Serial communication
}

void loop() {
  int tiltState = digitalRead(tiltPin); // Read the tilt switch

  if (tiltState == HIGH) {              // If tilted (open circuit)
    digitalWrite(ledPin, HIGH);         // Turn LED ON
    Serial.println("Tilted → LED ON");
  } else {                              // If upright (closed circuit)
    digitalWrite(ledPin, LOW);          // Turn LED OFF
    Serial.println("Upright → LED OFF");
  }

  delay(100);  // Small delay to prevent bouncing
}
```

## How It Works

When the tilt switch is tilted, the metal ball rolls away and opens the circuit. With `INPUT_PULLUP`, the pin is pulled up to HIGH (5V). This makes `digitalRead(tiltPin)` return HIGH, which triggers the `if` statement and turns the LED ON.

When the switch is upright, the ball sits at the bottom and connects the two contacts (closed circuit) to GND. This makes `digitalRead(tiltPin)` return LOW, so the `else` statement runs and turns the LED OFF.

**So:** Tilted = LED ON, Upright = LED OFF.

The Serial Monitor shows real-time messages so you can see exactly what state the switch is in.

## Key Takeaway

The tilt ball switch works like a button—it's a simple digital input. Using `INPUT_PULLUP` simplifies the circuit by removing the need for an external resistor.

I also learned that getting the logic right sometimes requires testing and adjusting. It's easy to assume how the code should work, but the best way to know is to upload it, test it, and adjust until it works the way you want.

**Most importantly:** This was the first project where I designed the circuit layout myself. It felt great to take what I learned from the previous chapters and apply it without following a step-by-step diagram.

---

<small>*Notes written by me, formatted with AI assistance.*</small>
