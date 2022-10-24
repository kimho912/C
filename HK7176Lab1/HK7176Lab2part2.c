/******************************************************************************
 * CSE 1310-003 Fall 2021
 * File name: HK7176Lab1Part2.c
 * Author : HK Kim
 * Created on: 12 Sep 21, 4:06pm
.*
 * UTA Student Name: Hyun Ho Kim
 * UTA ID:1001967176
*******************************************************************************/
#include <stdio.h>

/****************************************************************************
 * Lab 1 Part 2 – Testing arithmetic in C
****************************************************************************/
int main(int argc, char**argv)
{
    int date1 = 28;
    int date2;
    int date3 = 21, date4;
    date4 = 6;
    printf("Printing variable values: \n");
    printf("date1 = %d\ndate2 = %d\n", date1, date2);
    printf("date3 = ");
    printf("%d\n",date3);
    printf("date4 = %d\n",date4);
    date2 = 9;
    printf("new value of date2 = %d\n\n",date2);
    
    printf("Product of date1 & date2 = %d\n",(date1*date2));
    printf("Quotient of date1 & date2 = %d : Remember that the variables are int\n", (date1 / date2));
    printf("Remainder of date1 & date2 = %d : Remember the variables are int\n", (date1 % date2));
    printf("\n");
    printf("Giving date4 the valuse of date3 minus date1 so ");
    printf("%d - %d = ", date3, date1);
    date4 = date3 - date1;
    printf("%d\n",date4);
    
    printf("\ndate1 = %d and date2 = %d\n", date1,date2);
    date4 = date1 / date2;
    printf("\nUsing integer variables:\n\tQuotient of %d & %d = %d\n",date1,date2,date4);
    double date5 = date1 / date2;
    printf("Using int division assigned to floating point variables:\n\tQuotient of %d & %d = %f\n",date1,date2,date5);
    date5 = date1 / (double)date2;
    printf("Using mixed division with cast assigned to floating point variables: \n\tQuotient of %d & (double)%d = %f\n\n", date1,date2,date5);
    
}





