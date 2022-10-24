#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int age;
  struct Node *next;
}Node;

int check_list(Node* h,int n)
{
  Node* temp=NULL;
  //Node* current=h;
  int counter=0;

  while(h)
  {
    if(h->age<n)
    {
      counter++;
    }
    temp=h;
    h=h->next;
    free(temp);
  }

  return counter;
}
int main(int argc,char **argv)
{
  int n;
  Node* head = malloc(sizeof(Node));
  Node* second = malloc(sizeof(Node));
  Node* third = malloc(sizeof(Node));

  if(!head||!second||!third)
  {
    printf("Memory not allocated. Exiting...");
  }

  else
  {
    printf("Enter age 1:\n");
    scanf("%d",&head->age);
    head->next=second;

    printf("Enter age 2:\n");
    scanf("%d",&second->age);
    second->next=third;

    printf("Enter age 3:\n");
    scanf("%d",&third->age);
    third->next=NULL;

    n=check_list(head,21);

    printf("People less than 21: %d\n",n);
  }
}
