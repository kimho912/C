//Hyun Ho Kim 1001967176
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
  char* color;
  int** details;
  struct Node* next;
}Node;
Node* light_info(char *filename)
{
  FILE *fp=fopen(filename,"r");

  char *line = malloc(20);
  char *token;
  Node *head = NULL;
  Node *temp = NULL;

  if(!fp)
  {
    printf("file is not opening...\n");
  }
  else if(!line)
  {
    printf("No memory allocated\n");
  }
  else
  {
    while(fgets(line,20,fp))
    {
      temp = malloc(sizeof(Node));

      token=strtok(line,",");
      temp->color = malloc(20);
      strcpy(temp->color,token);

      temp->details = malloc(sizeof(int*)*2);

      token=strtok(NULL,",");
      temp->details[0]=malloc(sizeof(int));
      *(temp->details[0]) = atoi(token);

      token=strtok(NULL,"\n");
      temp->details[1]=malloc(sizeof(int));
      *(temp->details[1]) = atoi(token);

      temp->next = head;
      head=temp;
    }
  }
  free(line);
  return head;
}
int check_off(Node *l) // check the lights lf all of them are off or not, if not, it turns off the lights
{
  Node *temp=NULL;
  int check;

  while(l!=NULL)
  {
    if(*(l->details[1])==1)
    {
      *(l->details[1])=0;
      check = 1;
    }
    else
    {
      check = 0;
    }
    temp=l;
    l=temp->next;
  }
  return check;
}
int check_on(Node *l) // check the lights lf all of them are on or not, if not, it turns on the lights
{
  Node *temp=NULL;
  int check;

  while(l!=NULL)
  {
    if(*(l->details[1])==0)
    {
      *(l->details[1])=1;
      check = 1;
    }
    else
    {
      check = 0;
    }
    temp=l;
    l=temp->next;
  }
  return check;
}
void print_lights(Node *l,int n) // print out the first letter of color as many as the size of the brightness.
{
  Node* temp = NULL;
  int i;

  if (n==1)
  {
    printf("\n***Turning lights on:\n");
    while (l != NULL)
    {
      for(i=0;i<*(l->details[0]);i++)
      {
        printf("%c",l->color[0]);
      }
      printf(" ");
      temp=l;
      l=temp->next;
    }
  }
  else if (n==0)
  {
    printf("\n***Turning lights off:\n");
    while (l != NULL)
    {
      for(i=0;i<*(l->details[0]);i++)
      {
        printf("%c",'-');
      }
      printf(" ");
      temp=l;
      l=temp->next;
    }
  }
  else
  {
    printf("invalid input\n");
  }
  printf("\n\n");
}
void free_info(Node*l) // free the allocted memories
{
  Node *temp=NULL;

  while(l!=NULL)
  {
    free(l->color);
    free(l->details[0]);
    free(l->details[1]);
    free(l->details);
    temp=l;
    l=temp->next;
    free(temp);
  }
}
int main(int argv,char **argc)
{
  Node *lights=light_info("lightstuff.txt");
  char* answer = malloc(20);
  int check;
  if(!answer)
  {
    printf("No memory allocaated in main...\n");
  }
  else
  {
    while(answer)
    {
      scanf("%s",answer);
      if(!strcmp(answer,"off"))
      {
        check=check_off(lights);
        if(check==1)
        {
          print_lights(lights,0);
        }
        else
        {
          printf("\n--Lights are already off.\n\n");
        }
      }
      else if(!strcmp(answer,"on"))
      {
        check=check_on(lights);
        if(check==1)
        {
          print_lights(lights,1);
        }
        else
        {
          printf("\n--Lights are already on.\n\n");
        }
      }
      else
      {
        answer = NULL;
        printf("Exiting...\n");
      }
    }
  }
  free (answer);
  free_info(lights);
}
