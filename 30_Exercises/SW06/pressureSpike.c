#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Struktur eines "Datenpunktes"
struct DataPoint{
  long long timeStamp;
  int pressure;
  char systemState;
  char alarmState;
}__attribute__((packed));

//Initialisierung der Funktionen
void PrintDataPoints(struct DataPoint dataPoints[], int numberOfPoints);
void printTime(long long timeStamp);
int PrintBinary (char State);

//Funktion für Aufg. 1

//Funktion für Aufg. 2

void OldPoints(struct DataPoint array[]);

//Funktion für Aufg. 3

//Funktion für Aufg. 4

//Funktion für Aufg. 5


int main(int argc, char *argv[]){
  //Öffnet das File und initialisiert einen Pointer:
	FILE *fid = fopen("pressureSpike.bin", "rb");

  //Sucht das Ende des Files und berechnet die Anzahl Datenpunkte:
  long numberOfPoints;
  fseek (fid , 0 , SEEK_END);
  numberOfPoints = ftell (fid)/sizeof(struct DataPoint);
  rewind (fid);
  
  //Array mit DataPoints wird generiert
  struct DataPoint myDataPoints[numberOfPoints];

  //Daten werden in das Array mit den DataPoints "abgefüllt":
  fread(myDataPoints, sizeof(struct DataPoint), numberOfPoints, fid);

  //PrintDataPoints(myDataPoints, numberOfPoints);
  
  OldPoints(myDataPoints);
  
  //PrintDataPoints(myDataPoints, 300);
  
    
  return 0;
  

  }
  

//Implementierung der Funktionen
void PrintDataPoints(struct DataPoint dataPoints[], int numberOfPoints){
  for(int i = 0; i < numberOfPoints; i+= 1){
   time_t rawtime = dataPoints[i].timeStamp / 1000;
    	int p=dataPoints[i].pressure;
    	int s=PrintBinary(dataPoints[i].systemState);
    	int a=dataPoints[i].alarmState;
    	
    	printf("%d; %ld; %d; %d; %d\n", i, rawtime , p, s, a);
    	    	 }
  return;
}

void printTime(long long timeStamp){
  time_t rawtime = timeStamp / 1000;
  
  printf("%s", ctime(&rawtime));
  return;
}


int PrintBinary (char input)
{
	int binary=0;
	int rem=0;
	int i=1;
	
	int n=input;
	
	while (n !=0){
		rem=n%2;
		n= n/2;
		binary= binary+rem*i;
		i=i*10;
	}
	
	return binary;		
}

//Funktion für Aufg. 1

//Funktion für Aufg. 2
void OldPoints(struct DataPoint array[]){

	time_t rawtimeStart = array[0].timeStamp / 1000;
	time_t rawtimeEnd = array[299].timeStamp / 1000;
	
	printf("Startzeitpunkt: \t %s\n", ctime(&rawtimeStart));
	printf("Endzeitpunkt: \t\t %s\n", ctime(&rawtimeEnd));
	long pressure=0;
	char systemState=0;
	char alarmState=1;
	
	for(int i = 0; i < 299; i+= 1){
		pressure=pressure+array[i].pressure;
		}
 	float pressureAvg= (pressure/300)/(100000);
 	
 	printf("durchschn. Druck: \t %f bar\n\n", pressureAvg);
 	
 	
 	for(int i = 0; i < 299; i+= 1){
 		if (systemState!=array[i].systemState){
 		time_t rawtimeChange = array[i].timeStamp / 1000;
		printf("Systemstatus: \t\t %d\n", PrintBinary(array[i].systemState));
		printf("Änderungszeit: \t\t %s\n\n", ctime(&rawtimeChange));
		systemState=array[i].systemState;
		}
	    }
	    
	for(int i = 0; i < 299; i+= 1){
 		if (alarmState!=array[i].alarmState){
 		time_t rawtimeChangeAlarm = array[i].timeStamp / 1000;
		printf("Alarmstatus: \t\t %d\n", array[i].alarmState);
		printf("Änderungszeit: \t\t %s\n\n", ctime(&rawtimeChangeAlarm));
		alarmState=array[i].alarmState;
		}
	    }

 	return; 		
}

//Funktion für Aufg. 3

//Funktion für Aufg. 4

//Funktion für Aufg. 5
