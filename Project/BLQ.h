

//some global variables
int gameCheck;
int suit;
int face;
enum suits { SPADES, HEARTS, DIAMONDS, CLUBS };
enum faces { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
             JACK, QUEEN, KING, ACE };
char *warsuit[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
char *warface[13] = {"2", "3", "4", "5", "6", "7", "8", "9",
            "10", "Jack", "Queen", "King", "Ace"};

//some function prototypes
void blackjack();
void war();
void quit();
void gameOn();
void shuffleDeck();
void printDeck();
void divideCards();
void warRules();
void draw();
void drawWar();
int compare();
void blackjackRules();
void hit();
void stand();
void checkBust();
void bet();

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
  queue->back = capacity - 1;
  queue->array = (int*) malloc(queue->capacity * sizeof(int));
  return queue;
}
//checks to see if the queue is full
int isFull(struct Queue* queue){
  return (queue->size == queue->capacity);
}
//checks to see if the queue is empty
int isEmpty(struct Queue* queue){
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
    return 0;
  int data = queue->array[queue->front];
  queue->front = (queue->front + 1)%queue->capacity;
  queue->size = queue->size - 1;
  return data;
}
//prints the element at the front of the queue
int frontQ(struct Queue* queue){
  if (isEmpty(queue)){
    printf("There are no elements in the queue!\n");
    return 0;
  }
  return queue->array[queue->front];
}
//prints the element at the back of the queue
int backQ(struct Queue* queue){
  if (isEmpty(queue)){
    printf("There are no elements in the queue!\n");
    return 0;
  }
  return queue->array[queue->back];
}

/*
** QUEUE IMPLEMENTATION ENDS
*/
