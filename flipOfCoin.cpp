#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 
#define SIZE 2 // define a constant

int filp( void ); // function prototype

// function main begins program execution
int main(void)
{
	unsigned int counter = 1;
	unsigned int coin[SIZE] = {0}; // A array hold the result of fipping coin.
	int result = 0; // A variable hole the he result of fipping coin.
    
    /**
     *  I use while loop to simulate the fipping coin.
     *  case 1: if the coin is head, add one to index one.
     *  case 2: if the coin is tails, add one to index zero.
     */
	while(counter <= 100) {
		result = filp(); // call the function int filp( void )
		if (result == 1){
			coin[1] = coin[1] + 1;
		}else if (result == 0) {
			coin[0] = coin[0] + 1;
		}else{
			printf("Wrong process\n"); // neither 1 nor 0.
		}
		counter = counter + 1;
	}

	printf("%s%17s\n", "Coin", "Frequency"); // Display the title.
	for(int i = 0; i < SIZE; i++){
		printf("%4d%17d\n",i, coin[i]); // Display the result.
	}
	system("pause"); // Let program stop, and we can see the result.
	return 0; // Main function is sucessful.
}// end main function

/**
 *  A function can fip a coin, and print the result.
 */
int filp( void )
{
   int coin1; // A coin
   int coin2; // Decide the coin face
   
   coin1 = ( rand() % 2); // pick random coin value
   coin2 = (int)(ceil(coin1)); // Get the lower integer.
   
   /**
    *  Use if - else if - else to distinguish the face of coin.
    *  case 1: if the coin is head, print "It's heads".
    *  case 2: if the coin is tails, print "It's tails".
    */
   if (coin2 == 1) {
		printf("It's heads\n");
		return 1;
   } else if(coin2 == 0) {
		printf("It's tails\n");
		return 0;
   } else {
	   printf("Wrong toss\n");
	   return -1;
   }// end if 
} // end function filp
