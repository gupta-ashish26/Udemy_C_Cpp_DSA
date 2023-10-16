#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *first=NULL;

void create(int arr[],int n)
{
    struct node *last,*temp;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=arr[0];
    first->next=NULL;
    last=first;

    for(int i = 1;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display()
{
    struct node *p = first;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}

void reverse()
{
    struct node *r=NULL,*q=NULL;
    struct node *p = first;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;

        q->next=r;
    }
    first = q;
}

void sortasc()
{
    struct node *p = first;
    
    while(p!=NULL)
    {
        struct node *min=p;
        struct node *q = p->next;
        while(q!=NULL)
        {
            if(min->data>q->data)
            {
                min = q;
                q = q->next;
            }
            else
                q = q->next;
        }

        int temp = p->data;
        p->data = min->data;
        min->data = temp;

        p = p->next;
    }
}

void sortdsc()
{
    struct node *p = first;
    
    while(p!=NULL)
    {
        struct node *max=p;
        struct node *q = p->next;
        while(q!=NULL)
        {
            if(max->data<q->data)
            {
                max = q;
                q = q->next;
            }
            else
                q = q->next;
        }

        int temp = p->data;
        p->data = max->data;
        max->data = temp;

        p = p->next;
    }
}

int main()
{
    int arr[]={10,20,40,30,50};
    create(arr,5);
    display();

    //reverse();
    //display();

    sortdsc();
    display();

    sortasc();
    display();

    return 0;
}