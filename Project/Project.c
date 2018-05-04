#include <stdio.h>
#include <stdlib.h>

void blackjack();
void war();

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
      printf("\t\t\t\t\t\t   Let's play Blackjack!");
      break;
    case 2:
      system("@cls||clear");
      printf("\n\n\n\n");
      printf("\t\t\t\t\t\t   Let's play War!");
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
      printf("Let's keep going!");
      break;
  }
  return 0;
}
