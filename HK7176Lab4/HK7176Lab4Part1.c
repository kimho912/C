/******************************************************************************

 * CSE 1310-003/009 Fall 2021
 * File name: Hk7176Lab4Part1
 * Author : Hyunho
 * Created on: 2 Dec 2021 11:44 PM
.*
 * UTA Student Name: Hyun Ho Kim
 * UTA ID:1001967176
 * 
*******************************************************************************/
#include <stdio.h>
#include <string.h>
/***********
 * Lab 4 Part 1 – Testing arithmetic in C
***********/
#define ROWS 40
#define COLS 5
#define MAXSTRLEN 30


const int DY = 0;
const int MO = 1;
const int YR = 2;

const int FN = 0;
const int LN = 1;
const int RL = 2;

void printTable(FILE * pFile, char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw);
void bubbleSortAge(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col);
void swap(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col);
void swprintTable(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col);
void bubbleSortRL(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col);
void bubbleSortLNFN(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col);
void bubbleSortBday(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col);  
void MainSortArray(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col);
int binsearchName(char arr[ROWS][COLS][MAXSTRLEN], char tgtF[MAXSTRLEN], char tgtL[MAXSTRLEN], int first, int last);
void outPrint(FILE * pFile, char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw);
int main(int argc, char *argv[])
{
    char peopStr[ROWS][COLS][MAXSTRLEN];
    int peopBday[ROWS][COLS];
    double peopAge[ROWS];
    char peopGen[ROWS];
    
    char line[128];
    int rw = 0;
    
    char inFileNm[50] = "L4InputHK7176.txt";
    FILE *inFile;
    
    inFile = fopen (inFileNm, "r");
    if (inFile == NULL)
        {
            printf ("\nError: The file name could not be opened\n");
        }
    while (!feof (inFile))
    {
        fgets (line, 128, inFile);
        sscanf (line, "%s %lf %c %d %d %d %[^,], %[^\n]",
		  peopStr[rw][RL], &(peopAge[rw]),
		  &(peopGen[rw]), &(peopBday[rw][DY]),
		  &(peopBday[rw][MO]), &(peopBday[rw][YR]),
		  peopStr[rw][LN], peopStr[rw][FN]);
        rw++;
    }
    
    //checking all values are saved
    // printf("Original arrays:\n");
    // printTable(peopStr,peopBday,peopAge,peopGen,rw);
    /*
    // 1.a) swap values in row rw with valuse in rw+1.
    swprintTable(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(inFile,peopStr,peopBday,peopAge,peopGen,rw);
    
    // 1.b) sort the arrays by age from youngest to oldest.
    bubbleSortAge(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(inFile,peopStr,peopBday,peopAge,peopGen,rw);
    
    // 1.c) sort the arrays by relationship in alphabetical order
    bubbleSortRL(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(inFile,peopStr,peopBday,peopAge,peopGen,rw);
    
    // 1.d) sort the arrays by last name and then first name in alphabetical order
    bubbleSortLNFN(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(inFile,peopStr,peopBday,peopAge,peopGen,rw);
    
    // 1.e) sort the arrays by day, month,and year
    bubbleSortBday(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(inFile,peopStr,peopBday,peopAge,peopGen,rw);
    
    // 1.f) binsearch searching for name
    MainSortArray(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(inFile,peopStr,peopBday,peopAge,peopGen,rw);
    */
    //1.i)Extra Credit 
    char ofileNm[50] = "L4OutHK7176.txt";
    FILE *outFile;
    outFile = fopen (ofileNm, "w");
    outPrint(outFile,peopStr,peopBday,peopAge,peopGen,rw);
    
    char Firstname[MAXSTRLEN];
    char Lastname[MAXSTRLEN];
    printf("\n\nWhat is the name you are searching for? (Lastname, Firstname): ");
    fprintf(outFile,"\n\nWhat is the name you are searching for? (Lastname, Firstname): ");
    scanf("%[^,], %[^\n]",Lastname,Firstname);
    
    int bin = binsearchName(peopStr, Lastname, Firstname, 0, rw-1);
    printf("\nThe target name %s, %s was %sfound",Lastname,Firstname, (bin==-1?"not ":""));
    fprintf(outFile,"\nThe target name %s, %s was %sfound",Lastname,Firstname, (bin==-1?"not ":""));
    if (bin>-1)
    {
        printf(" at location %d\n",bin);
        fprintf(outFile," at location %d\n",bin);
    }
    else
        printf("\n");
        fprintf(outFile,"\n");
    // end
    
    return 0;
}
int binsearchName(char arr[ROWS][COLS][MAXSTRLEN], char tgtL[MAXSTRLEN], char tgtF[MAXSTRLEN], int first, int last)
{
    int loc = -1;
    if (first <= last)
    {
        int mid = (first+last)/2;
        if (strcmp(arr[mid][LN],tgtL) == 0)
        {
            if (strcmp(arr[mid][FN],tgtF) == 0)
            {
                return mid;
            }
            else if (strcmp(arr[mid][FN],tgtF) < 0)
            {
                binsearchName(arr, tgtL, tgtF, mid+1, last);
            }
            else
            {
                binsearchName(arr, tgtL, tgtF, first, mid-1);
            }
        }
        else if (strcmp(arr[mid][LN],tgtL) < 0)
        {
            binsearchName(arr, tgtL, tgtF, mid+1, last);

        }
        else
        {
            binsearchName(arr, tgtL, tgtF, first, mid-1);
        }
    }
    else
        return loc;
}
void MainSortArray(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col)
{
    printf("\n1.f) (Main routine) Sorted arrays by last name and first name in alphabetical order:\n");
    for (int q=0; q < rw-1; q++)
    {
        for (int w = 0; w < rw-1; w++)
        {
            if (strcmp(peopStr[w][LN],peopStr[w+1][LN]) > 0)
            {
                swap(peopStr,peopBday,peopAge,peopGen,w,COLS);
            }
            else if (strcmp(peopStr[w][LN],peopStr[w+1][LN]) == 0)
                if (strcmp(peopStr[w][FN],peopStr[w+1][FN]) > 0)
                {
                    swap(peopStr,peopBday,peopAge,peopGen,w,COLS);
                }
        }
    }
}
void bubbleSortBday(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col)
{
    printf("\n1.e) Sorted arrays by day, month,and year from earliest to lastest:\n");
    for (int q=0; q < rw-1; q++)
    {
        for (int w = 0; w < rw-1; w++)
        {
            if (peopBday[w][YR] > peopBday[w+1][YR])
            {
                swap(peopStr,peopBday,peopAge,peopGen,w,COLS);
            }
            else if (peopBday[w][YR] == peopBday[w+1][YR])
            {
                if (peopBday[w][MO] > peopBday[w+1][MO])
                {
                    swap(peopStr,peopBday,peopAge,peopGen,w,COLS);
                }
                else if (peopBday[w][MO] == peopBday[w+1][MO])
                {
                    if (peopBday[w][DY] > peopBday[w+1][DY])
                    {
                        swap(peopStr,peopBday,peopAge,peopGen,w,COLS);
                    }
                }
            }
        }
    }
}
void bubbleSortLNFN(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col)
{
    printf("\n1.d) Sorted arrays by last name and then first name in alphabetical order:\n");
    for (int q=0; q < rw-1; q++)
    {
        for (int w = 0; w < rw-1; w++)
        {
            if (strcmp(peopStr[w][LN],peopStr[w+1][LN]) > 0)
            {
                swap(peopStr,peopBday,peopAge,peopGen,w,COLS);
            }
            else if (strcmp(peopStr[w][LN],peopStr[w+1][LN]) == 0)
                if (strcmp(peopStr[w][FN],peopStr[w+1][FN]) > 0)
                {
                    swap(peopStr,peopBday,peopAge,peopGen,w,COLS);
                }
        }
    }
}
void bubbleSortRL(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col)
{
    printf("\n1.c) Sorted arrays by relationship in alphabetical order:\n");
    for (int r=0; r < rw-1; r++)
    {
        for (int e = 0; e < rw-1; e++)
        {
            if (strcmp(peopStr[e][RL],peopStr[e+1][RL]) > 0)
            {
                swap(peopStr,peopBday,peopAge,peopGen,e,COLS);
            }
        }
    }
}
void bubbleSortAge(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col)
{
    printf("\n1.b) Sorted arrays by age from youngest to oldest:\n");
    for (int j=0; j < rw-1; j++)
    {
        for (int u = 0; u < rw-1; u++)
        {
            if (peopAge[u] > peopAge[u+1])
            {
                swap(peopStr,peopBday,peopAge,peopGen,u,COLS);
            }
        }
    }
}
void swap(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col)
{
    double tmpAge;
    tmpAge = peopAge[rw];
    peopAge[rw] = peopAge[rw+1];
    peopAge[rw+1] = tmpAge;

    char tmpGen;
    tmpGen = peopGen[rw];
    peopGen[rw] = peopGen[rw+1];
    peopGen[rw+1] = tmpGen;
    
    for (int m = 0; m<col; m++)
    {
    char tmpWd[MAXSTRLEN];
    strcpy(tmpWd, peopStr[rw][m]);
    strcpy(peopStr[rw][m],peopStr[rw+1][m]);
    strcpy(peopStr[rw+1][m],tmpWd);
    
    int tmpNum;
    tmpNum = peopBday[rw][m];
    peopBday[rw][m] = peopBday[rw+1][m];
    peopBday[rw+1][m] = tmpNum;
    }
}
void swprintTable(char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw, int col)
{
    printf("\n1.a) Swaped arrays in row rw with values in row rw+1:\n");
        for (int g = 0; g < rw-1; g++)
        {
            swap(peopStr,peopBday,peopAge,peopGen,g,COLS);
        }
}
void printTable(FILE * pFile, char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw)
{
    printf("%s %15s %10s %5s %5s %5s %5s %20s %20s\n",
            "Line","Relation","Age","Gender","Day","Month","Year","Last Name","First Name");
    fprintf(pFile,"%s %15s %10s %5s %5s %5s %5s %20s %20s\n",
            "Line","Relation","Age","Gender","Day","Month","Year","Last Name","First Name");
    for (int p=0; p<100; p++)
    {
        printf("=");
        fprintf(pFile,"=");
    }
    printf("\n");
    fprintf(pFile,"\n");
    for (int i=0; i<rw; i++)
    {
        printf("%3d: %15s %10.2lf %5c %5d %5d %5d %20s %20s\n", i,
            peopStr[i][RL], (peopAge[i]),
            peopGen[i], (peopBday[i][DY]),
            (peopBday[i][MO]),(peopBday[i][YR]),
            peopStr[i][LN],peopStr[i][FN]);
        fprintf(pFile,"%3d: %15s %10.2lf %5c %5d %5d %5d %20s %20s\n", i,
            peopStr[i][RL], (peopAge[i]),
            peopGen[i], (peopBday[i][DY]),
            (peopBday[i][MO]),(peopBday[i][YR]),
            peopStr[i][LN],peopStr[i][FN]);
    }
    for (int t=0; t<100; t++)
    {
        printf("=");
        fprintf(pFile,"=");
    }
        printf("\n");
        fprintf(pFile,"\n");
}
void outPrint(FILE * pFile, char peopStr[ROWS][COLS][MAXSTRLEN],int peopBday[ROWS][COLS],
                double peopAge[ROWS],char peopGen[ROWS], int rw)
{
    fprintf(pFile,"\n1.a) Swaped arrays in row rw with values in row rw+1:\n");
    swprintTable(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(pFile,peopStr,peopBday,peopAge,peopGen,rw);
    
    fprintf(pFile,"\n1.b) Sorted arrays by age from youngest to oldest:\n");
    bubbleSortAge(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(pFile,peopStr,peopBday,peopAge,peopGen,rw);
    
    fprintf(pFile,"\n1.c) Sorted arrays by relationship in alphabetical order:\n");
    bubbleSortRL(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(pFile,peopStr,peopBday,peopAge,peopGen,rw);
    
    fprintf(pFile,"\n1.d) Sorted arrays by last name and then first name in alphabetical order:\n");
    bubbleSortLNFN(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(pFile,peopStr,peopBday,peopAge,peopGen,rw);
    
    fprintf(pFile,"\n1.e) Sorted arrays by day, month,and year from earliest to lastest:\n");
    bubbleSortBday(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(pFile,peopStr,peopBday,peopAge,peopGen,rw);
    
    fprintf(pFile,"\n1.f) (Main routine) Sorted arrays by last name and first name in alphabetical order:\n");
    MainSortArray(peopStr,peopBday,peopAge,peopGen,rw,COLS);
    printTable(pFile,peopStr,peopBday,peopAge,peopGen,rw);
}