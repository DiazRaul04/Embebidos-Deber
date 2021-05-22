/*
* DEBER 4.2_SE - Interrupciones
* Nombre: Díaz Raúl 
*                
*Instrucciones:  Realizar la modificación correspondiente en el código 16 que se utilizó en clase, 
*                para que al iniciar el sistema solicite el número de veces a jugar y se comience 
*                a ejecutar de forma normal desde el inicio.  
*
*/

const int leds[6]={13,12,11,10,9,8};
 int on=0;                              //int0
 int cont;                              //int1
 int i;                                 //variable de conteo
 int j=0;                               //variable de conteo


 void setup(){
  for(i=0;i<6;i++){                     //configuración de los leds
    pinMode(leds[i],OUTPUT);
  }
  i=0;
  Serial.begin(9600);                   //activación de la comunicación serial
  attachInterrupt(0,activacion,LOW);    //interrupt 0 habilitada
  attachInterrupt(1,contador,LOW);      //interrupt 1 habilitada
 }

 void loop(){
  if(on==2){
    for (;i<cont;i++){
      for(j=0;j<6;j++){
        digitalWrite(leds[j],HIGH);
        delay (200);
        digitalWrite(leds[j],LOW);
        delay (200);
      }
    }
  }
 }


 void activacion(){
  switch(on){                           //opciones de los botones
    case 0:
   
    Serial.println("Inicio del Sistema");
   on++;
    Serial.println("Ingrese el numero de veces a jugar");

    cont=0;
    
    break;
    case 1:
     on++;
    Serial.println("Inicio de Juego");

    break;
    case 2:
    Serial.println("Fin de juego");
  on++;
    on=0;
    i=0;

    break;
  }
 }


 void contador(){
  if(on==1){
    cont++;
    Serial.println(String("Juega ")+String(cont)+String("  veces"));
  }
 }
 
