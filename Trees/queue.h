#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;

};

struct queue
{
    int size;
    int front;
    int rear;
    struct node **Q;
};

void create(struct queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct node **)malloc(q->size*sizeof(struct node *));

}

void enqueue(struct queue *q,struct node* val)
{
    if(q->rear==q->size-1)
        printf("Queue is Full!\n");
    else
    {
        q->rear++;
        q->Q[q->rear]=val;
    }
}

struct node* dequeue(struct queue *q)
{
    struct node* x = NULL;
    if(q->rear==q->front)
        printf("Queue is Empty!\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct queue q)
{
    return q.front==q.rear;
}