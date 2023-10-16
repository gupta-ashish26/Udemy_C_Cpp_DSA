#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

void push(int x)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    if(t==NULL)
        printf("Stack Overflow\n");
    else
        t->data = x;
        t->next = top;
        top = t;
}

int pop()
{
    int x = -1;

    if(top==NULL)
        printf("Stack Underflow\n");
    else
    {
        struct node *t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct node *p = top;
    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p=p->next;
    }
    printf("\n");
}

void isempty()
{
    if(top==NULL)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

void isfull()
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    if(t==NULL)
        printf("Stack is full\n");
    else
    {
        printf("Stack is not full\n");
        free(t);
    }
}

void peek(int pos)
{
    struct node *p = top;
    for(int i = 1;p!=NULL&&i<pos;i++)
        p=p->next;
    printf("%d\n",p->data);
}

void stacktop()
{
    if(top==NULL)
        printf("Stack is empty\n");
    else
        printf("%d\n",top->data);
}

int main()
{

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();


    pop();
    pop();
    display();

    isempty();
    isfull();

    peek(2);
    stacktop();

    return 0;
}