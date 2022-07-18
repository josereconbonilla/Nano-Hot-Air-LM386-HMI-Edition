#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <stdint.h>
#include <Wire.h>
#include <SoftwareSerial.h>
//------------------------------------------ class lcd DSPLay for soldering IRON -----------------------------
class DSPL : protected SoftwareSerial {
  public:
    DSPL(void) : SoftwareSerial (A2, A3) { }
    virtual ~DSPL() { }
    void init(void);
    void clear(void);
    void screenMode(uint16_t t);
    void calibScreen(void);
    void tSet(uint16_t t); // Show the preset temperature
    void tCurr(uint16_t t); // Show the current temperature
    void tInternal(uint16_t t); // Show the current temperature in internal units
    void calibReady(bool on);
    void tReal(uint16_t t); // Show the real temperature in Celsius in calibrate mode
    void fanSpeed(uint16_t s); // Show the fan speed
    void appliedPower(uint8_t p, bool show_zero = true); // Show applied power (%)
    void setupMode(uint8_t mode);
    void msgON(void); // Show message: "ON"
    void msgOFF(void);
    void msgReady(void);
    void msgCold(void);
    void msgFail(void); // Show 'Fail' message
    void msgTune(void); // Show 'Tune' message
};

#endif
