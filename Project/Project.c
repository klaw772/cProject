#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "BLQ.h"

// I DON'T KNOW IF WE EVEN NEED QUEUES. We can easily just iterate through an array
// to find values that aren't == to 0. Both players have an array of 52 cards,
// and when they're playing a card, for example, it searches through the front (or back)
// of the array and prints the first value that isn't 0. Then, when a player wins a battle,
// the values of the cards they won can be added to the first indecies of the ray that
// == 0. This is still possible with queues, and may be more time efficient, but there is
// the option there. Okay, end rant.

//This is a great rant.
//ty ty





/*
** GAME IMPLEMENTATION
*/


// main method
int main() {
  srand(time(NULL));
  system("@cls||clear");
  printf("Welcome to our program!\n\n");
  sleep(1);
  gameOn();
  return 0;
}

 //prints the face and suit of each card in the deck
void printDeck(struct Queue* deck){
  printf("Printing the specified deck:\n");
  for (int i = 0; i < deck->capacity; i++) {
       int card = deck->array[i];
       int suit = card / 13;
       int face = card % 13;
       printf("%s of %s\n", faces_str[face], suits_str[suit]);
     }
}

// creates and shuffles the deck
void shuffleDeck(struct Queue* deck){
  for (int i = 0; i < deck -> capacity; i++) {
       /* start with a sorted deck */
     addQ(deck, i);
   }

  for (int i = 0; i < 1000; i++) {
    /* shuffle by swapping cards pseudo-randomly a 1000 times */
    int from = rand() % deck->capacity;
    int to = rand() % deck->capacity;
    int card = deck->array[from];
    deck->array[from] = deck->array[to];
    deck->array[to] = card;
  }

}

/**void divideCards (struct Queue* humanPile, struct Queue* computerPile, struct Queue* deck){
  for (int i = 0; i < deck -> capacity; i++){

  }

}
**/

// A barebones function that sets global variable gameCheck to 1
// and prints a successful game played message
void blackjack(){
  gameCheck = 1;
  system("@cls||clear");
  struct Queue* queue = createQ(1000);

      addQ(queue, 10);
      addQ(queue, 20);
      addQ(queue, 30);
      addQ(queue, 40);

      printf("%d removed from queue\n", removeQ(queue));

      printf("Front item is %d\n", frontQ(queue));
      printf("Back item is %d\n", backQ(queue));


  printf("Believe it or not, you just played Blackjack!\n");

  quit();
}



// War game function
void war(){
  gameCheck = 2;
  system("@cls||clear");
  char placeholder;
  scanf("%c", &placeholder);
  char enter;
  printf("Welcome to the game of War! Here are the rules. Press enter after you read each step to move on to the next step.\n\n");
  printf("Step 1: We will be using a standard deck of 52 cards. After shuffling, the deck is divided into two piles: one for you and one for the computer.\n\n"); //starting the rules
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to continue!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  printf("Step 2: You will draw the topmost card from your pile and show it. The computer will do the same.\n\n");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to continue!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  printf("Step 3: These cards' values will be compared, and whoever has the higher value will take both cards and put them at the bottom of their pile of cards.\n\n");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to continue!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  printf("Step 4: If the cards are of the same rank, then it is War!! Draw 3 cards face-down, then draw the fourth card face-up. These cards' values will be compared, and whoever has the higher value will take all the cards! These will all be put at the bottom of their pile of cards.\n\n");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to continue!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  printf("Step 5: Whoever ends up with all of the cards at the end of the game wins!\n\n");
  printf("When you are ready to play, press enter to start!");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to start playing!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  struct Queue* deck = createQ(52);
  printf("Shuffling the deck!\n\n");
  sleep(3); //delays for aesthetic effect
  shuffleDeck(deck);
  printf("Dealing the cards to each player!\n\n");
  struct Queue* humanPile = createQ(52); //queues with max capacities of 52
  struct Queue* computerPile = createQ(52);
  //divideCards(humanPile, computerPile, deck);
  printf("Your pile\n"); //these are here mostly to check that divide cards method works
  //printDeck(humanPile);
  printf("Computer pile\n");
  //printDeck(computerPile);
  printf("Believe it or not, you just played War!\n");
  quit();
}


// initial game set-up function at start of program
void gameOn(){
  printf("Please select your choice of game by pressing 1 for Blackjack or 2 for War: ");
  int game;
  scanf("%d", &game);
  while ((game != 1 && game != 2) && (sizeof(game) != sizeof(int)))
  {
     printf("Not a valid option. Please select your choice of game by pressing 1 for Blackjack or 2 for War: "); // lol
     scanf("%d", &game);
  }
  switch(game)
  {
    case 1:
      printf("Let's play Blackjack!\n\n\n\n");
      printf("Loading....\n");
      sleep(3);
      blackjack(); //calls the blackjack function
      break;
    case 2:
      printf("\n\n\n\n");
      printf("Let's play War!\n\n\n\n");
      printf("Loading....\n");
      sleep(3);
      war(); //calls the war function
      break;
  }
}

// method for quitting the game after various rounds
void quit(){
  printf("\nWould you like to quit? Press 3 if you want to quit, 4 if you want to play the same game, or 5 if you would like to play the other game: ");
  int decide;
  scanf("%d", &decide);
  while ((decide != 3) && (decide != 4) && (decide != 5) && (sizeof(decide) != sizeof(int)))
  {
    printf("Not a valid option. Press 3 if you want to quit, 4 if you want to play the same game, or 5 if you would like to play the other game: ");
    scanf("%d", &decide);
  }
  switch (decide)
  {
    case 3:
      printf("Thanks for playing!\n");
      break;
    case 4:
      printf("Let's keep going with this game!\n\n");
      printf("Loading....\n");
      sleep(3);
      if (gameCheck == 1){ //if they already called the blackjack function, then gameCheck = 1
        blackjack();
      } // since gameCheck = 1, it re-calls the blackjack function
      else if (gameCheck == 2){ //if they had called the war function though, gameCheck = 2
        war();
      } // since gameCheck != 1, it re-calls the war function
      break;
    case 5:
      printf("Let's play a different game!\n\n");
      printf("Loading....\n");
      sleep(3);
      if (gameCheck == 1){ //if they already called the blackjack function, then gameCheck = 1
        war();
      } // since gameCheck = 1, it re-calls the blackjack function
      else if (gameCheck == 2){ //if they had called the war function though, gameCheck = 2
        blackjack();
      }// since gameCheck != 1, it re-calls the war function
      break;
  }



/*
** GAME IMPLEMENTATION ENDS
*/
}
