// C++ code
//
#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <LiquidCrystal_I2C.h>
#include "Largador_Carerras.h"


LiquidCrystal_I2C lcd_1(0x27, 16, 2);
ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void setup()
{
  lcd_1.setBacklight(1);
 
  pinMode(buzzer, OUTPUT);
  pinMode(OutPin, OUTPUT);
  pinMode(analogInPin, INPUT);
  pinMode(boton, INPUT);
  
  Serial.begin(9600);
 
  Rtc.Begin();
  lcd_1.init();
  lcd_1.clear();
  lcd_1.print(" Reloj Largador");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Ver Puerto Serie");
  
  Menu();

  lcd_1.clear();
  lcd_1.print("Regresion: ");

}

void loop()
{
  if (k==N){
    int j=0;
    lcd_1.clear();
    lcd_1.print(" Ver Resultados");
    
    while(j!=N){
      sensorValue = analogRead(analogInPin);
      if(sensorValue > 900)
        {
          digitalWrite(OutPin, HIGH);
          RtcDateTime now = Rtc.GetDateTime();
          Serial.println("Ingrese el Numero del piloto que finalizo: ");
       
          while(Serial.available()==0){};
          String str = Serial.readStringUntil('\n');
          int piloto = str.toInt();
       
          Serial.print("Piloto Numero: ");Serial.print(piloto);Serial.print(" Hora de llegada: ");
          printDateTime(now);
          j++;
          delay(1000);
        }
      else
       {
          digitalWrite(OutPin, LOW);
       }
    }
    while(1){}
   }
  
  Serial.print("Piloto Numero: ");Serial.print(a[k]);Serial.print(" Hora de largada: ");
  RtcDateTime now = Rtc.GetDateTime();
  printDateTime(now);
  
  lcd_1.setCursor(0, 1);
  lcd_1.print("Corredor N: ");
  lcd_1.print(a[k]);
  lcd_1.setCursor(0, 0);
  
  for(int i=seconds; i>=0; i--){
    if (seconds>=10){
      lcd_1.setCursor(13, 0);
      lcd_1.print(seconds);
    }
    if (seconds<10){
      lcd_1.setCursor(13, 0); 
      lcd_1.print(0);
      lcd_1.setCursor(14, 0);
      lcd_1.print(seconds);
    }
  
    delay(900);
    seconds--;
 
    if (seconds<=3){
      tone(buzzer, 300, 500);
    }
    if (seconds==0){
      tone(buzzer, 900, 800);
      seconds=10;
    }
  }
  k+=1;
}
