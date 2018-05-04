#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BLQ.h"


char *suits_str[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
char *faces_str[13] = {"2", "3", "4", "5", "6", "7", "8", "9",
            "10", "Jack", "Queen", "King", "Ace"};


enum suits { SPADES, HEARTS, DIAMONDS, CLUBS };
enum faces { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
             JACK, QUEEN, KING, ACE };
int suit;
int face;

int deck[52];


/*
** QUEUE IMPLEMENTATION
*/










/*
** QUEUE IMPLEMENTATION ENDS
*/



/*
** GAME IMPLEMENTATION
*/


// main method
int main() {
  srand(time(NULL));
  system("@cls||clear");
  printf("Welcome to our program!\n\n");
  printf("");
  gameOn();
  return 0;
}

void printDeck(){


  printf("Here is a shuffled deck:\n");
  for (int i = 0; i < 52; i++) {
       int card = deck[i];
       int suit = card / 13;
       int face = card % 13;
       printf("%s of %s\n", suits_str[face], faces_str[suit]);
     }


}

// creates and shuffles the deck
void shuffleDeck(){

for (int i = 0; i < 52; i++) {
     /* start with a sorted deck */
     deck[i] = i;
}

for (int i = 0; i < 1000; i++) {
    /* shuffle by swapping cards pseudo-randomly a 1000 times */
    int from = rand() % 52;
    int to = rand() % 52;
    int card = deck[from];
    deck[from] = deck[to];
    deck[to] = card;
}

}


// A barebones function that sets global variable gameCheck to 1
// and prints a successful game played message
void blackjack(){
  gameCheck = 1;


  printf("Believe it or not, you just played Blackjack!\n");


  quit();
}



// A barebones function that sets global variable gameCheck to 2
// and prints a successful game played message
void war(){
  gameCheck = 2;

  shuffleDeck();
  printDeck();
  printf("Believe it or not, you just played War!\n");


  quit();
}


// primary game function
void gameOn(){
  printf("Please select your choice of game by pressing 1 for Blackjack or 2 for War: ");
  int game;
  scanf("%d", &game);
  while (game != 1 && game != 2)
  {
     printf("Not a valid option. Please select your choice of game by pressing 1 for Blackjack or 2 for War: "); // lol
     scanf("%d", &game);
  }
  switch(game)
  {
    case 1:
      system("@cls||clear");
      printf("\n\n\n\n");
      printf("Let's play Blackjack!\n");
      blackjack(); //calls the blackjack function
      break;
    case 2:
      system("@cls||clear");
      printf("\n\n\n\n");
      printf("Let's play War!\n");
      war(); //calls the war function
      break;
  }
}

// method for quitting the game at various stages
void quit(){
  printf("\nWould you like to quit? Press 3 if you want to quit, 4 if you want to play the same game, or 5 if you would like to play the other game: ");
  int decide;
  scanf("%d", &decide);
  while ((decide != 3) && (decide != 4) && (decide != 5))
  {
    printf("Not a valid option. Press 3 if you want to quit, 4 if you want to play the same game, or 5 if you would like to play the other game: ");
    scanf("%d", &decide);
  }
  switch (decide)
  {
    case 3:
      printf("Thanks for playing!\n\n\n\n\n");
      break;
    case 4:
      printf("Let's keep going with this game!\n");
      if (gameCheck == 1) //if they already called the blackjack function, then gameCheck = 1
        blackjack(); // since gameCheck = 1, it re-calls the blackjack function
      else if (gameCheck == 2) //if they had called the war function though, gameCheck = 2
        war(); // since gameCheck != 1, it re-calls the war function
      break;
    case 5:
      printf("Let's play another game!\n");
      if (gameCheck == 1) //if they already called the blackjack function, then gameCheck = 1
        war(); // since gameCheck = 1, it re-calls the blackjack function
      else if (gameCheck == 2) //if they had called the war function though, gameCheck = 2
        blackjack(); // since gameCheck != 1, it re-calls the war function
      break;
  }



/*
** GAME IMPLEMENTATION ENDS
*/
}
