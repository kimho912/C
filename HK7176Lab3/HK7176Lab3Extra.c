/******************************************************************************

 * CSE 1310-003/009 Fall 2021
 * File name: HK7176Lab3Extra
 * Author : Hyunho
 * Created on: 23 Nov 2021 03:57 AM
.*
 * UTA Student Name: Hyun Ho Kim
 * UTA ID:1001967176
 * 
*******************************************************************************/
#include <stdio.h>
/***********
 * Lab 3 Part 2 – Testing arithmetic in C
***********/
int main()
{
    int n, c = 0, k, r;
    int arr[10];

    printf("Type an integer less than 100 : ");
    scanf("%d", &n);
    do
    {
        k = n / 2;
        r = n - k * 2;
        arr[c++] = r;
        n = k;
    }
    while (k != 0);


    for (int i = c - 1; i >= 0; i--)
    printf("%d", arr[i]);

    return 0;
}
