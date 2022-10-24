#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
  char *name;
  char *phone_num;
  char *city;
  struct Node *next;
}Node;

Node* populate_list()
{
  FILE *fp=fopen("callcenter.txt","r");

  char *token;
  char *line=malloc(100);
  struct Node *head = NULL;
  struct Node *temp = NULL;

  while(fgets(line, 100,fp))
  {
    token=strtok(line, ",");
    temp = malloc(sizeof(Node));
    temp->name=malloc(20);
    strcpy(temp->name,token);
    token=strtok(NULL,",");
    temp->phone_num=malloc(20);
    strcpy(temp->phone_num, token);

    temp->city=malloc(20);
    if(atoi(token)==817)
    {
      strcpy(temp->city,"Fort Worth");
    }
    else if(atoi(token)==214)
    {
      strcpy(temp->city,"Dallas");
    }
    else
    {
      strcpy(temp->city,"Grand Prairie");
    }

    temp->next=head;
    head=temp;

    printf("Phone number:%s, city: %s, %d\n", temp->phone_num,temp->city, atoi(token));
  }

  free(line);
  return head;
}
Node* pick_next(Node*list, char*city_name)
{
  while(list)
  {
    if(!strcmp(list->city, city_name))
    {
      return list;
    }
    list=list->next;
  }
  return NULL;
}
Node *completed(Node* current, char *name)
{
  Node* temp=NULL;
  Node* head=current;

  if(!current)
  {
    return current;
  }

  if(strcmp(current->name,name))
  {
    printf("Call completed!\n");
    temp=current;
    current=current->next;
    free(temp);
    return current;
  }

  current=current->next;

  while(current)
  {
    if (!strcmp(name,current->name))
    {
      temp->next=current->next;
      free(current);
      printf("Call completed!\n");
      break;
    }
    temp=current;
    current=current->next;
  }
  return head;
}
void show_list(Node* head)
{
  printf("\n--Current list--\n");
  while(head)
  {
    printf("%s \n",head->name);
    head=head->next;
  }
}
int main(int argc,char **argv)
{
  Node* call_wait=populate_list();
  char *answer=malloc(20);
  Node* cur=call_wait;
  char c='a';
  int minutes=0, total=0;

  printf("\nCall center loading...session started.");
  show_list(call_wait);
  printf("\nWhich city are we taking callers from\n");
  fgets(answer,20,stdin);
  strtok(answer,"\n");

  while(cur)
  {
    cur=pick_next(call_wait, answer);
    if (cur)
    {
      printf("\n--Now on the line: %s\n", cur->name);

      while(c!='d')
      {
        minutes++;
        printf("Minutes: %d\n", minutes);
        scanf(" %c", &c);
      }

      call_wait=completed(call_wait, cur->name);
      c='a';
      total++;
    }
  }

  printf("\nTotal time (in minutes) spent for callers from %s: %d\n",answer,total);
  show_list(call_wait);
  printf("Ending session...\n");
}
