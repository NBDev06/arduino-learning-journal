# Chapter 10: Ultrasonic Sensor (HC-SR04)

<img width="700" height="auto" alt="IMG_20260724_154438" src="https://github.com/user-attachments/assets/8b0756b1-e941-4d8a-819c-376068e6b8ee" />

This is my tenth Arduino project, following along with the PDF guide. I built a circuit with an ultrasonic sensor that measures distance.

## Circuit Overview

- One HC-SR04 ultrasonic sensor connected to pins 11 and 12
- The sensor sends out sound waves and measures how long they take to bounce back
- The distance is printed to the Serial Monitor

## Wiring

<img width="380" height="auto" alt="Screenshot 2026-07-24 154043" src="https://github.com/user-attachments/assets/c6feff95-41ca-4c5a-bebd-2a2b7b5b9d83" />


- **TRIG Pin** -> Pin 12
- **ECHO Pin** -> Pin 11
- **VCC** -> 5V
- **GND** -> GND

## What I Learned

This project taught me how to use an ultrasonic sensor to measure distance. The sensor sends out a sound wave and measures how long it takes to bounce back. The library handles all the complex timing for me, so I just need to read the distance.

### Understanding the Code

#### 1. Including the Library

```cpp
#include <hcsr04.h>
```

I include the HC-SR04 library, which gives me access to functions for controlling the sensor.

#### 2. Defining the Pins

```cpp
#define TRIG_PIN 12
#define ECHO_PIN 11
```

I define two variables for the pins. The TRIG pin sends out the sound wave and the ECHO pin listens for the wave to bounce back.

#### 3. Creating the Sensor Object

```cpp
HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);
```

This creates an object called `hcsr04` that represents the sensor. The numbers `20` and `4000` are timing parameters:
- `20` means the sensor will wait up to 20ms for a return signal
- `4000` sets the maximum distance to 4000mm (4 meters)

#### 4. The Setup Function

```cpp
void setup() {
  Serial.begin(9600);
}
```

I start serial communication at 9600 baud so I can see the distance readings on my computer.

#### 5. The Loop Function

```cpp
void loop() {
  Serial.println(hcsr04.distanceInMillimeters());
  delay(250);
}
```

- `hcsr04.distanceInMillimeters()`: Reads the distance from the sensor in millimeters
- `Serial.println()`: Prints the distance to the Serial Monitor
- `delay(250)`: Waits 250ms before taking the next reading

## Code

```cpp
#include <hcsr04.h>

#define TRIG_PIN 12
#define ECHO_PIN 11

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(hcsr04.distanceInMillimeters());
  delay(250);
}
```

## How It Works

The ultrasonic sensor works like a bat's echolocation. It sends out a sound wave from the TRIG pin, and the ECHO pin listens for the wave to bounce back from an object. The time it takes for the wave to return tells us how far away the object is.

The library handles all the complex timing calculations. I just tell it to measure the distance, and it returns the result in millimeters.

## Key Takeaway

I learned that ultrasonic sensors are simple to use with the right library, and an easy way to measure short distances.

I also learned how to use a library from GitHub (`jeremylindsayni`). I think this is a good skill to have since many Arduino projects use third-party libraries.

---

<small>*Notes written by me, formatted with AI assistance.*</small>
