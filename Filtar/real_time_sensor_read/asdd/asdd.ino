float xn1 = 0;
float yn1 = 0;
int k = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  //Citanje sa senzora
 float xn=analogRead(A0);
  xn = xn/1023.0*5;    //Konverzija mijenjati u zavisnosti od senzora
  
  // Filtrirani signal koeficijenti u notebooku zavisno koji hocemo
  float yn = 0.969*yn1 + 0.0155*xn + 0.0155*xn1;

  delay(1);   //Kasnjenje od jedne mili sekunde mislim vise je ako racunamo i ostalo
  xn1 = xn;
  yn1 = yn;

  if(k % 3 == 0)
    {         //na ploter da bi prikazivao >1ms zbog toga 3*
   
    //Serial.print(2*xn);
    Serial.print(" ");
    Serial.println(2*yn);
    k=0;
    }
  k = k+1;

}
  
