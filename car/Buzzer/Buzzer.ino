#include "DoReMi.h"
int melody[] = {0, Do, Re, Mi, Fa, So, La, Si, HDo};
#define Buzzer 3 //buzzer
void setup() {
  // put your setup code here, to run once:
  pinMode(Buzzer, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  tone(Buzzer, melody[5], 300);
  delay(300);
  tone(Buzzer, melody[3], 300);
  delay(300);
  tone(Buzzer, melody[3], 600);
  delay(600);
  tone(Buzzer, melody[4], 300);
  delay(300);
  tone(Buzzer, melody[2], 300);
  delay(300);
  tone(Buzzer, melody[2], 600);
  delay(600);
  tone(Buzzer, melody[1], 300);
  delay(300);
  tone(Buzzer, melody[2], 300);
  delay(300);
  tone(Buzzer, melody[3], 300);
  delay(300);
  tone(Buzzer, melody[4], 300);
  delay(300);
  tone(Buzzer, melody[5], 300);
  delay(300);
  tone(Buzzer, melody[5], 300);
  delay(300);
  tone(Buzzer, melody[5], 600);
  delay(600);
}
