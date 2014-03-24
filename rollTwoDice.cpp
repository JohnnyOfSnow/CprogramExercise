#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13


int rollDice(void);

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
    
    // Print the result header
    printf("%s%17s\n", "Face", "Frequency");
    
    // Display result in tabular format
    for(int i = 2; i < SIZE; ++i){
            printf("%4d%17d\n", i, dice[i]);
    }
    
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

