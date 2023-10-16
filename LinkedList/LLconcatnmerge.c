#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first=NULL,*second=NULL,*third=NULL;

void create(int a[],int n)
{
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last=t;
    }
}

void create2(int a[],int n)
{
    int i;
    struct Node *t,*last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = a[0];
    second->next = NULL;
    last = second;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
}

void concat(struct Node *p,struct Node *q)
{
    third = p;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data<q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL; 
    }

    while(p&&q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last = p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last = q;
            q=q->next;
            last->next=NULL;
        }
    }
    if (p) last->next = p;
    if (q) last->next = q;
}

int main()
{
    int a[]={3,5,7,10,15};
    create(a,5);
    int b[]={1,4,9,18,19,25,37};
    create2(b,7);
    
    /*
    Display(first);
    printf("\n");
    Display(second);
    printf("\n");
    concat(first,second);
    Display(third);
    */

    merge(first,second);
    Display(third);

    return 0;
}