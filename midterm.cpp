// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

// prototypes
void shuffle( unsigned int wDeck[][ FACES ] ); // shuffling modifies wDeck
void deal( unsigned int wDeck[][ FACES ], const char *wFace[], 
   const char *wSuit[] ); // dealing doesn't modify the arrays
void onepair(int array[], const char *wFace[]);
void twopair(int array[], const char *wFace[]);
void threesame(int array[], const char *wFace[]);
void foursame(int array[], const char *wFace[]);
void sameflower(int array[], const char *wSuit[]);

int main( void )
{
   // initialize suit array                       
   const char *suit[ SUITS ] =            
      { "Hearts", "Diamonds", "Clubs", "Spades" };
   
   // initialize face array                   
   const char *face[ FACES ] =
      { "Ace", "Deuce", "Three", "Four",         
        "Five", "Six", "Seven", "Eight",         
        "Nine", "Ten", "Jack", "Queen", "King" };

   // initialize deck array
   unsigned int deck[ SUITS ][ FACES ] = { 0 };

   srand( time( NULL ) ); // seed random-number generator

   shuffle( deck ); // shuffle the deck
   deal( deck, face, suit ); // deal the deck
   system("pause");
   return 0;
} // end main

// shuffle cards in deck
void shuffle( unsigned int wDeck[][ FACES ] )
{
   size_t row; // row number
   size_t column; // column number
   size_t card; // counter

   // for each of the cards, choose slot of deck randomly
   for ( card = 1; card <= CARDS; ++card ) {

      // choose new random location until unoccupied slot found
      do {                                                        
         row = rand() % SUITS;                                   
         column = rand() % FACES;                             
      } while( wDeck[ row ][ column ] != 0 ); // end do...while

      // place card number in chosen slot of deck
      wDeck[ row ][ column ] = card;
   } // end for
} // end function shuffle

// deal cards in deck
void deal( unsigned int wDeck[][ FACES ], const char *wFace[],
   const char *wSuit[] )
{
   size_t card; // card counter
   size_t row; // row counter
   size_t column; // column counter
   int array[6];
   
   // initialize suit array                       
   const char *suit[ SUITS ] =            
      { "Hearts", "Diamonds", "Clubs", "Spades" };
   
   // initialize face array                   
   const char *face[ FACES ] =
      { "King","Ace", "Deuce", "Three", "Four",         
        "Five", "Six", "Seven", "Eight",         
        "Nine", "Ten", "Jack", "Queen" };
        
        
   printf("You get five card are\n");
   puts(" ");
   // deal each of the cards
   for ( card = 1; card <= 5; ++card ) {
      // loop through rows of wDeck
      for ( row = 0; row < SUITS; ++row ) {
         // loop through columns of wDeck for current row
         for ( column = 0; column < FACES; ++column ) {
            // if slot contains current card, display card
            if ( wDeck[ row ][ column ] == card ) {
               printf( "%5s of %-8s\n", wFace[ column ], wSuit[ row ]); 
               array[card] = (column + 1) + (row * 13);
            } // end if
         } // end for
      } // end for
   } // end for
   
   
   onepair(array,face);
   twopair(array,face);
   threesame(array,face);
   foursame(array,face);
   sameflower(array,suit);
} // end function deal

void onepair(int array[], const char *wFace[]){
     int count[13] = {0};
     int card;
     int hold;
     
     for(card = 1; card <= 5; ++card) {
          hold = array[card] % 13;
          count[hold] = count[hold] + 1;   
     }
     puts(" ");
     
     for(card = 0; card <=12; ++card) {
              if(count[card] == 2){
                             printf("You have a pair of %-8s\n", wFace[card]);
              }
     }
}

void twopair(int array[], const char *wFace[]){
     int count[13] = {0};
     int card;
     int hold;
     int count1 = 0;
     
     for(card = 1; card <= 5; ++card) {
          hold = array[card] % 13;
          count[hold] = count[hold] + 1;   
     }
     puts(" ");
     
     for(card = 0; card <=12; ++card) {
              if(count[card] == 2){
                             count1 = count1 + 1;
              }
              if(count1 == 2){
              			     printf("You have two pair \n");
              			     break;
              }
     }
}

void threesame(int array[], const char *wFace[]){
	int count[13] = {0};
     int card;
     int hold;
     
     for(card = 1; card <= 5; ++card) {
          hold = array[card] % 13;
          count[hold] = count[hold] + 1;   
     }
     puts(" ");
     
     for(card = 0; card <=12; ++card) {
              if(count[card] == 3){
                             printf("You have a three same of %-8s\n", wFace[card]);
              }
     }
}

void foursame(int array[], const char *wFace[]){
	 int count[13] = {0};
     int card;
     int hold;
     
     for(card = 1; card <= 5; ++card) {
          hold = array[card] % 13;
          count[hold] = count[hold] + 1;   
     }
     puts(" ");
     
     for(card = 0; card <=12; ++card) {
              if(count[card] == 4){
                             printf("You have a four same of %-8s\n", wFace[card]);
              }
     }
}

void sameflower(int array[], const char *wSuit[]){
	int count[4] = {0};
     int card;
     int hold;
     
     for(card = 1; card <= 5; ++card) {
          hold = array[card] % 4;
          count[hold] = count[hold] + 1;   
     }
     puts(" ");
     
     for(card = 0; card <= 3; ++card) {
              if(count[card] == 5){
                             printf("You have a four same of %-8s\n", wSuit[card]);
              }
     }
}






