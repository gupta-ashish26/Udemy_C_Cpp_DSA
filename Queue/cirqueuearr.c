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
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full!\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
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
        q->front=(q->front+1)%q->size;
        x = q->arr[q->front];
    }
    return x;
}

void display(struct queue q)
{
    int i = q.front+1;
    do
    {
        printf("%d\t",q.arr[i]);
        i = (i+1)%q.size;
    } while (i!=(q.rear+1)%q.size);
    
    printf("\n");
}

int main()
{
    struct queue q;
    q.size = 5;
    q.front=q.rear=0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q,10);
    enqueue(&q,20);
    display(q);
    enqueue(&q,30);
    enqueue(&q,40);
    display(q);
    enqueue(&q,50);
    display(q);
    dequeue(&q);
    enqueue(&q,50);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);

    return 0;
}