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
void insertbeg(int data);
void insertpos(int data,int pos);
void del(int pos);
void update(int item,int newitem);
void search(int item);
void sort();
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
            case 3: printf("\nEnter element to be inserted: ");
                    scanf("%d",&data);
                    insertbeg(data);
                    display();
                    break;
            case 4: printf("\nEnter element and the position to be inserted: ");
                    scanf("%d %d",&data,&pos);
                    insertpos(data,pos);
                    display();
                    break;
            case 5: printf("\nEnter the position to be deleted: ");
                    scanf("%d",&pos);
                    del(pos);
                    display();
                    break;
            case 6: printf("\nEnter element to be searched: ");
                    scanf("%d",&item);
                    search(item);
                    break;
            case 7: sort();
                    display();
                    break;
            case 8: printf("\nEnter the item to be updated and the new item: ");
                    scanf("%d %d", &item,&newitem);
                    update(item,newitem);
                    display();
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
void insertbeg(int data)
{
    struct node *p=start,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    while(p->link!=start)
        p=p->link;
    p->link=tmp;
    tmp->link=start;
    start=tmp;
}
void insertpos(int data,int pos)
{
    struct node *p,*p1,*p2,*tmp;
    int c=1,count=1;
    tmp=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    tmp->info=data;
    if(pos==1)
    {
        p1=start;
        while(p1->link!=start)
            p1=p1->link;
        p1->link=tmp;
        tmp->link=start;
        start=tmp;
    }
    else
    {
        p1=start;
        p=start;
        while(p->link!=start)
        {
            count++;
            p=p->link;
        }
        count++;
        if (pos>count)
        {
            printf("There are less than %d elements\n",pos);
            return;
        }
        while(c<pos)
        {
            p2=p1;
            p1=p1->link;
            c++;
        }
        tmp->link=p1;
        p2->link=tmp;
    }
}
void del(int pos)
{
    struct node *p1=start,*tmp=start;
    int c=1;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    if(pos==1)
    {
        while(p1->link!=start)
            p1=p1->link;
        start=tmp->link;
        p1->link=start;
        free(tmp);
    }
    else
    {
        while(c<pos)
        {
            tmp=p1;
            p1=p1->link;
            c++;
        }
        tmp->link=p1->link;
        free(p1);
    }
}
void update(int item,int newitem)
{
    struct node *p=start;
    int flag=0;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        while(p->link!=start)
        {
            if(p->info==item)
            {
                p->info=newitem;
                flag=1;
                break;
            }
            p=p->link;
        }
        if(p->info==item)
        {
            p->info=newitem;
            flag=1;
        }
        if(flag==1)
            printf("\nUpdate successful\n");
        else
            printf("\nUpdate not successful");
    }
}
void search(int item)
{
    struct node *p=start;
    int count=0,flag=0;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        while(p->link!=start)
        {
            if(p->info==item)
            {
                printf("Item found at position: %d",count+1);
                flag=1;
                break;
            }
            count++;
            p=p->link;
        }
        if(flag==0)
            printf("Item not found");
    }
}
void sort()
{
    struct node *p=start,*next;
    int temp;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        while(p->link!=start)
        {
            next=p->link;
            while(next!=start)
            {
                if(next!=start)
                {
                    if(p->info > next->info)
                    {
                        temp=p->info;
                        p->info=next->info;
                        next->info=temp;
                    }
                }
                else
                    break;
                next=next->link;
            }
            p=p->link;
        }
    }
}
