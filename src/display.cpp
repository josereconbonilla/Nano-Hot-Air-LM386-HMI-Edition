#include <Arduino.h>
#include "display.h"
#include "vars.h"

//------------------------------------------ class lcd DSPLay for soldering IRON -----------------------------
void DSPL::init(void) {
  SoftwareSerial::begin(9600);
  //  delay(100);
}

void DSPL::clear(void) {
  SoftwareSerial::println(F("page 1"));
  //  delay(10);
  SoftwareSerial::println(F("number0.val=888"));
  //  delay(10);
  SoftwareSerial::println(F("number1.val=888"));
  //  delay(10);
  SoftwareSerial::println(F("number2.val=0"));
  //  delay(10);
  SoftwareSerial::println(F("number3.val=0"));
  //  delay(10);
  SoftwareSerial::println(F("textBox0.txt=\"BUSY\""));
  //  delay(10);

}

void DSPL::screenMode(uint16_t t) {
  if (t == 0) {
    SoftwareSerial::println(F("number0.backc=65504"));
    //    delay(10);
    SoftwareSerial::println(F("number2.backc=2016"));
    //    delay(10);
  } else {
    SoftwareSerial::println(F("number0.backc=2016"));
    //    delay(10);
    SoftwareSerial::println(F("number2.backc=65504"));
    //    delay(10);
  }

}

void DSPL::tSet(uint16_t t) {
  SoftwareSerial::print(F("number0.val="));
  SoftwareSerial::println(t);
}

void DSPL::tCurr(uint16_t t) {
  if (t < 1000) {
    SoftwareSerial::print(F("number1.val="));
    SoftwareSerial::println(t);
  } else {
    SoftwareSerial::print(F("number1.val=0"));
    return;
  }
}

void DSPL::tInternal(uint16_t t) {
  if (t < 1023) {
    SoftwareSerial::print(F("number1.val="));
    SoftwareSerial::println(t);
  } else {
    SoftwareSerial::print(F("number1.val=0"));
    return;
  }
}

void DSPL::calibScreen(void) {
  SoftwareSerial::println(F("page 3"));
  //  delay(10);
}

void DSPL::calibReady(bool on) {
  if (on) {
    msgReady();
  }
}

void DSPL::fanSpeed(uint16_t s) {
  uint8_t p;
  p = map(s, min_fan_speed, max_fan_speed, 0, 100);
  p = constrain(p, 0, 100);
  SoftwareSerial::print(F("number2.val="));
  SoftwareSerial::println(p);
}

void DSPL::appliedPower(uint8_t p, bool show_zero) {

  if (p > 99) p = 99;
  if (p == 0 && !show_zero) {
    SoftwareSerial::print(F("number3.val=0"));
  } else {
    SoftwareSerial::print(F("number3.val="));
    SoftwareSerial::println(p);
  }
}

void DSPL::setupMode(byte mode) {
  SoftwareSerial::println(F("page 2"));
  //  delay(10);
  switch (mode) {
    case 0: // tip calibrate
      SoftwareSerial::println(F("picBox2.pic=7"));
      //      delay(10);
      break;
    case 1: // tune
      SoftwareSerial::println(F("picBox2.pic=8"));
      //      delay(10);
      break;
    case 2: // save
      SoftwareSerial::println(F("picBox2.pic=10"));
      //      delay(10);
      break;
    case 3: // cancel
      SoftwareSerial::println(F("picBox2.pic=11"));
      //      delay(10);
      break;
    case 4: // set defaults
      SoftwareSerial::println(F("picBox2.pic=9"));
      //      delay(10);
      break;
    default:
      break;
  }
}

void DSPL::msgON(void) {
  SoftwareSerial::println(F("textBox0.txt=\"ON\""));
  //  delay(10);
}

void DSPL::msgOFF(void) {
  SoftwareSerial::println(F("textBox0.txt=\"OFF\""));
  //  delay(10);
}


void DSPL::msgReady(void) {
  SoftwareSerial::println(F("textBox0.txt=\"RDY\""));
  //  delay(10);
}

void DSPL::msgCold(void) {
  SoftwareSerial::println(F("textBox0.txt=\"COLD\""));
  //  delay(10);
}

void DSPL::msgFail(void) {
  SoftwareSerial::println(F("number2.val=888"));
  //  delay(10);
  SoftwareSerial::println(F("number3.val=888"));
  //  delay(10);
  SoftwareSerial::println(F("textBox0.txt=\"FAIL\""));
  //  delay(10);
}

void DSPL::msgTune(void) {
  SoftwareSerial::println(F("page 4"));
  //  delay(10);
}
