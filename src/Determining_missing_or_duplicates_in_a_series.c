/*To perform the following:
The user inputs the number and then enters a series of numbers from 1 to that number. The program should determine which number is missing or duplicate in the series, if any */
#include<stdio.h>
int main()
{
    int arr[100];
    int n,i,j,count=0;
    printf("\nEnter number: ");
    scanf("%d",&n);
    printf("\nCorrect series: ");
    for(i=1;i<=n;i++)
        printf("%d ",i);
    printf("\nEnter series: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
            if(arr[j]==i)
                count++;
        if(count>=2)
            printf("\nDuplicate %d: %d times",i,count);
        if(count==0)
            printf("\nMissing: %d",i);
        count=0;
    }
    return 0;
}
