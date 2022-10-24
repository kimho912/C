//Hyun Ho Kim 1001967176

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct order{
  char *name;
  char payment;
  int total_items;
  float price;
  int fulfilled;
}order;

void input_orders(order *o, int size, char*filename)
{
  FILE *fp=fopen(filename,"r+");
  char *token;
  char *line=malloc(40);
  o->name=malloc(30);
  int i;

  for (i=0;i<size;i++)
  {
    fgets(line,40,fp);
    token=strtok(line,",");
    strcpy(o->name,token);
    token=strtok(NULL,",");
    o->payment=token[0];
    token=strtok(NULL,",");
    o->total_items=atoi(token);
    token=strtok(NULL,",");
    o->price=atof(token);
    token=strtok(NULL,"\n");
    o->fulfilled=atoi(token);
    o++;
  }
  fclose(fp);
  free(line);
}
void print_out(int status, order*o, int size)
{
  int i;
    for (i=0;i<size;i++)
    {
      if(o[i].fulfilled==status)
      {
        printf("%s\n",o[i].name);
      }
    }
}
int pick_next(order *o, int size_order)
{
  int i;
  int highest=0, current=0, highest_index=-1;
  for(i=0;i<size_order;i++)
  {
    if(o[i].fulfilled==2)
    {
      current=o[i].price;
      if(highest<current)
      {
        highest=current;
        highest_index=i;
      }
    }
  }

  return highest_index;
}
void output_file(char*filename, order *o, int size_order)
{
  FILE *fp=fopen(filename,"w+");
  int i;

  for (i=0;i<size_order;i++)
  {
    fprintf(fp,"%s,%c,%d,%.2f,%d",o[i].name,o[i].payment,o[i].total_items,o[i].price,o[i].fulfilled);
    free(o[i].name);
  }
  fclose(fp);
}
int main (int argc,char**argv)
{
  int num=atoi(argv[1]);
  int check=1;
  int status;
  order* order_stand=malloc(sizeof(order)*num);
  char *answer=malloc(20);

  printf("\n***Buongiorno Chef Bartolomeo!***\n\n");

  if(order_stand==NULL)
  {
    printf("No memory is allocated!\n");
  }
  else
  {
    input_orders(order_stand,num,argv[2]);

    while(check)
    {
      printf("What to do?\n");
      printf("1. print out orders\n");
      printf("2. pick next order to fulfill\n");
      printf("3. exit\n");

      scanf("%s",answer);
      int n=atoi(answer);

      if(n==1)
      {
        printf("\nDo tou want to see all orders to fill or orders already completed? Type fill or completed\n");
        scanf("%s",answer);
        if (!strcmp(answer,"completed"))
        {
          status=1;
          printf("Already filled:\n");
        }
        else if (!strcmp(answer,"fill"))
        {
          status=2;
          printf("Need to fill:\n");
        }
        print_out(status,order_stand,num);
      }
      else if(n==2)
      {
        int hi=pick_next(order_stand,num);
        if (hi==-1)
        {
          printf("All orders are fulfilled!\n");
        }
        else
        {
          printf("\nNext order to fill: %s\n",order_stand[hi].name);
          printf("Go ahead and fulfill this order? y or n\n");
          scanf("%s",answer);
          if (!strcmp(answer,"y"))
          {
            order_stand[hi].fulfilled=1;
            printf("Fulfilled!");
          }
          else if (!strcmp(answer,"n"))
          {
            printf("Not fulfilled.");
          }
        }

      }
      else if(n==3)
      {
        printf("\nSaving information...Ciao!\n");
        output_file(argv[2],order_stand,num);
        check=0;
        free(order_stand);
        free(answer);
      }
      else
      {
        printf("\nNot a valid menu choice.\n");
      }
    }
  }
}
