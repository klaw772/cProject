

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

enum bjfaces { two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9, ten = 10,
             jack = 10, queen = 10, king = 10, ace = 10};
char *bjsuit[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
char *bjface[13] = {"2", "3", "4", "5", "6", "7", "8", "9",
            "10", "Jack", "Queen", "King", "Ace"};
int playerValue;
int dealerValue;
struct Queue* bjdeck;
struct Queue* humanHand;
struct Queue* dealerHand;

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
int checkBust();
void bjDraw();

//IMPLEMENTATION OF QUEUE

struct Queue {
  int front, back, size;
  unsigned capacity;
  int* array;
};

//creates a queue
struct Queue* createQ(int capacity){
  struct Queue* queue = malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->back = capacity - 1;
  queue->array = malloc(queue->capacity * sizeof(int));
  return queue;
}
//checks to see if the queue is empty
int isEmpty(struct Queue* queue){
  return (queue->size == 0);
}

//checks to see if the queue is full
int isFull(struct Queue* queue){
  return (queue->size == queue->capacity);
}

//adds an element to the back of the queue
void addQ(struct Queue* queue, int data){
  if (isFull(queue))
    printf("Queue is full!");
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

//END OF QUEUE IMPLEMENTATION
