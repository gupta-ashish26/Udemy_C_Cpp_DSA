#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

struct stack
{
    int size;
    int top;
    int *arr;
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

int pop(struct stack *st)
{
    int x;
    if(st->top==-1)
        printf("Stack Underflow\n");
    else
    {
        x = st->arr[st->top];
        st->top--;
    }
    return x;
}

int isoperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else 
        return 1;
}

int eval(char *postfix)
{
    struct stack st;
    st.size=strlen(postfix);
    st.top=-1;
    st.arr = (int*)malloc(st.size*sizeof(int));

    int i,x1,x2,r;
    for(i=0;postfix[i]!='\0';i++)
    {
        if (isoperand(postfix[i]))
            push(&st,postfix[i]-'0');
        else
        {
            x2=pop(&st);
            x1=pop(&st);

            switch (postfix[i])
            {
                case '+':
                    r = x1+x2;
                    push(&st,r);
                    break;

                case '-':
                    r = x1-x2;
                    push(&st,r);
                    break;

                case '*':
                    r = x1*x2;
                    push(&st,r);
                    break;

                case '/':
                    r = x1/x2;
                    push(&st,r);
                    break;
            }
        }
    }
    return pop(&st);
}

int main()
{
    char* postfix="35*62/+4-";
    printf("%d",eval(postfix));

    return 0;
}