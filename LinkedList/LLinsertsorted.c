#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first=NULL;

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

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
}

void sortedinsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first==NULL)
        first = t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p = p->next;
        }
        if (p==first)
        {
            t->next = first;
            first = t;
        }
        else
        t->next = q->next;
        q->next = t;
    }

}

int main()
{

    int a[]={10,20,30,40,50};
    create(a,5);

    Display(first);
    printf("\n");

    sortedinsert(first,35);

    Display(first);
    printf("\n");

    return 0;
}