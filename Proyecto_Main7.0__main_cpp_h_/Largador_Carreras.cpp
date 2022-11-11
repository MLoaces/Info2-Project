#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <LiquidCrystal_I2C.h>
#include "Largador_Carerras.h"


int sensorValue = 0; 
int seconds = 10;
int k=0;
int a[N];

void IngresarArreglo(){
  
  for(int i=0; i<N; i++){
    Serial.println("Introduce un numero: ");
    while(Serial.available()==0){};
    String str = Serial.readStringUntil('\n');
    a[i] = str.toInt();
  }
}
  
void ImprimirArreglo(){
  Serial.println("La lista es: ");
  for (int i=0; i<N; i++){
    Serial.println(a[i]);
  }
  Serial.println();
}

void Menu(){
  int i=0;
  do{
    Serial.println("\nBienvenido al menu\n1.Ingresar Corredores\n2.Mostrar Lista\n3.Segundos de Regresion\n4.Guardar\n");
    while(Serial.available()==0){;};
    String str = Serial.readStringUntil('\n');
    i = str.toInt();
      
    if (i==1){IngresarArreglo();}
    if (i==2){ImprimirArreglo();}
    if (i==3){
      Serial.println("Ingresar segundos de conteo(10s Valor por defecto):\n"); 
      while(Serial.available()==0){};
      String str = Serial.readStringUntil('\n');
      seconds = str.toInt();}
    if (i==4){Serial.println("Reloj listo para comenzar, Presione el boton rojo\n"); while(analogRead(boton)>1000){;}}
      
  } while(i!=4);
}

#define countof(a) (sizeof(a) / sizeof(a[0]))
  
void printDateTime(const RtcDateTime& dt)
{
  char datestring[20];
    
  snprintf_P(datestring, 
        countof(datestring),
        PSTR("%02u:%02u:%02u"),
        dt.Hour(),
        dt.Minute(),
        dt.Second() );
  Serial.println(datestring);
  }
