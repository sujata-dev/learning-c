//Implementing queue using linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*tmp,*front1;
void enqueue(int item);
void empty(struct node *front,struct node *rear);
void display();
void create();
void dequeue();
void count();
int cnt=0;
int main()
{
    int item,ch;
    while(1)
    {
        printf("\n1) Create queue");
        printf("\n2) Enqueue");
        printf("\n3) Dequeue");
        printf("\n4) Display");
        printf("\n5) Count of elements in queue");
        printf("\n6) Exit");
        printf("\nEnter 1-6: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: printf("Enter element to be enqueued: ");
                    scanf("%d",&item);
                    enqueue(item);
                    display();
                    break;
            case 3: dequeue();
                    display();
                    break;
            case 4: display();
                    break;
            case 5: count();
                    break;
            case 6: exit(0);
            default:    printf("\nWrong choice: ");
                        break;
        }
    }
}
void create()
{
    front=rear=NULL;
    printf("\nQueue Created\n");
}
void enqueue(int item)
{
    if(rear==NULL)
    {
        rear=(struct node*)malloc(sizeof(struct node));
        rear->ptr=NULL;
        rear->info=item;
        front=rear;
    }
    else
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        rear->ptr=tmp;
        tmp->info=item;
        tmp->ptr=NULL;
        rear=tmp;
    }
    cnt++;
}
void display()
{
    front1=front;
    empty(front1,rear);
    printf("\nQueue:\n");
    while(front1!=rear)
    {
        printf("%d->",front1->info);
        front1=front1->ptr;
    }
    if (front1==rear)
        printf("%d->NULL\n",front1->info);
}
void empty(struct node *front,struct node *rear)
{
    if((front==NULL)&&(rear==NULL))
        printf("\nUnderflow");
}
void dequeue()
{
    front1=front;
    if(front1==NULL)
    {
        printf("\nUnderflow");
        return;
    }
    else
    {
        if(front1->ptr!=NULL)
        {
            front1=front1->ptr;
            printf("\nDequeued value: %d",front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\nDequeued value: %d",front->info);
            free(front);
            front=NULL;
            rear=NULL;
        }
        cnt--;
    }
}
void count()
{
    printf("\nNumber of elements in queue: %d",cnt);
}
