/*
Consider a Book Rack , Where the Books are palced in a stack . Each book has acc_no (1,2,3,...).
If you are asked to place book in stack using acc_no and take the book from stack using acc_no , 
how you perform these two operations on stack of books .The sequence of operation is given :
push(1),push(2),push(3),pop(3),push(4),push(5),pop(5)
Display the final position of the stack
*/
#include<stdio.h>
#include<stdlib.h>
void push(int st[],int max,int* top,int item){
    if(*top==max-1){
        printf("Stack Overflow !");
        return;
    }
    (*top)++;
    st[*top]=item;
}

int pop(int st[],int* top){
    if(*top==-1){
        printf("Underflow !");
        return -1;
    }
    int x=st[*top];
    (*top)--;
    return x;
}

int main(){
    int acc_no,choice;
    int stack[10];
    int top=-1;
    while(1){
        printf("Enter Your choice :\n 1:Push \n 2:pop \n 3:exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
                printf("Enter acc_no to be pushed :");
                scanf("%d",&acc_no);
                push(stack,10,&top,acc_no);
                break;
            case 2 :
                int x=pop(stack,&top);
                printf("Popped %d \n",x);
                break;
            case 3 :
                printf("\nFinal Stack :\n");
                for(int i=0;i<=top;i++){
                    printf("%d ",stack[i]);
                }
                printf("\n");  
                exit(0);
        }
    }
    return 0;
}