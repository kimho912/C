/******************************************************************************
 * CSE 1310 Fall 2021
 * File name: HK7176Lab2Part1d
 * Author : Hyunho
 * Created on: October 31, 2021, 4:16 PM
.*
 * UTA Student Name: Hyun Ho Kim
 * UTA ID: 1001967176
*******************************************************************************/
#include <stdio.h>
#include <ctype.h>
/***********
 * Lab 2 Part 1 – Testing arithmetic in C
***********/
int iscons(char ltr);
int main()
{
    printf("%c %c %c %c %c %c\n",72,121,117,110,104,111);
    printf("%d %d %d %d %d %d\n",'H','y','u','n','h','o');

    printf("%4c %4c %4c %4c %4c %4c\n",72,121,117,110,104,111);
    printf("%4d %4d %4d %4d %4d %4d\n",'H','y','u','n','h','o');

    char fName[] = "Hyunho";
    if (iscons(fName[0])==1)
        {
            printf("\n%c %d",fName[0],fName[0]);
        }
    if (iscons(fName[1])==1)
        {
            printf("\n%c %d",fName[1],fName[1]);
        }
    if (iscons(fName[2])==1)
        {
            printf("\n%c %d",fName[2],fName[2]);
        }
    if (iscons(fName[3])==1)
        {
            printf("\n%c %d",fName[3],fName[3]);
        }
    if (iscons(fName[4])==1)
        {
            printf("\n%c %d",fName[4],fName[4]);
        }
    if (iscons(fName[5])==1)
        {
            printf("\n%c %d",fName[5],fName[5]);
        }
        
    return 0;
}
int iscons(char ltr)
{
    ltr = tolower(ltr);
    if ((ltr == 'a') || (ltr == 'e') ||  (ltr == 'i') 
        ||  (ltr == 'o') ||  (ltr == 'u'))
        return 0;
    return 1;
}





