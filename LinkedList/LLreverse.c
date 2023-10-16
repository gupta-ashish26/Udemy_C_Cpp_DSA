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

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
}

//Reversing Elements
void llreverse(struct Node *p)
{
    int arr[count(p)];
    int i=0;

    while(p!=NULL)
    {
        arr[i] = p->data;
        p=p->next;
        i++;
    }

    p=first;
    i--;

    while(p!=NULL)
    {
        p->data = arr[i];
        p=p->next;
        i--;
    }

}

//Reversing the Links
void reverse(struct Node *p) 
{
    struct Node *q = NULL;
    struct Node *r = NULL;
    
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;
}

//Reversing using recursion(while returning)
void recreverse(struct Node *q,struct Node *p)
{
    if (p!=NULL)
    {
        recreverse(p,p->next);
        p->next = q;
    }
    else
        first = q;

}

int main()
{

    int a[]={10,20,30,40,50};
    create(a,5);

    Display(first);
    printf("\n");

    //llreverse(first);
    reverse(first);
    //recreverse(NULL,first);

    Display(first);
    printf("\n");

    return 0;
}