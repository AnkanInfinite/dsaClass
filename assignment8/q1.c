/*
Q.8.1.
Reversing a Delivery Route  using a Singly linked list.

A delivery Company Store it's delivery stops in a singly linked list.
Each Node Contains a Stop number and a pointer to the next stop .
After completing the deliveries , the driver needs to stops dilsplayed in
reverse order for the return journey.

Task: WACP to create the route , display it , reverse the singly linked , and display reversed route .

Example:
    Original Route : 101 -> 102 -> 103 -> 104 -> NULL
    Reversed Route : 104 -> 103 -> 102 -> 101 -> NULL
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct st{
    int stop;
    struct st* next;
}node;

void create(node** head ,int data){
    node* ptr=NULL;
    node* temp=NULL;
    ptr=(node *)malloc(sizeof(node));
    ptr->stop=data;
    ptr->next=NULL;
    if(*head==NULL){
        *head=ptr;
    }
    else{
        temp=*head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
}

void traverse(node* head){
    node* temp=head;
    while(temp != NULL){
        printf("%d ",temp->stop);
        temp=temp->next;
    }
}

void reverse(node** head){
    node *pre=NULL;
    node *cur=*head;
    while(cur != NULL){
        node *post=cur->next;
        cur->next=pre;
        pre=cur;
        cur=post;
    }
    *head=pre;
}

int main(){
    node* head=NULL;
    int choice,data;
    do{
        printf("\n1. Create Route\n2. Display Route\n3. Reverse Route\n4. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter stop number to add: ");
                scanf("%d",&data);
                create(&head,data);
                break;
            case 2:
                printf("Current Route: ");
                traverse(head);
                break;
            case 3:
                reverse(&head);
                printf("Route Reversed.\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(choice != 4);
    return 0;
}