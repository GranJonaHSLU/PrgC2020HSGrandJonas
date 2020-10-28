#include <stdio.h>

#include "bitOperations.h"

int main( int argc, char *argv[] )
{
	unsigned char myNumber = 0x10; //16 decimal
	
	printf("Before: %d, 0x%x\n", (unsigned char)myNumber, (unsigned char)myNumber);
	SetBitNInByte(&myNumber, 1);
	//erwatet Resultat: 0x12 //18 decimal
	
	printf("After setting Bit 1: %d, 0x%x\n", (unsigned char)myNumber, (unsigned char)myNumber);
	
	SetBitNInByte(&myNumber, 7);
	//erwatet Resultat: 0x92 //146 decimal
	
	printf("After setting Bit 7: %d, 0x%x\n", (unsigned char)myNumber, (unsigned char)myNumber);
	
	ClearBitNInByte(&myNumber, 7);
	printf("After clearing Bit 7: %d, 0x%x\n", (unsigned char)myNumber, (unsigned char)myNumber);
	
	FlipBitN(&myNumber, 7);
	printf("After flipping Bit 7: %d, 0x%x\n", (unsigned char)myNumber, (unsigned char)myNumber);
	
	
	CheckBitN(&myNumber, 7);
	
	
	return 0;
}
