/*
Иван Гузенков. Харьков 2020. instagramm @grabbly

При нажатии кнопки, переменная push принимает значение TRUE.
debounceDelay - время подавления дребезга и переходного процесса.
При удержании кнопки нажатой, переменная push будет менять значение с TRUE на FALSE с периодичностью debounceDelay
*/

#include <sbutton.h>
#define BUTTON_1_PIN 7              // первая кнопка на пине 7
#define BUTTON_2_PIN 8              // вторая кнопка на пине 8

byte ledState;  // просто переменная счетчик

Button button1(BUTTON_1_PIN, 300);  //создаем объект button1 класса Button с параметрами. Button button1(byte pin(физический пин), int debounceDelay(время фильтрации дребезга))
Button button2(BUTTON_2_PIN, 300);  //создаем объект button1 класса Button с параметрами. Button button1(byte pin(физический пин), int debounceDelay(время фильтрации дребезга))
void setup()
  {
    Serial.begin(9600);
  }
void loop() {
button1.scanState();    // сканируем состояние первой кнопки
button2.scanState();    // сканируем состояние второй кнопки (по отдельности для каждой новой кнопки. Пока так, я только учусь :D )
if (button1.push == true) ledState++; //если кнопка 1 нажата, прибавляем счетчик
if (button2.push == true) ledState--; //если кнопка 2 нажата, убавляем счетчик
Serial.println(ledState);
}
