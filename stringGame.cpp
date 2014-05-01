#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80
void printTheRequire(char *string1, char *string2, int timesToInt);

int main( void )
{
    
    char s[SIZE]; // hold the string that user inputs.
	int c; 
	int i = 0; // for loop count
	char *tokenPtr; 
	int count = 0; 
	char *string1; // hold the string 1
	char *string2; // hold the string 2
	char *times; // hold the print times
	double timesToDouble; // A variable to save the value that char *times convert to double.
	char *timesPtr; // A pointer to point the times
	int timesToInt; // A variable to save the value that double timesToDouble convert to int.
    
     // prompt user input data
	puts("You can enter two string and a number\nProgram will connect two string\nand print the string many time that you enter the number");
	puts("--------------------------------------------------------------");
	puts("User should enter in this form.\nHollo Java 4");
	puts("--------------------------------------------------------------");
	puts("Your enter is:");
	
   	// user getchar to read each character
	while(i < SIZE - 1 && (c = getchar()) != '\n'){
		s[i++] = c;
	}// end while
	
	s[i] = '\0'; // end the string
    
    tokenPtr = strtok(s," "); // begin tokenizing sentence
    
    // continue tokenizing sentence until tokenPtr becomes NULL
    while ( tokenPtr != NULL) {
          switch(count){
                  case 0: 
                      string1 = tokenPtr;
                      break;
                  case 1:
                      string2 = tokenPtr;
                      break;
                  case 2:
                      times = tokenPtr;
                      break;
                  default:
                      printf("The program have a logical error.");      
          }// end switch
          tokenPtr = strtok(NULL," "); // get next token
          count = count + 1;
    }// end while
    
    puts("--------------------------------------------------------------");
    timesToDouble = strtod(times, &timesPtr);
    timesToInt = (int)timesToDouble; // cast the timesToDouble, and let it change to an integer.
    printTheRequire(string1, string2, timesToInt); // invoke function printTheRequire.  
    system("pause"); // Let program stop in this statement, and user can see the result.
    return 0;
} // end main

void printTheRequire(char *string1, char *string2, int timesToInt){
     char *srtingCombine = strcat(string1, string2); // connect string1 and string2, and save to srtingCombine. 
     int i; // A for loop counter
     
     for(i = 1; i <= timesToInt; i++){
           printf("%s\n", srtingCombine); // print the srtingCombine
     }
     puts("--------------------------------------------------------------");
     printf("%s is printed %d times.\n", srtingCombine, timesToInt);
}
