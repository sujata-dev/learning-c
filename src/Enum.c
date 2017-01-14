//Implementing enumeration
#include <stdio.h>
enum week{mon,tue,wed,thur,fri,sat,sun};
int main()
{
    enum week today;
    today=wed;
    printf("Day: %d",today+1);
    return 0;
}
