#include <hcsr04.h>

#define TRIG_PIN 12
#define ECHO_PIN 11

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 500);

void setup(){
    Serial.begin(9600);
}

void loop() {

    // Output the distance in mm
	Serial.println(hcsr04.distanceInMillimeters());
    delay(250);
}