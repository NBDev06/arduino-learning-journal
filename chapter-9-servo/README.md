# Chapter 9: Servo Motor

<img width="700" height="auto" alt="IMG_20260723_153805" src="https://github.com/user-attachments/assets/6000c649-55aa-4c49-833f-c7811782eaf9" />

This is my ninth Arduino project, following along with the PDF guide. I built a circuit with a servo motor that moves to different angles.

## Circuit Overview

- One servo motor connected to pin 9
- Servo uses PWM to control its position
- The servo moves between 0° and 180°

*Note: Servos require a PWM pin (marked with ~).*

## Wiring

- **Servo Signal (Orange/Yellow)** -> Pin 9 (PWM)
- **Servo Power (Red)** -> 5V
- **Servo Ground (Brown/Black)** -> GND

## What I Learned

This project was much simpler than the previous one. I learned how to control a servo motor using the built-in Servo library. The servo can rotate to specific angles between 0° and 180°.

### Understanding the Code

#### 1. Including the Library

```cpp
#include <Servo.h>
```

I include the Servo library, which gives me access to servo control functions.

#### 2. Creating a Servo Object

```cpp
Servo myservo;
```

I create a Servo object called `myservo`. This is like creating a variable, but it's a special type that represents the physical servo.

#### 3. The Setup Function

```cpp
void setup() {
  myservo.attach(9);
  myservo.write(90);
}
```

- `myservo.attach(9)`: Attaches the servo to pin 9 on the Arduino. Pin 9 is PWM-capable, which is required for servos.
- `myservo.write(90)`: Moves the servo to 90 degrees immediately when the Arduino starts.

#### 4. The Loop Function

```cpp
void loop() {
  myservo.write(90);
  delay(1000);
  myservo.write(30);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(150);
  delay(1000);
}
```

This is a simple sequence that moves the servo through different angles:
1. Move to 90°
2. Wait 1 second
3. Move to 30°
4. Wait 1 second
5. Move to 90° 
6. Wait 1 second
7. Move to 150°
8. Wait 1 second

The `delay(1000)` gives the servo time to complete each movement before moving to the next position.

## Code

```cpp
#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(9);
  myservo.write(90);
}

void loop() {
  myservo.write(90);
  delay(1000);
  myservo.write(30);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(150);
  delay(1000);
}
```

## How It Works

The servo receives a PWM signal from pin 9. The length of the PWM pulse determines the angle the servo moves to. The Servo library handles all the timing for me, so I just need to tell it what angle I want.

The servo continuously cycles through four positions: 90° → 30° → 90° → 150°, with a 1-second pause between each movement.

## Key Takeaway

Servos are easy to control with the Servo library. I just need to attach it to a PWM pin, then use `write(angle)` to move it.

The biggest lesson from this project was learning how to use a library. The Servo library handles all the complex timing for me, so I can focus on what I want the servo to do instead of worrying about how it works internally.

**Note:** Always make sure your servo is connected to a PWM pin. The Arduino's PWM pins are marked with a ~ symbol (e.x., ~9, ~10, ~11).

---

<small>*Notes written by me, formatted with AI assistance.*</small>
