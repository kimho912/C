//Hyun Ho Kim 1001967176

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct mailbox{
  char first_name[20];
  char last_name[20];
  int apt_num;
  char all_mail[2][400];
  int pieces_of_mail;
}MAILBOX;

int set_info(char *txt,MAILBOX residents[])
{
  FILE *fp;
  int i=0,j=0;
  int check;
  char line[500];
  char *token;
  fp=fopen(txt,"r+");

  if(!fp)
  {
    printf("File is not opening...\n");
    check=0;
  }
  else
  {
    printf("\nReading all resident info from apt_residents.txt...\n");

    while(!feof(fp))
    {
      fgets(line,500,fp);
      token=strtok(line," ,\n");
      strcpy(residents[i].first_name,token);
      token=strtok(NULL,",\n");
      strcpy(residents[i].last_name,token);
      token=strtok(NULL," ");
      token=strtok(NULL,",\n");
      residents[i].apt_num=atoi(token);
      token=strtok(NULL,",\n");
      residents[i].pieces_of_mail=atoi(token);
      i++;
    }
    for (j=0;j<5;j++)
    {
      printf("Creating mailbox for %s %s in apt %d. Currently has %d letter(s).\n",
              residents[j].first_name,residents[j].last_name,residents[j].apt_num,
              residents[j].pieces_of_mail);
    }
    check=1;
    printf("All mailboxes created!\n\n");
    printf("************\n\n");
  }

  return check;
}
int deliver_mail(char *txt, MAILBOX residents[], int num)
{
  FILE *mfp;
  mfp=fopen(txt,"r+");
  char line[300];
  char *token;
  int undelivered=0;
  int i;
  char *messages;

  if(!mfp)
  {
    printf("File is not opening...\n");
  }
  else
  {
    printf("~~Delivering mail...\n");
    while(!feof(mfp))
    {
      fgets(line,300,mfp);
      token=strtok(line,":");
      messages=strtok(NULL,"\n");
      printf("Delivering to %s:%s\n",token,messages);

      for (i=0;i<num;i++)
      {
        if ((!strcmp(token,residents[i].last_name))||(atoi(token)==residents[i].apt_num))
        {
          if(residents[i].pieces_of_mail<2)
          {
            strcpy(residents[i].all_mail[residents[i].pieces_of_mail],messages);
            residents[i].pieces_of_mail++;
            printf("%d currently has %d letters(s).",residents[i].apt_num,residents[i].pieces_of_mail);
            if (residents[i].pieces_of_mail==2)
            {
              printf(" Mailbox is now full.");
            }
            printf("\n\n");
          }
          else if (residents[i].pieces_of_mail==2)
          {
            undelivered++;
            printf("Sorry, mailbox is full. %d undelivered letter(s).\n\n",undelivered);
          }
        }
      }
    }
  }
  printf("\n************\n\n");
  return undelivered;
}
void exit_program(char *txt, MAILBOX residents[],int num)
{
  int i;
  printf("\nExiting program...mail report being saved to file mail_report.txt...\n");
  FILE *efp=fopen(txt,"w");
  for(i=0;i<num;i++)
  {
    fprintf(efp,"%s, %s: %d\n",residents[i].last_name,residents[i].first_name,residents[i].pieces_of_mail);
  }
}
int main(int argc, char**argv)
{
  MAILBOX all_residents[5];

  if(set_info(argv[1], all_residents))
  {
    int mail_info=deliver_mail(argv[2], all_residents, 5);

    if(!mail_info)
    {
      printf("All mail was successfully delievered!\n");
    }
    else
    {
      printf("Some mailboxes were full, number of undelivered letters: %d\n", mail_info);
    }

    int check=1;
    char answer[20];
    int i;
    while (check)
    {
      printf("\nEnter resident's last name or apt number: ");
      fgets(answer,20,stdin);
      strtok(answer,"\n");
      for (i=0;i<5;i++)
      {
        if (!strcmp(answer,all_residents[i].last_name)||atoi(answer)==all_residents[i].apt_num)
        {
          printf("%s %s, resident in apt %d, has %d letter(s):\n",
                all_residents[i].first_name,all_residents[i].last_name,all_residents[i].apt_num,mail_info);
          if (all_residents[i].pieces_of_mail==1)
          {
            printf("1.%s\n",all_residents[i].all_mail[0]);
            break;
          }
          else if (all_residents[i].pieces_of_mail==2)
          {
            printf("1.%s\n",all_residents[i].all_mail[0]);
            printf("2.%s\n",all_residents[i].all_mail[1]);
            break;
          }
        }
      }
      if (!strcmp(answer,"exit"))
      {
        check=0;
      }
    }
    exit_program(argv[3], all_residents,5);
  }
}
