//Práctica 10
  int ledNaranja=2;
  int ledAzul=3;
  int ledRojo=4;
  int ledBlanco=5;
  int ledVerde=6;
  
void setup() {
          pinMode(ledNaranja,OUTPUT);   
          pinMode(ledAzul,OUTPUT);
          pinMode(ledRojo,OUTPUT);
          pinMode(ledBlanco,OUTPUT);
          pinMode(ledVerde,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
  int numero=Serial.parseInt();
  Serial.println(numero);
 
    switch(numero){
      case 1:
      digitalWrite(ledNaranja,!digitalRead(ledNaranja));
      break;
       case 2:
      digitalWrite(ledAzul,!digitalRead(ledAzul));
      break;
       case 3:
      digitalWrite(ledRojo,!digitalRead(ledRojo));
      break;
       case 4:
      digitalWrite(ledBlanco,!digitalRead(ledBlanco));
      break;
       case 5:
      digitalWrite(ledVerde,!digitalRead(ledVerde));
      break;
    }
  }
}
