//Implementing stack using linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*tmp;
void create();
void push(int item);
void pop();
void empty(struct node *top);
void display();
void count();
int cnt=0;

int main()
{
    int item,ch;
    while(1)
    {
        printf("\n1) Create stack");
        printf("\n2) Push");
        printf("\n3) Pop");
        printf("\n4) Display");
        printf("\n5) Count of elements in stack");
        printf("\n6) Exit");
        printf("\nEnter 1-6: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: printf("\nEnter element to be pushed: ");
                    scanf("%d", &item);
                    push(item);
                    display();
                    break;
            case 4: display();
                    break;
            case 6: exit(0);
                    break;
            default:    printf("\nWrong choice: ");
                        break;
        }
    }
}
void create()
{
    top=NULL;
    printf("\nStack Created\n");
}
void push(int item)
{
    if(top==NULL)
    {
        top=(struct node*)malloc(sizeof(struct node));
        top->ptr=NULL;
        top->info=item;
    }
    else
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->ptr=top;
        tmp->info=item;
        top=tmp;
    }
    cnt++;
}
void display()
{
    top1=top;
    empty(top1);
    printf("\nStack:\n");
    while(top1!=NULL)
    {
        printf("%d\n",top1->info);
        top1=top1->ptr;
    }
}
void empty(struct node *top)
{
    if(top==NULL)
        printf("\nUnderflow");
}
