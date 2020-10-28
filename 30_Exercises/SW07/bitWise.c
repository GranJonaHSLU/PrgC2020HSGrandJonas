#include <stdio.h>


int main (int argc, char *argv[])
{
	unsigned char a = 12;
	unsigned char b = 25;
	
	printf("bitwise &: %d\n", a & b);
	printf("bitwise |: %d\n", a | b);
	printf("bitwise ^: %d\n", a ^ b);
	printf("bitwise ~: %u\n", ~a);
		


	return 0;
}
