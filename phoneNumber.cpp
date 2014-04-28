#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#define SIZE 80

int main( void )
{
	char s[SIZE]; // hold the string that user inputs.
	int c; 
	int i = 0; // for loop count
	char *tokenPtr;
	unsigned long int x;
	char *reminderPtr;
	char number;


	 // prompt user input data
	puts("You should enter a phone number in this form (555) 555-5555:\n");
    
    	// user getchar to read each character
	while(i < SIZE - 1 && (c = getchar()) != '\n'){
		s[i++] = c;
	}
	s[i] = '\0'; // end the string

	tokenPtr = strtok(s,"(");
	printf("%s\n", tokenPtr);
	
	x = strtoul(tokenPtr,&reminderPtr,0 );
	
	printf(%lu, x);
	
	
	system("pause");
   return 0;
} // end main
