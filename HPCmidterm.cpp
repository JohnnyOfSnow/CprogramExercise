// Fig. 10.3: fig10_03.c
// Card shuffling and dealing program using structures
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CARDS 52
#define FACES 13
#define SUITS 4

// card structure definition                  
struct card {                                 
   const char *face; // define pointer face   
   const char *suit; // define pointer suit
   int number;   
}; // end struct card                         

typedef struct card Card; // new type name for struct card   

// prototypes
void fillDeck( Card * const wDeck, const char * wFace[], 
   const char * wSuit[] );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck);
void onepair(int array[], const char *wFace[]);
void twopair(int array[], const char *wFace[]);
void threesame(int array[], const char *wFace[]);
void foursame(int array[], const char *wFace[]);
void sameflower(int array[], const char *wSuit[]);

int main( void )
{ 
   Card deck[ CARDS ]; // define array of Cards

   // initialize array of pointers
   const char *face[] = { "一", "老二", "三", "四", "五",
      "六", "七", "八", "九", "十",
      "十一", "十二", "老k"};

   // initialize array of pointers
   const char *suit[] = { "紅心", "方塊", "梅花", "黑桃"};

   srand( time( NULL ) ); // randomize

   fillDeck( deck, face, suit ); // load the deck with Cards
   shuffle( deck ); // put Cards in random order
   deal( deck); // deal all 52 Cards
   system("pause");
   return 0;
} // end main

// place strings into Card structures
void fillDeck( Card * const wDeck, const char * wFace[], 
   const char * wSuit[] )
{ 
   size_t i; // counter

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) { 
      wDeck[ i ].face = wFace[ i % FACES ];
      wDeck[ i ].suit = wSuit[ i / FACES ];
      wDeck[ i ].number = i;
   } // end for
} // end function fillDeck

// shuffle cards
void shuffle( Card * const wDeck )
{ 
   size_t i; // counter
   size_t j; // variable to hold random value between 0 - 51
   Card temp; // define temporary structure for swapping Cards
   int tempForNumber;

   // loop through wDeck randomly swapping Cards
   for ( i = 0; i < CARDS; ++i ) { 
      j = rand() % CARDS;
      temp = wDeck[ i ];      
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;
      
   } // end for
} // end function shuffle

// deal cards
void deal( const Card * const wDeck)
{ 
   // initialize suit array                       
   const char *suit[ SUITS ] =            
      { "紅心", "方塊", "梅花", "黑桃" };
   
   // initialize face array                   
   const char *face[ FACES ] ={ "老k","一", "老二", "三", "四", "五",
      "六", "七", "八", "九", "十", "十一", "十二" };
   size_t i; // counter
   int array[6];
   int count = 0;
   int hand = 1;

   printf("現在為第 %d 手牌\n", hand);
   
   puts(" ");
   // loop through wDeck
   for ( i = 1; i < 51; ++i ) {
      printf( "%5s%-8s\n",  wDeck[ i ].suit,wDeck[ i ].face);
      count = count + 1;
      array[count] = wDeck[ i ].number + 1;
      if(count == 5){
      	puts(" ");
      	hand = hand + 1;
   		onepair(array,face);
   		twopair(array,face);
  		threesame(array,face);
   		foursame(array,face);
   		sameflower(array,suit);
		count = 0;
		int array[6] = {0};
		puts("-------------------------");
		if(i == 50){
		} else {
			printf("現在為第 %d 手牌\n", hand);
			puts(" "); 
		}
      	
      }
   }
    
   
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
                             printf("你有一對%-8s\n", wFace[card]);
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
              				 puts(""); 
              			     printf("你有兩對\n");
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
                             printf("你有%s的三條\n", wFace[card]);
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
                             printf("你有%-8s的鐵支\n", wFace[card]);
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
                             printf("你有%-8s的同花\n", wSuit[card]);
              }
     }
}
