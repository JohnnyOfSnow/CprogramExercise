#include <stdio.h>

#define SIZE 80

int count(int range1, int range2){
	int times = 1;
	int interval = 0;
	int bigNumber = range1;
	int smallNumber = 0;
	int biggestTime = 1;
	int renumber = 0;
	
	if(bigNumber < range2){
		smallNumber = bigNumber;
		bigNumber = range2;
	}else{
		smallNumber = range2;
	}
	
	for (interval = smallNumber; interval <= bigNumber; interval++){
		renumber = 	interval;
		times = times + 1;
		
		while(renumber != 1){
			if (renumber % 2 == 0){
				renumber = renumber / 2;
			}else{
				renumber = renumber * 3 + 1;
			}
			times = times + 1;	
		}
		
		if(biggestTime <= times){
			biggestTime = times;
		}
		times = 0;		
	}
	
	return biggestTime;
}

int main(){
	char s[SIZE]; // hold the string that user inputs.
	int c; 
	int x; // x value to be input
	int y; // y value to be input
	int i = 0; // for loop count

	 // prompt user input data
	puts("Please enter two integer, and we can get the biggest times in the range");
	printf("-------------------------------------------\n");
    
    	// user getchar to read each character
	while(i < SIZE - 1 && (c = getchar()) != '\n'){
		s[i++] = c;
	}
	
	s[i] = '\0'; // end the string

	sscanf(s, "%d%d", &x,&y); // Convert string into number 
	int biggestTime = count(x,y); // Invoke function to get gcd
	
	printf("%3d %3d %3d", x, y, biggestTime);
	
	
}
