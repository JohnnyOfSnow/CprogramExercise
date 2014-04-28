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
	char *phonenumber1;
	char *phonenumber2;
	char *areanumber;
	char *areanumberPtr; // for function strtod use
	int count = 0; // token count
	double areanumberToDouble; 
	char *entirePhoneNumber;
	long entirePhoneNumberToLong;
	char *remainderPhoneNumber; // for function strtol use


	 // prompt user input data
	puts("You should enter a phone number in this form ( 555 ) 555-5555:");
	puts("--------------------------------------------------------------");
    
   	// user getchar to read each character
	while(i < SIZE - 1 && (c = getchar()) != '\n'){
		s[i++] = c;
	}
	s[i] = '\0'; // end the string

	tokenPtr = strtok(s," "); // begin tokenizing sentence
 
	/**
	 *  continue tokenizing sentence sentence until tokenPtr becomes NULL
	 *  count = 0    catch (
	 *  count = 1    catch the areanumber
	 *  count = 2    catch the first half of the phone number
	 *  count = 3    catch the last half of the phone number
	 */
	while ( tokenPtr != NULL) {        
        if (count == 1) {
           areanumber = tokenPtr; // catch the areanumber   
        }
        tokenPtr = strtok( NULL," ");  
        count = count + 1;  
        while (count == 2 || count == 3){
               tokenPtr = strtok( NULL,"-"); 
               if (count == 2){
                    phonenumber1 =  tokenPtr; // catch the first half of the phone number   
               } else {
                    phonenumber2 =  tokenPtr; // catch the last half of the phone number
               }
               count = count + 1;    
        }
       }
    	puts("--------------------------------------------------------------");
    	areanumberToDouble = strtod(areanumber,&areanumberPtr); // string to double.
    	printf("The area code is %d\n", (int)areanumberToDouble); // for the question, should convert to integer.
    	entirePhoneNumber = strcat( phonenumber1, phonenumber2); // connect the phone number.
    	entirePhoneNumberToLong = strtol( entirePhoneNumber, &remainderPhoneNumber, 0); // string to long integer
    	printf("The phone number is %ld\n", entirePhoneNumberToLong); // print the phone number
	
    	system("pause"); // program will stop in this statement, and let user see the result.
    	return 0;
} // end main
