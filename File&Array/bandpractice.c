// Hyun ho Kim 1001967176

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

int read_doctor_list(char filename[],char type[],char band_names[][20],char band_diagnose[]);
void band_practice_list(char filename[],char diagnosis[],char band_names[][20],char band_diagnose[])
{
    printf("Creating list...\n\n");
    
    FILE* Pfp=fopen(filename,"w");
    FILE* Nfp=fopen(filename,"w");
    
    if (!strcmp(filename,"output_p.txt"))
        fprintf(Pfp,"---List of Positive cases:---\n");
    if (!strcmp(filename,"output_n.txt"))
        fprintf(Nfp,"---List of Negative cases:---\n");
    
    for (int k=0;k<strlen(band_diagnose);k++)
    {
        if (band_diagnose[k]=='P')
        {
            printf("%s:P...Can't go to pratice! :(\n\n",band_names[k]);
            if (!strcmp(filename,"output_p.txt"))
                fprintf(Pfp,"--%s: +Positive+\n",band_names[k]);
        }
        if (band_diagnose[k]=='N')
        {
            printf("%s:N...Good to go to pratice! :(\n\n",band_names[k]);
            if (!strcmp(filename,"output_n.txt"))
                fprintf(Nfp,"--%s: -Neg-\n",band_names[k]);
        }
    }
    fclose(Pfp);
    fclose(Nfp);
}
int main (int argc, char** argv)
{
    char band_names[SIZE][20];
    char band_diagnose[SIZE];

    int n=read_doctor_list("doctorlist.txt","r",band_names,band_diagnose); /*input file, mode to read file, names of band members, diagnosis as letters (for example, Positive should be saved as just ‘P’)*/

    if(n)
    band_practice_list("output_p.txt","Positive",band_names,band_diagnose); /*output file, which diagnosis to list (Positive in this case),
    names of band members, diagnosis as letters (for example, Positive should be saved as just ‘P’)*/
    band_practice_list("output_n.txt","Negative",band_names,band_diagnose);
}
    

int read_doctor_list(char filename[],char type[],char band_names[][20],char band_diagnose[])
{
  FILE* fp=fopen(filename,type);
  int i = 0;
  char line[20];
  if(!fp)
  {
    printf("File not opened.\n");
    return 0;
  }
  else
  {
    while(!feof(fp))
    {
      fgets(band_names[i],20,fp);
      strtok(band_names[i],"\n");
      fgets(line,20,fp);
      strtok(line,"\n");
      if (!strcmp(line,"Positive"))
      {
        band_diagnose[i] = 'P';
      }
      else if (!strcmp(line,"Negative"))
      {
        band_diagnose[i] = 'N';
      }
      i++;
    }

    fclose(fp);
    return 1;
  }
}
