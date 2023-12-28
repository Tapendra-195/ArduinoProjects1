 #include "pitches.h"

int buzzerPin = 8;

// notes in the melody: (music)
int melody[] = {
  NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_A4, 0, //JATI MAYA LAYE PANI
  NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_A4, 0, //JATI KASAM KHAYE PANI
  NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_GS4, 0, //NISTHURI LE BATO LAGDA
  NOTE_A4, NOTE_GS4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_FS4, 0, //AKHA TARI GAYE PAXI
  NOTE_E4, NOTE_FS4, NOTE_E4, NOTE_D4, 0,  NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_GS4, NOTE_A4, 0, // MANMA PIR TA PARNE NAI BHAYO 
  NOTE_A4, NOTE_A4, NOTE_GS4, NOTE_FS4, NOTE_GS4, NOTE_FS4, NOTE_GS4, NOTE_E4, NOTE_E4, 0 //YO MAN TESAI MARNE NAI BHAYO NOTE_E4
  };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
//int noteDurations[] = {  4, 8, 8, 4,4,4,4,4 };
int noteDurations[] = {  
2, 4, 2, 2, 2, 2, 2, 2, 3,  //JATI MAYA LAYE PANI, 9
2, 4, 2, 2, 2, 2, 2, 2, 3,  //JATI KASAM KHAYE PANI, 18
2, 4, 2, 2, 2, 3, 2, 2, 3,  //NISTHURI LE BATO LAGDA, 27
3, 2, 2, 4, 4, 2, 4, 2, 4,  //AKHA TARI GAYE PAXI, 36 ///
2, 4, 2, 3, 8, 2, 4, 2, 4, 3, 3, // MANMA PIR TA PARNE NAI BHAYO, 47
4, 3, 2, 2, 2, 4, 2,3, 2, 3  //YO MAN TESAI MARNE NAI BHAYO, 57
};

void setup() {
  pinMode(buzzerPin, OUTPUT);  
}

void loop() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 57; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    //int pauseBetweenNotes = noteDuration * 1.30;
    int pauseBetweenNotes = noteDuration * 1.1;//10;
    delay(pauseBetweenNotes);
  }

}
