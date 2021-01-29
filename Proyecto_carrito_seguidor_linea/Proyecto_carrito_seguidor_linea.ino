int infra=8;
int valor=0;
void setup() {
  pinMode(infra,INPUT);
  Serial.begin(9600);
}

void loop() {
  valor=digitalRead(infra);
  Serial.println(valor);
  
}
