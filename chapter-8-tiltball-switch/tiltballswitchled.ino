const int ledPin = 2; // LED connected to pin 2
const int tiltPin = 3; // Tilt switch connected to pin 3

void setup() {
  pinMode(ledPin, OUTPUT); // LED as output
  pinMode(tiltPin, INPUT_PULLUP);   // Tilt switch with internal pull-up
  Serial.begin(9600); // Start Serial communication
}

void loop() {
  int tiltState = digitalRead(tiltPin); // Read the tilt switch

  if (tiltState == HIGH) {           // If tilted (open circuit)
    digitalWrite(ledPin, HIGH); // Turn LED ON
    Serial.println("Tilted → LED ON");
  } else {                          // If upright (closed circuit)
    digitalWrite(ledPin, LOW); // Turns LED OFF
    Serial.println("Upright → LED OFF");
  }

  delay(100);  // Small delay to prevent bouncing
}