#include <stdio.h>
#include <stdlib.h>
#define SIZE 80
int getGCD(int x, int y);

/**
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}*/

int main(void){
	char s[SIZE]; // hold the string that user inputs.
	int c; 
	int x; // x value to be input
	int y; // y value to be input
	int i = 0; // for loop count

    // prompt user input data
	puts("Please enter two integer, and we can get GCD");
    printf("-------------------------------------------\n");
    
    // user getchar to read each character
	while(i < SIZE - 1 && (c = getchar()) != '\n'){
		s[i++] = c;
	}
	s[i] = '\0'; // end the string
	
	sscanf(s, "%d%d", &x,&y); // Convert string into number 
	int gcd = getGCD(x,y); // Invoke function to get gcd
	printf("--------------------------------------------\n");
	if (gcd == 0){
         printf("Your input is wrong, GCD is based on non-negative number and not zero.\n");   
    } else {
   	     printf("We can get GCD is %d for %d and %d\n", gcd, x, y); 
    }

	system("pause");
	return 0;
}

int getGCD(int x, int y){
    
    // Exception handle, x = 0 , y = 0,or x = y = 0
    if(x * y == 0){
         return 0;
    }
    
    // Exception handle, x < 0, y < 0,or x < 0 y < 0
    if(x < 0 || y < 0){
         return 0;
    }
    
	int bigNumber = x;
	if(bigNumber < y){
        bigNumber = y;
        y = x;         
    }
	
	int gcd = 0;
	// The biggest gcd is the small number(y), so check the gcd fron it.
	for(gcd = y; gcd >= 1; gcd--){
            if((bigNumber % gcd == 0) && (y % gcd == 0)){
                          return gcd; // Find the gcd
            }
    }
	
	return 1; // The small gcd is 1.
}


