//Circular singly linked list operations
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *start=NULL;
void create();
void display();
int main()
{
    int ch,n,data,pos,item,newitem;
    while(1)
    {
        printf("\n1) Create List");
        printf("\n2) Display");
        printf("\n3) Insert at the beginning");
        printf("\n4) Insert at position");
        printf("\n5) Deletion");
        printf("\n6) Search");
        printf("\n7) Sort");
        printf("\n8) Update");
        printf("\n9) Reverse");
        printf("\n10) Quit");
        printf("\nEnter 1-10: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter number of nodes: ");
                    scanf("%d",&n);
                    create(n);
                    display();
                    break;
            case 2: display();
                    break;
            case 10:    exit(1);
                        break;
            default:    printf("\nWrong choice: ");
                        break;
        }
    }
}
void create(int n)
{
    int i,data;
    struct node *prev,*tmp;
    if(n>=1)
    {
        start=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter element to be inserted: ");
        scanf("%d",&data);
        start->info=data;
        start->link=NULL;
        prev=start;
        for(i=2;i<=n;i++)
        {
            tmp=(struct node*)malloc(sizeof(struct node));
            printf("Enter element to be inserted: ");
            scanf("%d",&data);
            tmp->info=data;
            tmp->link=NULL;
            prev->link=tmp;
            prev=tmp;
        }
        prev->link=start;
    }
}
void display()
{
    struct node *p=start;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        printf("\nList:\n");
        while (p->link!=start)
        {
            printf("%d->",p->info);
            p=p->link;
        }
        printf("%d->NULL\n",p->info);
    }
}
