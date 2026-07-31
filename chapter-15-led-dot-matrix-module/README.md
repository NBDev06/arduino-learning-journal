# Chapter 15: 8x8 LED Matrix

<img width="700" height="auto" alt="IMG_20260731_103150" src="https://github.com/user-attachments/assets/85e06c9d-c40b-4394-9343-7302f08b9f7b" />

This is my fifteenth Arduino project, following along with the PDF guide. I built a circuit with an 8x8 LED matrix that displays characters and animations.

## Circuit Overview

- One 8x8 LED matrix connected to pins 10, 11, and 12
- The display has 64 LEDs arranged in 8 rows and 8 columns
- The display can show characters, numbers, and simple animations

*Note: The LED matrix uses the MAX7219 driver IC.*

## Wiring

<img width="700" height="auto" alt="Screenshot 2026-07-31 104516" src="https://github.com/user-attachments/assets/dda0b75a-7115-4e4f-8904-f61b14894f3d" />

- **DATA (DataIn)** -> Pin 12
- **CLK** -> Pin 10
- **CS (LOAD)** -> Pin 11
- **VCC** -> 5V
- **GND** -> GND

## What I Learned

This project taught me how to use an 8x8 LED matrix. I learned about the MAX7219 driver IC, how to use binary numbers to represent LED patterns, and how to create characters using arrays.

### Understanding the Code

#### 1. Including the Library

```cpp
#include "LedControl.h"
```

I include the LedControl library, which gives me access to functions for controlling the LED matrix.

#### 2. Creating the Display Object

```cpp
LedControl lc = LedControl(12, 10, 11, 1);
```

This creates a LedControl object called `lc`:
- `12`: Data pin (sends the actual data)
- `10`: Clock pin (synchronizes data transfer)
- `11`: Chip Select pin (selects the display)
- `1`: Number of MAX72XX devices connected (I have 1 display)

#### 3. The Setup Function

```cpp
void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}
```

- `lc.shutdown(0, false)`: Wakes up the display from power-saving mode
- `lc.setIntensity(0, 8)`: Sets the brightness to a medium value (0-15)
- `lc.clearDisplay(0)`: Clears the display

#### 4. Creating Characters with Binary

```cpp
byte a[5] = {
  B01111110,  // Row 1:  0 1 1 1 1 1 1 0
  B10001000,  // Row 2:  1 0 0 0 1 0 0 0
  B10001000,  // Row 3:  1 0 0 0 1 0 0 0
  B10001000,  // Row 4:  1 0 0 0 1 0 0 0
  B01111110   // Row 5:  0 1 1 1 1 1 1 0
};
```

The `B` prefix means binary. Each byte represents one row of the LED matrix. A `1` means the LED is ON and a `0` means it's OFF.

#### 5. Displaying a Character

```cpp
lc.setRow(0, 0, a[0]);
lc.setRow(0, 1, a[1]);
lc.setRow(0, 2, a[2]);
lc.setRow(0, 3, a[3]);
lc.setRow(0, 4, a[4]);
```

`lc.setRow(0, 0, a[0])` sets row 0 of display 0 to the first byte of the "A" array.

#### 6. Animation Functions

The code has three animation functions:
- `rows()`: Lights up rows with a blinking pattern
- `columns()`: Lights up columns with a blinking pattern
- `single()`: Lights up individual LEDs one by one

These use nested loops to create interesting patterns on the display.

#### 7. The Loop Function

```cpp
void loop() {
  writeArduinoOnMatrix();
  rows();
  columns();
  single();
}
```

The loop runs four things in sequence:
1. Displays "Arduino" on the matrix
2. Runs the row animation
3. Runs the column animation
4. Runs the single LED animation

## Code

