/*
 * CAPITULO IV: PERIFERICOS ESPECIALES
 * DEBER 4.1_SE
 * NOMBRE: Díaz Raúl
 * TEMA:  CAD y PWM
 * OBJETIVO: Realizar un sistema en el cual se conecten 2 motores (parecido al diagrama que se utilizo en clase). 
 *           Los datos de CAD, V y PWM se deben visulizar en una LCD para cada motor.   
 *           A travez de la activación de un botón y un switch (el funcionamiento de un motor dependerá de la 
 *           activación de un botón y el otro dependerá de la activación de un switch, a su elección) entrará en 
 *           funcionamiento el motor que corresponda y se visualizará en la LCD de ese motor los datos de CAD, Voltaje y PWM.
 *           
 */

 #include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,5,4,3,2);       //seleccion de pines para la LCD
LiquidCrystal lcd1(9,8,5,4,3,2);       //seleccion de pines para la LCD
int conversor;                          //variable para adquirir datos del conversor entre 0-1023
float voltaje;                          //variable de conversion de conversor a voltaje
int dutty;
 
void setup() {
  lcd.begin(16,2);                      // inicializa la LCD
  lcd1.begin(16,2); 
}

void loop() {
  conversor=analogRead(A0);             // lectura del canal A0-0-14
  voltaje=(conversor*5.0)/1023.0;       //conversor de voltaje
  dutty=conversor/4;                    //cambio la escala para el dutty
  analogWrite(11,dutty);                //envio de valor al pin 11
  lcd.setCursor(0,0);
  lcd.print("CAD:");
  lcd.setCursor(5,0);
  lcd.print(conversor);
  lcd.setCursor(0,1);
  lcd.print("V:");
  lcd.setCursor(3,1);
  lcd.print(voltaje);
  lcd.setCursor(9,1);
  lcd.print("PWM:");
  lcd.setCursor(13,1);
  lcd.print((dutty*100)/255);
  delay(600);
  //lcd.clear();

  conversor=analogRead(A1);             // lectura del canal A0-0-14
  voltaje=(conversor*5.0)/1023.0;       //conversor de voltaje
  dutty=conversor/4;                    //cambio la escala para el dutty
  analogWrite(10,dutty);                //envio de valor al pin 11
  lcd1.setCursor(0,0);
  lcd1.print("CAD:");
  lcd1.setCursor(5,0);
  lcd1.print(conversor);
  lcd1.setCursor(0,1);
  lcd1.print("V:");
  lcd1.setCursor(3,1);
  lcd1.print(voltaje);
  lcd1.setCursor(9,1);
  lcd1.print("PWM:");
  lcd1.setCursor(13,1);
  lcd1.print((dutty*100)/255);
  delay(600);
  //lcd1.clear();
  

   

}
