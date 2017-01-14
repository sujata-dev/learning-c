//To calculate GCD of a number
#include<stdio.h>
int ans(int,int);
int main()
{
    int a,b;
    printf("\nEnter two numbers: ");
    scanf("%d %d",&a,&b);
    printf("\nGCD: %d",ans(a,b));
    return 0;
}
int ans(int x,int y)
{
    int i,gcd;
    for(i=1;(i<=x&&i<=y);i++)
        if(((x%i)==0)&&((y%i)==0))
            gcd=i;
    return gcd;
}
