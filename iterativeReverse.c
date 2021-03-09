#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*link;
}*head=0;

void CreateList(){

    struct Node *temp,*newNode;
    int choice;
    do{
        newNode =(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d",&newNode->data);
        newNode->link = 0;
        if(head==0){
            head = temp = newNode;
        }
        else{
            temp->link = newNode;
            temp = newNode;
        }
        printf("Continue inserting data?(Enter 1 to continue): ");
        scanf("%d",&choice);
    }while(choice == 1);
}

void display(struct Node*p){
    printf("\nDisplaying data: ");
    while(p){
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");
}

void reverseList(struct Node*p){
    struct Node*q,*r;
    q = r = 0;
    while(p){
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    head = q;
}

int main(){

    CreateList();
    display(head);
    struct Node *q = 0;
    reverseList(head);
    display(h
            ead);

    return 0;
}
