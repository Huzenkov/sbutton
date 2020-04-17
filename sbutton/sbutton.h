/*
Иван Гузенков. Харьков 2020. instagramm @grabbly

При нажатии кнопки, переменная push принимает значение TRUE.
debounceDelay - время подавления дребезга и переходного процесса.
При удержании кнопки нажатой, переменная push будет менять значение с TRUE на FALSE с периодичностью debounceDelay
*/
#ifndef sbutton_h
#define sbutton_h
#include "Arduino.h"

class Button{
  public:
    Button(byte pin, long debounceDelay);
    bool push;
    void scanState();
    void setPinTime(byte pin,long debounceDelay);
  private:
    long _lastDebounceTime;
    long _debounceDelay;
    byte _pin;
};
#endif
