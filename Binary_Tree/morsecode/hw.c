//Hyun Ho Kim 1001967176
#include "hw.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_info(char *f)
{
  char check ='a';

  while (check!='n')
  {
    QUEUE* queue=malloc(sizeof(QUEUE));
    char morse[5];
    char letter;
    int i=0;
    int ch;
    FILE *fp = fopen(f,"r");

    printf("---Reading in\n");
    printf("---Translating...\n");
    if (queue)
    {
      queue->front=0;
      queue->rear=0;
    }
    while (!feof(fp))
    {
      ch=fgetc(fp);
      if (ch==' '||ch=='#')
      {
        morse[i]='\0';
        strtok(morse,"\0");
        letter = translate(morse);
        enqueue(queue,letter);
        if (morse[0]=='\0'&&morse[1]=='\0')
        {
          ch=fgetc(fp);
        }
        i=0;
      }
      else
      {
        morse[i] = ch;
        i++;
      }
    }
    fclose(fp);
    outfile(queue);
    free (queue);
    printf("Would you like to read in another file? y or n\n");
    scanf(" %c",&check);
  }
}
