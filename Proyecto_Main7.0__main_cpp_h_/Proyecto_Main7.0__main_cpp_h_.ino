// C++ code
//
#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <LiquidCrystal_I2C.h>
#include "Largador_Carreras.h"

void setup()
{
  Serial.begin(9600);
  configuracion();

}

void loop()
{
  ejecutarbarrera();
  ejecutarcontador();
}
