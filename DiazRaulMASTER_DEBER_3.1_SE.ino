/*
 * CAPITULO III: MODULOS DE COMUNICACIÓN I2C
 * DEBER 3.1_SE
 * TEMA: Comunicación I2C
 * OBJETIVO: Mediante comunicación I2C configurar 1 maestro y 3 esclavos. Cada esclavo tendrá conectados 3 leds en sus salidas digitales, 
 *           los cuales deberán encenderse de forma síncrona   y ordenada. Los leds del primer esclavo deberán entran en funcionamiento 
 *           cuando se ingrese 'Cualquier caracter', luego cuando se ingrese otro 'Cualquier caracter 2' entrará en funcionamiento el 
 *           esclavo 2, y después cuando se ingrese otro 'Cualquier caracter 3' entrará en funcionamiento el esclavo 3.
 *           
 *           
 *           
 *           
 *           
 *           
 /////////////////////////////MASTER////////////////////////////////
 */

 #include <Wire.h>              //libreria I2C
 char dato;
 
void setup() {
  Wire.begin();                 //inicia comunicacion I2C
  Serial.begin(9600);           //inicia comunicacion serial
}

void loop() {
  if(Serial.available()>0){     //verifica que exista datos
    dato=Serial.read();
    Wire.beginTransmission(4);
    Wire.write(dato);
    Wire.endTransmission();
   
  }
}
