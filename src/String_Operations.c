//Various string operations
#include<stdio.h>
void copy(char [100]);
void rev(char [100],int);
void pal(char [100],int);
void concat(char [100],char [100],int);
int main()
{
    char s1[100],s2[100];
    int choice,len,ans=5;
    printf("\nEnter string s1: ");
    scanf("%s",s1);
    for(len=0; s1[len]!='\0'; ++len);
    printf("Length of string: %d\n",len);
    while(ans==5)
    {
        printf("\n1) To copy a string");
        printf("\n2) To reverse a string");
        printf("\n3) To find whether it is palindrome or not");
        printf("\n4) To concatenate two strings");
        printf("\nEnter 1,2,3 or 4: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: copy(s1);
                    break;
            case 2: rev(s1,len);
                    break;
            case 3: pal(s1,len);
                    break;
            case 4: printf("Enter second string: ");
                    scanf("%s",s2);
                    concat(s1,s2,len);
                    break;
            default: printf("\nInvalid Choice");
        }
        printf("\nEnter 5 to continue, else exit: ");
        scanf("%d",&ans);
    }
    return 0;
}
void copy(char str1[100])
{
    char str2[100];
    int i;
    for(i=0; str1[i]!='\0'; ++i)
    {
        str2[i]=str1[i];
    }
    str2[i]='\0';
    printf("\nCopied string: ");
    puts(str2);
}
void rev(char str1[100],int length)
{

    char temp;
    int i,j;
    i=0;
    j=length-1;
    while(i<j)
    {
        temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
        i++;
        j--;
    }
    printf("\nReverse string is: ");
    puts(str1);
}
void pal(char str1[100],int length)
{
    int i,flag=0;
    for(i=0;i<length;i++)
    {
        if(str1[i] != str1[length-i-1])
        {
            flag=1;
            break;
        }
    }
    if(flag)
        printf("\nIt is not a palindrome");
    else
        printf("\nIt is a palindrome");
}
void concat(char str1[100],char str2[100],int length)
{
    int j;
    for(j=0; str2[j]!='\0'; ++j, ++length)
    {
        str1[length]=str2[j];
    }
    str1[length]='\0';
    printf("\nConcatenated String: ");
    puts(str1);
}
