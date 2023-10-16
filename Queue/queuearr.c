#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(struct queue *q,int val)
{
    if(q->rear==q->size-1)
        printf("Queue is Full!\n");
    else
    {
        q->rear++;
        q->arr[q->rear]=val;
    }
}

int dequeue(struct queue *q)
{
    int x = -1;
    if(q->rear==q->front)
        printf("Queue is Empty!\n");
    else
    {
        q->front++;
        x = q->arr[q->front];
    }
    return x;
}

void display(struct queue q)
{
    if(q.rear==q.front)
        printf("Queue is Empty!\n");
    else
    {
        for(int i=q.front+1;i<=q.rear;i++)
        {
            printf("%d\t",q.arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    struct queue q;
    q.size = 10;
    q.front=q.rear=-1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q,10);
    enqueue(&q,20);
    display(q);
    enqueue(&q,30);
    display(q);
    enqueue(&q,40);
    enqueue(&q,50);
    display(q);
    dequeue(&q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);

    return 0;
}