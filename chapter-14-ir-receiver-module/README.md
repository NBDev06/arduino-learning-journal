# Chapter 14: IR Remote Control

<img width="700" height="auto" alt="IMG_20260728_121854" src="https://github.com/user-attachments/assets/ab791caa-c8d2-4b0c-82e1-9728f3902b97" />

This is my fourteenth Arduino project, following along with the PDF guide. I built a circuit with an IR receiver that detects signals from a remote control and prints the button names to the Serial Monitor.

## Circuit Overview

- One IR receiver connected to pin 11
- The receiver detects infrared signals from a remote control
- Each button on the remote sends a unique code

*Note: The IR receiver has three pins: Signal, VCC, and GND.*

## Wiring

<img width="700" height="auto" alt="Screenshot 2026-07-28 123024" src="https://github.com/user-attachments/assets/fab50103-61f7-48b1-9ed8-830493ba74e1" />

- **Signal Pin** -> Pin 11
- **VCC** -> 5V
- **GND** -> GND

## What I Learned

This project taught me how to use an IR receiver to decode signals from a remote control. I learned about hexadecimal numbers, which are used to represent the IR codes. I also learned about `uint32_t` (a 32-bit integer) and how to use a `switch-case` statement to map IR codes to button names.

**This was the most difficult project so far** because it introduced new concepts like hexadecimal numbers and a large `switch-case` structure.

### Understanding the Code

#### 1. Including the Library and Defining the Pin

```cpp
#include "IRremote.h"
int receiver = 11;
```

I include the IRremote library and define the receiver pin as pin 11.

#### 2. Creating the Receiver Object

```cpp
IRrecv irrecv(receiver);
uint32_t last_decodedRawData = 0;
```

- `IRrecv irrecv(receiver);`: Creates an IR receiver object
- `uint32_t last_decodedRawData = 0;`: Creates a 32-bit variable to store the last IR code. `uint32_t` stands for "unsigned 32-bit integer"

#### 3. The `translateIR()` Function

```cpp
void translateIR()
{
  if (irrecv.decodedIRData.flags)
  {
    irrecv.decodedIRData.decodedRawData = last_decodedRawData;
    Serial.println("REPEAT!");
  } else
  {
    Serial.print("IR code:0x");
    Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
  }

  switch (irrecv.decodedIRData.decodedRawData)
  {
    case 0xBA45FF00: Serial.println("POWER"); break;
    case 0xB847FF00: Serial.println("FUNC/STOP"); break;
    case 0xB946FF00: Serial.println("VOL+"); break;
    case 0xBB44FF00: Serial.println("FAST BACK"); break;
    case 0xBF40FF00: Serial.println("PAUSE"); break;
    case 0xBC43FF00: Serial.println("FAST FORWARD"); break;
    case 0xF807FF00: Serial.println("DOWN"); break;
    case 0xEA15FF00: Serial.println("VOL-"); break;
    case 0xF609FF00: Serial.println("UP"); break;
    case 0xE619FF00: Serial.println("EQ"); break;
    case 0xF20DFF00: Serial.println("ST/REPT"); break;
    case 0xE916FF00: Serial.println("0"); break;
    case 0xF30CFF00: Serial.println("1"); break;
    case 0xE718FF00: Serial.println("2"); break;
    case 0xA15EFF00: Serial.println("3"); break;
    case 0xF708FF00: Serial.println("4"); break;
    case 0xE31CFF00: Serial.println("5"); break;
    case 0xA55AFF00: Serial.println("6"); break;
    case 0xBD42FF00: Serial.println("7"); break;
    case 0xAD52FF00: Serial.println("8"); break;
    case 0xB54AFF00: Serial.println("9"); break;
    default:
      Serial.println(" other button   ");
  }

  last_decodedRawData = irrecv.decodedIRData.decodedRawData;
  delay(500);
}
```

This function processes the IR signal:

- First it checks if it's a repeat signal. If it is, it uses the last code instead of the new one.
- Then it prints the IR code in hexadecimal (the `0x` prefix means it's a hex number).
- The `switch-case` statement checks which button was pressed and prints the corresponding name.
- After the `switch-case`, it stores the current code for future repeat detection.
- The `delay(500)` prevents the receiver from detecting the same signal too quickly.

#### 4. The Setup Function

```cpp
void setup()
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
}
```

- `Serial.begin(9600);`: Starts serial communication
- `Serial.println("IR Receiver Button Decode");`: Prints a message to the Serial Monitor
- `irrecv.enableIRIn();`: Starts the IR receiver so it can detect signals

#### 5. The Loop Function

```cpp
void loop()
{
  if (irrecv.decode())
  {
    translateIR();
    irrecv.resume();
  }
}
```

- `irrecv.decode()`: Checks if an IR signal has been received
- `translateIR()`: Processes the signal
- `irrecv.resume()`: Tells the receiver to start listening for the next signal

## Code

```cpp
#include "IRremote.h"

int receiver = 11;

IRrecv irrecv(receiver);
uint32_t last_decodedRawData = 0;

void translateIR()
{
  if (irrecv.decodedIRData.flags)
  {
    irrecv.decodedIRData.decodedRawData = last_decodedRawData;
    Serial.println("REPEAT!");
  } else
  {
    Serial.print("IR code:0x");
    Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
  }

  switch (irrecv.decodedIRData.decodedRawData)
  {
    case 0xBA45FF00: Serial.println("POWER"); break;
    case 0xB847FF00: Serial.println("FUNC/STOP"); break;
    case 0xB946FF00: Serial.println("VOL+"); break;
    case 0xBB44FF00: Serial.println("FAST BACK"); break;
    case 0xBF40FF00: Serial.println("PAUSE"); break;
    case 0xBC43FF00: Serial.println("FAST FORWARD"); break;
    case 0xF807FF00: Serial.println("DOWN"); break;
    case 0xEA15FF00: Serial.println("VOL-"); break;
    case 0xF609FF00: Serial.println("UP"); break;
    case 0xE619FF00: Serial.println("EQ"); break;
    case 0xF20DFF00: Serial.println("ST/REPT"); break;
    case 0xE916FF00: Serial.println("0"); break;
    case 0xF30CFF00: Serial.println("1"); break;
    case 0xE718FF00: Serial.println("2"); break;
    case 0xA15EFF00: Serial.println("3"); break;
    case 0xF708FF00: Serial.println("4"); break;
    case 0xE31CFF00: Serial.println("5"); break;
    case 0xA55AFF00: Serial.println("6"); break;
    case 0xBD42FF00: Serial.println("7"); break;
    case 0xAD52FF00: Serial.println("8"); break;
    case 0xB54AFF00: Serial.println("9"); break;
    default:
      Serial.println(" other button   ");
  }

  last_decodedRawData = irrecv.decodedIRData.decodedRawData;
  delay(500);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode())
  {
    translateIR();
    irrecv.resume();
  }
}
```

## How It Works

The IR receiver detects infrared signals from the remote control. Each button on the remote sends a unique code (a hexadecimal number). The library decodes the signal, and the `switch-case` statement maps each code to a button name.

When you press a button, the code prints the button name to the Serial Monitor. If you hold down a button, it detects a repeat signal and prints "REPEAT!".

## Key Takeaway

This project taught me how to use an IR receiver with a remote control. I learned about hexadecimal numbers, `uint32_t` variables, and how to use a `switch-case` statement to map codes to actions.

**The biggest challenge** was understanding how the IR library works and what the hexadecimal codes mean. But once I understood that each button has a unique code, the rest made sense.

---

<small>*Notes written by me, formatted with AI assistance.*</small>
