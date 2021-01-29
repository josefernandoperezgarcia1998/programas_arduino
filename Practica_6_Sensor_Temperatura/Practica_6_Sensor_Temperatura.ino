int ledRojo=8; //Led rojo conectado al pin 8
int ledAma=9; // Led amarillo conectado al pin 9
int ledVerde=10; //Led verde conectado al pin 10
int sensorTmp=A0; //Sensor TMP36 conectado al pin A0
float lectura=0; //Se inicializa la variable que llevará la lectura del sensor

void setup() {

  pinMode(ledRojo,OUTPUT);    //Led como salida
  pinMode(ledAma,OUTPUT);     //Led como salida
  pinMode(ledVerde,OUTPUT);    //Led como salida

  Serial.begin(9600);       //serial con 9600 baudios
}

void loop() {
  
  float gCelsius;              //Se crea una variable que contendrá la temperatura en grados celcius
  
  lectura=analogRead(sensorTmp)*0.0048828125; //Se guarda en la variable lectura el voltaje que tiene el sensor

  gCelsius=(lectura-0.5)*100.0;   //Se convierte a °C. El voltaje recibido de la variable del sensor "lectura" se multiplica por 0.5 y después se multiplica por 100

  Serial.println("Grados C:");  //Muestra mensaje Grados C:
  Serial.println(gCelsius);     //Muestra los grados C 
  delay(500);                  //Retraso de un segundo para que se pueda notar la diferencia

  if(gCelsius<=18 || gCelsius<=19){
    digitalWrite(ledVerde,HIGH);
    digitalWrite(ledAma,LOW);
    digitalWrite(ledRojo,LOW);
  }
  else if(gCelsius<=20 || gCelsius<=21){
    digitalWrite(ledAma,HIGH);
     digitalWrite(ledVerde,LOW);
      digitalWrite(ledRojo,LOW);
  }
  else if(gCelsius<=22){
    digitalWrite(ledRojo,HIGH);
     digitalWrite(ledVerde,LOW);
      digitalWrite(ledAma,HIGH);
  }
  else{
    Serial.println("too hot");
  }
}
  
