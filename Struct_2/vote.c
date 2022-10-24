//Hyun Ho Kim 1001967176

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
  char* first_name;
  char* last_name;
  int* number_order_registered;
};

int registered(FILE *fp)
{
  char line[30];
  int counter=0;

  printf("\n\n***Registered so far:***\n\n");
  if(!fp)
  {
    return counter;
  }
  else
  {
    while (fgets(line,30,fp))
    {
      counter++;
      printf("%d. %s",counter,line);
    }
  }
  fclose(fp);
  return counter;
}
void new_register(FILE *fp)
{

  char first_name[30];
  char last_name[30];

  printf("Enter name: ");
  scanf("%s %s",first_name,last_name);
  printf("Adding: %s %s",first_name,last_name);
  fprintf(fp,"%s %s\n",first_name,last_name);
  fclose(fp);
}
void print_info (char *f1,char *f2,int n)
{
  struct person *vote=malloc(sizeof(struct person)*n);

  char line[50];
  char *token;
  FILE *fp1=fopen(f1,"r+");
  FILE *fp2=fopen(f2,"w+");
  int i=0;

  if(!vote)
  {
    printf("No memory allocated\n");
  }
  while (fgets(line,50,fp1))
  {
    token=strtok(line," ");
    vote->first_name=malloc(30);
    strcpy(vote->first_name,token);
    token=strtok(NULL," \n");
    vote->last_name=malloc(30);
    strcpy(vote->last_name,token);
    vote->number_order_registered=malloc(sizeof(int));
    *(vote->number_order_registered)=i+1;
    printf("%s, %s...%d\n",vote->last_name,vote->first_name,*(vote->number_order_registered));
    fprintf(fp2,"%s, %s...%d\n",vote->last_name,vote->first_name,*(vote->number_order_registered));
    i++;
    vote++;
  }
  if (!fp2)
  {
    printf("fp2 is not opening");
  }
  for (i=0;i<n;i++)
  {
    // free(vote->last_name);
    // free(vote->first_name);
    vote++;
  }
  //free(vote);
  fclose(fp1);
  fclose(fp2);
}
int main(int argc,char**argv)
{
  FILE *fp;
  int i=0,n=0,num;
  char answer;
  char filename[20]="people_info.txt";
  fp=fopen(argv[1],"r+");
  n=registered(fp);

  printf("\nHow many people to ask right now?\n");
  scanf("%d",&num);


  while (i<num)
  {
    if (n<10)
    {
      printf("\n-Person %d: Would you like to register to vote?\n",i+1);
      scanf(" %c",&answer);

      if (answer=='n')
      {
        printf("OK.\n");
      }
      else if (answer=='y')
      {
        fp=fopen(argv[1],"a");
        new_register(fp);
        fp=fopen(argv[1],"r");
        n=registered(fp);
      }
    }
    if (n==10)
    {
      printf("Target Reached! Exiting...\n");
      break;
    }
    i++;
  }
  printf("\n%d people asked! Taking a break\n",num);
  print_info(argv[1],filename,n);


}
