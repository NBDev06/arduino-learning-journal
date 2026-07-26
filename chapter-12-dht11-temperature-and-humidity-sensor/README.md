# Chapter 12: DHT11 Temperature and Humidity Sensor

<img width="700" height="auto" alt="IMG_20260726_104042" src="https://github.com/user-attachments/assets/b0622015-213f-45e7-91e0-32f25a5fcf7d" />

This is my twelfth Arduino project, following along with the PDF guide. I built a circuit with a DHT11 sensor that measures temperature and humidity and prints the readings to the Serial Monitor.

## Circuit Overview

- One DHT11 temperature and humidity sensor connected to pin 2
- The sensor measures both temperature and humidity
- The readings are printed to the Serial Monitor every few seconds

*Note: The DHT11 uses a single data pin for communication.*

## Wiring

<img width="700" height="auto" alt="Screenshot 2026-07-26 111432" src="https://github.com/user-attachments/assets/88de947f-9d2f-4b9b-b3a5-4e230ce0500b" />

- **DATA Pin** -> Pin 2
- **VCC** -> 5V
- **GND** -> GND

## What I Learned

This project taught me how to use a DHT11 temperature and humidity sensor. I learned about different data types like `bool`, `float`, and `static`. I also learned about pointers and references, which are used to pass variables to functions so they can be modified.

**I did struggle with understanding pointers at first.** It was confusing trying to understand what `*` and `&` actually do. But after discussing it with someone and working through the code, I finally understood it.

Here's how I understand it now:

```cpp
int x = 10;          // Create a variable x with value 10
int *ptr = &x;       // Create a pointer that holds the address of x
printf("%d\n", *ptr); // Go to that address and print the value → prints 10
```

The `*` is used to declare a pointer and also to go to the address it holds. The `&` gives the address of a variable.

In my code, the function `measure_environment` uses `float *temperature` and `float *humidity` as parameters. When I call it with `&temperature` and `&humidity`, I'm passing the addresses of my variables. The function then uses those addresses to store the measured values directly into them.

That's all it is. It felt complicated at first, but now I get it.

### Understanding the Code

#### 1. Including the Library and Defining the Sensor

```cpp
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
```

I include the DHT library and define the sensor type as DHT11.

#### 2. Defining the Pin and Creating the Sensor Object

```cpp
static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
```

- `static const int DHT_SENSOR_PIN = 2;`: Creates a constant for pin 2
- `DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);`: Creates a sensor object

#### 3. The Setup Function

```cpp
void setup( )
{
  Serial.begin( 9600);
}
```

I start serial communication at 9600 baud so I can see the readings on my computer.

#### 4. The Measurement Function

```cpp
static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }
  return( false );
}
```

This function is more advanced than what I've seen before. Here's what I understood:

- `bool`: The function returns either `true` or `false` to tell us if the measurement was successful
- `float *temperature` and `float *humidity`: These are pointers. The function uses them to fill in the temperature and humidity values directly into the variables I pass in
- `static unsigned long measurement_timestamp = millis( );`: This keeps track of when we last measured. The `static` keyword makes it remember the value between function calls
- `millis( ) - measurement_timestamp > 3000ul`: Checks if 3 seconds (3000ms) have passed since the last measurement
- `dht_sensor.measure( temperature, humidity )`: Tries to measure the temperature and humidity
- `return( true )`: Returns true if the measurement was successful
- `return( false )`: Returns false if it hasn't been 3 seconds yet or if the measurement failed

#### 5. The Loop Function

```cpp
void loop( )
{
  float temperature;
  float humidity;

  if( measure_environment( &temperature, &humidity ) == true )
  {
    Serial.print( "T = " );
    Serial.print( temperature, 1 );
    Serial.print( " deg. C, H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
  }
}
```

- `float temperature;` and `float humidity;`: Create two variables to store the readings
- `measure_environment( &temperature, &humidity )`: Calls the measurement function and passes the addresses of the temperature and humidity variables. The `&` means "the address of"
- `Serial.print( temperature, 1 );`: Prints the temperature with 1 decimal place
- `Serial.println( "%" );`: Prints the humidity with 1 decimal place and adds a new line

## Code

```cpp
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void setup( )
{
  Serial.begin( 9600);
}

static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }
  return( false );
}

void loop( )
{
  float temperature;
  float humidity;

  if( measure_environment( &temperature, &humidity ) == true )
  {
    Serial.print( "T = " );
    Serial.print( temperature, 1 );
    Serial.print( " deg. C, H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
  }
}
```

## How It Works

The DHT11 sensor measures temperature and humidity every 3 seconds. The `measure_environment` function checks if it's time to measure, takes the measurement if it is, and updates the variables with the new values. The readings are then printed to the Serial Monitor.

## Key Takeaway

This project taught me about more advanced concepts like `bool`, `float`, `static`, and pointers. I learned that pointers and references allow functions to modify variables that are passed to them.

**The biggest challenge was understanding pointers.** At first, the `*` and `&` symbols were really confusing. But after breaking it down step by step, I finally got it. Now I understand that the function can take the addresses of my variables and put values directly into them. This lets the function "return" two values (temperature and humidity) even though a function can only officially return one thing.

---

<small>*Notes written by me, formatted with AI assistance.*</small>
