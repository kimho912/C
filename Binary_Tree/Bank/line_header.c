//Hyun Ho Kim 1001967176
#include <stdio.h>
#include <stdlib.h>
#include "line_header.h"

struct Node* enter_info(int n)
{
  struct Node *head=NULL;
  struct Node *temp=NULL;
  int answer;
  int i;

  for (i=0;i<n;i++)
  {
    temp=malloc(sizeof(struct Node));
    printf("Enter age: ");
    scanf("%d",&answer);
    temp->age=answer;

    temp->next=head;
    head=temp;
  }
  return head;
}
struct Node* combine(struct Node* line_one, struct Node* line_two)
{
  struct Node *previous = NULL;
  struct Node *head=line_one;

  while (line_one)
  {
    previous=line_one;
    line_one=line_one->next;
  }

  previous->next=line_two;

  return head;
}
void print_list(struct Node* head, char *message)
{
  struct Node* temp = head;

  printf("\n%s\n", message);

  while (temp != NULL)
  {
    printf("%d ", temp->age);
    temp = temp->next;
  }
    printf("\n");
}
struct Node* reverse_list_rec(struct Node* head_ref)
{
  struct Node *current= head_ref;
  
  if (!current)
  {
    return ;
  }
  head_ref= reverse_list_rec(head_ref);

  return prev;
}
