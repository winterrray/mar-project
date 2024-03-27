#include <LiquidCrystal.h>// initialize the library
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
#include <Servo.h> //includes the servo library

Servo myservol;

int ir_s1 = 2;
int ir_s2 = 4;
int Space; 
int total = 3;

int flag1 = 0;
int flag2 = 0;

void setup() {
pinMode(ir_s1, INPUT);
pinMode(ir_s2, INPUT);

myservol.attach(3);
myservol.write(100);

lcd.begin(16, 2);

lcd.setCursor (0,0);
lcd.print(" Car Parking ");
lcd. setCursor (0,1);
lcd.print(" System ");
delay (2000);

lcd. clear();

Space = total;
}
void loop(){

if(digitalRead (ir_s1) == LOW && flag1==0){
if(Space>0)
{
flag1=1;
if(flag2==0){myservol.write(0); Space = Space-1;}
}
else{

lcd.setCursor(0,0);
lcd.print(" Sorry no Space ");
lcd.setCursor(2,1);
lcd.print(" Available");
delay(1000);
lcd. clear();

}

}

if(digitalRead (ir_s2) == LOW && flag2==0){flag2=1;
if(flag1==0){myservol.write(0); Space = Space+1;}
}

if(flag1==1 && flag2==1){
delay (1000);
myservol.write(100);
flag1=0, flag2-0;

}

lcd.setCursor(0,0);
lcd.print("total Space : ");
lcd.print("total");

lcd.setCursor (0,1);
lcd.print("Left Space: ");
lcd.print("Space");

}
