// C++ code
//
#include <Adafruit_LiquidCrystal.h>
const int N=3;
#define buzzer 9
int a[N];
void ImprimirArreglo();
void IngresarArreglo();
void Menu();
void ImprimirResultados();
int seconds = 10;
int k=0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  lcd_1.print(" Reloj Largador");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Ver Puerto Serie");
  Menu();
  //IngresarArreglo();
  //ImprimirArreglo();
  
  lcd_1.begin(16, 2);
  lcd_1.print("Regresion: ");
  
  
}

void loop()
{
  lcd_1.setCursor(0, 1);
  lcd_1.print("Corredor N: ");
  lcd_1.print(a[k]);
  lcd_1.setCursor(0, 0);
  for(int i=10; i>=0; i--){
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
  lcd_1.setBacklight(1);
  delay(500); // Wait for 500 millisecond(s)
  lcd_1.setBacklight(0);
  delay(500);

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
  if (k==N){
    lcd_1.begin(16, 2);
    lcd_1.print(" Ver Resultados");
    ImprimirResultados();}
}

void IngresarArreglo(){

  for(int i=0; i<N; i++){
    Serial.println("Introduce un numero: ");
   while(Serial.available()<=0){};
    a[i]=Serial.parseInt();
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
  Serial.println("\nBienvenido al menu\n1.Ingresar corredores\n2.Mostrar Lista\n3.Comenzar!\n");
  while(Serial.available()<=0){};
  i=Serial.parseInt();
  if (i==1){IngresarArreglo();}
  if (i==2){ImprimirArreglo();}
  } while(i!=3);
}

void ImprimirResultados(){
  Serial.println("\tResultados de la carrera\n\n");

}
