// Hyun ho Kim 1001967176
#include "hw6.h"

int jar(float* stack)
{
  char line[20];
  float tips;
  int top=-1;

  printf("***Tip Jar*** (Type the amount or done)\n");
  while (!isfull(top))
  {
    printf("Enter tip: $");
    fgets(line,20,stdin);
    strtok(line,"\n");
    if (!strcmp(line,"done"))
    {
      break;
    }
    else
    {
      tips=atof(line);
    }
    top++;
    stack[top]=tips;
  }
  if (isfull(top))
  {
    printf("Jar is full\n");
  }
  return top;
}
void pop_jar(float* stack,int top)
{
  int time;
  int i;

  printf("\nHello, how many hours did you work? ");
  scanf("%d",&time);
  printf("\nOK, giving you $%d.\n",time*2);
  if(stack[top]-time*2>=0)
  {
    if(stack[top]-time*2==0)
    {
      top--;
    }
    else
    {
      stack[top]=stack[top]-time*2;
    }
  }
  else
  {
    stack[top]=stack[top]-time*2;
    while(stack[top]<0)
    {
      top--;
      stack[top]=stack[top]+stack[top+1];
    }
  }
  printf("\n***Tip Jar (Updated)***\n");
  for (i=0;i<=top;i++)
  {
    printf("Enter tip: $%.2f\n",stack[i]);
  }
  if (stack[0]<0)
  {
    printf("Sorry not enough money in the jar\n");
  }
}
void read_info(QUEUE* queue,char *f)
{
  char line[30];
  char *token;
  char first[10];
  char last[10];
  int data;
  int count=0;

  queue->front=NULL;
  queue->rear=NULL;

  printf("--Adding in customer info from file:\n");

  FILE *fp = fopen(f,"r");

  if(!fp)
  {
    printf("file is not opening\n");
  }
  else
  {
    while(fgets(line,30,fp))
    {
      token=strtok(line,",");
      strcpy(first,token);
      token=strtok(NULL,",");
      strcpy(last,token);
      token=strtok(NULL,"\n");
      data=atoi(token);
      count++;
      if (count<CAPACITY+1)
      {
        enqueue(queue,first,last,data);
        printf("%s %s - %d\n", queue->rear->full_name[0],queue->rear->full_name[1],queue->rear->data);
      }
    }
    printf("\nAll customer info added.\n");
  }
  fclose(fp);
}
void search(QUEUE* queue)
{
  FILE* fp=fopen("output_f.txt","w");

  int answer;

  printf("--Passengers for ");
  scanf("%d",&answer);
  fprintf(fp,"--Passengers for %d\n",answer);

  QUEUE_NODE* temp = queue->front;
  while(temp)
  {
    if (temp->data==answer)
    {
      printf("  %s %s is taking flight %d.\n",temp->full_name[0],temp->full_name[1],temp->data);
      fprintf(fp,"  %s %s is taking flight %d.\n",temp->full_name[0],temp->full_name[1],temp->data);
    }
    temp=temp->next;
  }
  dequeue(queue);
  fclose(fp);
}
