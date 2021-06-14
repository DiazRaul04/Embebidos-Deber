/*
 * CAPITULO V:  Funciones Específicas 
 * DEBER 5.4_SE
 * NOMBRE: Díaz Raúl
 * TEMA:  Manejo de modos Sleep
 * Instrucciones:     Realizar el funcionamiento de un semáforo basados en las funciones y tareas de RTOS.
 */
 
#include <Arduino_FreeRTOS.h> // librería de RTOS
 
#define ROJO 7                  //Pin 7 led Rojo, Pin 6 amarillo, Pin 5 verde
#define AMARILLO 6              
#define VERDE 5       
          
//objeto del gestor tareas
typedef int TaskProfiler;
//definir las tareas
TaskProfiler rojoLEDProfiler;
TaskProfiler amarilloLEDProfiler;
TaskProfiler verdeLEDProfiler;
int monitor_suspend=0;

void setup() {
Serial.begin(9600);
//crear las rutinas de cada tarea
xTaskCreate(rojoLedControllerTask,"Rojo LED Task",100,NULL,1,NULL);               //rutina,nombre,memoria,NULL,prioridad,NULL
xTaskCreate(amarilloLedControllerTask,"Amarillo LED Task",100,NULL,1,NULL);       //rutina,nombre,memoria,NULL,prioridad,NULL
xTaskCreate(verdeLedControllerTask,"Verde LED Task",100,NULL,1,NULL);             //rutina,nombre,memoria,NULL,prioridad,NULL
}


void rojoLedControllerTask(void *pvParameters){                                   //tarea LED ROJO
  pinMode(ROJO,OUTPUT);
  while(1){
      //Serial.println("Proceso led rojo");
      rojoLEDProfiler++;
      Serial.print("ROJO");
      Serial.println(rojoLEDProfiler);
      digitalWrite(ROJO,digitalRead(ROJO)^1);
       vTaskDelay(55);
    }
}

void amarilloLedControllerTask (void *pvParameters){                             //tarea LED AMARILLO
 pinMode(AMARILLO,OUTPUT);
 while(1){
    //Serial.println("Proceso led amarillo");
      amarilloLEDProfiler++;
      Serial.print("AMARILLO:");
      Serial.println(amarilloLEDProfiler);
      digitalWrite(AMARILLO,digitalRead(AMARILLO)^1);
      vTaskDelay(55);
  } 
 }
void verdeLedControllerTask (void *pvParameters){                               //tarea LED VERDE
 pinMode(VERDE,OUTPUT);
  while(1){
    //Serial.println("Proceso led verde");
      verdeLEDProfiler++;
      Serial.print("VERDE:");
      Serial.println(verdeLEDProfiler);
      digitalWrite(VERDE,digitalRead(VERDE)^1);      
      monitor_suspend++;
      if(monitor_suspend==3){
        if(digitalRead(ROJO==HIGH)){
       digitalWrite(VERDE,LOW); 
       digitalWrite(AMARILLO,LOW); 
      }      
      }
       if(monitor_suspend==4){
      if(digitalRead(AMARILLO==LOW)){
      digitalWrite(AMARILLO,HIGH); 
      digitalWrite(ROJO,LOW); 
      digitalWrite(VERDE,LOW); 
      }      
      }  
      if(monitor_suspend==5){
      if(digitalRead(VERDE==LOW)){
      digitalWrite(VERDE,HIGH);
      digitalWrite(ROJO,LOW); 
      digitalWrite(AMARILLO,LOW); 
      }      
      monitor_suspend=0;    
      }
      vTaskDelay(55);
    } 
 }

void loop() {

}
