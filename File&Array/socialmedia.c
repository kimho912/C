//Hyun Ho Kim 1001967176

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_account_info(char filename[], char account_holder[][20], int followers[]);
int find_person(char account_holder[][20], char person[])
{
  int i;
  for(i=0;i<7;i++)
  {
    if (!strcmp(account_holder[i],person))
    {
      return i;
    }
  }
  return -1;
}
void get_user_input(char answer[])
{
  fgets(answer,40,stdin);
  strtok(answer,"\n");
}
void exit_report(char filename[], char account_holder[][20], int followers[])
{
  int i;
  int biggest=0;
  char name[20];
  FILE* outfp=fopen(filename,"w");
  for (i=0;i<7;i++)
  {
    fprintf(outfp,"---Followers for %s: %d\n",account_holder[i],followers[i]);
    if (followers[i]>biggest)
    {
        biggest = followers[i];
        strcpy(name, account_holder[i]);
    }
  }
    fprintf(outfp,"\n--Most followers: %s with %d followers! This user gets $%d.",name,biggest,biggest*5);
    fclose(outfp);
}
int main (int argc, char **argv)
{
  char account_holder[7][20];
  int followers[7];

  int n=get_account_info("inputfile.txt",account_holder,followers);
  char answer[20];
  char person[20];
  
  while(n)
  {
    printf("Add followers or exit?\n");
    get_user_input(answer);

    if(!strcmp(answer, "add"))
    {
      printf("Enter name of person to find:\n");
      get_user_input(person);

      int i = find_person(account_holder, person);

      if (i==-1)
      {
        printf("Person not found.\n");
      }
      else
      {
        printf("How many followers to add?\n");
        get_user_input(answer);
        int k = atoi(answer);

        followers[i]=followers[i]+k;
        printf("Updated followers for %s: %d\n",account_holder[i],followers[i]);
      };

    }
    else if(!strcmp(answer, "exit"))
    {
        
        printf("Outputting file...\n");
        exit_report("outputfile.txt", account_holder, followers);
        n=0;
    }
    else
    {
      printf("unknown response.\n");
    }
  }
}
int get_account_info(char filename[], char account_holder[][20], int followers[])
{
  FILE* fp=fopen(filename,"r");
  char line[40];
  int i;

  if(!fp)
  {
    printf("File not opened.\n");
    return 0;
  }

  else
  {
    while(!feof(fp))
    {
        fgets(account_holder[i],40,fp);
        strtok(account_holder[i],"\n");
        fgets(line,40,fp);
        followers[i]=atoi(line);
        i++;
    }
    fclose(fp);
    return 1;
  }
}
