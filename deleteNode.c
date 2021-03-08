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

void deleteNode(int val){
    struct Node *p,*q;
    p = head;
    q = 0;
    if(head==0||val>countNode){
        printf("Can't perform operation at this position.");
    }
    if(val==1){
        head = p->next;
        free(p);
    }
    else{
        int i = 1;
        while(i++<val){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
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
    int val;
    printf("Enter the node you want to delete: ");
    scanf("%d",&val);
    deleteNode(val);
    display(head);

    return 0;
}
