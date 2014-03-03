#include <stdio.h>

int main(void){
    int ziNumber;
    printf("You can enter a non-negative number to estimate the natural number e\n");
    printf("The number is: ");
    scanf("%d", ziNumber);
    
    // The following is counter-control to estimate the natural number e
    int counter = 1;
    double x, sum;
    x = 1.0;
    sum = 1.0;
    while(counter <= ziNumber) {
	x = x / counter;
	sum = sum + x;
	counter = counter + 1;
    }
    
    printf("The result of estimating is %.6f", sum);
}
