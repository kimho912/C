/******************************************************************************
 * CSE 1310-003 Fall 2021
 * File name: HK7176Lab1Part1.c
 * Author : HK Kim
 * Created on: 8 Sep 21, 5:48pm
.*
 * UTA Student Name: Hyun Ho Kim
 * UTA ID:1001967176
*******************************************************************************/
#include <stdio.h>

/****************************************************************************
 * Lab 1 Part 1 – Testing arithmetic in C
****************************************************************************/
int main(int argc, char** argv)
{
    printf("Testing string output and arithmetic with negative numbers\n");
    printf("%d\n", 12);
    printf("%d\n",-6);
    printf("%d - %d\n", 12, -6);
    printf("%d\n", 12 - -6);
    
    printf("Testing more output and arithmetic\n");
    printf("12 + 3 = \n");
    printf("%d\n", 12 + 3);
    printf("12 + 3 = ");
    printf("%d\n", 12 + 3);
    printf("12 + 3 = \t");
    printf("%d\n", 12 + 3);
    printf("12.0 + 3.0 = \n");
    printf("%f\n", 12.0 + 3.0);        
    printf("12 + 3 = ");
    printf("%d", 12 + 3); 
    printf("%f\n", 12.0 + 3.0); 
    printf("\n");     
        
    printf("Mathematically 12 + 3 = %d and %f\n", (12 + 3) , (12.0 + 3.0));

    return 0;
}





