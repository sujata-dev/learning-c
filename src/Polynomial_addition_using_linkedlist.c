//Polynomial addition using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    float coef;
    int exp;
    struct node *link;
};
struct node *input(struct node *start);
struct node *create(struct node *start,float co,int ex);
void display(struct node *ptr);
struct node *add(struct node *p1,struct node *p2);
int main()
{
    struct node *start1=NULL,*start2=NULL,*start3=NULL;
    printf("Polynomial1:\n");
    start1=input(start1);
    printf("Polynomial2:\n");
    start2=input(start2);
    start3=add(start1,start2);
    printf("\nPolynomial1 is:");
    display(start1);
    printf("Polynomial2 is:");
    display(start2);
    printf("Added Polynomial is:");
    display(start3);
}
struct node *input(struct node *start)
{
    int i,n,ex;
    float co;
    printf("No of terms to be entered: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter coefficient for term %d: ",i);
        scanf("%f",&co);
        printf("Enter exponent for term %d: ",i);
        scanf("%d",&ex);
        start=create(start,co,ex);
    }
    return start;
}
struct node *create(struct node *start,float co,int ex)
{
    struct node *ptr,*tmp;
    tmp=malloc(sizeof(struct node));
    tmp->coef=co;
    tmp->exp=ex;
    if(start==NULL ||ex>start->exp)
    {
        tmp->link=start;
        start=tmp;
    }
    else
    {
        ptr=start;
        while(ptr->link!=NULL && ptr->link->exp>ex)
            ptr=ptr->link;
        tmp->link=ptr->link;
        ptr->link=tmp;
        if(ptr->link==NULL)
            tmp->link=NULL;
    }
    return start;
}
void display(struct node *ptr)
{
    if(ptr==NULL)
    {
        printf("Empty\n");
        return;
    }
    while(ptr!=NULL)
    {
        printf(" (%.1fx^%d) +",ptr->coef,ptr->exp);
        ptr=ptr->link;
    }
    printf("\b \b\n\n");
}
struct node *add(struct node *p1,struct node *p2)
{
    struct node *start3=NULL,*p3,*tmp;
    if(p1==NULL && p2==NULL)
        return start3;
    while(p1!=NULL && p2!=NULL)
    {
        tmp=malloc(sizeof(struct node));
        if(start3==NULL)
        {
            start3=tmp;
            p3=start3;
        }
        else
        {
            p3->link=tmp;
            p3=p3->link;
        }
        if(p1->exp > p2->exp)
        {
            tmp->coef=p1->coef;
            tmp->exp=p1->exp;
            p1=p1->link;
        }
        else
        {
            if(p2->exp > p1->exp)
            {
                tmp->coef=p2->coef;
                tmp->exp=p2->exp;
                p2=p2->link;
            }
            else
            {
                if(p1->exp == p2->exp)
                {
                    tmp->coef=p1->coef + p2->coef;
                    tmp->exp=p1->exp;
                    p1=p1->link;
                    p2=p2->link;
                }
            }
        }
    }
    while(p1!=NULL)
    {
        tmp=malloc(sizeof(struct node));
        tmp->coef=p1->coef;
        tmp->exp=p1->exp;
        if(start3==NULL)
        {
            start3=tmp;
            p3=start3;
        }
        else
        {
            p3->link=tmp;
            p3=p3->link;
        }
        p1=p1->link;
    }
    while(p2!=NULL)
    {
        tmp=malloc(sizeof(struct node));
        tmp->coef=p2->coef;
        tmp->exp=p2->exp;
        if(start3==NULL)
        {
            start3=tmp;
            p3=start3;
        }
        else
        {
            p3->link=tmp;
            p3=p3->link;
        }
        p2=p2->link;
    }
    p3->link=NULL;
    return start3;
}
