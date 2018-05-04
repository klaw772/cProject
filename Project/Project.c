#include <stdio.h>
#include <stdlib.h>

//James: yeah, you right
//Kat: okay. I think for option 3 it's the same as 2 but reversed


void blackjack();
void war();
void quit();
void gameOn();
int gameCheck; //global variable for re-calling the same game they had initially played

int main() {
  system("@cls||clear");
  printf("Welcome to our program!\n\n");
  printf("");
  gameOn();
  return 0;
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

void gameOn(){
  printf("Please select your choice of game by pressing 1 for Blackjack or 2 for War: ");
  int game;
  scanf("%d", &game);
  switch(game)
  {
    case 1:
      system("@cls||clear");
      printf("\n\n\n\n");
      printf("\t\t\t\t\t\t   Let's play Blackjack!\n");
      blackjack(); //calls the blackjack function
      break;
    case 2:
      system("@cls||clear");
      printf("\n\n\n\n");
      printf("\t\t\t\t\t\t   Let's play War!\n");
      war(); //calls the war function
      break;
  }
  while (game != 1 && game != 2)
  {
     printf("SorrySorrySorrySorry we didn't plan to have more than 2 games halp "); // lol
  }
}

void quit(){
  printf("\nWould you like to quit? Press 1 if you want to quit, 2 if you want to play the same game, or 3 if you would like to play the other game: ");
  char space;
  char decide;
  scanf("%c", &space);
  scanf("%c", &decide);
  switch (decide)
  {
    case '1':
      printf("Thanks for playing!\n\n\n\n\n");
      break;
    case '2':
      printf("Let's keep going with this game!\n");
      if (gameCheck == 1) //if they already called the blackjack function, then gameCheck = 1
        blackjack(); // since gameCheck = 1, it re-calls the blackjack function
      else if (gameCheck == 2) //if they had called the war function though, gameCheck = 2
        war(); // since gameCheck != 1, it re-calls the war function
    case '3': 
      printf("Let's play another game!");
      if (gameCheck == 1) //if they already called the blackjack function, then gameCheck = 1
        war(); // since gameCheck = 1, it re-calls the blackjack function
      else if (gameCheck == 2) //if they had called the war function though, gameCheck = 2
        blackjack(); // since gameCheck != 1, it re-calls the war function
      break;
  }
}
