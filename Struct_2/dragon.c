//Hyun Ho Kim 1001967176

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dragon{
  char name[20];
  char* color;
  int num_heads;
  int num_tails;
}dragon;

void dragon_info(dragon *d)
{
  char line[100];
  char *token;
  int i,j;

  fgets (line,100,stdin);
  token=strtok(line,",");

  while (token!=NULL)
  {
    token=strtok(NULL,",");
    strcpy(d->name,token);
    for (j=0;j<3;j++)
    {
      token=strtok(NULL,",");
      d->color=&token[0];
    }
    token=strtok(NULL,",");
    d->num_heads=atoi(token);
    token=strtok(NULL,",\n");
    d->num_tails=atoi(token);
    d++;
  }
}
void color(char* color, dragon *d)
{
  int i;
  for (i=0;i<4;i++)
  {
    switch(*color)
    {
      case'r':
        strcpy(d->color,"red");
        break;
      case'w':
        strcpy(d->color,"red");
        break;
      case'g':
        strcpy(d->color,"red");
        break;
      case'y':
        strcpy(d->color,"red");
        break;
      default:
        strcpy(d->color,"unknown");
    }
    printf("%s is %s\n",d->name,d->color);
    d++;
  }

}
int main(int argc,char**argv)
{
  dragon total[4];
  dragon_info(total);
  char c='b';
  color(&c,total);
}
