/*
Q.8.2.
Train coaches using Doubly Linked List:   
A railway system stores the coaches of a train in a doubly linked list. 
Each coach has a coach number and link to both previous and next coaches. 
This allows the railway staff to inspect the coaches from the engine towards 
the last coach and from the last coach back towards the engine.   

Task: — Write a C Program (WACP) to:   
i) Create a doubly linked list of coach numbers.   
ii) Traverse and display the coaches in forward order.   
iii) Traverse and display the coaches in backward order.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct st{
    struct st *prev;
    int data;
    struct st *next;
}node;

void createDoublyLlist(node** head , node** tail ,int couchNumber){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->prev=NULL;
    ptr->next=NULL;
    ptr->data=couchNumber;
    if(*head==NULL){
        *head=ptr;
        *tail=ptr;
        return;
    }
    ptr->prev=*tail;
    (*tail)->next=ptr;
    *tail=ptr;
}

void traverseForward(node *head){
    node* temp=head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void traverseBackward(node *tail){
    node *temp=tail;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}

int main(){
    node *head=NULL;
    node *tail=NULL;
    int choice,couchNumber;
    while(1){
        printf("\n1. Create Doubly Linked List\n2. Traverse Forward\n3. Traverse Backward\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter couch number: ");
                scanf("%d",&couchNumber);
                createDoublyLlist(&head,&tail,couchNumber);
                break;
            case 2:
                traverseForward(head);
                break;
            case 3:
                traverseBackward(tail);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}