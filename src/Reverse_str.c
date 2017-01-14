//To reverse a string
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],temp;
    printf("\nEnter string: ");
    gets(str);
    int i=0,j=strlen(str)-1;
    while(i<j)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
    printf("\nReversed string: ");
    puts(str);
    return 0;
}
