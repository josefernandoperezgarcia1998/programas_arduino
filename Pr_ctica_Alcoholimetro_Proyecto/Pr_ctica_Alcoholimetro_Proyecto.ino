#include <LiquidCrystal.h>
//Práctica 11
/*
 * Gobierno de Tuxla Gutiérrez 2020
+----------------------------------------------------------------------+
|GRADO DE ALCOHOL | CLASIFICACIÓN                 | PENALIZACIÓN       |
+-----------------+-------------------------------+--------------------+
|0.01 a 0.07      | Tolerancia - Sin penalización | Sin penalización   |
+-----------------+-------------------------------+--------------------+
|0.08 a 0.019     | Aliento alcohólico            | 10 salarios mínimos|
+-----------------+-------------------------------+--------------------+
|0.20 - 0.39      | Ebrio incompleto              | 30 salarios mínimos|
+-----------------+-------------------------------+--------------------+--------------------------------------------+
|0.40 en adelante | No apto para coducir          | 150 salarios mínimos, arresto inconmutable y retiro del vehículo|
+-------------------------------------------------------------------------------------------------------------------+
FUENTE: http://conapra.salud.gob.mx/Interior/Documentos/Manuales/Programa_Nacional_Alcoholimetria.pdf
*/

int valor_limite= 700;  // El valor límite es igual a 750, por lo tanto 750 = 0.8, esto es el inicio de aliento alcohólico
float valor_alcohol;    //Variable que llevará la cuenta del sensor analógico
int buzzer=47;          //pin 47 para buzzer
int ledVerde=48;        //pin 48 para led verde 
int ledRojo=49;         //pin 49 para led rojo
float mq3=A0;           //Pin A0 para el sensor mq3
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //Se crea el objeto lcd de tipo LiquidCrystal 
                                        //en donde se tienen los pines 7-12 en el LCD y arduino

                                        
void setup() { 
             
  pinMode(ledVerde,OUTPUT);   //Led verde configurado como salida
  pinMode(ledRojo,OUTPUT);    //Led rojo configurado como salida
  pinMode(buzzer,OUTPUT);     //Buzzer configurado como salida
                              //No se declara el sensor como output por ser analógico
  Serial.begin(9600);         // Se configura el Puerto Serial en 9600 Baudios


   lcd.begin(16, 2); //Se inicializa la pantalla LCD
}

void loop() { 
 
  lcd.setCursor(0,0);             //Se coloca el cursor en 0,0
  lcd.write("ALCOHOLIMETRO");     //De manda a escribir el siguiente mensaje en 0,0
  
  valor_alcohol=analogRead(mq3);             //La variable almacena los valores analógicos leídos del sensor mq3 
  float porcentaje=(valor_alcohol/10000);    //calcula el porcentaje del valor que contiene el alcohol                 
  lcd.setCursor(0,1);                        //se coloca el cursr en 0,1
  lcd.print(porcentaje);                    //Se imprime el porcentaje en 0,1
  delay(400);                               //Retraso de 400
  
  
  if(valor_alcohol > valor_limite){         //Se hace la comparación si el valor del alcohol es MAYOR QUÉ el límite permitido
       digitalWrite(ledRojo, HIGH);         //Si se cumple, se enciende el led rojo
       lcd.setCursor(6, 2);                //El cursos se pone en 6,2
       lcd.print("POSITIVO");               //Se imprime el mensaje "positivo" en 6,2
       tone(buzzer,240);                    //Se activa el buzzer con un tono de 240
       digitalWrite(ledVerde, LOW);         //Se mantiene apagado el led verde
   }
   else{                                    //En caso de que NO se cumpla la condición, 
      digitalWrite(ledVerde, HIGH);         //o sea que, el valor del alcohol sea MENOR QUÉ el valor límite
      lcd.setCursor(6, 2);                  //Se enciende el led verde y el cursor se coloca en 6,2
      lcd.print("NEGATIVO");               //Se imprime el mensaje "negativo" en 6,2
      noTone(buzzer);                      //Se desactiva el buzzer
      digitalWrite(ledRojo, LOW);           //Se mantiene apagado el led rojo
   }
  delay (400);                          // Se tiene un retraso de 400 para leer el próximo dato
}
