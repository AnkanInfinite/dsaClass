/*
17/09/2026
7.1.
In a shop the Product prices of 5 products are stored in a list.
The price is stored in a float/double .
Each node of list consist of price of one product and address of next.
Perform the following operation on the list in menu driven form.
option 1:Create List
option 2:Traverse list
option 3:Search one price in list taken input from user
option 4:Insert the price of new at the head
option 5:Insert the Price of new item at 3rd position of list.

Sample:
List : 50.5->20.25->13.5->18.5->41.25
at head insert 65.25
at position 3 insert 102.50
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct st{
    double price;
    struct st* next;
}node;

void create(node** head ,double data){
    node* ptr=NULL;
    node* temp=NULL;
    ptr=(node *)malloc(sizeof(node));
    ptr->price=data;
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

void traverse( node *head){
    node *temp=head;
    while(temp->next !=NULL){
        printf("%.2lf ",temp->price);
        temp=temp->next;
    }
    printf("%.2lf ",temp->price);
}

int searchList( node* head ,double item){
    if(head==NULL)return 0;
    node *temp=head;
    while(temp !=NULL){
        if(temp->price==item)return 1;
        else{
            temp=temp->next;
        }
    }
    return 0;
}

void insertHead(node** head,double item){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->next=*head;
    ptr->price=item;
    *head=ptr;
}

void insertPos( node* head,int pos,double item){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->next=NULL;
    ptr->price=item;
    node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
}

int main(){
    node* head=NULL;
    int choice;
    double item;
    int pos=3;
    do{
        printf("\n1.Create List\n2.Traverse List\n3.Search Price\n4.Insert at Head\n5.Insert at Position 3\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter price of product :");
                scanf("%lf",&item);
                create(&head,item);
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                printf("Enter price to search: ");
                scanf("%lf",&item);
                if(searchList(head,item)){
                    printf("Price %.2lf found in the list.\n",item);
                }else{
                    printf("Price %.2lf not found in the list.\n",item);
                }
                break;
            case 4:
                printf("Enter price to insert at head: ");
                scanf("%lf",&item);
                insertHead(&head,item);
                break;
            case 5:
                printf("Enter price to insert at position 3: ");
                scanf("%lf",&item);
                insertPos(head,pos,item);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(1);
    return 0;
}