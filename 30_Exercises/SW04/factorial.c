#include <stdio.h>
#include <stdlib.h>



long Factorial( long n)
{
	long result =0;
	
	if (n>= 1)
	{
		result = n*Factorial(n-1);
	}
	else
	{
		result =1;
	}
	return result;
}





int main(int argc, char* argv[]){
	
	long input = atoi(argv[1]);
	long result = 0;
	
	result = Factorial(input);
	
	printf("Factorial of %ld is %ld\n", input, result);



	return 0;
}
