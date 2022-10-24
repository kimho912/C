/******************************************************************************

 * CSE 1310-003/009 Fall 2021
 * File name: Hk7176Lab3Part1
 * Author : Hyunho
 * Created on: 20 Nov 2021 6:54 PM
.*
 * UTA Student Name: Hyun Ho Kim
 * UTA ID:1001967176
 * 
*******************************************************************************/
#include <stdio.h>
/***********
 * Lab 3 Part 1 – Testing arithmetic in C
***********/
#define ROWS 25 
#define DMYS 3

const int DY = 0;
const int MO = 1;
const int YR = 2;

int checkDate(int day, int month, int year);
int checkLeap(int yr);
void errorMsgs(int flag,int day, int month, int year);

void printAmerDate( int day, int month, int year);
void printEuroDate( int day, int month, int year);
void printISODate( int day, int month, int year);
void printSpaceDate( int day, int month, int year);

int addYear(int year);
int priorMonthDays(int month, int year);

int main()
{
    int dates[ROWS][DMYS];
    int count = 0;
    int invalid = 0;
    char filename[] = "TestDatesData.txt";
    FILE *variable = fopen(filename,"r");
    
    
    while ((variable != NULL) && (!feof(variable)))
    {
        fscanf(variable,"%d %d %d",&dates[count][DY],&dates[count][MO],&dates[count][YR]);
        invalid = checkDate(dates[count][DY], dates[count][MO], dates[count][YR]);
        if (!invalid)
            count++;
    }
    
    printf("\n\nValid dates from the file are: \n");
    
    for (int i=0; i<count; i++)
    {
        if (i % 4 == 0)
            printAmerDate(dates[i][DY], dates[i][MO], dates[i][YR]);
        else if (i % 4 == 1)
            printEuroDate(dates[i][DY], dates[i][MO], dates[i][YR]);
        else if (i % 4 == 2)
            printISODate(dates[i][DY], dates[i][MO], dates[i][YR]);
        else if (i % 4 == 3)
            printSpaceDate(dates[i][DY], dates[i][MO], dates[i][YR]);
    }
    printf("\n\n");
    
    int ear = 0;
    int lat = 0;
    
    for (int j=0; j<count-1; j++)
    {
        if ((dates[j][YR] > dates[j+1][YR])
            || ((dates[j][YR] == dates[j+1][YR]) && (dates[j][MO] > dates[j+1][MO]))
            || ((dates[j][YR] == dates[j+1][YR]) && (dates[j][MO] == dates[j+1][MO]) && (dates[j][DY] > dates[j+1][DY])))
        {
            ear = j+1;
            lat = j;
        }
        else if ((dates[j][YR] < dates[j+1][YR])
        || ((dates[j][YR] == dates[j+1][YR]) && (dates[j][MO] < dates[j+1][MO]))
        || ((dates[j][YR] == dates[j+1][YR]) && (dates[j][MO] == dates[j+1][MO]) && (dates[j][DY] < dates[j+1][DY])))
        {
            ear = j;
            lat = j+1;
        }
        else
        {
            ear = j;
            lat = j;
        }
        
        printf("The dates are %d/%d/%d and %d/%d/%d, and the earlier date is %d/%d/%d\n",
            dates[j][MO],dates[j][DY],dates[j][YR],
            dates[j+1][MO],dates[j+1][DY],dates[j+1][YR],
            dates[ear][MO],dates[ear][DY],dates[ear][YR]);
        
        int sum = priorMonthDays(dates[ear][MO], dates[ear][YR]) + dates[ear][DY];
        
        if (dates[lat][YR] > dates[ear][YR])
        {
            sum = addYear(dates[ear][YR]) - sum;
        }
        
        int countYr = dates[ear][YR] + 1;
        
        while (countYr < dates[lat][YR])
        {
            sum += addYear(countYr);
            countYr++;
        }
        int thisYear = priorMonthDays(dates[lat][MO], dates[lat][YR]) + dates[lat][DY];
        if (dates[lat][YR] == dates[ear][YR])   
            sum = thisYear - sum;   
        else     
            sum = sum + thisYear;
        
        printf("The number of days from the ealier date %d/%d/%d to the later date %d/%d/%d is %d\n\n",
            dates[ear][MO],dates[ear][DY],dates[ear][YR],dates[lat][MO],dates[lat][DY],dates[lat][YR],sum);
        }
        
        
    return 0;
}
int addYear(int year)
{
    if (checkLeap(year) == 1)
        return 366;
    else 
        return 365;    
}
int priorMonthDays(int month, int year)
{
    int sum = 0;
    int lastm = month-1;
    
    if (lastm == 11)
        sum = sum + 30;
    if (lastm >= 10)
        sum = sum + 31;
    if (lastm >= 9)
        sum = sum + 30;
    if (lastm >= 8)
        sum += 31;
    if (lastm >= 7)
        sum += 31;
    if (lastm >= 6)
        sum += 30;   
    if (lastm >= 5)
        sum += 31;  
    if (lastm >= 4)
        sum += 30;  
    if (lastm >= 3)
        sum += 31;   
    if (lastm >= 2)
        if (checkLeap(year) == 1)
            sum += 29;
        else
            sum += 28;
    if (lastm >= 1)
        sum += 31;
        
    
    return sum;           
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
void printSpaceDate( int day, int month, int year)
{
    printf("%d %d %d\n", day, month, year);
    return;
}

void printAmerDate( int day, int month, int year)
{
    printf("%d/%d/%d\n",month, day, year);
    return;
}

void printEuroDate( int day, int month, int year)
{
    printf("%d.%d.%d\n",day,month, year);
    return;
}
void printISODate( int day, int month, int year)
{
    printf("%d-%d-%d\n",year, month, day);
    return;
}