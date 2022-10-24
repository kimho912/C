/******************************************************************************
 * CSE 1310-003 Fall 2021
 * File name: HK7176Lab1Part3.c
 * Author : HK Kim
 * Created on: 16 Sep 21, 6:36pm
.*
 * UTA Student Name: Hyun Ho Kim
 * UTA ID:1001967176
*******************************************************************************/
#include <stdio.h>

/****************************************************************************
 * Lab 1 Part 3 – Testing arithmetic in C
****************************************************************************/
int main(int argc, char**argv)
{   // Correctly find the sum of two fractions
    int a = 3;
    int b = 4;
    int c = 1;
    int d = 2;
    
    printf("Original fractions are ");
    printf("%d/%d and %d/%d\n",a,b,c,d);
    
    int quoNum = a * d;
    int quoDenom = b * c;
    printf("The term in the numerator is ");
    printf("%d and the denominator is %d\n",quoNum, quoDenom);
    
    
    double fractionQuotient = (quoNum)/ (double) quoDenom;
    printf("The equation for the quotient of two fractions is ");
    printf("(%d * %d)/(%d * %d) = %d/%d\n",a, d, b, c, quoNum, quoDenom);

    printf("The quotient of the two fractions is %f\n", fractionQuotient); 
    
}



