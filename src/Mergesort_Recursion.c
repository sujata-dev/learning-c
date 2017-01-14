//Merge sort using recursion
#include<stdio.h>
void mergesort(int a[],int low,int high);
void merge(int a[],int i1,int j1,int i2,int j2);
int main()
{
    int a[30],i,n;
    printf("\nEnter no of elements: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("\nSorted array is: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,mid+1,high);
    }
}
void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[50];
    int i,j,k;
    i=i1;
    j=i2;
    k=0;
    while(i<=j1&&j<=j2)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=j1)
        temp[k++]=a[i++];
    while(j<=j2)
        temp[k++]=a[j++];
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}
