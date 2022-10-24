//Hyun Ho Kim 1001967176

#include <stdio.h>
#include <string.h>

int find_filename(int n,char **b)
{
    int i;
    int counter=0; /*equals -1 if didnt find*/
    int check=0;

    for(i=0;i<n&&!check;i++)
    {
        if(!strcmp(*b, "filename"))
        {
            check=1;
        }
        counter++;
        b++;
    }
    if(check!=1)
    {
        counter=0;
    }
    return (counter-1);
}
int main(int argc,char **argv)
{
    int a;
    char line[128];

    a=find_filename(argc,argv);

    if (a==-1)
    {
        printf("No filename given. Bye!\n");
    }
    else
    {
        FILE *fp = fopen(argv[a+1],"r");
        while(!feof(fp))
        {
            fgets(line,128,fp);
            strtok(line,"\n");
            printf("%s\n",line);
        }
    }


    return 0;
}
