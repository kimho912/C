//Hyun Ho Kim 1001967176
#include "stack_queue6.h"

int isempty(int top)
{
  if (top == -1)
    return 1;
  else
    return 0;
}
int isfull(int top)
{
  if (top == MAXSIZE-1)
    return 1;
  else
    return 0;
}
void enqueue(QUEUE* queue,char f[],char l[],int data)
{
  QUEUE_NODE* queue_node = malloc(sizeof(QUEUE_NODE));
  queue_node->full_name=malloc(sizeof(char*)*2);
  queue_node->full_name[0]=malloc(10);
  queue_node->full_name[1]=malloc(10);
  strcpy(queue_node->full_name[0],f);
  strcpy(queue_node->full_name[1],l);
  queue_node->data = data;
  queue_node->next = NULL;

  if(queue->front==NULL)
  {
    queue->front=queue_node;
    queue->rear=queue_node;
  }
  else
  {
    queue->rear->next=queue_node;
    queue->rear=queue_node;
  }
}
void dequeue(QUEUE* queue)
{
  while (queue->front)
  {
    QUEUE_NODE* temp = queue->front;
    queue->front=queue->front->next;
    free(temp->full_name[0]);
    free(temp->full_name[1]);
    free(temp->full_name);
    free(temp);
  }
}
