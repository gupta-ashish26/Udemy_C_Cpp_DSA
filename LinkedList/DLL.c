#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *createdll(int arr[],int n) 
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *tail = NULL;

    head->prev = NULL;
    head->data = arr[0];
    head->next = NULL;
    tail = head;

    for(int i = 1;i<n;i++)
    {
        struct node *t = (struct node*)malloc(sizeof(struct node));
        t->prev = tail;
        t->data = arr[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }

    return head;
}

void displaydll(struct node *head)
{
    struct node *p = head;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

void insertdll(struct node **head,int pos,int key)
{
    struct node *p = *head;
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = key;

    if (pos==0)
    {
        t->prev=NULL;
        t->next = p;
        p->prev = t;

        *head = t;
        return;
    }

    for(int i = 1;i<pos;i++)
    {
        p=p->next;
    }
    t->next = p->next;
    t->prev = p;
    if(p->next)
        (p->next)->prev = t;
    p->next = t;

}

void deletedll(struct node **head,int pos)
{
    struct node *p=*head;
    struct node *q=NULL;

    if(pos==1)
    {
        q=p;
        p=p->next;
        p->prev = NULL;
        free(q);
        *head = p;
        return;
    }
    for(int i = 1;i<pos;i++)
    {
        q=p;
        p=p->next;
    }
    q->next = p->next;
    if(p->next)
        p->next->prev = q;
    free(p);
}

void reversedll(struct node **head)
{
    struct node *p=*head;
    while(p)
    {
        struct node *t = p->next;
        p->next = p->prev;
        p->prev = t;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            *head = p;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    struct node *first = NULL;
    first = createdll(arr,sizeof(arr)/sizeof(*arr));
    displaydll(first);

    insertdll(&first,5,6);
    displaydll(first);

    deletedll(&first,6); 
    displaydll(first);

    reversedll(&first);
    displaydll(first);

    return 0;
}