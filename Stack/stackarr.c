#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void display(struct stack st)
{
    if(st.top==-1)
        printf("Empty Stack\n");
    else
    {
        for(int i = st.top;i>=0;i--)
            printf("%d \t",st.arr[i]);
    }
    printf("\n");
}

void push(struct stack *st,int val)
{
    if (st->top==st->size-1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->arr[st->top] = val;
    }
}

int pop(struct stack *st)
{
    int x = -1;
    if(st->top==-1)
        printf("Stack Underflow\n");
    else
    {
        x = st->arr[st->top];
        st->top--;
    }
    return x;
}

void stacktop(struct stack st)
{
    if(st.top==-1)
        printf("Stack Underflow\n");
    else
        printf("The last element was %d\n",st.arr[st.top]);
}

void isempty(struct stack st)
{
    if(st.top==-1)
        printf("Stack is Empty\n");
    else
        printf("Stack is not Empty\n");
}

void isfull(struct stack st)
{
    if (st.top==st.size-1)
        printf("Stack is Full\n");
    else
        printf("Stack is Not full\n");
}

void peek(struct stack st,int pos)
{
    int index = st.top-pos+1;
    if(index<0)
        printf("Not a valid position\n");
    else
        printf("The element at %d position is %d\n",pos,st.arr[index]);
}

int main()
{
    struct stack a;
    a.size = 5;
    a.top = -1;
    a.arr = (int *)malloc(a.size*sizeof(int));

    push(&a,1);
    push(&a,2);
    push(&a,3);
    push(&a,4);
    push(&a,5);

    display(a);
    
    int x  = pop(&a);
    printf("The Poped element was %d\n",x);
    
    display(a);

    stacktop(a);

    isempty(a);
    isfull(a);
    
    display(a);
    peek(a,4);

    return 0;
}