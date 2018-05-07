#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "BLQ.h"


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
  for (int i = 0; i < deck->size; i++) {
       int card = deck->array[i];
       int suit = card / 13;
       int face = card % 13;
       printf("%s of %s\n", warface[face], warsuit[suit]);
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

// separates the cards into a human and a computer pile
void divideCards (struct Queue* humanPile, struct Queue* computerPile, struct Queue* deck){
  int flip = 0; //flip denotes if humanPile (0) or computerPile(1)
  for (int i = 0; i < deck -> capacity; i++){
    if (flip == 0)
    {
      addQ(humanPile, deck -> array[i]);
      flip = 1;
    }
    else if (flip == 1)
    {
      addQ(computerPile, deck -> array[i]);
      flip = 0;
    }
  }

}

void stand(){
  printf("you just got stood up bro\n");
}
void hit(){
  printf("HIT YO\n");
  bet();
  checkBust();
}
void checkBust(){
  printf("BUSTED!\n");
}
void bet(){

  //char answerTingy;
  //printf("Would you like to bet some moneys? y or n :D\n");
  //scanf("%c\n", &answerTingy);
  //while ((answerTingy != 'y') || answerTingy != 'Y') {
    /* code */
  //}
}


// A barebones function that sets global variable gameCheck to 1
// and prints a successful game played message
void blackjack(){
  gameCheck = 1;
  char turn;
  int moneys = 10;

  blackjackRules();
  system("@cls||clear");

  printf("What would you like your moneys to start wiff, yo? (The default is 10): \n");
  scanf("%d\n", &moneys);

  struct Queue* deck = createQ(52);
  printf("Shuffling the deck!\n\n");
  sleep(2); //delays for aesthetic effect
  shuffleDeck(deck);

  struct Queue* humanHand = createQ(52);
  struct Queue* dealerHand = createQ(52);

  while (moneys > 0){
    printf("Would you like to hit or stand? Enter 'h' or 's': \n");
    scanf("%c\n", &turn);
      while (turn != 'h' || turn != 's') {
        printf("KILL YO SELF (but naht just re-enter a letter, yo): \n");
        scanf("%c\n", &turn);
      }
    switch(turn){
      case 'h':
        hit();
        break;
      case 's':
        stand();
        break;
    }
  }

  //Game flow:
  //deals 2 cards to player and to the dealer
  //asks player if they want to hit or stand
  //10s, j, q, k, are all 10 points





  printf("Believe it or not, you just played Blackjack!\n");

  quit();
}


void blackjackRules(){
  system("@cls||clear");
  char placeholder;
  scanf("%c", &placeholder);
  char enter;
  printf("Welcome to the game of Blackjack! Here are the rules. Press enter after you read each step to move on to the next step.\n\n");
  printf("Step 1: The goal of Blackjack is to get closer than the dealer to a hand value of 21. Cards 2-9 are face value, cards 10-k are worth 10, and aces are worth either 1 or 11. \n\n"); //starting the rules
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to continue!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  printf("Step 2: When the game starts, each player (including the dealer) is dealt 2 cards which are displayed face up. After this, players place their bets and their turn starts!\n\n");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to continue!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  printf("Step 3: On a player's turn, they are prompted to either hit or stand. Hitting is the act of being dealt a card, which increases your total hand value. This gets you potentially closer to the value of 21, although it also runs the risk of Busting -- going over 23 and losing the hand. Alternatively, the player can stand and let the dealer draw a card instead.\n\n");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to continue!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  printf("Step 4: At the beginning of each turn, the player can choose to place a bet using their moneys. If you run out of moneys, then you lose the game. You will win the game once you collect 100 moneys!\n\n");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to continue!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  //printf("Step 5: \n\n");
  printf("When you are ready to play, press enter to start!\n\n");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to start playing!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
}


void warRules(){
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
  printf("Step 4: If the cards are of the same rank, then it is War!! Draw 1 card face-down, then draw the second card face-up. These cards' values will be compared, and whoever has the higher value will take all the cards! These will all be put at the bottom of their pile of cards.\n\n");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to continue!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  printf("Step 5: Whoever ends up with all of the cards at the end of the game wins!\n\n");
  printf("When you are ready to play, press enter to start!\n\n");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to start playing!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
}

void draw(struct Queue* humanPile, struct Queue* computerPile, struct Queue* cardsAtStake)
{
  int htemp = removeQ(humanPile); //preserves data from the front of the human pile
  int ctemp = removeQ(computerPile); //preserves data from the front of the computer pile
  char enter;
  printf("Press enter to draw your top card.\n\n");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to draw your top card!\n\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  printf("Your card is: %s of %s\n", warface[humanPile -> array[humanPile -> front] % 13], warsuit[humanPile -> array [humanPile ->front] / 13]);
  printf("The computer's card is: %s of %s\n", warface[computerPile -> array[computerPile -> front] % 13], warsuit[computerPile -> array[computerPile -> front] / 13]);
  addQ(cardsAtStake, htemp);
  addQ(cardsAtStake, ctemp);
}

void drawWar(struct Queue* humanPile, struct Queue* computerPile, struct Queue* cardsAtStake)
{
  char enter;
  printf("WAR!!!\n\n");
  printf("Pres enter to draw your next card face down, and then drop the second card face up.\n\n");
  scanf("%c", &enter);
  while (enter != '\n')
  {
    printf("Press enter to draw your cards!\n");
    scanf("%c", &enter);
    scanf("%c", &enter);
  }
  addQ(cardsAtStake, removeQ(humanPile));
  addQ(cardsAtStake, removeQ(computerPile));
  printf("\n\nYour second card is: %s of %s\n", warface[humanPile -> array[humanPile -> front] % 13], warsuit[humanPile -> array [humanPile -> front] / 13]);
  printf("\n\nThe computer's second card is: %s of %s\n", warface[computerPile -> array[computerPile -> front] % 13], warsuit[computerPile -> array[computerPile -> front] / 13]);
  addQ(cardsAtStake, removeQ(humanPile));
  addQ(cardsAtStake, removeQ(computerPile));

}

int compare(struct Queue* cardsAtStake)
{
  int humanCompare = cardsAtStake -> array [cardsAtStake -> size - 2];
  int hcompareface = humanCompare % 13;
  int computerCompare = cardsAtStake -> array [cardsAtStake -> size - 1];
  int ccompareface = computerCompare % 13;
  if (warface[hcompareface] == warface[ccompareface])
  {
    return 0;
  }
  else if (warface[hcompareface] > warface[ccompareface])
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

int addToPile(struct Queue* cardsAtStake, struct Queue* winnerPile)
{
  for (int i = 0; i < cardsAtStake -> size; i++)
  {
    addQ(winnerPile, removeQ(cardsAtStake));
  }
}
// War game function
void war(){
  gameCheck = 2;
  warRules();
  struct Queue* deck = createQ(52);
  printf("Shuffling the deck!\n\n");
  sleep(2); //delays for aesthetic effect
  shuffleDeck(deck);
  printf("Dealing the cards to each player!\n\n");
  sleep(2);
  struct Queue* humanPile = createQ(52); //queues with max capacities of 52
  struct Queue* computerPile = createQ(52);
  divideCards(humanPile, computerPile, deck);
  //printf("Your pile\n"); //these are here mostly to check that divide cards method works
  //printDeck(humanPile);
  //printf("\n\nComputer pile\n");
  //printDeck(computerPile);
  //printf("\n\nLet's start the game!\n\n");
  sleep(1);
  while (humanPile->size != 52 || computerPile -> size != 52){ //checking if either player has all 52 cards
    struct Queue* cardsAtStake = createQ(52);
    draw(humanPile, computerPile, cardsAtStake);
    while (compare(cardsAtStake)==0)
    {
      drawWar(humanPile, computerPile, cardsAtStake);

    }
    if (compare(cardsAtStake) == -1)
    {
      printf("Computer wins cards and adds them to the bottom of their pile.\n");
      addToPile(cardsAtStake, computerPile);
      printf("\n\nNew computer pile: \n");
      printDeck(computerPile);
      printf("\n\nNew human pile: \n");
      printDeck(humanPile);
    }
    else if (compare(cardsAtStake) == 1)
    {
      printf("You win cards and add them to the bottom of your pile.\n");
      addToPile(cardsAtStake, humanPile);
      printf("Your new pile: \n");
      printDeck(humanPile);
      printf("New computer pile: \n");
      printDeck(computerPile);
    }
  }
   if (humanPile ->size == 52)
   {
     printf("You win!\n");
   }
   else if (computerPile -> size == 52)
   {
     printf("The computer wins!\n");
   }
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
