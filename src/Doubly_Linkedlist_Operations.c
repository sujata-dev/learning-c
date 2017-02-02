//Doubly linked list operations
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
struct node *create(struct node *start);
struct node *insertempty(struct node *start,int data);
struct node *insertend(struct node *start,int data);
int main()
{
    struct node *start=NULL;
    int ch;
    while(1)
    {
        printf("\n1) Create List");
        printf("\n2) Display");
        printf("\n3) Insert to empty list");
        printf("\n4) Insert at the beginning");
        printf("\n5) Insert at the end");
        printf("\n6) Insert after node");
        printf("\n7) Insert before node");
        printf("\n8) Delete");
        printf("\n9) Reverse");
        printf("\n10) Quit");
        printf("\nEnter 1-10: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: start=create(start);
                    break;
            case 10:    exit(1);
                        break;
            default:    printf("\nWrong choice: ");
                        break;
        }
    }
}
struct node *create(struct node *start)
{
    int i,n,data;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
        return start;
    printf("\nEnter element to be inserted: ");
    scanf("%d",&data);
    start=insertempty(start,data);
    for(i=2;i<=n;i++)
    {
        printf("Enter element to be inserted: ");
        scanf("%d",&data);
        start=insertend(start,data);
    }
    return start;
}
struct node *insertempty(struct node *start,int data)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->prev=NULL;
    tmp->next=NULL;
    start=tmp;
    return start;
}
struct node *insertend(struct node *start,int data)
{
    struct node *p,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    p=start;
    while(p->next!=NULL)
        p=p->next;
    p->next=tmp;
    tmp->next=NULL;
    tmp->prev=p;
    return start;
}
