# Chapter 6: Active Buzzer

<img width="700" height="auto" alt="IMG_20260720_153710" src="https://github.com/user-attachments/assets/37a1f52b-f75c-4358-81e3-9c07646cc6eb" />

This is my sixth Arduino project, following along with the PDF guide. I built a circuit with an active buzzer that makes different beeping patterns.

## Circuit Overview

- One active buzzer connected to pin 12
- Anode (positive) -> Pin 12
- Cathode (negative) -> GND

## Wiring

- **Buzzer Anode (+)** -> Pin 12
- **Buzzer Cathode (-)** -> GND

## What I Learned

This project was very simple. The main goal was to understand how to control an active buzzer using `digitalWrite()` and `delay()`.

### Understanding the Code

I start by defining the variable `buzzer` and connecting it to pin 12 on the Arduino:

```cpp
int buzzer = 12;
```

In the `setup()` function, I set the buzzer pin to OUTPUT so it can send voltage to the buzzer:

```cpp
void setup()
{
  pinMode(buzzer, OUTPUT);
}
```

### The Loop Logic

Inside `void loop()`, I define a variable called `sound_duration` and set it to 500ms. Then I create a `for` loop with a counter variable `i` that increases by 1 each time and counts to 20 times.

The `for` loop checks the value of `i`:
- If `i < 5`, the sound duration is 500ms
- Else if `i < 10`, the sound duration is 300ms
- Else if `i < 20`, the sound duration is 100ms

This makes the beeps get faster as the variable increases.

After the `for` loop determines the duration, I use:

```cpp
digitalWrite(buzzer, HIGH);
delay(sound_duration);
digitalWrite(buzzer, LOW);
delay(sound_duration);
```

This turns the buzzer ON (HIGH) for the duration, then OFF (LOW) for the same duration. This creates a rhythmic pattern of beeps. 

### The Final Long Beep

After the `for` loop finishes running 20 times, the code exits the loop and runs:

```cpp
digitalWrite(buzzer, HIGH);
delay(5000);
```

This plays a single long continuous beep for 5000ms (5 seconds). After that, `void loop()` restarts from the beginning and the whole pattern repeats.

## Code

```cpp
int buzzer = 12;

void setup()
{
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  int sound_duration = 500;
  
  for (int i = 0; i < 20; i++)
  {
    if (i < 5)
    {
      sound_duration = 500;
    } 
    else if (i < 10)
    {
      sound_duration = 300;
    } 
    else if (i < 20)
    {
      sound_duration = 100;
    }
    
    digitalWrite(buzzer, HIGH);
    delay(sound_duration);
    digitalWrite(buzzer, LOW);
    delay(sound_duration);
  }
  
  digitalWrite(buzzer, HIGH);
  delay(5000);
}
```
---

<small>*Notes written by me, formatted with AI assistance.*</small>
