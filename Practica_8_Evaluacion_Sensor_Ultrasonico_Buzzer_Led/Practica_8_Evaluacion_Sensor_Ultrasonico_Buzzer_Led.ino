int buzzer=7;
int pinTrig=8;
int pinEco=9;
int ledRojo=10;
int ledAma=11;
int ledVerde=12;

int tiempo;
int longitud;

void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEco,INPUT);
  pinMode(ledRojo,OUTPUT);
   pinMode(ledAma,OUTPUT);
    pinMode(ledVerde,OUTPUT);
  Serial.begin(9600);
}

void loop() {
   digitalWrite(pinTrig,HIGH);
   delay(1);
   digitalWrite(pinTrig,LOW);
   tiempo=pulseIn(pinEco,HIGH);

   longitud=tiempo/58.2; //conversión a la distancia 

   Serial.println("La distancia es:");
   Serial.println(longitud);
   delay(200);

    if(longitud<=0 || longitud <=5){
       digitalWrite(ledRojo,HIGH);
       digitalWrite(ledAma,LOW);
       digitalWrite(ledVerde,LOW);
       tone(buzzer,220);
      Serial.println("Cuidado, estás a 5 cm");
     }
     else if(longitud<=6 || longitud<=10){
       digitalWrite(ledVerde,LOW);
       digitalWrite(ledRojo,LOW);
       tone(buzzer,440);
       Serial.println("Cuidado, estás a 10 cm");
                   for(int i=0; i<3; i++){
                        
                         digitalWrite(ledAma,HIGH);
                         delay(50);
                         digitalWrite(ledAma,LOW);
                         delay(50);
                    }
    }
    else{
         digitalWrite(ledVerde,HIGH);
         digitalWrite(ledRojo,LOW);
         digitalWrite(ledAma,LOW);
           noTone(buzzer);
        Serial.println("Vas bien");
    }
}
