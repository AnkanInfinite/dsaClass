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
typedef struct {
    char ar[30];
    int top;
}stack;

int precedence(char c){
    if(c=='+')return 1;
    else if(c=='-')return 1;
    else if(c=='*' || c=='/')return 2;
    return 2;
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
                st->ar[++(st->top)]=s[i];
            }
            else if(precedence(st->ar[st->top]) < precedence(s[i])){
                st->ar[(++(st->top))]=s[i];
            }
            else{
                while((st->top)>-1 &&  (precedence(st->ar[st->top]) >= precedence(s[i]))){
                    postfix[j]=st->ar[st->top];
                    st->top--;
                    j++;
                }
                st->ar[++(st->top)]=s[i];
            }
        }
    }
    while((st->top) >-1 ){
        postfix[j]=st->ar[st->top];
        st->top--;
        j++;
    }
    postfix[++j]='\0';
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