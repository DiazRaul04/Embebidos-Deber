/*
 * CAPITULO VI
 * DEBER 6.1_SE
 * NOMBRE: Díaz Raúl
 * RETO 2
 */

boolean b = false;
boolean b1 = false;
boolean b2 = false;
volatile float d1;

void setup() {
  size(400, 400);
  ellipseMode(RADIUS);
}


void draw() {
  if(b == false){
    base1();
  }
}


void base1(){
  b = false;
  b1 = false;
  b2 = false;
  d1 = dist(mouseX, mouseY, 200,200);
  background(#C6C6C4);
  fill(#FF050E);
  stroke(#FF050E);
  ellipse(200, 200, 100, 100);
  textSize(20);
  fill(#0A0A0A);
  textAlign(CENTER);
  text("Presione el boton para \n encender o apagar el LED", 200, 30);
  fill(#FFFAFA);
  text("¡Apagado!", 200, 200);
}


void mousePressed() {
  if (mouseButton == RIGHT && b == false && d1 < 50) {
    b = true;
    background(#C6C6C4);
    fill(#791013);
    stroke(#791013);
    ellipse(200, 200, 75, 75);
    textSize(20);
    fill(#0A0A0A);
    textAlign(CENTER);
    text("Presione el boton para \n encender o apagar el LED", 200, 30);
  }
  if (mouseButton == LEFT && b1 == true && d1 < 50) {
    b2 = true;
    background(#C6C6C4);
    fill(#39862A);
    stroke(#39862A);
    ellipse(200, 200, 75, 75);
    textSize(20);
    fill(#0A0A0A);
    textAlign(CENTER);
    text("Presione el boton para \n encender o apagar el LED", 200, 30);
  }
}


void mouseReleased() {
  if (b == true) {
    background(#C6C6C4);
    fill(#17F50C);
    stroke(#17F50C);
    ellipse(200, 200, 100, 100);
    textSize(20);
    fill(#0A0A0A);
    textAlign(CENTER);
    text("Presione el boton para \n encender o apagar el LED", 200, 30);
    fill(#FFFAFA);
    text("¡Encendido!", 200, 200);
    b1 = true;
  }
  if(b2 == true){
    b = false;
  }
}
