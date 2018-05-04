#ifndef BLQ_H
#define BLQ_H

int gameCheck;

void blackjack();
void war();
void quit();
void gameOn();
void drawCard();

struct card{};
struct queue{
  int front, rear, size;
};


#endif
