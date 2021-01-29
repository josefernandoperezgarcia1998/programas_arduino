int ledRojo=2,ledAma=3,ledVerde=4;
void setup() {
  // Se configuran los pines 2,3,4 para salida:
     pinMode(ledRojo,OUTPUT);
     pinMode(ledAma,OUTPUT);
     pinMode(ledVerde,OUTPUT);
}
void loop() {
  //Se activa el led verde durant 2.5 segundos, se apaga durante 0.5 s
   digitalWrite(ledVerde,HIGH);
   delay(2500);
   digitalWrite(ledVerde,LOW);
   delay(500);
   digitalWrite(ledVerde,HIGH);
   delay(1000);
   digitalWrite(ledVerde,LOW);
   delay(500);
  //El ciclo esta 3 veces para hacer parpadear durante medio segundo el led amarillo
  for(int i=0; i<3;i++){
      digitalWrite(ledAma,HIGH);
      delay(500);
      digitalWrite(ledAma,LOW);
      delay(500);
  }
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledRojo,HIGH);
  delay(3000);
  digitalWrite(ledRojo,LOW);
 }
