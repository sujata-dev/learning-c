//To find prime numbers from a set of numbers
#include<stdio.h>
int main()
{
    int n1,n2,i,flag;
    printf("\nEnter two numbers: ");
    scanf("%d %d",&n1,&n2);
    printf("\nPrime numbers between them: ");
    while(n1<n2)
    {
        flag=0;
        for(i=2;i<=n1/2;++i)
        {
            if(n1%i==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("%d ",n1);
        ++n1;
    }
    return 0;
}
