#include <LiquidCrystal.h>

const int MQ2_Pin = 8;
int MQ2_state=0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  lcd.begin(20,4);
  Serial.begin(9600);
  pinMode(MQ2_Pin, INPUT);
  lcd.setCursor(0,0);
  lcd.print("'GAS DETECTION'");
  lcd.setCursor(0,2);
  lcd.print("Don't Smoke In This");
  lcd.setCursor(0,3);
  lcd.print("Room, Please!");
  delay(1000);
}

void loop(){
  MQ2_state = digitalRead(MQ2_Pin);

  if(MQ2_state== HIGH){
    lcd.clear();
    int MQ2_SerialData=10;
    Serial.write(MQ2_SerialData);
    lcd.setCursor(0,1);
    lcd.print("GAS DETECTED");
    delay(50);
  }

  else{
    lcd.clear();
    int MQ2_SerialData=20;
    Serial.write(MQ2_SerialData);
    lcd.setCursor(0,1);
    lcd.print("NO GAS DETECTED");
    delay(50);
  }
}
