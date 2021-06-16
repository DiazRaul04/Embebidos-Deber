/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * PROYECTO BIMESTRAL: 2BIMESTRE
 * OBJETIVOS: REALIZAR FILTRADO DE LA SE;AL 2
 *NOMBRE: Alexander Moreno
 *        Raul Diaz
 *
 *
 */
#import "datos.h"
#import "datos_clasificados.h"
#include <avr/power.h>
#include <avr/sleep.h>
#include <MsTimer2.h>
int tiempos = 0;
int dtPrueba[2][2];
int val1;
int val2;
int tiempom = 0;
int conti = 0;
int cont = 0;
int cont1 = 0;
int etiqueta = 1;
boolean t = true;
boolean x = true;
int auxmax = 0; // para columna 1
int auxmax1 = 0; // para columna 2
int auxmin1 = 2000;
int auxmin = 2000;
#include <ListLib.h>
List <int> list;

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
  MsTimer2::set(10, reloj);
  MsTimer2::start();

}

void loop() {
  if(digitalRead(7)==HIGH){
    recogerDatos();
    }
  
  

  //if(analogRead(0)!=0 && analogRead(1)!=0){
  // algoritmoKnn(3);// tomar en cuenta que si el numero de vecinos es par puede existir empate ..
  //delay(20000);
  //Bayes(0.27);
  //delay(200);
  //delay(20000);
  //matrizConfusion();
  //delay(20000);
  //}
  // cont = 0;

}
void maxmin() {

  for (int i = 0; i < 200; i++) {
    if (lectura[i][0] > auxmax) {
      auxmax = lectura[i][0];
    } else {
      auxmax = auxmax;
    }
    if (lectura[i][1] > auxmax1) {
      auxmax1 = lectura[i][1];

    } else {
      auxmax1 = auxmax1;
    }
    if (lectura[i][0] < auxmin) {
      auxmin = lectura[i][0];
    } else {
      auxmin = auxmin;
    }
    if (lectura[i + 1][1] < auxmin1) {
      auxmin1 = lectura[i][1];
    } else {
      auxmin1 = auxmin1;
    }

  }
}
void normalizarDatos() {
  maxmin();
  for (int i = 0; i < 200; i++) {
    lectura[i][0] = (lectura[i][0] - auxmin) / (auxmax - auxmin);
    lectura[i][1] = (lectura[i][1] - auxmin1) / (auxmax1 - auxmin1);
    //Serial.println(String(lectura[i][0])+String("-")+String(lectura[i][1]));
  }
  for (int i = 0; i < 30; i++) {
    dtPrueba[i][0] = (dtPrueba[i][0] - auxmin) / (auxmax -  auxmin);
    dtPrueba[i][1] = (dtPrueba[i][1] - auxmin1) / (auxmax1 - auxmin1);
    //Serial.println(String(lectura[i][0])+String("-")+String(lectura[i][1]));
  }

}
void algoritmoKnn(int num) {
  double auxl;
  double auxil;

  double dist[200][2];
  double distancia;
  //normalizarDatos();
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 200; i++) {
      distancia = sqrt(pow(dtPrueba[j][0] - lectura[i][0], 2) + pow(dtPrueba[j][1] - lectura[i][1], 2));
      dist[i][0] = i;
      dist[i][1] = distancia;

    }
    for (int p = 0; p < 200; p++) {
      for (int t = 0; t < 200 - 1 ; t++) {
        if (dist[t][1] > dist[t + 1][1]) {
          auxl = dist[t][1];
          dist[t][1] = dist[t + 1][1];
          dist[t + 1][1] = auxl;
          // posición
          auxil = dist[t][0];
          dist[t][0] = dist[t + 1][0];
          dist[t + 1][0] = auxil;
          //Serial.println(dist[t][0]);
        }
        //Serial.println(auxl);

      }
      // Serial.println(minimo);

    }
    int cont = 0;
    int cont1 = 0;
    for (int n = 0; n < num; n++) {
      if (lectura[int(dist[0][n])][2] == 1) {
        cont++;
      } else if (lectura[int(dist[0][n])][2] == 2) {
        cont1++;

      }
    }
    //Serial.println(String(cont) + String(cont1));
    //delay(500);
    if (cont > cont1) {
      //Serial.print( String( String(dtPrueba[j][0]) + String(",") + String(dtPrueba[j][1]) + String(",") + String(1)) );
      Serial.write(dtPrueba[j][0]);
      delay(100);
      Serial.write(dtPrueba[j][1]);
      delay(100);
      Serial.write(1);
      delay(100);
      cont = 0;
      cont1 = 0;
    }
    if (cont1 > cont) {

      //Serial.print( String( String(dtPrueba[j][0]) + String(",") + String(dtPrueba[j][1]) + String(",") + String(2)) );
      Serial.write(dtPrueba[j][0]);
      delay(100);
      Serial.write(dtPrueba[j][1]);
      delay(100);
      Serial.write(2);
      delay(100);
      cont = 0;
      cont1 = 0;
    }

    //delay(200);

  }

}
void Bayes(double r) {
  double dist[200][2];
  double distancia;
  double numDatos1 = 0;
  double numDatos2 = 0;
  double prob1;
  double prob2;
  double distMayor = 0;

  int eti1 = 0;
  int eti2 = 0;
  double p_x = 0;
  for (int i = 0; i < 200; i++) {
    if (lectura[i][2] == 1) {
      numDatos1++;
    } if (lectura[i][2] == 2) {
      numDatos2++;
    }
  }
  //Serial.println(String(numDatos1)+String(",")+String(numDatos2));
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 200; i++) {
      distancia = sqrt(pow(dtPrueba[j][0] - lectura[i][0], 2) + pow(dtPrueba[j][1] - lectura[i][1], 2));
      dist[i][0] = i;
      dist[i][1] = distancia;
    }
    // busco distancia mayor
    for (int n = 0; n < 200; n++) {
      if (dist[n][1] > distMayor) {
        distMayor = dist[n][1];
      }
    }//Normalizar distancias de la matriz
    for (int m = 0; m < 200; m++) {
      dist[m][1] = dist[m][1] / distMayor;
      if (dist[m][1] < r) {
        list.Add(m);
      }
    }
    for (int g = 0; g < list.Count(); g++) {
      if (lectura[list[g]][2] == 1) {
        eti1++;
      } else if (lectura[list[g]][2] == 2) {
        eti2++;
      }

    }
    p_x = double(list.Count()) / double(200);
    //Serial.println(eti2);
    prob1 = ((numDatos1 / 200) * (eti1 / numDatos1)) / p_x;
    prob2 = ((numDatos2 / 200) * (eti2 / numDatos2)) / p_x;
    // Serial.println(double(numDatos1/200));
    if (prob1 > prob2) {
      //Serial.print( String(String(dtPrueba[j][0]) + String(",") + String(dtPrueba[j][1]) + String(",") + String(1)));
      Serial.write(dtPrueba[j][0]);
      delay(100);
      Serial.write(dtPrueba[j][1]);
      delay(100);
      Serial.write(1);
      delay(100);
    }
    else if (prob2 > prob1) {
      //Serial.print(  String(String(dtPrueba[j][0]) + String(",") + String(dtPrueba[j][1]) + String(",") + String(2) ));
      Serial.write(dtPrueba[j][0]);
      delay(100);
      Serial.write(dtPrueba[j][1]);
      delay(100);
      Serial.write(2);
      delay(100);
    }else{
      Serial.write(dtPrueba[j][0]);
      delay(100);
      Serial.write(dtPrueba[j][1]);
      delay(100);
      Serial.write(0);
      delay(100);
      
      }
    //delay(200);
    list.Clear();
    eti1 = 0;
    eti2 = 0;
    prob1 = 0;
    prob2 = 0;
  }
  // delay(20000);
}
void matrizConfusion() {
  int vp = 0;
  int fn = 0;
  int fp = 0;
  int vn = 0;
  for (int i = 0; i < 70; i++) {
    if (dtPrueba[i][2] == dtClasificadosKnn[i][2] &&  dtPrueba[i][2] == 1) {
      vp++;
    }
    if (dtPrueba[i][2] != dtClasificadosKnn[i][2] == 1) {
      fn++;
    }
    if (dtPrueba[i][2] == dtClasificadosKnn[i][2] && dtPrueba[i][2] == 2) {
      vn++;
    }
    if (dtPrueba[i][2] != dtClasificadosKnn[i][2] == 2) {
      fp++;
    }

  }
  Serial.println("Algoritmo Knn");
  Serial.println(String(" vp = ") + String(vp) + String(" fn = ") + String(fn) + String(" vn = ") + String(vn) + String(" fp = ") + String(fp));
  vp = 0; fn = 0; fp = 0; vn = 0;
  for (int i = 0; i < 70; i++) {
    if (dtPrueba[i][2] == dtClasificadosBayes[i][2] && dtPrueba[i][2] == 1) {
      vp++;
    }
    if (dtPrueba[i][2] != dtClasificadosBayes[i][2] == 1) {
      fn++;
    }
    if (dtPrueba[i][2] == dtClasificadosBayes[i][2] && dtPrueba[i][2] == 2) {
      vn++;
    }
    if (dtPrueba[i][2] != dtClasificadosBayes[i][2] == 2) {
      fp++;
    }

  }
  Serial.println("Algoritmo Bayesiano");
  Serial.println(String(" vp = ") + String(vp) + String(" fn = ") + String(fn) + String(" vn = ") + String(vn) + String(" fp = ") + String(fp));
  vp = 0; fn = 0; fp = 0; vn = 0;
}
void modoSleep() {
  //Serial.println("Estoy Inactivo..");
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();
  power_adc_disable();
  power_timer0_disable();
  power_timer1_disable();
  power_twi_disable();
  sleep_mode();
}
void despertar() {
  //Serial.println("he despertado..");
  sleep_disable();
  power_all_enable();
}
void recogerDatos() {
  if (tiempom == 1 && t == true ) {
    despertar();
    if (cont < 2 ) {
      val1 = analogRead(0);
      val2 = analogRead(1);
      dtPrueba[cont][0] = val1;
      dtPrueba[cont][1] = val2;
      cont++;

    } else {
      Bayes(0.27);  //normalizado
      delay(100);   //para poder observaer
      algoritmoKnn(3);  //3vecinos 
      delay(100);
      modoSleep();   //zzz para no recoger datos
      t = false;
      cont = 0;


    }
  } else {
    modoSleep();
  }

}
void reloj() {
  if (tiempos < 59) {
    tiempos++;

  } else if (tiempom < 1) {
    tiempos = 0;
    //Serial.println(tiempom);
    tiempom++;
    if (tiempom == 1) {
      t = true;
    }
  } else {
    tiempos = 0;
    tiempom = 0;
  }
}
