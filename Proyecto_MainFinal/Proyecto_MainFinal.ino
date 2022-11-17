// C++ code
//
#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <LiquidCrystal_I2C.h>
#include "Largador_Carreras.h"

void setup()
{
  Serial.begin(9600);
  configuracion(); //Conf de pines, menu y lcd

}

void loop()
{
  ejecutarbarrera(); //Solo cuando todos los corredores largaron
  ejecutarcontador(); //Implementacion lcd, regresion y rtc
}
