#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Struktur eines "Datenpunktes"
struct DataPoint{
  long long timeStamp;
  int pressure;
  char systemState;
  char alarmState;
}_attribute_((packed));

//Initialisierung der Funktionen
void PrintDataPoints(struct DataPoint array[], long numberOfPoints);
void printTime(long long timeStamp);

//Funktion für Aufg. 1

//Funktion für Aufg. 2

//Funktion für Aufg. 3

//Funktion für Aufg. 4

//Funktion für Aufg. 5


int main(int argc, char *argv[]){
  //Öffnet das File und initialisiert einen Pointer:
	FILE *fid = fopen("pressureSpike.bin", "rb");

  //Sucht das Ende des Files und berechnet die Anzahl Datenpunkte:
  long numberOfPoints;
  fseek (fid , 0 , SEEK_END);
  numberOfPoints = (ftell (fid)/sizeof(struct DataPoint));
  rewind (fid);

  //Array mit DataPoints wird generiert
  struct DataPoint myDataPoints[numberOfPoints];

  //Daten werden in das Array mit den DataPoints "abgefüllt":
  fread(myDataPoints, sizeof(struct DataPoint), numberOfPoints, fid);

  //PrintDataPoints(myDataPoints, numberOfPoints);
  printTime(myDataPoints[0].timeStamp);
  return 0;
}

//Implementierung der Funktionen
void PrintDataPoints(struct DataPoint array[], long numberOfPoints){
  for(int i = 0; i < numberOfPoints; i+= 1){
    printf("%d %lld \t%d \t%d \t%d \n", i, array[i].timeStamp, array[i].pressure, array[i].systemState, array[i].alarmState);
  }
}

void printTime(long long timeStamp){
  time_t rawtime = timeStamp / 1000;
  printf("%s", ctime(&rawtime));
  return;
}


//Funktion für Aufg. 1

//Funktion für Aufg. 2

//Funktion für Aufg. 3

//Funktion für Aufg. 4

//Funktion für Aufg. 5
