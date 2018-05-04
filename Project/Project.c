#include <stdio.h>
#include <stdlib.h>
#include "BLQ.h"


// main method
int main() {
  system("@cls||clear");
  printf("Welcome to our program!\n\n");
  printf("");
  gameOn();
  return 0;
}


void drawCard(){

  int card = 1 + (rand()% 3);


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


}
