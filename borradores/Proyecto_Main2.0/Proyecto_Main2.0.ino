// C++ code
//

#include <LiquidCrystal_I2C.h>
const int N=2;
#define buzzer 9
int a[N];
void ImprimirArreglo();
void IngresarArreglo();
void Menu();
void ImprimirResultados();
int seconds = 10;
int k=0;

LiquidCrystal_I2C lcd_1(0x27, 16, 2);

void setup()
{
  
  lcd_1.setBacklight(1);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  lcd_1.init();
  lcd_1.clear();
  lcd_1.print(" Reloj Largador");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Ver Puerto Serie");
  Menu();
  //IngresarArreglo();
  //ImprimirArreglo();
  
  lcd_1.clear();
  lcd_1.print("Regresion: ");
  
  
}

void loop()
{
  if (k==N){
    lcd_1.clear();
    lcd_1.print(" Ver Resultados");
    ImprimirResultados();}
    
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
  delay(1000);
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
  Serial.println("\nBienvenido al menu\n1.Ingresar corredores\n2.Mostrar Lista\n3.Comenzar!\n");
  while(Serial.available()==0){;};
  String str = Serial.readStringUntil('\n');
  i = str.toInt();
  if (i==1){IngresarArreglo();}
  if (i==2){ImprimirArreglo();}
  } while(i!=3);
}

void ImprimirResultados(){
  Serial.println("\tResultados de la carrera\n\n");

while(1){;}
}
