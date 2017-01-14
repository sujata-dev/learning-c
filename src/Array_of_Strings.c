//Array of strings
#include<stdio.h>
#define size 10
#define max 4
int main()
{
    char arr[max][size];
    int i;
    for(i=0;i<max;i++)
        gets(arr[i]);
    for(i=0;i<max;i++)
        puts(arr[i]);
}
