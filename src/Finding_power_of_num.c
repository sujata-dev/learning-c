//To find power of a number
#include<stdio.h>
void power(int,int);
int main()
{
    int b,e;
    printf("Enter a base number, and the power upto which you want to find: ");
    scanf("%d %d",&b,&e);
    power(b,e);
    return 0;
}
void power(int base,int exp)
{
    int x=1;
    for(int i=1;i<=exp;i++)
        x=x*base;
    printf("Ans: %d",x);
}