```cpp
#include "LedControl.h"

LedControl lc = LedControl(12, 10, 11, 1);

unsigned long delaytime1 = 500;
unsigned long delaytime2 = 50;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void writeArduinoOnMatrix() {
  byte a[5] = {B01111110, B10001000, B10001000, B10001000, B01111110};
  byte r[5] = {B00010000, B00100000, B00100000, B00010000, B00111110};
  byte d[5] = {B11111110, B00010010, B00100010, B00100010, B00011100};
  byte u[5] = {B00111110, B00000100, B00000010, B00000010, B00111100};
  byte i[5] = {B00000000, B00000010, B10111110, B00100010, B00000000};
  byte n[5] = {B00011110, B00100000, B00100000, B00010000, B00111110};
  byte o[5] = {B00011100, B00100010, B00100010, B00100010, B00011100};

  lc.setRow(0, 0, a[0]);
  lc.setRow(0, 1, a[1]);
  lc.setRow(0, 2, a[2]);
  lc.setRow(0, 3, a[3]);
  lc.setRow(0, 4, a[4]);
  delay(delaytime1);
  
  lc.setRow(0, 0, r[0]);
  lc.setRow(0, 1, r[1]);
  lc.setRow(0, 2, r[2]);
  lc.setRow(0, 3, r[3]);
  lc.setRow(0, 4, r[4]);
  delay(delaytime1);
  
  lc.setRow(0, 0, d[0]);
  lc.setRow(0, 1, d[1]);
  lc.setRow(0, 2, d[2]);
  lc.setRow(0, 3, d[3]);
  lc.setRow(0, 4, d[4]);
  delay(delaytime1);
  
  lc.setRow(0, 0, u[0]);
  lc.setRow(0, 1, u[1]);
  lc.setRow(0, 2, u[2]);
  lc.setRow(0, 3, u[3]);
  lc.setRow(0, 4, u[4]);
  delay(delaytime1);
  
  lc.setRow(0, 0, i[0]);
  lc.setRow(0, 1, i[1]);
  lc.setRow(0, 2, i[2]);
  lc.setRow(0, 3, i[3]);
  lc.setRow(0, 4, i[4]);
  delay(delaytime1);
  
  lc.setRow(0, 0, n[0]);
  lc.setRow(0, 1, n[1]);
  lc.setRow(0, 2, n[2]);
  lc.setRow(0, 3, n[3]);
  lc.setRow(0, 4, n[4]);
  delay(delaytime1);
  
  lc.setRow(0, 0, o[0]);
  lc.setRow(0, 1, o[1]);
  lc.setRow(0, 2, o[2]);
  lc.setRow(0, 3, o[3]);
  lc.setRow(0, 4, o[4]);
  delay(delaytime1);
  
  lc.setRow(0, 0, 0);
  lc.setRow(0, 1, 0);
  lc.setRow(0, 2, 0);
  lc.setRow(0, 3, 0);
  lc.setRow(0, 4, 0);
  delay(delaytime1);
}

void rows() {
  for(int row = 0; row < 8; row++) {
    delay(delaytime2);
    lc.setRow(0, row, B10100000);
    delay(delaytime2);
    lc.setRow(0, row, (byte)0);
    for(int i = 0; i < row; i++) {
      delay(delaytime2);
      lc.setRow(0, row, B10100000);
      delay(delaytime2);
      lc.setRow(0, row, (byte)0);
    }
  }
}

void columns() {
  for(int col = 0; col < 8; col++) {
    delay(delaytime2);
    lc.setColumn(0, col, B10100000);
    delay(delaytime2);
    lc.setColumn(0, col, (byte)0);
    for(int i = 0; i < col; i++) {
      delay(delaytime2);
      lc.setColumn(0, col, B10100000);
      delay(delaytime2);
      lc.setColumn(0, col, (byte)0);
    }
  }
}

void single() {
  for(int row = 0; row < 8; row++) {
    for(int col = 0; col < 8; col++) {
      delay(delaytime2);
      lc.setLed(0, row, col, true);
      delay(delaytime2);
      for(int i = 0; i < col; i++) {
        lc.setLed(0, row, col, false);
        delay(delaytime2);
        lc.setLed(0, row, col, true);
        delay(delaytime2);
      }
    }
  }
}

void loop() {
  writeArduinoOnMatrix();
  rows();
  columns();
  single();
}
```

## How It Works

The LED matrix uses the MAX7219 driver IC, which controls all 64 LEDs. The LedControl library sends data to the driver over three pins: Data, Clock, and Chip Select.

Characters are defined as arrays of binary numbers, where each bit represents one LED. A `1` means ON and `0` means OFF.

## Key Takeaway

This project taught me how to use an LED matrix. I learned about binary representation, arrays, and how to use a driver IC to control many LEDs with just a few pins.

I also learned that the `B` prefix means binary, and that each byte represents one row of the display.

---

<small>*Notes written by me, formatted with AI assistance.*</small>
