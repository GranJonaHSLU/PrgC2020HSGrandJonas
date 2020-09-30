#include <stdio.h>

int main(int argc, char* argv[]){

	short largeShort = 32760;
	printf("before:%d  ", largeShort);
	largeShort = largeShort +12345;
	printf("after:%d\n\n", largeShort);


	return 0;
}
