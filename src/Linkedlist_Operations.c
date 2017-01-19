//Linked list operations
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *create(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *insertbeg(struct node *start,int data);
struct node *insertend(struct node *start,int data);
struct node *insertafter(struct node *start,int data,int item);
struct node *insertbefore(struct node *start,int data,int item);
struct node *insertpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);
struct node *concat(struct node *start1,struct node *start2);
int main()
{
    struct node *start=NULL,*start1=NULL,*start2=NULL;
    int ch,data,pos,item;
    while(1)
    {
        printf("\n1) Create List");
        printf("\n2) Display");
        printf("\n3) Count");
        printf("\n4) Search");
        printf("\n5) Insert at the beginning");
        printf("\n6) Insert at the end");
        printf("\n7) Insert after node");
        printf("\n8) Insert before node");
        printf("\n9) Insert at a position");
        printf("\n10) Delete");
        printf("\n11) Reverse");
        printf("\n12) Concatenate 2 lists");
        printf("\n13) Quit");
        printf("\nEnter 1-13: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: start=create(start);
                    display(start);
                    break;
            case 2: display(start);
                    break;
            case 3: count(start);
                    break;
            case 4: printf("\nEnter element to be searched: ");
                    scanf("%d",&data);
                    search(start,data);
                    break;
            case 5: printf("\nEnter element to be inserted: ");
                    scanf("%d",&data);
                    start=insertbeg(start,data);
                    display(start);
                    break;
            case 6: printf("\nEnter element to be inserted: ");
                    scanf("%d",&data);
                    start=insertend(start,data);
                    display(start);
                    break;
            case 7: printf("\nEnter element to be inserted: ");
                    scanf("%d",&data);
                    printf("\nEnter element after which to insert: ");
                    scanf("%d",&item);
                    start=insertafter(start,data,item);
                    display(start);
                    break;
            case 8: printf("\nEnter element to be inserted: ");
                    scanf("%d",&data);
                    printf("\nEnter element before which to insert: ");
                    scanf("%d",&item);
                    start=insertbefore(start,data,item);
                    display(start);
                    break;
            case 9: printf("\nEnter element and the position to be inserted: ");
                    scanf("%d %d",&data,&pos);
                    start=insertpos(start,data,pos);
                    display(start);
                    break;
            case 10:    printf("\nEnter element to be deleted: ");
                        scanf("%d",&data);
                        start=del(start,data);
                        display(start);
                        break;
            case 11:    start=reverse(start);
                        display(start);
                        break;
            case 12:    printf("\nFirst list:\n");
                        start1=create(start1);
                        printf("\nSecond list:\n");
                        start2=create(start2);
                        printf("\nList1: ");
                        display(start1);
                        printf("\nList2: ");
                        display(start2);
                        start1=concat(start1,start2);
                        printf("\nConcatenated list: ");
                        display(start1);
                        break;
            case 13:    exit(1);
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
    start=insertbeg(start,data);
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
        p=p->link;
    }
    printf("NULL\n");
}
void count(struct node *start)
{
    struct node *p;
    int cnt=0;
    p=start;
    while(p!=NULL)
    {
        p=p->link;
        cnt++;
    }
    printf("\nNumber of elements: %d\n",cnt);
}
void search(struct node *start,int item)
{
    struct node *p=start;
    int pos=1;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            printf("Item found at position %d\n",pos);
            return;
        }
        p=p->link;
        pos++;
    }
    printf("Item not found");
}
struct node *insertbeg(struct node *start,int data)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=start;
    start=tmp;
    return start;
}
struct node *insertend(struct node *start,int data)
{
    struct node *p,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    p=start;
    while(p->link!=NULL)
        p=p->link;
    p->link=tmp;
    tmp->link=NULL;
    return start;
}
struct node *insertafter(struct node *start,int data,int item)
{
    struct node *p,*tmp;
    p=start;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            return start;
        }
        p=p->link;
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
        tmp->link=start;
        start=tmp;
        return start;
    }
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->info==item)
        {
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            return start;
        }
        p=p->link;
    }
    printf("%d not present in list\n",item);
    return start;
}
struct node *insertpos(struct node *start,int data,int pos)
{
    struct node *p,*tmp;
    int i;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    if(pos==1)
    {
        tmp->link=start;
        start=tmp;
        return start;
    }
    p=start;
    for(i=1;i<pos-1 && p!=NULL;i++)
        p=p->link;
    if(p==NULL)
        printf("There are less than %d elements\n",pos);
    else
    {
        tmp->link=p->link;
        p->link=tmp;
    }
    return start;
}
struct node *del(struct node *start,int data)
{
    struct node *p,*tmp;
    if(start==NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if(start->info==data)
    {
        tmp=start;
        start=start->link;
        free(tmp);
        return start;
    }
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->info==data)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            return start;
        }
        p=p->link;
    }
    printf("%d not found in list\n",data);
    return start;
}
struct node *reverse(struct node *start)
{
    struct node *prev,*ptr,*next;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return start;
}
struct node *concat(struct node *start1,struct node *start2)
{
    struct node *ptr;
    if(start1==NULL)
    {
        start1=start2;
        return start1;
    }
    if(start2==NULL)
        return start1;
    ptr=start1;
    while(ptr->link!=NULL)
        ptr=ptr->link;
    ptr->link=start2;
    return start1;
}
