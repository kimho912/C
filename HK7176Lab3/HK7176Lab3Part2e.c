/******************************************************************************

 * CSE 1310-003/009 Fall 2021
 * File name: HK7176Lab3Part2e
 * Author : Hyunho
 * Created on: 23 Nov 2021 03:57 AM
.*
 * UTA Student Name: Hyun Ho Kim
 * UTA ID:1001967176
 * 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/***********
 * Lab 3 Part 2 – Testing arithmetic in C
***********/
#define MAXROW 25
#define MAXCOL 30
#define MAXSTR 3

const int REL = 0;
const int LAST = 1;
const int FIRST = 2;

const int DY = 0;
const int MO = 1;
const int YR = 2;

int checkDate(int day, int month, int year);
int checkLeap(int yr);
void errorMsgs(int flag,int day, int month, int year);
void checkGen(char genders);
int findAge (int day, int currentday, int month, int currentmonth, int year, int currentyear);
int findOldest (double age[], int CTNL);
int findYoungest (double age[], int CTL);

int main(int argc, char *argv[])
{
    char names[MAXROW][MAXSTR][MAXCOL];
    char genders[MAXCOL];
    double ages[MAXCOL];
    int Bdays[MAXROW][MAXCOL];
    
    int invalid = 0;
    int index = 0;

    
    // open first file
    char filename[50];
    strcpy(filename, argv[1]);
    FILE *inFile = fopen (filename, "r");
    // check if the file invaild
    if (inFile == NULL)
    {
        printf ("\n ERROR: input file %s is not available.\n", filename);
    }
    // scan data
    else
    {
        while ((inFile != NULL) && (!feof(inFile))) 
        {
            fscanf(inFile, "%s %lf %c %d %d %d %[^','], %[^\n]",names[index][REL], &(ages[index]), &(genders[index]), 
                &(Bdays[index][DY]),&(Bdays[index][MO]),&(Bdays[index][YR]),
                names[index][LAST], names[index][FIRST]);
            //check date
            invalid = checkDate(Bdays[index][DY], Bdays[index][MO], Bdays[index][YR]);
            //check age,gender
            if (!invalid && (((genders[index]) == 'F')||((genders[index]) == 'M')||((genders[index]) == 'N')||((genders[index]) == 'U')) && (ages[index] >= 0)) 
                index++;
        }
    }
    //print data
    printf("\n\nAfter all the data is read in, print the data out in a table format as shown below: \n");
    printf("%-15s %-15s %-15s %-15s %-15s %-15s\n","First","Last","Age","Birthday","Gender","Relationship");
    for (int i=0; i<index; i++) 
    {
        printf("%-15s %-15s %-15.2lf %-d/%-d/%-11d %-15c %-15s\n", names[i][FIRST], names[i][LAST], (ages[i]),
            (Bdays[i][MO]),(Bdays[i][DY]),(Bdays[i][YR]), (genders[i]), names[i][REL]);
    }
    
    // current date info
    int currentday, currentmonth, currentyear;
    time_t now;
        
    time(&now);
    struct tm *local = localtime(&now);
    currentday = local->tm_mday;
    currentmonth = local->tm_mon + 1;
    currentyear = local->tm_year + 1900;
    //
    int CTL;
    printf("\n\nIf the person is no longer living, print a message as follows: \n");
    for (int j = 0; j<index; j++)
    {
        int age = findAge(Bdays[j][DY],currentday,Bdays[j][MO],currentmonth,Bdays[j][YR],currentyear);
        if ((ages[j] <= age+1 ) && (ages[j] >= age-1))
            CTL++;
        else
        {
            printf("%-15s %-15s %-15s %-15.2lf\n", names[j][FIRST], names[j][LAST],
            names[j][REL], (ages[j]));
        }
    }
    //
    //Find oldest 2.f)
    int oldrow = findOldest (ages, CTL);
    printf("\n\nAt age %.2lf, %s %s was born on %d/%d/%d and is the oldest living person in the file.\n",
        ages[oldrow],names[oldrow][FIRST],names[oldrow][LAST],Bdays[oldrow][MO],Bdays[oldrow][DY],Bdays[oldrow][YR]);
    
    //Find youngest 2.g)
    int youngRow = findYoungest (ages, CTL);
    printf("\n\nBorn on %d/%d/%d, %s %s has the most recent birthdate in the file.\n",
        Bdays[youngRow][MO],Bdays[youngRow][DY],Bdays[youngRow][YR],names[youngRow][FIRST],names[youngRow][LAST]);    
    
    //2.h)
    char fileNm[50];
    strcpy(fileNm, argv[2]);
    FILE *fileOut = fopen (fileNm, "w");
    
    for (int l=0; l<CTL; l++) 
    {
        fprintf(fileOut,"%-15s %-15s %-15.2lf %-d/%-d/%-11d %-15c %-15s\n", names[l][FIRST], names[l][LAST], (ages[l]),
            (Bdays[l][MO]),(Bdays[l][DY]),(Bdays[l][YR]), (genders[l]), names[l][REL]);
    }

    
    return 0;
}
int findYoungest (double age[], int CTL)
{
    int youngrow = 0;
    for ( int k = 0; k < CTL+1; k++)
    {
        if(age[youngrow]>age[k+1])
        youngrow = k+1;
    }
    return youngrow;    
}
int findOldest (double age[], int CTL)
{
    int oldrow = 0;
    for ( int k = 0; k < CTL+1; k++)
    {
        if(age[oldrow]<age[k+1])
        oldrow = k+1;
    }
    return oldrow;
}
int findAge (int day, int currentday, int month, int currentmonth, int year, int currentyear)
{
    int age = 0;
    age = currentyear-year;
    if ( month > currentmonth)
        age = age - 1;
    else if ( month == currentmonth)
    {
        if (day > currentday)
        age = age - 1;
    }
    return age;
}
int checkDate(int day, int month, int year)
{
    int dateInvalid = 0;
    
    if ((year < 1000) || (year > 9999))
        dateInvalid = 1;
    
    else if ((month < 1) || (month > 12))
        dateInvalid = 2;
    
    else if ((day < 1) || (day > 31))
        dateInvalid = 3;
       
    
    if (!dateInvalid)
    {
        if ( ((month == 4) || (month == 6) || (month == 9) || (month == 11)) &&
                (day > 30))
            dateInvalid = 4;
           
        else if (month == 2)
        {
            if (checkLeap(year) == 0)
            {
                if (day > 28)
                    dateInvalid = 5;
            }
            else
                if (day > 29)
                    dateInvalid = 6;
        }
    }
    errorMsgs(dateInvalid, day, month, year);
    return dateInvalid;
}

void errorMsgs(int flag,int day, int month, int year)
{
    switch (flag)
    {
        case 1: 
            printf("\nError: Year %d is out of 4 digit range\n", year);
            break;
        case 2:
            printf("\nError: Month %d is out of valid range\n", month);
            break;    
        case 3:
            printf("\nError: Day %d is out of valid range\n", day);
            break; 
        case 4:
            printf("\nError: Day %d is out of range for given month %d with 30 days\n", day, month);
            break; 
        case 5:
            printf("\nError: Day %d is out of range for given month %d and year %d\n", day, month, year);
            break; 
        case 6:
            printf("\nError: Day %d is out of range for given month %d and leap year %d\n", day, month, year);
            break;  
        default:
            break;             
    }
    
}

int checkLeap(int yr)
{
    int leap = 0;

    if ((yr % 4) != 0)
        leap = 0;
    else if ((yr % 400) == 0)
        leap = 1;
    else if ((yr % 100) == 0)
        leap = 0;
    else
        leap = 1;
    
    return leap;
}