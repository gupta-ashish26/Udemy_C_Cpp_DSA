#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *front;
    struct node *rear;
};

struct node q;

void enqueue(int val)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
        printf("Queue is Full!\n");
    else
    {
        t->data=val;
        t->next=NULL;
        if(q.front==NULL)
            q.front = q.rear = t;
        else
        {
            q.rear->next=t;
            q.rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct node *p;
    if(q.front==NULL)
        printf("Queue is Empty!\n");
    else
    {
        p=q.front;
        q.front=q.front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display()
{
    struct node *p = q.front;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    display();
    enqueue(30);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}