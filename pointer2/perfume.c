#include <stdlib.h>// Hyun Ho Kim 1001967176
#include <stdio.h>
#include <string.h>

int find_spray_perfume(char a[],char *pn[],int *s)
{
    int count=-1;
    int i;
    for (i=0;i<*s;i++)
    {
        if(!strcmp(a,pn[i]))
        {
            count=i;
        }
    }
    return count;
}
void perfume_spray(int index,char **pp,int oz[],int s)
{
    printf("Total oz in this bottle of %s: %d\n",pp[index],oz[index]);
    if (oz[index]>2)
    {
        oz[index]-=2;
        printf("**SPRAY! Now we have %d oz**\n\n",oz[index]);

    }
    else
    {
        printf("Not enough to spray 2oz...you should go buy more.\n\n");
    }

}
void exit_list(char **pp,int oz[],int s,char *a)
{
    int i;
    FILE* fp= fopen(a,"w");

    fprintf(fp,"~~Total perfumes: %d~~\n",s);
    for (i=0;i<s;i++)
    {
        fprintf(fp,"--%s-%d oz\n",pp[i],oz[i]);
    }
}
int main(int argc,char **argv)
{
    char answer[40];
    char* perfume_names[]={"Gucci Flora", "Chanel Chance", "Dior J'adore"};
    char** perf_ptr=perfume_names;


    int perfume_bottles_oz[]={32,1,24};
    int num_times_run_loop=atoi(argv[1]);
    int size=3, index;

    for(int i=0;i<num_times_run_loop;i++)
    {
        printf("Which perfume to use? ");
        fgets(answer, 40, stdin);
        strtok(answer,"\n");

        index=find_spray_perfume(answer,perfume_names,&size);

        if(index==-1)
        {
            printf("No perfume found with this name...\n");
        }

        else
        {
            perfume_spray(index, perf_ptr, perfume_bottles_oz, *(&size));
        }
    }
    printf("Exiting...");
    exit_list(&*&*perf_ptr, perfume_bottles_oz, size, argv[2]);

}
