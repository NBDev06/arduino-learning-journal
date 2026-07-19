# Chapter 5: Digital Inputs (Two Buttons + LED)

<img width="700" height="auto" alt="IMG_20260719_154457" src="https://github.com/user-attachments/assets/896b4dcc-65ad-4749-80b6-a9eb15a08d7f" />


This is my fifth Arduino project, following along with the PDF guide. I built a circuit with two buttons and an LED to practice reading digital inputs and understanding how buttons work with pull-up resistors.

## Circuit Overview

- Two buttons connected to pins 9 and 8
- One LED connected to pin 5 (with a 220Ω resistor)
- Buttons use the Arduino's internal pull-up resistors

## Wiring

- **LED** -> Pin 5 (through a 220Ω resistor)
- **Button A** -> Pin 9 (with INPUT_PULLUP)
- **Button B** -> Pin 8 (with INPUT_PULLUP)

## What I Learned

### What is pinMode and INPUT_PULLUP?

If I don't use pinMode to give the button the INPUT_PULLUP command it will randomly read HIGH or LOW based on ambient electrical noise.

What INPUT_PULLUP does is that it connects to the Arduino's internal resistor that connects that pin to 5V (HIGH). This way you can actually reliably program it.

What basically happens is that when the button isn't pressed it reads 5V (HIGH) and then when it is pressed it connects to the GND (0V) and we can use this with our digitalRead function combined with digitalWrite to set the ledPin to HIGH or LOW causing it to glow or not.

### Understanding digitalRead()

The digitalRead() function returns either HIGH (5V) or LOW (0V). In this code, when I press the button, it returns LOW, which triggers the digitalWrite() command.

## Code

```cpp
int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

byte leds = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(buttonApin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
}
```
---
<small>*Notes written by me, formatted with AI help.*</small>
