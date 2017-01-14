//To delete a character from a string
#include<stdio.h>
#include<string.h>
void del(char *str, char ch);
int main()
{
   char *str,ch;
   printf("\nEnter string: ");
   gets(str);
   printf("\nEnter character to be deleted: ");
   scanf("%ch",&ch);
   del(str,ch);
   return 0;
}

void del(char *str1, char ch)
{
    int j=0;
    char str2[10];
    for(int i=0;i<strlen(str1);i++)
    {
        if (str1[i]!=ch)
        {
            str2[j]=str1[i];
            j++;
        }
    }
    str2[j] = '\0';
    printf("\nCorrected string:");
    puts(str2);
}
