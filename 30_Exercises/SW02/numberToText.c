#include <stdio.h>

int main(int argc, char* argv[]){

	int InputValue = 1;
	
	
	while(InputValue != 10){
	
	printf("Enter a number between (including) 0 and 9: ");
	
	scanf("%d", &InputValue);
	
	
	
	if (InputValue == 10){
		printf("Thank you. Good bye.\n");
		break;
	}
	
	switch(InputValue){
	
	case 0:
	printf ("0 as text is 'zero'\n");
	break;
	
	case 1:
	printf ("1 as text is 'one'\n");
	break;
	
	case 2:
	printf ("2 as text is 'two'\n");
	break;
	
	case 3:
	printf ("3 as text is 'three'\n");
	break;
	
	case 4:
	printf ("4 as text is 'four'\n");
	break;
	
	case 5:
	printf ("5 as text is 'five'\n");
	break;
	
	case 6:
	printf ("6 as text is 'six'\n");
	break;
	
	case 7:
	printf ("7 as text is 'seven'\n");
	break;
	
	case 8:
	printf ("8 as text is 'eight'\n");
	break;
	
	case 9:
	printf ("9 as text is 'nine'\n");
	break;
	
	
	default:
	printf("invalid -> try again\n");
	break;
	
	}
	
	
	}	


	return 0;
}

