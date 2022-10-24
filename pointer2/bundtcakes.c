// Hyun Ho Kim  1001967176

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_out(int *num, char* f[])
{
    int i;

    printf("%d Flavors:\n",*num);

    for (i=0;i<*num;i++)
    {
        printf("%s\n",f[i]);
    }
    printf("\n");
}
int name_flavors(char *n, char* f[], int *s)
{
    int i;
    int counter=0;
    if(*n>='a' && *n<='z')
    {
        *n=*n-32;
    }
    for (i=0;i<*s;i++)
    {
        if((*n)==(*f[0]))
        {
            printf("Falvor match! %s\n",*f);
            counter++;
        }
        f++;
    }
    return counter;
}
int main(int argc,char **argv)
{
    int num;
    char* flavors[]={"Red velvet","Cinnamon","Chocolate",
                    "Classic Vanilla","Carrot"};
    int check=1;
    char answer[20];
    int total=0;
    char name[20];
    char line[20];
    int size = sizeof(flavors)/sizeof(flavors[0]);

    while (check)
    {
        printf("***Menu: ****\n");
        printf("1-pick how many you want\n");
        printf("2-see if any match the first letter of your name\n");
        printf("3-to exit\n");
        fgets(answer,20,stdin);
        strtok(answer,"\n");

        if (!strcmp(answer,"1"))
        {
            printf("\nHow many do you want? ");
            fgets(line,20,stdin);
            num=atoi(line);
            print_out(&num,flavors);

            check=1;
        }
        else if(!strcmp(answer,"2"))
        {
            printf("\nEnter a name:\n");
            fgets(name,20,stdin);
            strtok(name,"\n");

            total=name_flavors(name,flavors,&size);
            printf("Number of matches:%d\n\n",total);

            check=1;
        }
        else if(!strcmp(answer,"3"))
        {
            printf("Bye\n");
            check=0;
        }
        else
        {
            printf("The input you typed %s is not valid",answer);
        }
    }
}
