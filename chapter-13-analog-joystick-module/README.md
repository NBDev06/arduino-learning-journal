# Chapter 13: Analog Joystick

<img width="700" height="auto" alt="IMG_20260727_133932" src="https://github.com/user-attachments/assets/f401fc8f-2299-4420-8ddb-459b01c5cf46" />

This is my thirteenth Arduino project, following along with the PDF guide. I built a circuit with an analog joystick that reads the X and Y positions and the switch state, then prints them to the Serial Monitor.

## Circuit Overview

- One analog joystick connected to pins 2, A0, and A1
- The joystick has two potentiometers (X and Y axes) and a push-button switch
- The readings are printed to the Serial Monitor

*Note: The joystick acts like two potentiometers and a button.*

## Wiring

<img width="700" height="auto" alt="Screenshot 2026-07-27 135307" src="https://github.com/user-attachments/assets/bd205973-573c-499e-886e-e1a19255b008" />

- **SW (Switch)** -> Pin 2 (Digital)
- **X-axis** -> Pin A0 (Analog)
- **Y-axis** -> Pin A1 (Analog)
- **VCC** -> 5V
- **GND** -> GND

## What I Learned

This project taught me how to use an analog joystick. The joystick has two potentiometers (for X and Y movement) and a push-button switch. I learned how to read analog values using `analogRead()` and digital values using `digitalRead()`.

### Understanding the Code

#### 1. Defining the Pins

```cpp
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0;  // analog pin connected to X output
const int Y_pin = 1;  // analog pin connected to Y output
```

I create constants for the pins:
- `SW_pin` is connected to digital pin 2 for the switch
- `X_pin` is connected to analog pin 0 for the X-axis
- `Y_pin` is connected to analog pin 1 for the Y-axis

#### 2. The Setup Function

```cpp
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}
```

- `pinMode(SW_pin, INPUT);`: Sets the switch pin to input mode
- `digitalWrite(SW_pin, HIGH);`: Enables the internal pull-up resistor on the switch pin. This means the switch reads HIGH (1) when not pressed and LOW (0) when pressed
- `Serial.begin(9600);`: Starts serial communication at 9600 baud

#### 3. The Loop Function

```cpp
void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(1000);
}
```

This loop continuously reads and prints the joystick state:

- `digitalRead(SW_pin)`: Reads the switch state (1 = not pressed, 0 = pressed)
- `analogRead(X_pin)`: Reads the X-axis position (0 to 1023)
- `analogRead(Y_pin)`: Reads the Y-axis position (0 to 1023)
- `delay(1000)`: Waits 1 second before taking the next reading

The `\n` adds a new line to make the output easier to read.

## Code

```cpp
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0;  // analog pin connected to X output
const int Y_pin = 1;  // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(1000);
}
```

## How It Works

The joystick has two potentiometers (for X and Y) and a push-button switch. When you move the joystick, the potentiometers change their resistance, which changes the analog voltage on the X and Y pins. The `analogRead()` function reads these voltages as values between 0 and 1023.

The switch is connected with an internal pull-up resistor enabled. This means it reads HIGH (1) when not pressed and LOW (0) when pressed.

## Key Takeaway

This project taught me how to use an analog joystick. The joystick is basically two potentiometers, plus a button. I learned how to read both analog and digital inputs in the same sketch.

---

<small>*Notes written by me, formatted with AI assistance.*</small>
