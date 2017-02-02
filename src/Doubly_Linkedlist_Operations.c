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
void display(struct node *start);
struct node *insertempty(struct node *start,int data);
struct node *insertend(struct node *start,int data);
struct node *insertbeg(struct node *start,int data);
struct node *insertafter(struct node *start,int data,int item);
struct node *insertbefore(struct node *start,int data,int item);
int main()
{
    struct node *start=NULL;
    int ch,data,item;
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
                    display(start);
                    break;
            case 2: display(start);
                    break;
            case 3: printf("\nEnter element to be inserted: ");
                    scanf("%d",&data);
                    start=insertempty(start,data);
                    display(start);
                    break;
            case 4: printf("\nEnter element to be inserted: ");
                    scanf("%d",&data);
                    start=insertbeg(start,data);
                    display(start);
                    break;
            case 5: printf("\nEnter element to be inserted: ");
                    scanf("%d",&data);
                    start=insertend(start,data);
                    display(start);
                    break;
            case 6: printf("\nEnter element to be inserted: ");
                    scanf("%d",&data);
                    printf("\nEnter element after which to insert: ");
                    scanf("%d",&item);
                    start=insertafter(start,data,item);
                    display(start);
                    break;
            case 7: printf("\nEnter element to be inserted: ");
                    scanf("%d",&data);
                    printf("\nEnter element before which to insert: ");
                    scanf("%d",&item);
                    start=insertbefore(start,data,item);
                    display(start);
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
void display(struct node *start)
{
    struct node *p;
    if(start==NULL)
    {
        printf("List is empty");
        return;
    }
    p=start;
    printf("\nList: ");
    while(p!=NULL)
    {
        printf("%d->",p->info);
        p=p->next;
    }
    printf("NULL\n");
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
struct node *insertbeg(struct node *start,int data)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->prev=NULL;
    tmp->next=start;
    start->prev=tmp;
    start=tmp;
    return start;
}
struct node *insertafter(struct node *start,int data,int item)
{
    struct node *p,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    p=start;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            tmp->prev=p;
            tmp->next=p->next;
            if(p->next!=NULL)
                p->next->prev=tmp;
            p->next=tmp;
            return start;
        }
        p=p->next;
    }
    printf("%d not present in list\n",item);
    return start;
}
struct node *insertbefore(struct node *start,int data,int item)
{
    struct node *p,*tmp;
    if(start==NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if(item==start->info)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->prev=NULL;
        tmp->next=start;
        start=tmp;
        return start;
    }
    p=start;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->prev=p->prev;
            tmp->next=p;
            p->prev->next=tmp;
            p->prev=tmp;
            return start;
        }
        p=p->next;
    }
    printf("%d not present in list\n",item);
    return start;
}
