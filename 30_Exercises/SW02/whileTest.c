#include <stdio.h>

int main(int argc, char* argv[]){
	
	int limitValue = 5;
	int counter = 0;
	
	while( counter < limitValue)
	{
		counter++;
		printf("# of while loop execution: %d\n", counter);
	}

	return 0;
}
