//Práctica 9
int ledNaranja=2;
int ledAzul=3;
int ledRojo=4;
int ledBlanco=5;
int ledVerde=6;

void setup() {
  pinMode(ledNaranja, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledBlanco, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
}

void encenderLeds(){
        for(int brillo=0; brillo<255;brillo++){
                  analogWrite(ledNaranja,brillo);
                  analogWrite(ledAzul,brillo);
                  analogWrite(ledRojo,brillo);
                  analogWrite(ledBlanco,brillo);
                  analogWrite(ledVerde,brillo);
                  Serial.println(brillo);
                  delay(10);
        }
        for(int brillo=255; brillo>=0;brillo--){
                  analogWrite(ledNaranja,brillo);
                  analogWrite(ledAzul,brillo);
                  analogWrite(ledRojo,brillo);
                  analogWrite(ledBlanco,brillo);
                  analogWrite(ledVerde,brillo);
                  Serial.println(brillo);
                  delay(10);
        }
}


void loop() {

 encenderLeds();
  //apagarLeds();  
}
