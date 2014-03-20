#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 2

int filp( void );

int main(void)
{
	unsigned int counter = 1;
	unsigned int coin[SIZE] = {0};
	int result = 0;

	while(counter <= 100) {
		result = filp();

		if (result == 1){
			coin[1] = coin[1] + 1;
		}else if (result == 0) {
			coin[0] = coin[0] + 1;
		}else{
			printf("Wrong process\n");
		}
		counter = counter + 1;
	}

	printf("%s%17s\n", "Coin", "Frequency");
	for(int i = 0; i < SIZE; i++){
		printf("%4d%17d\n",i, coin[i]);
	}
	system("pause");
	return 0;
}


int filp( void )
{
   int coin1; // A coin
   int coin2; // Decide the coin face
   
   coin1 = ( rand() % 2); // pick random coin value
   coin2 = (int)(ceil(coin1));
   
   if (coin2 == 1) {
		printf("It's heads\n");
		return 1;
   } else if(coin2 == 0) {
		printf("It's tails\n");
		return 0;
   } else {
	   printf("Wrong toss\n");
	   return -1;
   }
   
} // end function filp
