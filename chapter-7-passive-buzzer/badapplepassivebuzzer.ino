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