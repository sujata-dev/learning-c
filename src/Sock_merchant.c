#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,pair=0,temp;
    scanf("%d",&n);
    int *c=malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
       scanf("%d",&c[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(c[i]>c[j])
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }

        }
    }
    for(i=0;i<n-1;i++)
    {
        if(c[i]==c[i+1])
        {
            pair++;
            i++;
        }
    }
    printf("%d",pair);
    return 0;
}
