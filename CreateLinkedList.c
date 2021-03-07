#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node* next;
}*head=0;

void CreateList(struct node*first){
    struct node*temp,*newNode;
    int choice;
    static countNode = 1;
    do{
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter no %d node: ",countNode);
        scanf("%d",&newNode->data);
        newNode->next = 0;
        if(head == 0){
            head = temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
        printf("Want to insert more data?(1/0): ");
        scanf("%d",&choice);
        countNode++;
    }while(choice == 1);
}

void displayList(struct node*p){
    printf("Displaying data: ");
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int main(){

    CreateList(head);
    displayList(head);

    return 0;
}
