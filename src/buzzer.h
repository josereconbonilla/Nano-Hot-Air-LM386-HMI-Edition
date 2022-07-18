#ifndef _BUZZER_H_
#define _BUZZER_H_

#include <Arduino.h>
//------------------------------------------ class BUZZER ------------------------------------------------------
class BUZZER {
  public:
    BUZZER(uint8_t buzzerP) {
      buzzer_pin = buzzerP;
    }
    void init(void);
    void encoderBeep(void) {
      tone(buzzer_pin, 3520, 160);
      delay(25);
      noTone(buzzer_pin);
    }
    void shortBeep(void) {
      tone(buzzer_pin, 3520, 160);
      delay(200);
      noTone(buzzer_pin);
    }
    void lowBeep(void) {
      tone(buzzer_pin,  880, 160);
      delay(200);
      noTone(buzzer_pin);
    }
    void doubleBeep(void) {
      tone(buzzer_pin, 3520, 160);
      delay(300);
      noTone(buzzer_pin);
      delay(100);
      tone(buzzer_pin, 3520, 160);
      delay(100);
      noTone(buzzer_pin);
    }
    void failedBeep(void) {
      tone(buzzer_pin, 3520, 160);
      delay(170);
      noTone(buzzer_pin);
      delay(100);
      tone(buzzer_pin,  880, 250);
      delay(260);
      noTone(buzzer_pin);
      delay(100);
      tone(buzzer_pin, 3520, 160);
      delay(100);
      noTone(buzzer_pin);
    }
  private:
    uint8_t buzzer_pin;
};

#endif
