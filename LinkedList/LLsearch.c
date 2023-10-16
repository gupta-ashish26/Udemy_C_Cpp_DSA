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

struct Node * Lsearch(struct Node *p,int key)
{
    while(p!=NULL)
    {
        if (key==p->data)
            return p;
        else
            p = p->next;
    }
    return NULL;
}

//Recursive Version

struct Node * Rlsearch(struct Node *p,int key)
{
    if (p==NULL)
        return NULL;
    if (key==p->data)
        return p;
    else
        return Rlsearch(p->next,key);

}

//Creating an optimised linear search algorithm.
//if the key is found sending the node to head so in case 
//if same key is searched again it takes less time.

struct Node * Loptimised_search(struct Node *p,int key)
{
    struct Node *q;
    while(p!=NULL)
    {
        if (key==p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        else
        {
            q=p;
            p = p->next;
        }
    }
    return NULL;
}


int main()
{
    int a[]={3,5,7,10,15};
    create(a,5);

    struct Node *temp;

    //temp=Lsearch(first,10);
    //temp=Rlsearch(first,10);
    temp=Loptimised_search(first,10);
    if (temp)
        printf("Key is found %d\n",temp->data) ;
    else
        printf("Key is not found");

    return 0;
}