#include <stdio.h>
#include <stdlib.h>

void blackjack();
void war();
int gameCheck; //global variable for re-calling the same game they had initially played

int main() {
  system("@cls||clear");
  printf("Welcome to our program!\n\n");
  printf("");
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
     printf("Sorry, "); // LOL THIS JUST KEEPS PRINTING SORRY, I LOVE IT
  }
  printf("\nWould you like to quit? Press y if you want to quit, or n if you want to stay in the program: ");
  char space;
  char decide;
  scanf("%c", &space);
  scanf("%c", &decide);
  switch (decide)
  {
    case 'y':
    case 'Y':
      printf("Thanks for playing!\n\n\n\n\n");
      break;
    case 'n':
    case 'N':
      printf("Let's keep going!\n"); // unfortunately this code doesn't loop, since after it re-calls the game they played, the main function ends.
                                     // So it currently just calls it once more if they say they want to keep playing
      if (gameCheck == 1) //if they already called the blackjack function, then gameCheck = 1
        blackjack(); // since gameCheck = 1, it re-calls the blackjack function
      else //if they had called the war function though, gameCheck = 2
        war(); // since gameCheck != 1, it re-calls the war function
      break;
  }
  return 0;
}

// A barebones function that sets global variable gameCheck to 1
// and prints a successful game played message
void blackjack(){}
  gameCheck = 1;
  printf("Believe it or not, you just played Blackjack!\n");
}

// A barebones function that sets global variable gameCheck to 2
// and prints a successful game played message
void war(){
  gameCheck = 2;
  printf("Believe it or not, you just played War!\n");
}
