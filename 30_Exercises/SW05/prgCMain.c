#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef enum{
	MAIN_MENU=1,
	NUMSTAT,
	FACTORIAL,
	CUBIC,
	NCHOOSEK,
	PRINTBINARY,
	ARRAYTEST,
	EXIT =99,
}MenuItem;

MenuItem PrintMainMenu(void);

long int NumStat (int x1, int x2);
long int Factorial (long int x);
long int ComputeCubic (long int x);
int nChooseK (int x1, int x2);
void ArrayTest(void);


int main(int argc, char* argv[]){
	
	MenuItem state= MAIN_MENU;
	int run=1;
	long int input=0;
	int value1=0;
	int value2=0;
	
	
	while (run)
	{
	switch(state)
	{
	case MAIN_MENU:
		state= PrintMainMenu();
		break;
		
	case NUMSTAT:
		printf("\n");
		printf("***********************************\n");
		printf("************* Numstat *************\n");
		printf("***********************************\n\n");
		printf("Enter Value 1 --> ");
		scanf("%d", &value1);
		printf("Enter Value 2 --> ");
		scanf("%d", &value2);
		printf("\n");
		
		printf( NumStat(value1, value2));
			
		
		state=MAIN_MENU;
		break;
		
	case FACTORIAL:
		printf("\n");
		printf("***********************************\n");
		printf("************ Factorial ************\n");
		printf("***********************************\n\n");
		
		printf("--> ");
		scanf("%d", (int*)&input);
		
		printf("Factorial of %ld is %ld\n", input, Factorial(input));
		printf("\n");
				
		state=MAIN_MENU;
		break;
		
	case CUBIC:
		printf("\n");
		printf("***********************************\n");
		printf("************** Cubic **************\n");
		printf("***********************************\n\n");
		
		printf("--> ");
		scanf("%d", (int*)&input);
		
		printf("Cubic of %ld is %ld\n", input, ComputeCubic(input));
		printf("\n");
		
			
		state=MAIN_MENU;
		break;
		
	case NCHOOSEK:
		printf("\n");
		printf("***********************************\n");
		printf("*********** n choose k ************\n");
		printf("***********************************\n\n");
		
		printf("Enter n --> ");
		scanf("%d", &value1);
		printf("Enter k --> ");
		scanf("%d", &value2);
		printf("%d choose %d is %d\n", value1, value2, nChooseK(value1, value2));
		printf("\n");
		
		state=MAIN_MENU;
		break;
		
	case PRINTBINARY:
		
		PrintBinary();
		state=MAIN_MENU;
		break;	
		
	case ARRAYTEST:
		printf("\n");
		printf("***********************************\n");
		printf("*********** Array Test ************\n");
		printf("***********************************\n\n");
		
		ArrayTest();
		
		state=MAIN_MENU;
		break;	
		
	case EXIT:
		printf("\n");
		printf("***********************************\n");
		printf("**************  Exit **************\n");
		run=0;
		printf("***********************************\n");
		break;
	
	default:
		printf("invalid Menu selected\n\n");
		state=MAIN_MENU;
		break;
	}
	}

	return 0;
}


MenuItem PrintMainMenu(void)
{
	MenuItem selectedState = MAIN_MENU;
	printf("***********************************\n");
	printf("************ Main Menu ************\n");
	printf("***********************************\n");
	printf("Select from the following options:\n\n");
	printf("%d - NumStat\n", NUMSTAT);
	printf("%d - Factorial\n", FACTORIAL);
	printf("%d - Cubic\n", CUBIC);
	printf("%d - n choose k\n", NCHOOSEK);
	printf("%d - Binary Converter k\n", PRINTBINARY);
	printf("%d - Array Test \n", ARRAYTEST);
	printf("%d - Exit\n", EXIT);
	printf("--> ");
	scanf("%d", (int*)&selectedState);
	return selectedState;
}
	
long int ComputeCubic (long int x){
	return x*x*x;
}	


long int Factorial( int long x)
{
	long int result =0;
	
	if (x>= 1)
	{
		result = x*Factorial(x-1);
	}
	else
	{
		result =1;
	}
	return result;
}


long int NumStat(int x1, int x2)
{
	float value1 = 0, value2 = 0;
	float maxValue = 0, minValue = 0;
	

	value1 = x1;
	value2 = x2;
		
	if(value1>value2)
		{
		maxValue=value1;
		minValue=value2;
		}
	else
		{
		maxValue=value2;
		minValue=value1;
		}
		
		printf("MinValue: %f\nMaxValue: %f\n", minValue, maxValue);
		
		printf("Sum: %f\n", value1+value2);
		
		printf("Absolute Difference: %f\n", fabs(maxValue-minValue));
		
		printf("Product: %f\n", value1*value2);
		
		printf("Ratio: %f\n", value2/value1);	
		
		printf("\n");	
		
	
	return 0;
}

int nChooseK (int n, int k)
{
	long int nf=Factorial(n);
	long int kf=Factorial(k);
	long int nkf=Factorial(n-k);
	
	return (nf/(kf*nkf));
}

int PrintBinary (void)
{
	printf("\n");
	printf("***********************************\n");
	printf("************* Binary **************\n");
	printf("***********************************\n\n");
	
	int input=0;
	long binary=0;
	int rem=0;
	int i=1;
	
	printf("%ld\n",binary);
	
	printf("Enter Number --> ");
	scanf("%d", &input);
	
	int n=input;
	
	while (n !=0){
		rem=n%2;
		n= n/2;
		binary= binary+rem*i;
		i=i*10;
	}
	
	printf("%d in binary is 0b%ld\n", input, binary);

	MenuItem selectedState = MAIN_MENU;
	return selectedState;		
}

void PrintIntArray (int array[], int arrayLength){
	for (int i =0; i < arrayLength; i++)
	{
		printf("%d", array[i]);
	}
	printf("\n");
}

#define INTARRAYLENGTH 6
void ArrayTest(void){
	int intArray[INTARRAYLENGTH]={0};
	PrintIntArray(intArray, INTARRAYLENGTH);
	for (int i=0; i< INTARRAYLENGTH; i++)
	{
		intArray[i]=i;
	}
	printf("\n");
	PrintIntArray(intArray, INTARRAYLENGTH);
	printf("\n");
}

