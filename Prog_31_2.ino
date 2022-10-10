/*  ----------------------------------------------------------------
    http://www.prometec.net/display-4digitos/
    Prog_31_2
    
    Controlando un display BCD de 7 digitos
--------------------------------------------------------------------  
*/


byte Digit[10][8] =
  {  { 1,1,1,1,1,1,0,0 },    // 0
     { 0,1,1,0,0,0,0,0 },    // 1
     { 1,1,0,1,1,0,1,0 },    // 2
     { 1,1,1,1,0,0,1,0 },    // 3
     { 0,0,1,0,0,1,1,0 },    // 4    
     { 1,0,1,1,0,1,1,0 },    // 5
     { 1,0,1,1,1,1,1,0 },    // 6
     { 1,1,1,0,0,0,0,0 },    // 7
     { 1,1,1,1,1,1,1,0 },    // 8
     { 1,1,1,0,0,1,1,0 }     // 9
   };
  
void setup() 
{  for (int i= 2; i<13; i++)
       pinMode(i, OUTPUT);
}

void loop() 
{   
   //CalculaDigitos(9999 - millis()/ 100);
    int n = millis() / 1000 ;
    int segundos = n % 60  ;
    int minutos =  n / 60  ;
  
    int k = minutos * 100 + segundos ;
    CalculaDigitos(k) ;
}

void Display(int pos, int N)
{  digitalWrite(9 ,LOW);      // Apaga todos los digitos
   digitalWrite(10,LOW);
   digitalWrite(11,LOW);
   digitalWrite(12,LOW);      
  
    for (int i= 0 ; i<8 ; i++)
             digitalWrite(i+2 , Digit[N][i]) ;
  
   digitalWrite(pos + 9, HIGH); // Enciende el digito pos
   //delay(1);
}

void CalculaDigitos( int Num)
{
  int Digit0 = Num %10 ;
  int Digit1 = (Num % 100) / 10 ;
  int Digit2 = (Num % 1000) / 100 ;
  int Digit3 = Num / 1000 ;
  
  Display(3 , Digit3);
  Display(2 , Digit2);
  Display(1 , Digit1);
  Display(0 , Digit0);
}

