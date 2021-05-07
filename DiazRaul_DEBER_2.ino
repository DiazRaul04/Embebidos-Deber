/*
 *DEBER 2.1
 *Nombre: Díaz Raúl
 *
 */

 //Variable que representan los Led
const int L1 = 4;    
const int L2 = 5;  
const int L3 = 6;  
const int L4 = 7; 
  


void setup() {

  pinMode(L1,OUTPUT); 
  pinMode(L2,OUTPUT); 
  pinMode(L3,OUTPUT); 
  pinMode(L4,OUTPUT); 
}

void loop() {
  digitalWrite(L1,HIGH); 
  delay(500);              
  digitalWrite(L1,LOW);  
  delay(500);              
  digitalWrite(L2,HIGH); 
  delay(500);              
  digitalWrite(L2,LOW);  
  delay(500);              
  digitalWrite(L3,HIGH); 
  delay(500);              
  digitalWrite(L3,LOW);  
  delay(500);              
  digitalWrite(L4,HIGH); 
  delay(500);              
  digitalWrite(L4,LOW);  
  delay(500);             
  
  
}
