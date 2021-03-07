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
    printf("\n");
}

void reArrangeList(struct node*first){
    struct node *p,*q;
    int temp;
    if(!first||!first->next){
        return;
    }
    p = first;
    q = first->next;
    while(q){
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        p = q->next;
        q = p?p->next:0;
    }
}

int main(){

    CreateList(head);
    printf("\n");
    displayList(head);
    reArrangeList(head);
    printf("After rearranging: ");
    displayList(head);

    return 0;
}
