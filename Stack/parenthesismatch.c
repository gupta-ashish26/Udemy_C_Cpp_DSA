#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void push(struct stack *st,char val)
{
    if(st->top==st->size-1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->arr[st->top]=val;
    }
}

void pop(struct stack *st)
{
    if (st->top==-1)
        printf("Stack Underflow\n");
    else
        st->top--;
}

int isempty(struct stack st)
{
    if (st.top==-1)
        return 1;
    else
        return 0;
}

int pmatch(char *exp)
{
    struct stack st;
    st.top=-1;
    st.size=strlen(exp);
    st.arr = (char*)malloc(st.size*sizeof(char));

    for(int i = 0;exp[i]!='\0';i++)
    {
        if (exp[i]=='(')
            push(&st,'(');
        else if (exp[i]==')')
        {
            if (isempty(st))
                return 0;
            else
                pop(&st);
        }
    }
    if (isempty(st))
        return 1;
    else 
        return 0;
}

int main()
{
    char *exp = "(a+b)*((c+d)/e)";
    if (pmatch(exp))
        printf("Parenthesis are matching!\n");
    else
        printf("Parenthesis are not matching\n");
    
    return 0;
}