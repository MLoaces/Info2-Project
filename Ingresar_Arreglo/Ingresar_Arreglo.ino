const int N=5;
int a[N];
void ImprimirArreglo();
void IngresarArreglo();
void setup()
{
  Serial.begin(9600);
    IngresarArreglo();
    ImprimirArreglo();
}

void loop()
{
 
}
void IngresarArreglo(){

  for(int i=0; i<N; i++){
    Serial.println("Introduce un numero: ");
   while(Serial.available()<=0){};
    a[i]=Serial.parseInt();
  }
}
void ImprimirArreglo(){
  Serial.println("Los numeros son: ");
  for (int i=0; i<N; i++){
    Serial.println(a[i]);
  }
  Serial.println();
}
