//Práctica 5 - Sensor LDR y led
int led=9;
int foto=0;
int lectura=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lectura=analogRead(foto);
  Serial.println(lectura);
  if(lectura<210){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}
