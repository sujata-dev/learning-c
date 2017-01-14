//Binary to decimal and decimal to binary conversion
#include<stdio.h>
#include<math.h>
int bintodec();
int dectobin();
int main()
{
    int choice;
    printf("\n1) To convert a binary number to decimal");
    printf("\n2) To convert a decimal number to binary");
    printf("\nEnter 1 or 2: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: bintodec();
                break;
        case 2: dectobin();
                break;
        default: printf("\nInvalid Choice");
    }
    return 0;
}
int bintodec()
{
    long int num;
    int dec=0,i=0,rem;
    printf("\nEnter a binary number: ");
    scanf("%ld", &num);
    while (num!=0)
    {
        rem=num%10;
        num=num/10;
        dec=dec+rem*pow(2,i);
        ++i;
    }
    printf("\nThe number in decimal: %d",dec);
}
int dectobin()
{
    long int num,a;
    int arr[100],i=1,j;
    printf("\nEnter a decimal number: ");
    scanf("%ld",&num);
    a=num;
    while(a!=0)
    {
        arr[i++]=a%2;
        a=a/2;
    }
    printf("\nThe number in binary: ");
    for(j=i-1;j>0;j--)
        printf("%d",arr[j]);
}
