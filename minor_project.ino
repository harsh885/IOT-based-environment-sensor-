#include <LiquidCrystal.h>

const int rs = 11, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 

//rs,en,d4,d5,d6,d7 are the user defined variables which stored constant int value connected to the digital part in Arduino.

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float temp;
float sensorValue;

//In Arduino, Analog Input Pins has 6 pins named A0 to A5 while Digital Output Pins have 14 pins numbered 0 to 13.

int tem= A0; //Temperature sensor is connected to Analog Part in Arduino(A0)
int led=12; //LED is connected to Digital part in Arduino(12)
int buzzer=8;
int gas=A1;
void setup()
{
  lcd.begin(16,2); //16*2 LED display
  
  //PinMode Syntax: pinMode(pin, mode)
  
  pinMode(led,OUTPUT); //LED and Buzzer are Output
  pinMode(buzzer,OUTPUT);
  pinMode(gas,INPUT); //Gas and Temperature are taking Input
  pinMode(tem,INPUT);
}
void loop()
{
  sensorValue=analogRead(gas); //Reads the value from the specified analog pin i.e Gas
  temp = analogRead(A0);
  temp=temp*0.48828125; // {temp*(+Vcc*1000/1024)/10}= Each voltage step required by a bit. Vcc is Supply voltage i.e. 5V.
  lcd.print("TEMP= "); 
  lcd.setCursor(6,0); //setCursor Syntax:1 setCursor(column, row)
  lcd.print(temp);
  lcd.setCursor(10,0);
  lcd.print("*C");
  lcd.setCursor(0,1);
  lcd.print("GAS=");
  lcd.setCursor(5,1);
  lcd.print(sensorValue);

  if(temp>40)
  {
   
    digitalWrite(led,HIGH); //Syntax: digitalWrite(pin,value). If voltage is 5V, value is HIGH and if it is 0V then LOW. 
    tone(buzzer,1000,200); //Syntax: tone(pin, freuency, duration(ms))
    lcd.clear();
    delay(100); //time in miliseconds
    lcd.write("Danger");  
  }
  if(sensorValue>250)
   {
    digitalWrite(led,HIGH);
    lcd.clear();
    delay(100);
    lcd.print("Smoke Detected!=");
    tone(buzzer,1000,200);
   }
  delay(500);
  lcd.clear();
   
}
