#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structure of a DataPoint
struct DataPoint{
  long long timeStamp;
  int pressure;
  char systemState;
  char alarmState;
}__attribute__((packed));

//Initialisierung der Funktionen
void PrintDataPoints(struct DataPoint dataPoints[], int numberOfPoints);
void PrintTime(long long timeStamp);
void PrintTitle(int numberOfTask);

//Funktion für Aufg. 1

//Funktion für Aufg. 2

//Funktion für Aufg. 3
void Print250Bar(struct DataPoint dataPoints[], int numberOfPoints);
void PrintPressureOfExplosion(struct DataPoint dataPoints[], int numberOfPoints);

//Funktion für Aufg. 4
void CalcTimeOfPressureIncrease(struct DataPoint dataPoints[], int numberOfPoints);
int ArraySum(int points[], int arrayLength);

//Funktion für Aufg. 5


int main(int argc, char *argv[]){
	FILE *fid = fopen("pressureSpike.bin", "rb"); //Öffnet das File und initialisiert einen Pointer:

  //Sucht das Ende des Files und berechnet die Anzahl Datenpunkte:
  int numberOfPoints;
  fseek (fid , 0 , SEEK_END);
  numberOfPoints = ftell (fid) / sizeof(struct DataPoint);
  rewind (fid); //Setzt den Pointer zurück

  struct DataPoint myDataPoints[numberOfPoints];   //Array mit DataPoints wird generiert
  fread(myDataPoints, sizeof(struct DataPoint), numberOfPoints, fid); //Daten werden in das Array mit den DataPoints "abgefüllt":


  //==================== Aufgabe 1 ====================
  PrintTitle(1);

  //==================== Aufgabe 2 ====================
  PrintTitle(2);

  //==================== Aufgabe 3 ====================
  PrintTitle(3);
  Print250Bar(myDataPoints, numberOfPoints);
  PrintPressureOfExplosion(myDataPoints, numberOfPoints);
  //==================== Aufgabe 4 ====================
  PrintTitle(4);
  CalcTimeOfPressureIncrease(myDataPoints, numberOfPoints);
  //==================== Aufgabe 5 ====================
  PrintTitle(5);

  // PrintTime(myDataPoints[0].timeStamp);
  // PrintTime(myDataPoints[1].timeStamp);


  //PrintDataPoints(myDataPoints, numberOfPoints);
  return 0;
}

//Implementierung der Funktionen

//==============================================================
//==================== Funktion für Aufg. 1 ====================
//==============================================================


//==============================================================
//==================== Funktion für Aufg. 2 ====================
//==============================================================


//==============================================================
//==================== Funktion für Aufg. 3 ====================
//==============================================================
void Print250Bar(struct DataPoint dataPoints[], int numberOfPoints){
	int toSearch = 25000000;
	int found;
	int i;
	for(i = 0; i < numberOfPoints; i++){
		if(dataPoints[i].pressure >= toSearch){
			found = 1;
			break;
			}
		}
		if(found == 1){
			printf("The pressure rose to over 250 bar at ");
      PrintTime(dataPoints[i].timeStamp);
		}else{
			printf("the pressure never rose above 250 bar");
		}
  return;
}

void PrintPressureOfExplosion(struct DataPoint dataPoints[], int numberOfPoints){
  printf("The pressure at which the signal breaks off is %d [Pa]", dataPoints[numberOfPoints - 1].pressure);
  printf("\n");
}

//==============================================================
//==================== Funktion für Aufg. 4 ====================
//==============================================================

//Calculates the average change in pressure over x Datapoints. The first time the avgGradient threshold is met, the time of the current dataPoint is printed
void CalcTimeOfPressureIncrease(struct DataPoint dataPoints[], int numberOfPoints){
  int numberOfDataPoints = 15;
  int pressurePoints[numberOfDataPoints];
  memset(pressurePoints, 0, sizeof(pressurePoints)); //Sets all elements of the array to 0
  int avgGradientThreshold = 1500; //[Pa / 0.25s] if this thershold is met, the time is printed

  for(int i = 0; i < numberOfPoints; i++){
    pressurePoints[i % numberOfDataPoints] = dataPoints[i + 1].pressure - dataPoints[i].pressure; //Calculates the pressure difference and adds it to the pressurePoints array
    int sum = ArraySum(pressurePoints, numberOfDataPoints); //Calculates the sum of the pressurePoint array
    if (sum / numberOfDataPoints > avgGradientThreshold){
      printf("The pressure started to increase at ");
      PrintTime(dataPoints[i-numberOfDataPoints].timeStamp);
      break;
    }
  }
  return;
}

//Calculates the sum of an array
int ArraySum(int points[], int arrayLength){
  int sum = 0;
  for (int i = 0; i < arrayLength; i++){
    sum += points[i];
  }
  return sum;
}

//==============================================================
//==================== Funktion für Aufg. 5 ====================
//==============================================================


//==============================================================
//==================== Restliche Funktionen ====================
//==============================================================
void PrintDataPoints(struct DataPoint dataPoints[], int numberOfPoints){
  for(int i = 0; i < numberOfPoints; i+= 1){
    printf("%d %lld \t%d \t%d \t%d \n", i, dataPoints[i].timeStamp, dataPoints[i].pressure, dataPoints[i].systemState, dataPoints[i].alarmState);
  }
  return;
}

//
void PrintTime(long long timeStamp){
  time_t rawtime = timeStamp / 1000;
  printf("%s", ctime(&rawtime));
  return;
}

void PrintTitle(int numberOfTask){
  int n = numberOfTask;
  printf("\n");
  for (int i = 0; i < 30; i++){
    printf("=");
  }
  printf(" Aufgabe %d ", n);
  for (int i = 0; i < 30; i++){
    printf("=");
  }
  printf("\n");
  return;
}s
