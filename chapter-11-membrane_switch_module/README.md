# Chapter 11: 4x4 Matrix Keypad

<img width="700" height="auto" alt="IMG_20260725_125630" src="https://github.com/user-attachments/assets/152c468e-3a85-4462-914a-cb9e72a6e516" />

This is my eleventh Arduino project, following along with the PDF guide. I built a circuit with a 4x4 matrix keypad that detects which button is pressed and prints it to the Serial Monitor.

## Circuit Overview

- One 4x4 matrix keypad connected to pins 2-9
- The keypad has 16 buttons arranged in 4 rows and 4 columns
- When a button is pressed, the Arduino detects which one and prints it to the Serial Monitor

*Note: This keypad uses a matrix arrangement to reduce the number of pins needed.*

## Wiring

<img width="700" height="auto" alt="Screenshot 2026-07-25 131433" src="https://github.com/user-attachments/assets/dd1c0e3e-01a6-412c-bd84-36bcdecab327" />

- **Keypad Pin 1** -> Pin 9 (Row 1)
- **Keypad Pin 2** -> Pin 8 (Row 2)
- **Keypad Pin 3** -> Pin 7 (Row 3)
- **Keypad Pin 4** -> Pin 6 (Row 4)
- **Keypad Pin 5** -> Pin 5 (Column 1)
- **Keypad Pin 6** -> Pin 4 (Column 2)
- **Keypad Pin 7** -> Pin 3 (Column 3)
- **Keypad Pin 8** -> Pin 2 (Column 4)

## What I Learned

This project taught me how to use a matrix keypad. A keypad uses fewer pins than a "linear" button matrix because it scans rows and columns instead of having a separate pin for each button.

I also learned about `char` and `byte` data types. `char` stores a single character, and `byte` stores a small number.

### Understanding the Code

#### 1. Including the Library

```cpp
#include <keypad.h>
```

I include the Keypad library, which gives me access to functions for controlling the keypad.

#### 2. Defining the Keypad Layout

```cpp
const byte ROWS = 4; 
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
```

- `ROWS` and `COLS` are constants that define the size of the keypad (4 rows and 4 columns)
- `hexaKeys` is a 2D array (a grid) that maps what each button on the keypad represents
- `char` is a data type that stores a single character (like `'1'`, `'A'`, or `'#'`)

#### 3. Defining the Pins

```cpp
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};
```

- `rowPins` is an array that stores which pins are connected to each row
- `colPins` is an array that stores which pins are connected to each column
- `byte` is a data type that stores a small number (0-255), which is enough for pin numbers

#### 4. Creating the Keypad Object

```cpp
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
```

This creates a Keypad object called `customKeypad`:
- `makeKeymap(hexaKeys)`: Converts the keymap into a format the library understands
- `rowPins` and `colPins`: Tell the library which pins are connected
- `ROWS` and `COLS`: Tell the library the size of the keypad

#### 5. The Setup Function

```cpp
void setup() {
  Serial.begin(9600);
}
```

I start serial communication at 9600 baud so I can see which keys are pressed on my computer.

#### 6. The Loop Function

```cpp
void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey) {
    Serial.println(customKey);
  }
}
```

- `customKeypad.getKey()`: Checks if a key is pressed. If a key is pressed, it returns that key (e.g., `'1'`, `'A'`, `'#'`). If no key is pressed, it returns `0`.
- `char customKey`: Stores the key that was pressed
- `if (customKey)`: Checks if a key was actually pressed before printing it
- `Serial.println(customKey)`: Prints the key to the Serial Monitor

## Code

```cpp
#include <keypad.h>

const byte ROWS = 4; 
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey) {
    Serial.println(customKey);
  }
}
```

## How It Works

The keypad uses a matrix scanning method. It sends a signal through each row one at a time and checks which column receives the signal. When a button is pressed, it connects a row and a column, and the Arduino knows exactly which button was pressed.

The library handles all the scanning for me. I just tell it to check for a keypress, and it returns the character that was pressed.

## Key Takeaway

Keypads are a great way to add user input to a project.

I also learned about `char` and `byte` data types, and I understood how to create and use objects from a library.

---

<small>*Notes written by me, formatted with AI assistance.*</small>
