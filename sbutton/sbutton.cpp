/*
Иван Гузенков. Харьков 2020. instagramm @grabbly

При нажатии кнопки, переменная push принимает значение TRUE.
debounceDelay - время подавления дребезга и переходного процесса.
При удержании кнопки нажатой, переменная push будет менять значение с TRUE на FALSE с периодичностью debounceDelay
*/

#include "Arduino.h"
#include "sbutton.h"
void Button::scanState(){

    if (millis()-_debounceDelay>_lastDebounceTime && digitalRead(_pin) == 1)
    {
      _lastDebounceTime = millis();
      push = 1;
    }
  else push = 0;
}

void Button::setPinTime(byte pin, long debounceDelay){
  _pin = pin;
  _debounceDelay = debounceDelay;
  pinMode(_pin, INPUT);
}

Button::Button(byte pin, long debounceDelay){
  _pin = pin;
  _debounceDelay = debounceDelay;
  pinMode(_pin, INPUT);
}
