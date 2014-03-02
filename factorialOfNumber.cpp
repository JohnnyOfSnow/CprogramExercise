#include <stdio.h>

int main(void){
    int ziNumber;
    printf("You can enter a non-negative number to give a factorial of the number\n");
    printf("The number is: ");
    scanf("%d", ziNumber);
    
    int result = 1;
    int counter = 0;
		int zinumber = number;
		counter = zinumber;
		while(counter > 0){
			result = result * counter;
			counter = counter - 1;
		}
		
		printf("%d! is %d",ziNumber, result);
}
