/*
 * CAPITULO V:  Funciones Específicas 
 * DEBER 5.2_SE
 * NOMBRE: Díaz Raúl
 * TEMA:  Manejo de modos Sleep
 * Instrucciones:     Realizar la modificación y corrección del 
 *                    CÓDIGO 23, correspondiente al Capítulo 5.
 */

#include<avr/power.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include <MsTimer2.h>
#include<EEPROM.h>


int dato;
int on=0;



void(* resetFunc) (void) = 0; 
//void on(void);



void setup() {
   dato=EEPROM.read(0);
   Serial.begin(9600);
   Serial.println("SETUP");
   if(dato==0){
    set_sleep_mode(SLEEP_MODE_STANDBY);
    sleep_enable();
    EEPROM.write(0,1);
    wdt_enable(WDTO_8S);
    }
    else{
    sleep_disable();
     EEPROM.write(0,0);
      MsTimer2::set(10000,tiempo); // configura timer 2 a un segundo
       MsTimer2::start();
    }
   attachInterrupt(0,encender,LOW);
}


void loop() {
if(dato==0){
  Serial.println("DORMIDO");
  delay(2000);
 sleep_mode(); 
}
 else{
  Serial.println("DESPIERTO");
  delay(1000);
  sleep_mode();
  }
}



void tiempo(){
  Serial.println("DORMIDO");
  delay(2000);
  
 }
 
 void encender (){
    resetFunc();  
 }
