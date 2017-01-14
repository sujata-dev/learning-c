//Converting spaces to dashes in a string
#include<stdio.h>
void abc(const char *str)
{
    while(*str)
    {
        if(*str==' ')
            printf("-");
        else
            printf("%c",*str);
        str++;
    }
}
int main()
{
    char s[50];
    printf("Enter a string: ");
    gets(s);
    abc(s);
    return 0;
}
