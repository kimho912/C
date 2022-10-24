//Hyun Ho Kim 1001967176

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char line[50];
  char *token;
  char letter;
  int check=1;

  printf("\n***************************\n");
  printf("***Morse Code Translaot***");
  printf("\n***************************\n");

  while (check)
  {
    printf("\n-Enter word in Morse code: ");
    fgets(line,50,stdin);
    token=strtok(line," \n");

    while (token!=NULL)
    {
      if (!strcmp(token,"exit"))
      {
        check=0;
      }
      else if (!strcmp(token,".-"))
      {
        printf("a");
      }
      else if (!strcmp(token,"-..."))
      {
        printf("b");
      }
      else if (!strcmp(token,"-.-."))
      {
        printf("c");
      }
      else if (!strcmp(token,"-.."))
      {
        printf("d");
      }
      else if (!strcmp(token,"."))
      {
        printf("e");
      }
      else if (!strcmp(token,"..-."))
      {
        printf("f");
      }
      else if (!strcmp(token,"--."))
      {
        printf("g");
      }
      else if (!strcmp(token,"...."))
      {
        printf("h");
      }
      else if (!strcmp(token,".."))
      {
        printf("i");
      }
      else if (!strcmp(token,".---"))
      {
        printf("j");
      }
      else if (!strcmp(token,"-.-"))
      {
        printf("k");
      }
      else if (!strcmp(token,".-.."))
      {
        printf("l");
      }
      else if (!strcmp(token,"--"))
      {
        printf("m");
      }
      else if (!strcmp(token,"-."))
      {
        printf("n");
      }
      else if (!strcmp(token,"---"))
      {
        printf("o");
      }
      else if (!strcmp(token,".--."))
      {
        printf("p");
      }
      else if (!strcmp(token,"--.-"))
      {
        printf("q");
      }
      else if (!strcmp(token,".-."))
      {
        printf("r");
      }
      else if (!strcmp(token,"..."))
      {
        printf("s");
      }
      else if (!strcmp(token,"-"))
      {
        printf("t");
      }
      else if (!strcmp(token,"..-"))
      {
        printf("u");
      }
      else if (!strcmp(token,"...-"))
      {
        printf("v");
      }
      else if (!strcmp(token,".--"))
      {
        printf("w");
      }
      else if (!strcmp(token,"-..-"))
      {
        printf("x");
      }
      else if (!strcmp(token,"-.--"))
      {
        printf("y");
      }
      else if (!strcmp(token,"--.."))
      {
        printf("z");
      }
      token=strtok(NULL," \n");
    }
    printf("\n");
  }
}
