/*
 * lab 03: COMUNICACIÓN - CAD - INTERRUPCIONES
 * GRUPO N°8:
 * Moreno Alexander
 * Raul Diaz
 * Sistemas Embebidos
 */
int x = 575; //encontrar el centro del screen
int letter;
PVector pos;
int bestScore = 0;
int y = 360; //encontrar el centro del screen
int x_food; //posiiones comida
int y_food;
int snake_size = 1;
int i;
int j;
boolean food = false;
boolean gameOver = false;
int count = 0;
ArrayList<PVector> tail;
int m = 0;
PImage img, img2, img3, Fondo;
PFont tipografia; 

void setup() {
  size(1155, 770);
  frameRate(10);  //FPS
  img = loadImage("food.png");  //food
  img2 = loadImage("head.png"); //head
  img3 = loadImage("body.png"); //body
  Fondo=loadImage("moore.png");
  background(Fondo);
  tail = new ArrayList<PVector>();
  tipografia = createFont("game_over.ttf", 500);
}

void draw() {
  if (!gameOver) {
    background(Fondo);
    fill(255);
    textFont(tipografia);
    stroke(255, 0, 0);
    rect(0, 720, 1155, 50); //dibujar el rectangulo con dimensiones en pantalla
    fill(0);
    textSize(60);
    text("Puntaje CITEL: ", 155, 755);
    text("Mejor Puntaje CITEL: ", 590, 755);
    if (bestScore < snake_size) {
      bestScore = snake_size;
    }
    text(bestScore - 1, 830, 755);

    text(snake_size - 1, 325, 755);
    stroke(0);
    fill(255);
    
    rect(x, y, 20, 20);      //dimensiones de cada cuadrado 20px * 20px
    for (PVector p : tail) {
     
      rect(p.x, p.y, 20, 20);
    }
    //Para saber si se mueve up down left rigth 
    switch (count) {
    case 1:
      if (x >= 0) {
        pos = new PVector(x, y);
        tail.add(pos.copy());
        x = x - 20;
        rect(x, y, 20, 20);
        if ( tail.size() > snake_size - 1) {
          tail.remove(0);
        }
      }
      break;
    //up  
    case 2:
      if (y >= 0) {
        pos = new PVector(x, y);
        tail.add(pos.copy());
        y = y - 20;
        rect(x, y, 20, 20);
        
        if ( tail.size() > snake_size - 1) {
          tail.remove(0);
        }
      }
      break;
      //left
    case 3:
      if (x <= 1135) {
        pos = new PVector(x, y);
        tail.add(pos.copy());
        x = x + 20;
        rect(x, y, 20, 20);
      
        if ( tail.size() > snake_size - 1) {
          tail.remove(0);
        }
      }
      break;
      //down
    case 4:
      if (y <= 700) {
        pos = new PVector(x, y);
        tail.add(pos.copy());
        y = y + 20;
        rect(x, y, 20, 20);
        if ( tail.size() > snake_size - 1) {
          tail.remove(0);
        }
      }
      break;     
    }
    if (!food) {
      food();
      food = true;
    }
    
    fill(77, 255, 77);
    image(img, x_food, y_food);
    
    if (x == x_food && y == y_food) {
      snake_size++;
      fill(0);
      rect(x_food, y_food, 20, 20);
      food = false;
    }
    for (PVector p : tail) {
      if ( p.x == x && p.y == y) {
        snake_size = 1;
        tail = new ArrayList<PVector>();
        gameOver = true;
      } else {
        if ( x < 0 || y < 0 || x > 1135 || y > 700) {
          snake_size = 1;
          tail = new ArrayList<PVector>();
          gameOver = true;
        }
      }
    }  
  }

  if (gameOver) {
    fill(0,0,255); //color gris 
    textFont(tipografia);
    rect(0, 0, 1155, 720);
    fill(255, 255, 255);  //color negro de las letras
    textSize(250);
    text("CITEL SNAKE", 250, 520 / 2);
    textSize(250);
    text("Game Over", 300, 720 / 2);
    textSize(100);
    text("Click para Jugar !", 400, 400);
    
  }   
}
//Para saber que teclas presionar (codigos 37=up,38=,39=,40=,80=P)
void keyPressed() {
  switch (keyCode) {
  case 37:
    count = 1;
    break;
    
  case 38:
    count = 2;
    break;
    
  case 39:
    count = 3;
    break;
    
  case 40:
    count = 4;
    break;
    
  case 80:
    m++;
    switch(m) {
      case 1:
        noLoop();
        fill(0, 0, 255);
        rect(0, 0, 1155, 720);
        fill(255,255,255);
        textSize(200);
        text(" P A U S E ", 350, 360);
        break;
        
      case 2: 
        loop();
        m = 0;
        break;
    }
    break;
  }
}

void mouseReleased() {
  if (mouseButton == LEFT) {
    gameOver = false;
    x = 540;
    y = 360;
    //secret
  } else if (mouseButton == RIGHT) {
    snake_size++;
  }
}

void food() {
  x_food = int(random(54)) * 20;
  y_food = int(random(36)) * 20;
}
