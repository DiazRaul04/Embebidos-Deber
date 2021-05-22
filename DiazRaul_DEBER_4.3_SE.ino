/*
 * CAPITULO IV: PERIFERICOS ESPECIALES
 * DEBER 4.3_SE
 * NOMBRE: Díaz Raúl
 * TEMA:  Timer 2
 * Instrucciones:    Realizar la modificación correspondiente en el código 18 que se utilizó en clase, 
 *                   trabajando con una LCD 20x4, en donde en la primera fila se observe un mensaje de 
 *                   bienvenida,  en la segunda línea se visualice su nombre y apellido, en la tercera 
 *                   línea se observe "Horas : minutos : segundos"; y en la última fila se visualice 
 *                   los valores asignados a las variables del timer2, centradas.  
 *           
 */
#include <MsTimer2.h>     //libreria Timer 2
#include <LiquidCrystal.h> //libreria LCD

LiquidCrystal lcd(13,12,11,10,9,8);       //objeto para la libreria de LCD

int segundos=0;         //variable de segundos
int minutos=0;          //variable de minutos
int horas=0;            //variable de horas

 
void setup() {
  lcd.begin(20,4); // inicia LCD
  MsTimer2::set(1000,reloj);    //cinfigura el timer 2 a 1s
  MsTimer2::start();            //Inicia el Timer 2

}

void loop() {
  // put your main code here, to run repeatedly:

}


void reloj(){
  if(segundos<59){      //condicion de segundos
    segundos++;         //incrementar variablr
  }
  else{
    segundos=0;
    if(minutos<59){     //condicion de minutos
      minutos++;        //incrementar la variable
    }
    else{
      minutos=0;
      if(horas<23){     //condicion horas
        horas++;        //incrementar la variable
      }
      else{
        horas=0;
      }
    }
  }
  lcd.clear();          //borrar el anterior mensaje
  lcd.setCursor(0,0);   //ubicacion de LCD
  lcd.print("HOLA BIENVENIDOS");
  lcd.setCursor(0,1);   //ubicacion de LCD
  lcd.print("Raul A. Diaz");
  lcd.setCursor(0,2);   //ubicacion de LCD
  lcd.print("Horas :  Min  : Seg");
  lcd.setCursor(0,3);   //ubicacion de LCD
  lcd.print(String("  ")+ String(horas)+String("   :   ")+String(minutos)+String("   :  ")+String(segundos)+String("  ") );
}
