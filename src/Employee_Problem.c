/*Declare a structure to store the following information of an employee:
- Employee code
- Employee name
- Salary
- Department number
- Date of Joining (a structure consisting of day, month and year).
Write a C program to store the data of 'n' employees where n is given by user. Include a menu to:
a) Display employee information getting the max and min salary.
b) Display employee records in ascending order according to their salary.
c) Display employee records in ascending order according to their date of joining.
d) Display the department wise employee records.*/
#include<stdio.h>
#include<stdlib.h>
void maxminsal(int);
void sal(int);
void doj(int);
void dept(int);
struct date
{
    int date1;
    int month;
    int year;
};
struct student
{
    int code;
    char name[20];
    int salary;
    int deptno;
    struct date d;
}*a[100];
int main()
{
    int i,n,ch,ans=5;
    printf("\nEnter number of records: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=(struct student*)malloc(sizeof(struct student));
        printf("\nEnter code: ");
        scanf("%d",&a[i]->code);
        printf("Enter name: ");
        scanf("%s",&(a[i]->name));
        printf("Enter salary: ");
        scanf("%d",&a[i]->salary);
        printf("Enter deptno: ");
        scanf("%d",&a[i]->deptno);
        printf("Enter date, month and year of joining: ");
        scanf("%d %d %d",&a[i]->d.date1,&a[i]->d.month,&a[i]->d.year);
    }
    while(ans==5)
    {
        printf("\n\n1) To get max-min values");
        printf("\n2) To arrange values in ascending order of salary");
        printf("\n3) To arrange values in ascending order of doj");
        printf("\n4) To arrange values in ascending order of deptno");
        printf("\nEnter 1, 2, 3 or 4: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: maxminsal(n);
                    break;
            case 2: sal(n);
                    break;
            case 3: doj(n);
                    break;
            case 4: dept(n);
                    break;
        }
        printf("\n\nEnter 5 to continue, else exit: ");
        scanf("%d",&ans);
    }
    return 0;
}
void maxminsal(int n)
{
    int i,num,ch;
    int large=a[0]->salary;
    int small=a[0]->salary;
    printf("\n1) To get max value");
    printf("\n2) To get min value");
    printf("\nEnter 1 or 2: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: for(i=1;i<n;i++)
                {
                    if(large<(a[i]->salary))
                    {
                        large=a[i]->salary;
                        num=i;
                    }
                }
                printf("\n\nFor max salary:");
                printf("\nCode %d",a[num]->code);
                printf("\nName %s",a[num]->name);
                printf("\nSalary %d",a[num]->salary);
                printf("\nDeptno %d",a[num]->deptno);
                printf("\nDate of joining %d/%d/%d",a[num]->d.date1,
                a[num]->d.month,a[num]->d.year);
                break;
        case 2: for(i=1;i<n;i++)
                {
                    if(small>(a[i]->salary))
                    {
                        small=(a[i]->salary);
                        num=i;
                    }
                }
                printf("\n\nFor min salary:");
                printf("\nCode %d",a[num]->code);
                printf("\nName %s",a[num]->name);
                printf("\nSalary %d",a[num]->salary);
                printf("\nDeptno %d",a[num]->deptno);
                printf("\nDate of joining %d/%d/%d",a[num]->d.date1,
                a[num]->d.month,a[num]->d.year);
                break;
    }
}
void sal(int n)
{
    int i,j,x;
    for(i=0;i<n;++i)
    {
        for(j=i+1;j<n;++j)
        {
            if((a[i]->salary)>(a[j]->salary))
            {
                x=a[i]->salary;
                a[i]->salary=a[j]->salary;
                a[j]->salary=x;
            }
        }
    }
    printf("\nAscending order of salary: \n");
    for(i=0;i<n;++i)
    {
        printf("\n\nCode: %d",a[i]->code);
        printf("\nName: %s",a[i]->name);
        printf("\nSalary: %d",a[i]->salary);
        printf("\nDeptno: %d",a[i]->deptno);
        printf("\nDate of joining: %d/%d/%d",a[i]->d.date1,
        a[i]->d.month,a[i]->d.year);
    }
}
void doj(int n)
{
    int i, j,x,y,z;
    for(i=0;i<n;++i)
    {
        for(j=i+1;j<n;++j)
        {
            if(a[i]->d.year>a[j]->d.year)
            {
                x=a[i]->d.year;
                a[i]->d.year=a[j]->d.year;
                a[j]->d.year=x;
            }
            else if(a[i]->d.month>a[j]->d.month)
            {
                y=a[i]->d.month;
                a[i]->d.month=a[j]->d.month;
                a[j]->d.month=y;
            }
            else
            {
                z=a[i]->d.date1;
                a[i]->d.date1=a[j]->d.date1;
                a[j]->d.date1=z;
            }

        }
    }
    printf("\nAscending order of date of joining: \n");
    for(i=0;i<n;++i)
    {
        printf("\n\nCode: %d",a[i]->code);
        printf("\nName: %s",a[i]->name);
        printf("\nSalary: %d",a[i]->salary);
        printf("\nDeptno: %d",a[i]->deptno);
        printf("\nDate of joining: %d/%d/%d",a[i]->d.date1,
        a[i]->d.month,a[i]->d.year);
    }
}
void dept(int n)
{
    int i,j,x;
    for(i=0;i<n;++i)
    {
        for(j=i+1;j<n;++j)
        {
            if((a[i]->deptno)>(a[j]->deptno))
            {
                x=a[i]->deptno;
                a[i]->deptno=a[j]->deptno;
               a[j]->deptno=x;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("\nDeptno: %d",a[i]->deptno);
        printf("\nCode: %d",a[i]->code);
        printf("\nName: %s",a[i]->name);
        printf("\nSalary: %d",a[i]->salary);
        printf("\nDate of joining: %d/%d/%d",a[i]->d.date1,
        a[i]->d.month,a[i]->d.year);
    }
}
