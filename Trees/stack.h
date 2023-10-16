#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    struct node **S;
};

void stackcreate(struct stack *st,int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct node **)malloc(st->size*sizeof(struct node *));
}

void push(struct stack *st,struct node *val)
{
    if (st->top==st->size-1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = val;
    }
}

struct node* pop(struct stack *st)
{
    struct node *x=NULL;
    if(st->top==-1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int isemptystack(struct stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}

int isfullstack(struct stack st)
{
    return (st.top==st.size-1);
}