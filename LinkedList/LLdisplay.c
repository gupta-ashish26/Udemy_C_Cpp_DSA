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

//Recursive Function for display

void Rdisplay(struct Node *p)
{
    if (p!=NULL)
    {
        printf("%d\t",p->data);
        Rdisplay(p->next);
    }
}

int main()
{
    int a[]={3,5,7,10,15};
    create(a,5);

    Display(first);
    printf("\n");
    Rdisplay(first);

    return 0;
}