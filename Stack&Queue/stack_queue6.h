//Hyun Ho Kim 1001967176
#ifndef STACK_QUEUE6_H
#define STACK_QUEUE6_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 8
//Prompt 1
int isempty(int top);
int isfull(int top);

typedef struct queue_node{
  char **full_name;
  int data;
  struct queue_node* next;
}QUEUE_NODE;

typedef struct queue{
  QUEUE_NODE* front;
  QUEUE_NODE* rear;
}QUEUE;

void enqueue(QUEUE* queue,char f[],char l[],int data);
void dequeue(QUEUE* queue);

#endif
