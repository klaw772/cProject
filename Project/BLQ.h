#ifndef BLQ_H
#define BLQ_H

//some global variables
int gameCheck;
int suit;
int face;
enum suits { SPADES, HEARTS, DIAMONDS, CLUBS };
enum faces { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
             JACK, QUEEN, KING, ACE };
int deck[52];
char *suits_str[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
char *faces_str[13] = {"2", "3", "4", "5", "6", "7", "8", "9",
            "10", "Jack", "Queen", "King", "Ace"};

//queue function prototypes
void createQ();
void isFull();
void isEmpty();
void addQ();
void removeQ();
void topQ();
void bottomQ();

//game function prototypes
void blackjack();
void war();
void quit();
void gameOn();
void shuffleDeck();
void printDeck();

#endif
