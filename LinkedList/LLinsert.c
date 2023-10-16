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

int count(struct Node *p)
{
    int l = 0;
    while(p)
    {
        l++;
        p=p->next;
    }

    return l;
}

void llinsert(struct Node *p,int pos,int val)
{
    struct Node *t;

    if(pos<0 || pos>count(p))
        return;
    
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data=val;

    if (pos==0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(int i = 0;i<(pos-1);i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    /*
    int a[]={3,5,7,10,15};
    create(a,5);

    Display(first);
    printf("\n");
    */

    //A new list can also be formed using insert only.
    llinsert(first,0,40);
    llinsert(first,1,20);

    Display(first);
    printf("\n");

    return 0;
}