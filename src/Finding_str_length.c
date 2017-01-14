//Finding length of string using call by reference
#include<stdio.h>
int len(char *s)
{
    int i;
    for(i=0;*s!='\0';s++,++i);
    return i;
}
int main()
{
    char str[20];
    printf("Enter string: ");
    gets(str);
    printf("Length of string: %d",len(&str));
    return 0;
}
