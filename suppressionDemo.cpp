#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#define SIZE 80

int main( void )
{
	
    int areanumber;
    int phonenumber1;
    int phonenumber2;

	  // prompt user input data
	  puts("You should enter a phone number in this form (555) 555-5555:");
	  puts("--------------------------------------------------------------");
    scanf("%*c%d%*c%d%*c%d", &areanumber, &phonenumber1, &phonenumber2);
   	// user getchar to read each character
	  puts("--------------------------------------------------------------");
	
	  printf("The area number is %d\n", areanumber);
	  printf("The phone number is %d%d\n", phonenumber1, phonenumber2);
	
	  system("pause"); // program will stop in this statement, and let user see the result.
	  return 0;
} // end main
