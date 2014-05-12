// Fig. 10.16: fig10_16.c
// Representing cards with bit fields in a struct
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARDS 52
#define SUITS 4
#define FACES 13


// bitCard structure definition with bit fields
struct bitCard {                                  
   unsigned int face : 4; // 4 bits; 0-15        
   unsigned int suit : 2; // 2 bits; 0-3         
   unsigned int color : 1; // 1 bit; 0-1          
}; // end struct bitCard                          

typedef struct bitCard Card; // new type name for struct bitCard   

void fillDeck( Card * const wDeck ); // prototype
void deal( const Card * const wDeck ,const char *wFace[], 
   const char *wSuit[]); // prototype
void shuffle(Card * const wDeck);
void onepair(int array[], const char *wFace[]);
void twopair(int array[], const char *wFace[]);
void threesame(int array[], const char *wFace[]);
void foursame(int array[], const char *wFace[]);
void sameflower(int array[], const char *wSuit[]);


int main( void )
{ 
   Card deck[ CARDS ]; // create array of Cards
   
   // initialize array of pointers
   const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
      "Six", "Seven", "Eight", "Nine", "Ten",
      "Jack", "Queen", "King"};

   // initialize array of pointers
   const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};
   srand( time( NULL ) ); // seed random-number generator
   fillDeck( deck );
   shuffle( deck );
   deal( deck, face, suit);
   system("pause");
   return 0;
} // end main

// initialize Cards
void fillDeck( Card * const wDeck )
{ 
   size_t i; // counter

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) { 
      wDeck[ i ].face = i % (CARDS / 4); 
      wDeck[ i ].suit = i / (CARDS / 4);  
      wDeck[ i ].color = i / (CARDS / 2);
   } // end for
} // end function fillDeck

void shuffle(Card * const wDeck){
     size_t i;
     size_t j;
     Card temp;
     
     for(i = 0; i < CARDS; ++i){
           j = rand() % CARDS;
           temp = wDeck[ i ];
           wDeck[ i ] = wDeck[ j ];
           wDeck[ j ] = temp;
     }  
}

// output cards in two-column format; cards 0-25 subscripted with 
// k1 (column 1); cards 26-51 subscripted with k2 (column 2)
void deal( const Card * const wDeck,const char *wFace[], 
   const char *wSuit[])
{ 
   size_t k1; // subscripts 0-25
   size_t k2; // subscripts 26-51
   int i;
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
   
   // loop through wDeck
   for(i = 1; i < 6; i++){
         printf("Card: %3d Suit: %3d\n", wDeck[i].face, wDeck[i].suit);
         printf("The card is %5s of %-8s\n", wFace[wDeck[i].face], wSuit[wDeck[i].suit]);
         array[i] = (wDeck[i].face + 1) + (wDeck[i].suit * 13);
   }
    puts(" ");
   
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
          if(array[card] % 13 == 0){
                  hold = (array[card] / 13) - 1;              
          } else {
                  hold = array[card] / 13;                  
                  count[hold] = count[hold] + 1;
          }       
     }    
     for(card = 0; card <= 3; ++card) {
              if(count[card] == 5){
                             printf("You have a five same of %-8s\n", wSuit[card]);
              }
     }
}

