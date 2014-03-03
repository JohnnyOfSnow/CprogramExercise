	
#include <stdio.h>

int main(void){
	printf("%s  %9s","pi","estimate pi\n" );
	double pi;
	double number;
	double reNumber;
	reNumber = -1.0;
	pi = 0.0;
	number = 1.0;
	for(int i = 1; i <= 1; i++){
		reNumber = reNumber + 2;
		number = number / reNumber;
		if(i % 2 == 0){
			number = -1 * number;
		}
		pi = pi + (4 * number);
		number = 1.0;
		printf("%2d  %.6f\n",i,pi );
		
	}

}
