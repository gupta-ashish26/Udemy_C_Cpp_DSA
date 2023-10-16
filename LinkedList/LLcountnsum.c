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

//Recursive function for count

int Rcount(struct Node *p)
{
    if(p!=NULL)
        return Rcount(p->next)+1;
    else
        return 0;

}

int sum(struct Node *p)
{
    int sum = 0;

    while(p)
    {
        sum = sum + p->data;
        p=p->next;
    }
    return sum;
}

//Recursive Sum function

int Rsum(struct Node *p)
{
    if(p!=NULL)
        return Rsum(p->next)+p->data;
    else
        return 0;
}

int main()
{
    int a[]={3,5,7,10,15};
    create(a,5);

    printf("Length is %d\n",count(first));
    printf("Length is %d\n",Rcount(first));

    printf("Sum is %d\n",sum(first));
    printf("Sum is %d\n",Rsum(first));

    return 0;
}