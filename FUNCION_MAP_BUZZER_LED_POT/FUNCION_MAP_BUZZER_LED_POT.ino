int led=7;
int pot=A0;
int lectura;
int porcentaje;
void setup() {
   Serial.begin(9600);
}

void loop() {
  lectura=analogRead(pot);
  porcentaje=map(lectura, 0, 1023, 0, 100); //map(variable, min, max, rango min, rango max)
  Serial.print("La lectura es: ");
  Serial.print(lectura);
  Serial.print(" Porcentaje: ");
  Serial.print(porcentaje);
  Serial.print("%");
  Serial.println();
}
