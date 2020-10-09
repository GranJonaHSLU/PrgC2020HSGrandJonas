#include <stdio.h>
#include <stdlib.h>


//forward declaration, function prototyps
long ComputeCubic( long x);

long ComputeCubic( long x)
{
	long xCubed=0;
	xCubed= x*x*x;
	return xCubed;	
}

int main(int argc, char* argv[]){
	
	long input = atoi(argv[1]);
	long xCubed=0;
	
	xCubed = ComputeCubic (input);
	
	printf("Cubic Value: %ld\n", xCubed);


	return 0;
}
