int led=9;
int pote=A0;
int valor;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valor=analogRead(pote);
  Serial.println(valor);
  analogWrite(led,valor);
}
