//sout("Copyright 17270162");
//sout.("JFPG");
#include <SoftwareSerial.h>

//Se crea un objeto de tipo SoftwareSerial con nombre miBT
SoftwareSerial miBT(10,11); //Comunicación serial Rx -> 11.
                            //Comunicación serial Tx ->10. 

  char dato=0;          //Variable de lectura para el bluetooth.
  int ledNaranja=7;     //Led Naranja pin 7.
  int ledAzul=6;        //Led Azul pin 6.
  int ledRojo=5;        //Led Rojo pin 5.
  int ledBlanco=4;      //Led Blanco pin 4.
  int ledVerde=3;       //Led Verde pin 3.

    
    void setup() {
         //Serial.begin(9600);         //1.- Se inicializa la comunicación serial a 9600 baudios.
         //Serial.println("Ya estás conectado");  
         miBT.begin(38400);            //Velocidad por defecto al módulo para el objeto miBT.
         pinMode(ledNaranja,OUTPUT);   //Se configura el pin del led naranja como salida.
         pinMode(ledAzul,OUTPUT);      //Se configura el pin del led azul como salida.
         pinMode(ledRojo,OUTPUT);      //Se configura el pin del led rojo como salida.
         pinMode(ledBlanco,OUTPUT);    //Se configura el pin del led blanco como salida.
         pinMode(ledVerde,OUTPUT);     //Se configura el pin del led verde como salida.
    }

void loop() {
/*
 //Con la función available del objeto miBT devuelve 
 //verdadero cuando hay datos disponibles en el módulo, es decir,
 //si no envía datos RETORNA FALSO.
 //En caso de si enviar datos pues es verdadero y se cumple el if.
 
 if(miBT.available()){    //Lee el módulo bluetooth y envia a arduino.
  Serial.write(miBT.read()); //miBT.read -> Lee lo que contenga el módulo 
                             //Serial.write -> Escribe en el monitor serial 
                             //Lo que haya encontrado en miBt.read().
 }

 if(Serial.available()){      //Lee a Arduino al módulo Bluetooth.
  miBT.write(Serial.read());  //Si hay información en el monitor serial la va a leer con Serial.read()
                              //Y con miBt.write se va a escribir en el Bluetooth.
 }*/

  if(miBT.available()){     //Si recibe datos va a hacer toda esta sentencia.

  dato=miBT.read();         //La variable "dato" va a almacenar todo lo que 
                            //se lea del objeto miBT, o sea el bluetooth.
  
    if(dato=='1'){    //Si se presiona 1 en la aplicación móvil (NARANJA)
      digitalWrite(ledNaranja,!digitalRead(ledNaranja));   //Se enciende el led naranja y a su vez lo apaga 
                                                           //si se vuelve a tocar el BOTÓN NARANJA porque 
                                                           //"!digitalRead(ledNaranja)" está leyendo si la lectura del led está encendido ó apagado
    }
    
    if(dato=='2'){  //Si se presiona 2 en la aplicación móvil (AZUL)
      digitalWrite(ledAzul,!digitalRead(ledAzul));         //Se enciende el led azul y a su vez lo apaga 
                                                           //si se vuelve a tocar el BOTÓN AZUL porque 
                                                           //"!digitalRead(ledAzul)" está leyendo si la lectura del led está encendido ó apagado
    }

   if(dato=='3'){    //Si se presiona 3 en la aplicación móvil (ROJO)
      digitalWrite(ledRojo,!digitalRead(ledRojo));          //Se enciende el led rojo y a su vez lo apaga 
                                                           //si se vuelve a tocar el BOTÓN ROJO porque 
                                                           //"!digitalRead(ledRojo)" está leyendo si la lectura del led está encendido ó apagado
    }
    
   if(dato=='4'){   //Si se presiona 4 en la aplicación móvil (BLANCO)
      digitalWrite(ledBlanco,!digitalRead(ledBlanco));      //Se enciende el led blanco y a su vez lo apaga 
                                                           //si se vuelve a tocar el BOTÓN BLANCO porque 
                                                           //"!digitalRead(ledBlanco)" está leyendo si la lectura del led está encendido ó apagado
    }

    if(dato=='5'){    //Si se presiona 5 en la aplicación móvil (VERDE)
      digitalWrite(ledVerde,!digitalRead(ledVerde));      //Se enciende el led verde y a su vez lo apaga 
                                                           //si se vuelve a tocar el BOTÓN VERDE porque 
                                                           //"!digitalRead(ledVerde)" está leyendo si la lectura del led está encendido ó apagado
    }

  
  if(dato=='6'){    //Si se presiona 6 en la aplicación móvil (SERIE)
          for(int i=0; i<3; i++){                         //Ciclo for de 3 recorridos
               for(int pinLed=2; pinLed<8; pinLed++){       //Ciclo for para hacer un recorrido del pin 2 hasta el 8 donde
                digitalWrite(pinLed,HIGH);                  //endiende y apaga los leds con delay de 80
                delay(80);
                digitalWrite(pinLed,LOW);     
               }    
                for(int pinLed=8; pinLed>2; pinLed--){    //Ciclo for para hacer un recorrido del pin 8 hasta el 2 donde
                  digitalWrite(pinLed,HIGH);              //endiende y apaga los leds con delay de 80
                  delay(80);
                  digitalWrite(pinLed,LOW);     
                }  
          }
  }
  
  if(dato=='7'){  //Si se presiona 7 en la aplicación móvil (SERIE2)
        for(int i=0; i<3; i++){   //Ciclo for que hace ver bonita la serie dos jajaja
          //Se encienden y apagan los leds naranja y verde,
          //delay de 100
            digitalWrite(ledNaranja,HIGH);
            digitalWrite(ledVerde,HIGH);
            delay(100);
            digitalWrite(ledNaranja,LOW);
            digitalWrite(ledVerde,LOW);
            delay(100);
            
           //Se encienden y apagan los leds azul y blanco,
           //delay de 100
            digitalWrite(ledAzul,HIGH);
            digitalWrite(ledBlanco,HIGH);
            delay(100);
            digitalWrite(ledAzul,LOW);
            digitalWrite(ledBlanco,LOW);
            delay(100);
            
            //Se enciende y se apaga el led rojo
            //con delay de 100
            digitalWrite(ledRojo,HIGH);
            delay(100);
            digitalWrite(ledRojo,LOW);
            delay(100);
        }
   }

   if(dato=='8'){   //Si se presiona 8 en la aplicación móvil (ON)
    digitalWrite(ledNaranja,HIGH);
    digitalWrite(ledVerde,HIGH);        //SE ENCIENDEN TODOS LOS LEDS.
    digitalWrite(ledAzul,HIGH);
    digitalWrite(ledBlanco,HIGH);
    digitalWrite(ledRojo,HIGH);
   }

    if(dato=='9'){ //Si se presiona 9 en la aplicación móvil (OFF)
    digitalWrite(ledNaranja,LOW);
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledAzul,LOW);        //SE APAGAN TODOS LOS LEDS.
    digitalWrite(ledBlanco,LOW);
    digitalWrite(ledRojo,LOW);
   }
   
  }
}
