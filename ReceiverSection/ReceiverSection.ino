#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int SpeakerPin=6;
const int redLedPin=7;
#define NOTE_F4 349

void setup(){
  pinMode(SpeakerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  lcd.begin(20,4);
  Serial.begin(9600);
  lcd.setCursor(0,1);
  lcd.print("Control Room");
  lcd.setCursor(0,2);
  lcd.print("Gas Leakage");
  delay(1000);
}

void loop(){
  int MQ2_SerialData= Serial.read();;
  if(MQ2_SerialData == 10){
    lcd.clear();
    Serial.print("GAS SENSOR:");
    Serial.println(MQ2_SerialData);
    digitalWrite(redLedPin, HIGH);
    alarmSound();
    lcd.setCursor(0,1);
    lcd.print("GAS DETECTED");
    delay(50);
  }
  else if(MQ2_SerialData==20){
    lcd.clear();
    Serial.print("GAS SENSOR:");
    Serial.println(MQ2_SerialData);
    digitalWrite(redLedPin, LOW);
    lcd.setCursor(0,1);
    lcd.print("NO GAS DETECTED");
    delay(50);
  }
}

void alarmSound(){
  tone(SpeakerPin,NOTE_F4,200);
  delay(5);
}
