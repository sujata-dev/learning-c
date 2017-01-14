//To search an element with multiple occurences using linear Search
#include<stdio.h>
int main()
{
    int arr[100],search,i,n,count=0;
    printf("\nEnter number of elements: ");
    scanf("%d",&n);
    printf("\nEnter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter item to be searched: ");
    scanf("%d",&search);
    for(i=0;i<n;i++)
    {
        if(arr[i]==search)
        {
            printf("\nElement present at location %d",i+1);
            count++;
        }
    }
    if(!count)
        printf("Element not present");
    return 0;
}
