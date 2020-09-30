#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	float value1 = 0, value2 = 0;
	float maxValue = 0, minValue = 0;
	
	//make sure, we have exactly 2 arguments
	
	if(argc != 3)
	{
		//usage message
		printf("usage: logicOperators val1 val2\n");
	}
	else
	{
		value1 = atof(argv[1]);
		value2 = atof(argv[2]);
		
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
		
	}



	return 0;
}
