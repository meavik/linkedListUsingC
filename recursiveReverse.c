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

void recursiveReverse(struct Node*p,struct Node *q){
    if(p){
        recursiveReverse(p->link,p);
        p->link = q;
    }
    else{
        head = q;
    }

}

int main(){

    CreateList();
    display(head);
    struct Node *q = 0;
    recursiveReverse(head,q);
    display(head);

    return 0;
}
