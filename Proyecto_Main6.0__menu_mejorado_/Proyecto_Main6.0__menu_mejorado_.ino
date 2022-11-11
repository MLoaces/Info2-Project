// C++ code
//
#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <LiquidCrystal_I2C.h>
#define boton A5
#define buzzer 9
#define analogInPin A1
#define OutPin 13
#define N 2

int sensorValue = 0; 
int seconds = 10;
int k=0;
int a[N];

void ImprimirArreglo();
void IngresarArreglo();
void Menu();

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
