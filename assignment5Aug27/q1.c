/*
27/08/2026
Q1.write a c programme to implement a single link list

*/
#include<stdio.h>
#include<stdlib.h>
typedef struct st{
    int n;
    struct st* next;
}link;

void create(link** head ,int data){
    link* ptr=NULL;
    link* temp=NULL;
    ptr=(link *)malloc(sizeof(link));
    ptr->n=data;
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

void traverse(link *head){
    link *temp=head;
    while(temp->next !=NULL){
        printf("%d ",temp->n);
        temp=temp->next;
    }
    printf("%d ",temp->n);
}

int main(){
    link *head=NULL;
    int choice;
    while(1){
        printf("\n Enter your Choice :");
        printf("\n 1:create node \n 2:Traverse list \n 3:exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                int data;
                printf("Enter Number to be kept in list:");
                scanf("%d",&data);
                create(&head,data);
                break;
            case 2:
                printf("Printing the created link List : \n");
                traverse(head);
                break;
            case 3:
                printf("Exiting Programme ...");
                printf("\n");
                exit(0);
            default:
                printf("Invalid Choice !");
        }
    }
    printf("\n");
    return 0;
}