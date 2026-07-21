# Chapter 7: Playing Melodies with a Passive Buzzer (Bad Apple)

<img width="700" height="auto" alt="IMG_20260721_144431" src="https://github.com/user-attachments/assets/d8c139f5-4dbd-48bf-9f1c-44803e9c4532" />


This is my seventh Arduino project, following along with the PDF guide. I built a circuit with a passive buzzer that plays the first ~30 seconds of "Bad Apple" from Touhou.

## Circuit Overview

- One passive buzzer connected to pin 8
- Pin 8 (signal) -> Buzzer positive
- GND -> Buzzer negative

*Note: Passive buzzers are not polarized, so polarity doesn't matter.*

## Wiring

- **Buzzer Signal** -> Pin 8
- **Buzzer GND** -> GND

## What I Learned

This project was the most complex one so far. I learned how to use the `tone()` function to play specific frequencies, how to structure arrays of notes and durations, and how tempo and note timing work together.

### Understanding the Code

#### 1. Including the Pitches Library

```cpp
#include "pitches.h"
```

This includes the `pitches.h` library which has all the note definitions (like `NOTE_C4`, `NOTE_D4`, etc.).

#### 2. Defining the Buzzer Pin

```cpp
#define BUZZER_PIN 8
```

This defines the variable `BUZZER_PIN` and connects it to pin 8 on the Arduino.

#### 3. Setting the Tempo

```cpp
int tempo = 138;
int wholenote = (60000 * 4) / tempo;
```

I create two variables. The first is `tempo` which is set to 138 beats per minute. The second is `wholenote` which calculates how long a whole note should be in milliseconds. The formula is `(60000 * 4) / tempo`. 60,000ms in a minute, multiplied by 4 beats per whole note, divided by the tempo.

#### 4. The Melody Array

```cpp
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_G4, 0, NOTE_C5, ...
};
```

This is a list (array) of all the notes that will be played. The numbers correspond to specific frequencies that the buzzer will output. The `0` represents a rest (silence).

#### 5. The Durations Array

```cpp
int durations[] = {
  8, 8, 8, 8, -8, 16, 8, 8, 4, ...
};
```

This is a list (array) of how long each note should be played. Each duration corresponds to the note at the same position in the `melody` array.
- Positive numbers (e.g., `8`) = regular note (eighth note)
- Negative numbers (e.g., `-8`) = dotted note (lasts 1.5x longer)

### The Loop Logic

#### 1. Counting the Notes

```cpp
int noteCount = sizeof(melody) / sizeof(melody[0]);
```

This calculates how many notes are in the `melody` array. `sizeof(melody)` returns the total bytes of the array, and `sizeof(melody[0])` returns the bytes of one single note. Dividing them gives the total number of notes.

#### 2. The For Loop

```cpp
for (int thisNote = 0; thisNote < noteCount; thisNote++) {
  // Code runs for each note
}
```

This loop runs once for every note in the song. `thisNote` starts at 0 and increases by 1 until it reaches the total note count.

#### 3. Calculating Note Duration

```cpp
int noteDuration = (durations[thisNote] > 0) 
  ? (wholenote / durations[thisNote]) 
  : (wholenote / abs(durations[thisNote]) * 1.5);
```

This uses a ternary operator (a shorthand `if` / `else` statement):
- If the duration is positive (regular note): use `wholenote / durations[thisNote]`
- If the duration is negative (dotted note): use `wholenote / abs(durations[thisNote]) * 1.5`

Dotted notes are 1.5 times longer than regular notes, so the `1.5` multiplier handles that.

#### 4. Playing the Note

```cpp
if (melody[thisNote] != 0) {
  tone(BUZZER_PIN, melody[thisNote], noteDuration * 0.9);
}
```

If the note is not a rest (0), the `tone()` function is called. It takes three arguments:
1. The pin (8)
2. The note (frequency from the `melody` array)
3. The duration (90% of the full note duration)

The `0.9` multiplier creates a tiny 10% gap between notes. This is called **articulation** and stops the notes from blending together and sounding muddy.

#### 5. Timing and Silence

```cpp
delay(noteDuration);
noTone(BUZZER_PIN);
```

`delay(noteDuration)` lets the full note play before moving to the next one. `noTone(BUZZER_PIN)` stops the buzzer from making sound so it can prepare for the next note.

#### 6. The Final Pause

```cpp
delay(2000);
```

After the song finishes, there is a 2-second pause before the song repeats.

## Code

```cpp
// Bad Apple!! (Touhou) - First ~30 seconds for passive buzzer
#include "pitches.h"

#define BUZZER_PIN 8

// Tempo
int tempo = 138;
int wholenote = (60000 * 4) / tempo;

// Notes (REST replaced with 0)
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_G4, 0, NOTE_C5, NOTE_AS4, NOTE_G4, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_G4,
  NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_G4, 0, NOTE_C5, NOTE_AS4, NOTE_G4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_D4, 0, NOTE_DS4, NOTE_F4, 0, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_F5,
  NOTE_G5, NOTE_C6, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_F5, NOTE_G5, NOTE_C6, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_F5, NOTE_G5,
  NOTE_F5, NOTE_DS5, NOTE_D5, 0, NOTE_DS5, NOTE_F5, NOTE_G5,

  // Start of chorus
  NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_F5, NOTE_G5, NOTE_C5
};

// Durations: 4 = quarter, 8 = eighth, -8 = dotted eighth, etc.
int durations[] = {
  8, 8, 8, 8, -8, 16, 8, 8, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 4,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, -8, 16, 8, 8, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 4,
  8, 8, 8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 4, 4,

  // Chorus start
  8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int noteCount = sizeof(melody) / sizeof(melody[0]);

  for (int thisNote = 0; thisNote < noteCount; thisNote++) {
    int noteDuration = (durations[thisNote] > 0) 
      ? (wholenote / durations[thisNote]) 
      : (wholenote / abs(durations[thisNote]) * 1.5);

    if (melody[thisNote] != 0) {
      tone(BUZZER_PIN, melody[thisNote], noteDuration * 0.9);
    }

    delay(noteDuration);
    noTone(BUZZER_PIN);
  }

  delay(2000);  // Pause before repeating
}
```

## How It Works

The Arduino reads through the `melody` and `durations` arrays simultaneously. For each note, it calculates how long it should play, sends the correct frequency to the buzzer, waits for the note to finish, then moves to the next note. Once all notes are played, it waits 2 seconds and repeats.

## Key Takeaway

This project taught me that the `tone()` function can create specific frequencies on any digital pin, not just PWM pins. By combining arrays of notes and durations, you can program an Arduino to play entire songs. The ternary operator (`? :`) was also new to me and is a useful shorthand for `if` / `else` statements.

---

<small>*Notes written by me, formatted with AI assistance. AI was also used to create the melody.*</small>
