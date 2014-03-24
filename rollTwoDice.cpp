#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13


int rollDice(void);
void printResult(int a[]);

int main(void){
    
    int dice[SIZE] = {0}; // Define a array that hold the result
    int myDice = 0; // Use to invoke function rollDice and hold value
    
    srand(time(NULL)); // randomize without entering a seed each time
    
    /**
     *  for loop use to invoke rollDice 36000 times
     */
    for(int roll = 1; roll <= 36000; ++roll){
            myDice = rollDice();
            ++dice[myDice];
    }
    
    
    
    // Display result in histogram
    printResult(dice);
    
    system("pause");
    return 0;
}

// A function use to simulate roll two dice
int rollDice(void){
    
    unsigned int dice1;  // non- negative integer, the first dice
    unsigned int dice2;  // non- negative integerm the second dice
    unsigned int sum;  // non- negative integer, sum = dice1 + dice2

    
    dice1 = 1 + rand() % 6;  // random from 1 to 6
    dice2 = 1 + rand() % 6;  // random from 1 to 6
    
    sum = dice1 + dice2; 
    
    return sum;
}

// A function use to print the result
void printResult(int a[]){
     int starNumber = 0; // record the number of star
     int underStar = 0; // record the value that is less than 200
     
     // output header for result columns
     printf("%s%11s%19s\n\n%59s\n%59s\n\n", 
            "Response", "Frequency", "Histogram",
            "1    1    2    2    3"," 5    0    5    0    5    0");
            
     // output result
     for (int k = 2; k < SIZE; ++k){
         printf("%8d%10d           ", k, a[k]);
         starNumber = a[k] / 200;
         underStar = a[k] - (starNumber * 200);
         
         // output histogram bar representing frequency value
         for(int star = 1; star <= starNumber; ++star ){
                 printf("%s", "*");
         }
         printf(" + %d", underStar);
         printf("    * = %d ", starNumber);
         
         puts(""); // being new line of output
         starNumber = 0; // Initializing 
         underStar = 0;  // Initializing 
     }
     printf("%130s%2s%3s\n", " * ", " = ", " 200 ");  // Print the * 's value
}

