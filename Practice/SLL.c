#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int arr[],int n)
{
    struct node *head = NULL, *tail = NULL, *temp = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = arr[0];
    head->next = NULL;
    tail = head;

    for(int i = 1;i<n;i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }

    return head;
}

void display(struct node *head)
{
    struct node *p = head;
    while(p != NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

int count(struct node *head)
{
    struct node *p = head;
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int sumnodes(struct node *head)
{
    struct node *p = head;
    int sum = 0;
    while(p != NULL)
    {
        sum+=p->data;
        p = p->next;
    }
    return sum;
}

void search(struct node *head,int key)
{
    struct node *p = head;
    while (p)
    {
        if(p->data==key)
        {
            printf("Asked Key which is %d is found!\n",key);
            return;
        }
        else
            p=p->next;
    }
    printf("No such key found\n");
}

void insert(struct node **head,int key,int pos)
{
    struct node *p = *head;
    if(pos<0||pos>count(p))
    {
        printf("Invalid position!\n");
        return;
    }
    p = *head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;

    if (pos==0)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        for(int i = 0;i<pos-1;i++)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
    
}

void delete(struct node **head,int pos)
{
    struct node *p = *head;

    if(pos<0||pos>count(p))
    {
        printf("Invalid position!\n");
        return;
    }

    if(pos==1)
    {
        *head = p->next;
        free(p);
    }
    else
    {
        struct node *q = p;
        p = p->next;
        for(int i=2;i<pos;i++)
        {
            p=p->next;
            q=q->next;
        }
        q->next=p->next;
        free(p);
    }
}

void reverse(struct node **head)
{
    struct node *p = *head;
    struct node *q = NULL;
    struct node *r = NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    *head = q;
}

struct node *concat(struct node *head1,struct node *head2)
{
    struct node *res=head1;
    while(head1->next!=NULL)
        head1=head1->next;
    head1->next = head2;

    return res;
}

void sortasc(struct node *head)
{
    struct node *current = head;

    while (current!=NULL)
    {
        struct node *min = current;
        struct node *temp = current->next;

        while(temp!=NULL)
        {
            if(temp->data<min->data)
                min = temp;
            temp = temp->next;
        }
        int tempdata = current->data;
        current->data = min->data;
        min->data = tempdata;

        current = current->next;
    }
}

void sortdsc(struct node *head)
{
    struct node *curr = head;
    while(curr!=NULL)
    {
        struct node *max = curr;
        struct node *temp = curr->next;

        while(temp!=NULL)
        {
            if(max->data<temp->data)
                max = temp;
            temp = temp->next;
        }

        int tempdata = curr->data;
        curr->data = max->data;
        max->data = tempdata;

        curr = curr->next;
    }
}

int main()
{
    struct node *first = NULL;
    int arr[] = {5,4,3,2,1};

    first = create(arr,(sizeof(arr)/sizeof(*arr)));

    display(first);

    int nodes = count(first);
    printf("Number of nodes = %d \n",nodes);

    int nodes_sum = sumnodes(first);
    printf("Sum of nodes = %d \n",nodes_sum);

    search(first,3);

    insert(&first,10,3);
    display(first);

    delete(&first,4);
    display(first);

    reverse(&first);
    display(first);

    /*
    struct node *second = NULL;
    int arr1[] = {6,7,8,9,10};

    second = create(arr1,(sizeof(arr1)/sizeof(*arr1)));

    struct node *concatinated = concat(first,second);
    display(concatinated);
    */

    sortasc(first);
    display(first);

    sortdsc(first);
    display(first);

    return 0;
}

