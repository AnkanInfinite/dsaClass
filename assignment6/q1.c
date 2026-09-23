/*
03/09/2026
Infix to postfix Conversion using stack

A simple Calculator Recives an infix expression It must:
-> Convert infix expression to postfix
Sample input: 3+4*5
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define maxStackSize 100
typedef struct {
    char ar[maxStackSize];
    int top;
}stack;
void push(stack* st,char item){
    if(st->top >= maxStackSize-1){
        printf(" Stack Overflow ");
        printf("\n");
        return;
    }
    st->ar[++(st->top)]=item;
}

int pop(stack* st){
    if(st->top<0){
        printf("Stack Underflow");
        printf("\n");
        return -1;
    }
    return st->ar[(st->top)--];
}
int precedence(char c){
    if(c=='+' || c=='-')return 1;
    else if(c=='*' || c=='/')return 2;
    else if(c=='^')return 3;
    return 0;
}

void infixToPostfix(char postfix[],char s[] , stack *st){
    int j=0;
    for(int i=0;s[i] !='\0';i++){
        if(isalnum(s[i])){
            postfix[j]=s[i];
            j++;
        }
        else{
            if(st->top==-1){
                push(st,s[i]);
            }
            else if(precedence(st->ar[st->top]) < precedence(s[i])){
                push(st,s[i]);
            }
            else{
                while((st->top)>-1 &&  (precedence(st->ar[st->top]) >= precedence(s[i]))){
                    postfix[j]=pop(st);
                    j++;
                }
                push(st,s[i]);
            }
        }
    }
    while((st->top) >-1 ){
        postfix[j]=pop(st);
        j++;
    }
    postfix[j]='\0';
}

int main(){
    char s[30];
    char postfix[30];
    stack st;
    st.top=-1;
    printf("Enter Infix Expression :");
    scanf("%s",s);
    infixToPostfix(postfix,s,&st);
    printf("Postfix Expression : %s\n",postfix);
    return 0;
}