#include<stdio.h>
#include<stdlib.h>

static int countNode;

struct Node
{
    int data;
    struct Node* next;
}*head=0;

void CreateList()
{
    struct Node*temp,*newNode;
    int choice;
    do
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the no %d node: ",++countNode);
        scanf("%d",&newNode->data);
        newNode->next = 0;
        if(head==0)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
        printf("Want to continue adding new nodes?(1 to continue): ");
        scanf("%d",&choice);

    }
    while(choice==1);
}

void insertNode(int val)
{
    struct Node *p,*q,*newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode -> next = 0;
    p = head;
    q = 0;
    if(head == 0)
    {
        head = newNode;
    }
    else
    {
        while(p&&p->data < newNode->data)
        {
            q = p;
            p = p->next;
        }
        if(p == head)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = q->next;
            q->next = newNode;
        }
    }
}

void display(struct Node*p)
{
    printf("\nDisplaying list: ");
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{

    CreateList();
    display(head);
    printf("Enter the node you want to insert: ");
    int val;
    scanf("%d",&val);
    insertNode(val);
    display(head);

    return 0;
}
