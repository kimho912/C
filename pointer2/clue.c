// Hyun Ho Kim 1001967176

#include <stdio.h>
#include <string.h>

// I don't understand how the meet counts up without pointer in the function.
int meet_with_suspect(char* sus[],int meet[],char name[])
{
    char answer[5];
    int check;

    if(!strcmp(sus[0],name))
    {
        printf("Suspect found. Adding meeting.\n");

        meet[0]++;
    }
    else if(!strcmp(sus[1],name))
    {
        printf("Suspect found. Adding meeting.\n");
        meet[1]++;
    }
    else if(!strcmp(sus[2],name))
    {
        printf("Suspect found. Adding meeting.\n");
        meet[2]++;
    }
    else
    {
        printf("Suspect not found.\n");
    }

    printf("--Would you like to continue meeting?\n");
    fgets(answer,5,stdin);
    strtok(answer,"\n");

    if (!strcmp(answer,"yes"))
    {
        check=1;
    }
    else if (!strcmp(answer,"no"))
    {
        check=0;
    }
    return check;
}

int main(int argc,char **argv)
{
    char* all_suspects[]={"Mustard","Scarlet","Plum"};
    int meet[3]={0};
    char name[100];
    int check=1;

    while(check)
    {
        printf("\n***Enter a suspect's name: ");
        fgets(name,100,stdin);
        strtok(name,"\n");

        if(!strcmp(name,"exit"))
        {
            check=0;
        }

        else
        {
            check=meet_with_suspect(all_suspects,meet,name);
        }
    }

    printf("Total meets for Mustard: %d\n",meet[0]);
    printf("Total meets for Scarlet: %d\n",meet[1]);
    printf("Total meets for Plum: %d\n",meet[2]);
}
