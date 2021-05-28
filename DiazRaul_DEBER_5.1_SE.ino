/*
 * CAPITULO V:  Funciones Específicas - Memoria EEPROM
 * DEBER 5.1_SE
 * NOMBRE: Díaz Raúl
 * TEMA:  Memoria EEPROM
 * Instrucciones:     Realizar la escritura de la memoria EEPROM a travez de un teclado matricial, 
 *                    el cual debe cumplir que se visualice en una LCD cada caracter que se introduzca 
 *                    (uno por uno el que vayamos escribiendo en la memoria EEPROM), es decir, 
 *                    cada vez que se presione una tecla. Con una tecla en específico, la que usted 
 *                    decida, al presionarla, en la LCD se debe observar todos los caracteres que se 
 *                    guardaron en la memoria. Esto debe visualizarse de la posición menor a la 
 *                    posición mayor si se observa de derecha a izquierda en la LCD.
 *           
 */
#include <EEPROM.h>  //Incluimos la librería de EEPROM
#include <Keypad.h> //Incluimos la librería Keypad
#include <LiquidCrystal.h>  //Incluimos la librería LiquidCrystal
LiquidCrystal lcd(13,12,11,10,9,8); //Definimos los pines del LCD

const byte ROWS = 4; // Número de filas
const byte COLS = 4; // Número de columnas
// Definimos el Keymap
char keys[ROWS][COLS] = {
  {7, 8, 9, '/'},
  {4, 5, 6, '*'},
  {1, 2, 3, '-'},
  {'ON',0, '=', '+'}
};
byte rowPins[ROWS] = { 7, 6, 5, 4 }; 
byte colPins[COLS] = { 3, 2, 1, 0 }; 
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int cont = 0; 
int enc=0;   
int pass[255]; 
int i=0;
int j=0;
int valor=0;
int imp=0;
void setup()
{  
  lcd.begin(16, 2);
    for (i ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);  
  }
  
}
void loop() {

char key = customKeypad.getKey();

  lcd.setCursor(0, 0);
  lcd.print("POR FAVOR INGRESA");
  lcd.setCursor(0,1);
    if (key != NO_KEY) {
      EEPROM.put(cont,key);
     imp= EEPROM.get(cont,key);
       lcd.print(imp);
       pass[cont]= key;
      delay(100);
      cont++;
    }
  if (key == '*') {   
  lcd.setCursor(0, 0);
  lcd.print("ESTO INGRESASTE");
  lcd.setCursor(j,1); 
  imp=pass[j];
  lcd.print(imp);
  j++;
  cont=0;
  }

 

     
}
