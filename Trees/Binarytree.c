#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
#include"stack.h"

struct node* root=NULL;

void BTcreate()
{
    struct node *p,*t;
    int x;
    struct queue q;
    create(&q,100);

    printf("Enter root value: ");
    scanf("%d",&x);
    root = (struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild = t;
            enqueue(&q,t);
        }

        printf("Enter right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }

}

void preorder(struct node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(struct node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void ipreorder(struct node *p)
{
    struct stack st;
    stackcreate(&st,100);

    while(p || !isemptystack(st))
    {
        if (p)
        {
            printf("%d ",p->data);
            push(&st,p);
            p = p->lchild;
        }
        else
        {
            p = pop(&st);
            p = p->rchild;
        }
    }
}

void iinorder(struct node *p)
{
    struct stack st;
    stackcreate(&st,100);

    while(p || !isemptystack(st))
    {
        if (p)
        {
            push(&st,p);
            p = p->lchild;
        }
        else
        {
            p = pop(&st);
            printf("%d ",p->data);
            p = p->rchild;
        }
    }
}

/*
Below is the code for iterative postorder.
As this code requires the stack type to be integer array and we are working currently
on struct node * type of array so this code won't work in this given file.

To run the code the stack array type needs to be modified which here will make all the code 
to stop. Can be done in a separate file as an exercise.
*/
// void ipostorder(struct node *p)
// {
//     struct stack st;
//     long int temp;
//     stackcreate(&st,100);
//     while(p || !isemptystack(st))
//     {
//         if (p)
//         {
//             push(&st,p);
//             p = p->lchild;
//         }
//         else
//         {
//             temp = pop(&st);
//             if (temp>0)
//             {
//                 push(&st,-temp);
//                 p = ((struct node *)temp)->rchild;
//             }
//             else
//             {
//                 printf("%d ",((struct node*)temp)->data);
//                 p = NULL;
//             }
//         }
//     }
// }

void levelorder(struct node *p)
{
    struct queue q;
    create(&q,100);
    printf("%d ",p->data);
    enqueue(&q,p);
    while(!isEmpty(q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            printf("%d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if (p->rchild)
        {
            printf("%d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}

int main()
{
    BTcreate();

    printf("preorder:\t");
    preorder(root);
    printf("\n");

    printf("inorder:\t");
    inorder(root);
    printf("\n");

    printf("postorder:\t");
    postorder(root);
    printf("\n");

    printf("preorder:\t");
    ipreorder(root);
    printf("\n");

    printf("inorder:\t");
    iinorder(root);
    printf("\n");

    // printf("postorder:\t");
    // ipostorder(root);
    // printf("\n");

    printf("levelorder:\t");
    levelorder(root);
    printf("\n");

    return 0;
}