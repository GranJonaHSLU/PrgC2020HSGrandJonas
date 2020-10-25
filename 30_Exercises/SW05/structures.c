#include <stdio.h>
#include <stdlib.h>

typedef struct{	
	int x;	//4 bytes
	int y;	//4 bytes
}Point2D;

typedef struct{
	Point2D pointTopLeft;		//4+4=8 bytes
	Point2D pointBottomRight;	//8 bytes
	double area;				//8 bytes
}Rectangle;

#define NUM_RECTANGLES 10

Rectangle myRectangles[NUM_RECTANGLES];

void PrintRectangleArray( Rectangle myRectangles[], int ArrayLength);
void PrintRectangle (Rectangle myRectangle);
double ComputeRectangleArea(Rectangle myRectangle);
		

int main(int argc, char* argv[]){
	
	//init random number generator
	srand (42);
	
	//init rectangles with random numbers
	for (int i=0; i<NUM_RECTANGLES; i++){
		
		//coordinates TopLeft
		myRectangles[i].pointTopLeft.x = rand() %500 -250;
		myRectangles[i].pointTopLeft.y = rand() %500 -250;
		
		//make sure Bottom Right is Bottom Right
		//take TopLeft point add/subtract random number
		myRectangles[i].pointBottomRight.x = myRectangles[i].pointTopLeft.x + rand() %100+1;
		myRectangles[i].pointBottomRight.y = myRectangles[i].pointTopLeft.y - rand() %100+1;
		
		//fill in Area
		myRectangles[i].area = ComputeRectangleArea(myRectangles[i]);	
	}
	
	PrintRectangle(myRectangles[0]);
	PrintRectangleArray(myRectangles, NUM_RECTANGLES);
	
	return 0;
}

void PrintRectangle (Rectangle myRectangle){
	printf("%d\t %d\t  %d\t%d\t \t %f\n",\
	myRectangle.pointTopLeft.x, myRectangle.pointTopLeft.y,\
	myRectangle.pointBottomRight.x, myRectangle.pointBottomRight.y,\
	myRectangle.area);
	}
	
void PrintRectangleArray (Rectangle myRectangles[], int ArrayLength)
{
	for (int i = 0; i< NUM_RECTANGLES; i++)
	{
		PrintRectangle(myRectangles[i]);
	}
}

double ComputeRectangleArea(Rectangle myRectangle)
{
	double area = 0;
	Point2D ptTL = myRectangle.pointTopLeft;
	Point2D ptBR = myRectangle.pointBottomRight;
	
	int deltaX = (ptBR.x - ptTL.x);
	int deltaY = (ptTL.y - ptBR.y);
	
	area= deltaX*deltaY;
	return area;
}
