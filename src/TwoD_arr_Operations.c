//Various operations on 2D array
#include<stdio.h>
void add(int[20][20],int[20][20],int,int,int,int);
void subtract(int[20][20],int[20][20],int,int,int,int);
void multiply(int[20][20],int[20][20],int,int,int,int);
void transpose(int[20][20],int,int);
int main()
{
    int choice,m,n,p,q,i,j;
    int arr1[20][20], arr2[20][20];
    printf("\nEnter number of rows and columns for matrix 1: ");
    scanf("%d %d",&m,&n);
    printf("\nEnter matrix 1:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr1[i][j]);
    printf("\nEnter number of rows and columns for matrix 2: ");
    scanf("%d %d",&p,&q);
    printf("\nEnter matrix 2:\n");
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
            scanf("%d",&arr2[i][j]);
    printf("\n1) To perform matrix addition");
    printf("\n2) To perform matrix subtraction");
    printf("\n3) To perform matrix multiplication");
    printf("\n4) To find transpose");
    printf("\nEnter 1,2,3 or 4: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: add(arr1,arr2,m,n,p,q);
                break;
        case 2: subtract(arr1,arr2,m,n,p,q);
                break;
        case 3: multiply(arr1,arr2,m,n,p,q);
                break;
        case 4: transpose(arr1,m,n);
                break;
        default: printf("\nInvalid Choice");
    }
    return 0;
}
void add(int a[20][20],int b[20][20],int r,int s,int x,int y)
{
    int c[20][20];
    int i,j;
    if(r==x&&s==y)
    {
        printf("\nAnswer:\n");
        for(i=0;i<r;i++)
        {
            for(j=0;j<s;j++)
            {
                c[i][j]=a[i][j]+b[i][j];
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    }
}
void subtract(int a[20][20],int b[20][20],int r,int s,int x,int y)
{
    int c[20][20];
    int i,j;
    if(r==x&&s==y)
    {
        printf("\nAnswer:\n");
        for(i=0;i<r;i++)
        {
            for(j=0;j<s;j++)
            {
                c[i][j]=a[i][j]-b[i][j];
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    }
}
void multiply(int a[20][20],int b[20][20],int r,int s,int x,int y)
{
    int c[20][20];
    int i,j,k,sum=0;
    if(s!=x)
        printf("\nMatrices can't be multiplied\n");
    else
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<y;j++)
            {
                for(k=0;k<x;k++)
                    sum=sum+a[i][k]*b[k][j];
                c[i][j]=sum;
                sum=0;
            }
        }
        printf("\nProduct of matrices:\n");
        for(i=0;i<r;i++)
        {
            for(j=0;j<y;j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }
    }
}
void transpose(int a[20][20],int r,int s)
{
    int c[20][20];
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<s;j++)
        {
            c[j][i]=a[i][j];
        }
    }
    printf("\nTranspose of first matrix:\n");
    for(i=0;i<s;i++)
    {
        for(j=0;j<r;j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }
}
