void buzzerlargador(void);
void setup()
{
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop()
{
 buzzerlargador();
}
void buzzerlargador(){
  for (int i=0; i<3;i++){
  tone(9, 300, 500);
  delay(1000);
  }
  tone(9, 900, 900);
  delay(1000);
}
