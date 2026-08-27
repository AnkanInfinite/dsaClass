/*
27/08/2026
1. Case Study: Student Registration Management
A university department wants to develop a simple system to maintain 
a list of students who have registered for a technical workshop.
The number of students registering for the workshop is not fixed. 
Therefore, using a static array may result in either:
•	Wastage of memory when fewer students register, or
•	Insufficient space when more students register.
To solve this problem, the software developer decides to use a Singly Linked List.
Each student record will be represented using a node containing:
•	Student ID
•	Pointer to the next student
The first node of the linked list is accessed through a pointer called HEAD.
The department wants the system to perform the following basic operations:
1.	Create a singly linked list.
2.	Add student records dynamically.
3.	Traverse the linked list.
4.	Display all student records in the order in which they were added.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int studentID;
    struct Node* next;
}link;

void addRecord(link **HEAD,int data){
    link *ptr=NULL;
    link *temp=NULL;
    ptr=(link *)malloc(sizeof(link));
    ptr->studentID=data;
    ptr->next=NULL;
    if(*HEAD == NULL){
        *HEAD=ptr;
    }
    else{
        temp=*HEAD;
        while(temp->next !=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
}

void displayRecords(link*  HEAD){
    link* temp=HEAD;
    while(temp != NULL){
        printf("%d  ",temp->studentID);
        temp=temp->next;
    }
}

int main(){
    link *HEAD=NULL;
    int choice;
    while(1){
        printf("\n Enter your Choice :");
        printf("\n 1:Add Student Record \n 2:Display Student Records \n 3:Exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                int data;
                printf("Enter Student ID to be added:");
                scanf("%d",&data);
                addRecord(&HEAD,data);
                break;
            case 2:
                printf("Displaying all student records : \n");
                displayRecords(HEAD);
                break;
            case 3:
                printf("Exiting Programme ...");
                printf("\n");
                exit(0);
            default:
                printf("Invalid Choice !\n");
        }
    }
    return 0;
}
