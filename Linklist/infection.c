//Hyun Ho Kim 1001967176
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node{
  char *country;
  char virus; /*virus*/
  int start_cases; /*number of initial cases reported*/
  float infection_rate; /*daily rate of infection*/
  struct Node* next;
}Node;

Node* read_file()
{
  FILE *fp=fopen("infectionstuff.txt","r");

  char *token;
  char *line=malloc(30);
  Node *head=NULL;
  Node *temp=NULL;

  if(!line)
  {
    printf("No memorry allocated\n");
  }
  int i=0;

  while(fgets(line,30,fp))
  {
    token=strtok(line,",");

    temp = malloc(sizeof(Node));
    temp->country=malloc(20);
    strcpy(temp->country,token);

    token=strtok(NULL,",");
    temp->virus=token[0];

    token=strtok(NULL,",");
    temp->start_cases=atoi(token);

    token=strtok(NULL,"\n");
    temp->infection_rate=atof(token);

    temp->next=head;
    head=temp;

  }
  free (line);
  fclose(fp);
  return head;
}
Node* reverse(Node *i)//reversing the order of nodes
{
  Node* prev=NULL;
  Node* current = i;
  Node* next = NULL;

  while(current)
  {
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }

  return prev;
}
void print_info(Node *i,int day,int workers,char*a)
{
  Node *temp=NULL;
  double actual;
  int rate;
  int limit=atoi(a);

  printf("\n--Day %d (Aid Workers Available: %d)\n\n",day,workers);

  while(i!=NULL)
  {
    if (day==0||i->infection_rate==0)
    {
      actual=i->start_cases;
    }
    else if (day==1)
    {
      actual=i->start_cases+(i->start_cases*i->infection_rate);
      //i->start_cases+=((float)i->start_cases*i->infection_rate);
    }
    else
    {
      actual=i->start_cases+(i->start_cases*i->infection_rate);
      actual=actual+(actual*i->infection_rate);
    }
    rate=i->infection_rate*100;
    printf("-%s-cases %.f (actual: %.4f | rate: %d%% daily)",i->country,round(actual),actual,rate);
    if (i->start_cases>=limit)
    {
      printf("   Careful...\n");
    }
    else
    {
      printf("\n");
    }
    temp=i;
    i=temp->next;
  }
}
void check_worker(int *n,int *workers) //check if it is a valid input, and then get a new input.
{
  int valid=1;
  while(valid)
  {
    if(*n>*workers)
    {
      printf("We don't have that many aid workers available. We currently only have %d.\n",*workers);
      scanf("%d",n);
    }
    else if(*n%10!=0)
    {
      printf("Not a valid number of aid workers. Enter multiple of 10.\n");
      scanf("%d",n);
    }
    else
    {
      valid=0;
    }
  }

}
void aim(Node *i,char *name,int *num,int *worker) //find the node and reduce the infection_rate
{
  Node *temp=NULL;
  float rate=*num;
  rate=rate/1000;

  while (i!=NULL)
  {
    if (!strcmp(name,i->country))
    {
      if (i->infection_rate==0)
      {
        printf("Already 0%% infection rate. Nothing more to do.\n\n");
        break;
      }
      else
      {
        *worker-=*num;
        i->infection_rate-=rate;
        printf("Rate for %s is now %.2f.\n\n",name,i->infection_rate);
        break;
      }
    }
    temp=i;
    i=temp->next;
  }
}
void free_info(Node *i)
{
  Node *temp=NULL;

  while (i!=NULL)
  {
    free (i->country);
    temp=i;
    i=temp->next;
    free (temp);
  }
}
int main(int argc,char **argv)
{
  Node *infection=read_file();
  infection=reverse(infection);
  char answer;
  int temp;
  char *name = malloc(20);
  int num;
  int worker=50;
  int day=0;

  if(!name)
  {
    printf("no memorry allocated in main\n");
  }
  else
  {
    while(worker)
    {
      print_info(infection,day,worker,argv[1]);
      scanf("%c",&answer);

      if(answer=='\n')
      {
        day++;
      }
      else if(answer=='s')
      {
        printf("Which country to send aid to and how many? ");
        scanf("%s %d %d",name,&temp,&num);
        sprintf(name,"%s %d",name,temp);
        check_worker(&num,&worker);
        aim(infection,name,&num,&worker);
        day++;
      }
      else
      {
        printf("invalid input...\n");
        worker=0;
      }
    }
    printf("\nNo more aid workers available. Exiting program...");
    free (name);
    free_info(infection);
  }

}
