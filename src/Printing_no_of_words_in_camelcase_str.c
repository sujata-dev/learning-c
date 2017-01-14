//printing the number of words in a camelcase string
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int count=0,i=0;
    char* s=(char*)malloc(10240*sizeof(char));
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++)
        if(s[i]>='A'&&s[i]<='Z')
            count++;
    printf("%d",count+1);
    return 0;
}
