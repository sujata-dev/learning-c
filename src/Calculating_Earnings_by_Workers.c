/*To calculate the earnings by workers who are paid an hourly wage. Workers working for more than 40 hours are paid 'time and a half'.*/
#include<stdio.h>
int main()
{   float rw,hw,extra,extra_wage,total,n;
    printf("\nEnter regular wage, for 40 hours (in Rs): ");
    scanf("%f",&rw);
    printf("\nEnter hourly rate (in Rs): ");
    scanf("%f",&hw);
    printf("\nEnter number of hours worked by worker: ");
    scanf("%f",&n);
    if(n>40)
    {
        extra=n-40;
        extra_wage=extra*hw;
        total=rw+extra_wage;
        printf("\nTotal wage of the worker: %f",total);
    }
    else
        printf("\nTotal wage of the worker: %f",rw);
    return 0;
}
