//Práctica 14 - RElevador y foco arduino
int foco=8;
void setup() {
 pinMode(foco,OUTPUT);
}

void loop() {

  digitalWrite(foco,HIGH);
  delay(1000);
  digitalWrite(foco,LOW);
  delay(1000);
 
}
