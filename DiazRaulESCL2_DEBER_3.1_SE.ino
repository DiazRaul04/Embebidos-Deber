/*
 * CAPITULO III: MODULOS DE COMUNICACIÓN I2C
 * DEBER 3.1_SE
 * NOMBRE: Díaz Raúl
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
 /////////////////////////////ESCLAVO #2////////////////////////////////
 */
 #include <Wire.h>
 char dato;
 const int led1=8;      //led1 pin8
 const int led2=9;      //led1 pin9
 const int led3=10;     //led1 pin10
 
void setup() {
  Wire.begin(4);        // id esclavo
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(led1,OUTPUT);   //pin8 como salida
  pinMode(led2,OUTPUT);   //pin9 como salida
  pinMode(led3,OUTPUT);   //pin10 como salida
  
}

void loop() {
}


void receiveEvent(int bytes){
  while(Wire.available()){
    dato=Wire.read();
    switch(dato){
      case 'B':
      digitalWrite(led1,HIGH);
      delay(9000);
      digitalWrite(led1,LOW);
      delay(9000);
      digitalWrite(led2,HIGH);
      delay(9000);
      digitalWrite(led2,LOW);
      delay(9000);
      digitalWrite(led3,HIGH);
      delay(9000);
      digitalWrite(led3,LOW); 
      break;
      /*
       case 'F':
      digitalWrite(led1,LOW);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);
      break;
       case 'G':
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,HIGH);
      break;
      */
       default:
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      break;
    }
  }
}
