#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("Number of Input Argumets: %d\n", argc);
	
	for (int i=0; i < argc; i++)
	{
		printf("Argument %d was %s\n", i, argv[i]);

	}
	return 0;
}
