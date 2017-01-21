//To insert, delete and update elements in an array
#include<stdio.h>
#include<stdlib.h>
void insert(int[],int,int);
void del(int[],int);
void update(int[],int,int);
int n;
int main()
{
    int *arr,loc,i,item,ch;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    while(1)
    {
        printf("\n1) To insert an element");
        printf("\n2) To delete an element");
        printf("\n3) To update value of an element");
        printf("\n4) To exit");
        printf("\nEnter 1, 2, 3 or 4: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter location and value of element to be inserted: ");
                    scanf("%d %d", &loc,&item);
                    insert(arr,loc,item);
                    break;
            case 2: printf("\nEnter the location of element to be deleted: ");
                    scanf("%d",&loc);
                    del(arr,loc);
                    break;
            case 3: printf("\nEnter position of element to be updated: ");
                    scanf("%d",&loc);
                    printf("\nEnter changed value: ");
                    scanf("%d",&item);
                    update(arr,loc,item);
                    break;
            case 4: exit(0);
            default:    printf("Wrong Choice");
        }
    }
    return 0;
}
void insert(int arr[],int loc,int item)
{
    int i;
    if(loc>=n+1)
        printf("Insertion not possible");
    else
    {
        for(i=n-1;i>=loc-1;i--)
            arr[i+1]=arr[i];
        arr[loc-1]=item;
        n=n+1;
        printf("\nUpdated array: ");
        for(i=0;i<n;i++)
            printf("%d ",arr[i]);
    }
}
void del(int arr[],int loc)
{
    int i;
    if(loc>=n+1)
        printf("Deletion not possible");
    else
    {
        for(i=loc-1;i<n-1;i++ )
            arr[i] = arr[i+1];
        n=n-1;
        printf("\nUpdated array: ");
        for(i=0;i<n;i++)
            printf("%d ",arr[i]);
    }
}
void update(int arr[],int loc,int item)
{
    int i;
    if(loc>=n+1)
        printf("Updation not possible");
    else
    {
        for(i=0;i<loc-1;i++);
        arr[i]=item;
        printf("\nUpdated array: ");
        for(i=0;i<n;i++)
            printf("%d ",arr[i]);
    }
}
