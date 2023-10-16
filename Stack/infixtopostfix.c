#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

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

char pop(struct stack *st)
{
    char x;
    if(st->top==-1)
        printf("Stack Underflow\n");
    else
    {
        x = st->arr[st->top];
        st->top--;
    }
    return x;
}

char stacktop(struct stack st)
{
    /*
    if(st.top==-1)
        return;
    else
    */
        return st.arr[st.top];
}

int isempty(struct stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

int isoperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else 
        return 1;
}

int pre(char x)
{
    if(x=='+'||x=='-')
        return 1;
    else if (x=='*'||x=='/')
        return 2;
    return 0;
}

char* convertpostfix(char *infix)
{
    struct stack st;
    st.size=strlen(infix);
    st.top=-1;
    st.arr = (char*)malloc(st.size+1);

    char *postfix = (char*)malloc(strlen(infix)+1);
    int i=0,j=0;

    while(infix[i]!='\0')
    {
        if (isoperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(pre(infix[i])>pre(stacktop(st)))
                push(&st,infix[i++]);
            else
                postfix[j++]=pop(&st);
        }
    }
    while(!isempty(st))
    {
        postfix[j++]=pop(&st);
    }
    postfix[j]='\0';

    return postfix;
}


int main()
{
    char *infix = "a+b*c-d/e";
    char *postfix = convertpostfix(infix);

    printf("%s",postfix);

    return 0;
}