#include <stdio.h>

#include "bitOperations.h"

void SetBitNInByte( unsigned char* target, unsigned char bitNumber){
	*target |= (1 << bitNumber);
}


void ClearBitNInByte( unsigned char* target, unsigned char bitNumber){
	*target &=~(1 << bitNumber);

}


void FlipBitN( unsigned char* target, unsigned char bitNumber){
	*target ^=(1 << bitNumber);
}
unsigned char CheckBitN( unsigned char* target, unsigned char bitNumber){
	if (*target &(1<<4)){
		printf("Bitnumber %d is 1\n", bitNumber);
	}
	else{
		printf("Bitnumber %d is 0\n", bitNumber);
	}
}

