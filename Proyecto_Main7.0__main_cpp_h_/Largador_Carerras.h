#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <LiquidCrystal_I2C.h>

#define boton A5
#define buzzer 9
#define analogInPin A1
#define OutPin 13
#define N 2

void ImprimirArreglo();
void IngresarArreglo();
void Menu();
void printDateTime(const RtcDateTime& dt);
