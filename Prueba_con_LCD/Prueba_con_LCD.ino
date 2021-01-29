#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  //Pines donde va conectada la pantalla (RS, E, D4, D5, D6, D7)

void setup() {

  lcd.begin(16, 2);   //Inicializamos la pantalla
}

void loop() {

  //Mensaje 1
  //lcd.setCursor(0, 0);          //Posiciona el cursor en la columna 0, fila 0
  //lcd.write("Prueba 1:");      //Escribe el mensaje
  lcd.setCursor(0, 1);         //Posiciona el cursor en la columna 0, fila 1
  lcd.write("Liliana");    //Escribe el mensaje
  delay(1500);                 //Espera 3.5 segundos
  lcd.clear();                 //Borra el mensaje mostrado

  //Mensaje 2
  //lcd.setCursor(3, 0);          //Posiciona el cursor en la columna 3, fila 0
  //lcd.write("Prueba 2:");       //Escribe el mensaje
  lcd.setCursor(3, 1);          //Posiciona el cursor en la columna 2, fila 1
  lcd.write("Te amoo");   //Escribe el mensaje
  delay(1500);                  //Espera 3.5 segundos
  lcd.clear();                  //Borra el mensaje mostrado
  
    //Mensaje 3
  //lcd.setCursor(3, 0);          //Posiciona el cursor en la columna 3, fila 0
  //lcd.write("Prueba 2:");       //Escribe el mensaje
  lcd.setCursor(9, 1);          //Posiciona el cursor en la columna 2, fila 1
  lcd.write("<3 <3");   //Escribe el mensaje
  delay(1500);                  //Espera 3.5 segundos
  lcd.clear();                  //Borra el mensaje 
}
