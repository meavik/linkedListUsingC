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

void insertNode(int pos)
{
    struct Node*temp,*newNode;
    int i = 1;
    if (pos==0)
    {
        struct Node*newNode;
        newNode =(struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter the data you want to insert: ");
        scanf("%d",&newNode->data);
        newNode->next=head;
        head = newNode;
    }
    else if(pos>countNode||pos<1)
    {
        printf("Invalid position");
    }
    else
    {
        temp = head;
        while(i<pos)
        {
            temp = temp->next;
            i++;
        }
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d",&newNode->data);
        newNode->next = temp->next;
        temp->next = newNode;
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
    printf("Enter the position after which you want to insert data: ");
    int pos;
    scanf("%d",&pos);
    insertNode(pos);
    display(head);

    return 0;
}
