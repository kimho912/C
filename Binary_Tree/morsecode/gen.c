//Hyun Ho Kim 1001967176
#include "gen.h"
#include <stdio.h>
#include <string.h>

char translate(char morse[])
{
  char letter;

  if (!strcmp(morse,".-"))
  {
    letter = 'a';
  }
  else if (!strcmp(morse,"-..."))
  {
    letter = 'b';
  }
  else if (!strcmp(morse,"-.-."))
  {
    letter = 'c';
  }
  else if (!strcmp(morse,"-.."))
  {
    letter = 'd';
  }
  else if (!strcmp(morse,"."))
  {
    letter = 'e';
  }
  else if (!strcmp(morse,"..-."))
  {
    letter = 'f';
  }
  else if (!strcmp(morse,"--."))
  {
    letter = 'g';
  }
  else if (!strcmp(morse,"...."))
  {
    letter = 'h';
  }
  else if (!strcmp(morse,".."))
  {
    letter = 'i';
  }
  else if (!strcmp(morse,".---"))
  {
    letter = 'j';
  }
  else if (!strcmp(morse,"-.-"))
  {
    letter = 'k';
  }
  else if (!strcmp(morse,".-.."))
  {
    letter = 'l';
  }
  else if (!strcmp(morse,"--"))
  {
    letter = 'm';
  }
  else if (!strcmp(morse,"-."))
  {
    letter = 'n';
  }
  else if (!strcmp(morse,"---"))
  {
    letter = 'o';
  }
  else if (!strcmp(morse,".--."))
  {
    letter = 'p';
  }
  else if (!strcmp(morse,"--.-"))
  {
    letter = 'q';
  }
  else if (!strcmp(morse,".-."))
  {
    letter = 'r';
  }
  else if (!strcmp(morse,"..."))
  {
    letter = 's';
  }
  else if (!strcmp(morse,"-"))
  {
    letter = 't';
  }
  else if (!strcmp(morse,"..-"))
  {
    letter = 'u';
  }
  else if (!strcmp(morse,"...-"))
  {
    letter = 'v';
  }
  else if (!strcmp(morse,".--"))
  {
    letter = 'w';
  }
  else if (!strcmp(morse,"-..-"))
  {
    letter = 'x';
  }
  else if (!strcmp(morse,"-.--"))
  {
    letter = 'y';
  }
  else if (!strcmp(morse,"--.."))
  {
    letter = 'z';
  }
  else
  {
    letter = ' ';
  }
  return letter;
}
void capital(char *letter)
{
  if((*letter>= 96) && (*letter <= 122))
  {
    *letter-=32;
  }
}
void enqueue(QUEUE* queue,char letter)
{
  if (queue->rear==0)
  {
    capital(&letter);
  }
  queue->letter[queue->rear] = letter;
  queue->rear++;
}
void outfile(QUEUE* queue)
{
  char filename[20];
  printf("What file to save to?\n");
  scanf("%s",filename);
  FILE *fp=fopen(filename,"w+");
  while (queue->front != queue->rear)
  {
    fprintf(fp,"%c", queue->letter[queue->front]);
    queue->front++;
  }
  printf("Saved to file!\n\n");
  fclose (fp);
}
