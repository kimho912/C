//Hyun Ho Kim 1001967176
#ifndef GEN_H
#define GEN_H

#define MAX 100

typedef struct queue{
  char letter[MAX];
  int front;
  int rear;
}QUEUE;

void enqueue(QUEUE *queue,char letter);
void outfile(QUEUE* queue);
char translate(char morse[]);
void capital(char *letter);
#endif
