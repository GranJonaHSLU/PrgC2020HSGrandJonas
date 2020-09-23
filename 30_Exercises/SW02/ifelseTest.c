#include <stdio.h>

int main ( int argc, char* argv[]) {
	int testValue = 3;
	int limitValue = 3;
	
	if (testValue >= limitValue ) {
		printf("%d is bigger than or equal to %d\n", testValue, limitValue);
	}
	else{
		printf("%d is less than %d\n", testValue, limitValue);
	}
	
	return 0;
}
