#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "BLQ.h"

// I DON'T KNOW IF WE EVEN NEED QUEUES. We can easily just iterate through an array
// to find values that aren't == to 0. Both players have an array of 52 cards,
// and when they're playing a card, for example, it searches through the front (or back)
// of the array and prints the first value that isn't 0. Then, when a player wins a batlle,
// the values of the cards they won can be added to the first indecies of the ray that
// == 0. This is still possible with queues, and may be more time efficient, but there is
// the option there. Okay, end rant.

/*
** QUEUE IMPLEMENTATION
*/

struct Queue {
  int front, back, size;
  unsigned capacity;
  int* array;
};

//creates a queue
struct Queue* createQ(unsigned capacity){
  struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->back = queue->size = capacity-1;
  queue->array = (int*) malloc(queue->capacity * sizeof(int));
  return queue;
}
//checks to see if the queue is full
int isFull(struct Queue* queue){
  printf("Queue is full!\n");
  return (queue->size == queue->capacity);
}
//checks to see if the queue is empty
int isEmpty(struct Queue* queue){
  printf("Queue is empty!\n");
  return (queue->size == 0);
}
//adds an element to the back of the queue
void addQ(struct Queue* queue, int data){
  if (isFull(queue))
    return;
  queue->back = (queue->back + 1)%queue->capacity;
  queue->array[queue->back] = data;
  queue->size = queue->size + 1;
}
//removes an element from the front of the queue
int removeQ(struct Queue* queue){
  if (isEmpty(queue))
    return INT_MIN;
  int data = queue->array[queue->front];
  queue->front = (queue->front + 1)%queue->capacity;
  queue->size = queue->size - 1;
  return data;
}
//prints the element at the front of the queue
int frontQ(struct Queue* queue){
  if (isEmpty){
    printf("There are no elements in the queue!\n");
    return INT_MIN;
  }
  return queue->array[queue->front];
}
//prints the element at the back of the queue
int backQ(struct Queue* queue){
  if (isEmpty){
    printf("There are no elements in the queue!\n");
    return INT_MIN;
  }
  return queue->array[queue->back];
}

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

// prints the face and suit of each card in the deck
void printDeck(){


  printf("Here is a shuffled deck:\n");
  for (int i = 0; i < 52; i++) {
       int card = deck[i];
       int suit = card / 13;
       int face = card % 13;
       printf("%s of %s\n", faces_str[face], suits_str[suit]);
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
