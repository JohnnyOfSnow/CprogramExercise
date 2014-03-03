#include <stdio.h>

int main(void){
    int ziNumber;
    int x;
    printf("You can enter a non-negative number to estimate the power of natural number e\n");
    printf("You should enter a integer to decide how many times you want to do\n");
    printf("The number is: ");
    scanf("%d", &ziNumber);
    printf("And, you should decide the variable x is: ");
    scanf("%d", &x);
    
    // The following is counter-control to estimate the power of natural number e
    
		int counter = 1;
		int sectionOneCounter = 1;
		int sectionTwoCounter = 1;
		double sectionOneResult = 1.0;
		int sectionTwoResult = 1;
		double sum;
		sum = 1.0;
		
		while(counter <= ziNumber) {
			while(sectionOneCounter <= counter) {
				sectionOneResult = sectionOneResult / sectionOneCounter;		
				sectionOneCounter = sectionOneCounter + 1;
			}
			printf("The %d! is %f\n", counter,sectionOneResult);
			
			while(sectionTwoCounter <= counter) {
				sectionTwoResult = sectionTwoResult * x;				
				sectionTwoCounter = sectionTwoCounter + 1;
			}
			printf("The %d is %d\n", counter,sectionTwoResult);
			
			sum = sum + (sectionOneResult * sectionTwoResult);			
			printf("%f\n",sum);
			counter = counter + 1;
			sectionOneCounter = 1;
			sectionTwoCounter = 1;
			sectionOneResult = 1.0;
			sectionTwoResult = 1;
		}
		
		printf("The result of estimating is %.6f", sum);
}
