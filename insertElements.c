#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*head=NULL;

static int nodeCount;

void CreateNode(){
    struct Node*temp,*newNode;
    int choice;
    do{
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter no %d node: ",++nodeCount);
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        if(head==NULL){
            head = temp = newNode;
        }
        else{
            temp->next  = newNode;
            temp = newNode;
        }
        printf("Want to continue adding nodes?(1 to continue): ");
        scanf("%d",&choice);
    }while(choice==1);

}

void insertBeginning(){
    struct Node*newNode;
    newNode =(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the data you want to insert: ");
    scanf("%d",&newNode->data);
    newNode->next=head;
    head = newNode;
}

void insertAtEnd(){
    struct Node*newNode,*temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data to insert at end of list: ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}

void showNode(struct Node*p){
    printf("\nDisplaying nodes: ");
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){

    CreateNode();
    showNode(head);
    insertBeginning();
    printf("After inserting at the beginning...");
    showNode(head);
    insertAtEnd();
    printf("After inserting at the end...");
    showNode(head);
    
    return 0;
}
