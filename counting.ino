
 #include "LiquidCrystal.h"  
 LiquidCrystal lcd(5,6,7,8,9,10);  
 int irPin=2;  
 int count=0;  
 boolean state = true;  
 void setup()  
 {  
  Serial.begin(9600);  
  lcd.begin(16,2);  
  pinMode(irPin, INPUT);  
  lcd.setCursor(0,0);  
  lcd.print("Count No : ");  
 }  
 void loop()  
 {  
  if (!digitalRead(irPin) && state){  
    count++;  
    state = false;  
    Serial.print("Count: ");  
    Serial.println(count);  
    lcd.setCursor(12,0);  
    lcd.print(count);  
    delay(100);  
  }  
  if (digitalRead(irPin))  
  {  
    state = true;  
    delay(100);  
  }  
 }
