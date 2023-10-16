#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createcll(int arr[],int n)
{
    struct node *head;
    struct node *tail;

    head = (struct node *)malloc(sizeof(struct node));
    head->data=arr[0];
    head->next=head;
    tail = head;

    for(int i = 1;i<n;i++)
    {
        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }

    return head;
}

void displaycll(struct node *head)
{
    struct node *p = head;
    do
    {
        printf("%d\t",p->data);
        p = p->next;
    } while (p!=head);
    printf("\n");
}

void insertcll(struct node **head,int key, int pos)
{

    struct node *p = *head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=key;
    if(pos==0)
    {
        if(p==NULL)
        {
            p = temp;
            p->next=*head;
            *head=p;
        }
        else
        {
            temp->next = *head;
            while(p->next!=*head)
                p = p->next;
            p->next = temp;
            *head = temp;
            return;
        }
    }
    for(int i = 1;i<pos;i++)
        p = p->next;
    temp->next = p->next;
    p->next = temp;
}

void deletecll(struct node **head,int pos)
{
    struct node *p = *head;
    struct node *q = NULL;

    if(pos==1)
    {
        if(p == NULL)
        {
            printf("List is already empty!");
            return;
        }    
        else
        {
            q=p;
            while(p->next!=*head)
                p=p->next;
            p->next = q->next;
            *head = q->next;
            free(q);
            return;
        }
    }

    for(int i = 1;i<pos;i++)
    {
        q=p;
        p=p->next;
    }
    q->next = p->next;
    free(p);
}

int main()
{
    int arr[]={1,2,3,4,5};
    struct node *first = NULL;
    first=createcll(arr,sizeof(arr)/sizeof(*arr));
    displaycll(first);
    //insertcll(&first,1,0);
    //displaycll(first);
    deletecll(&first,1);
    displaycll(first);

    return 0;
}