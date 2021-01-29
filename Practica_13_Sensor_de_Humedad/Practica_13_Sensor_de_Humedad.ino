int lectura;
int sensor=A0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  lectura=analogRead(sensor);
 int lecturaPorcentaje=map(lectura,1023,0,0,100);
  Serial.print("Humedad: ");
  Serial.print(lecturaPorcentaje);
  Serial.println("%");
}
