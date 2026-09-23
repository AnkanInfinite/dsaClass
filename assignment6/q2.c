/*
10/09/2026
A basic Calculator needs to evaluate expression already written in postfix from.
Requirements:
1.Evaluate given postfix expression
Input: 62+3*
*/

#include<stdio.h>
#define maxStackSize 100
typedef struct {
    float ar[maxStackSize];
    int top;
}stack;


float operation(float n1,float n2,char c){
    if(c=='+')return n1 + n2;
    else if(c=='-')return n1-n2;
    else if(c=='*')return n1*n2;
    return n1/n2;
}


void push(stack* st,float item){
    if(st->top >= maxStackSize-1){
        printf(" Stack Overflow ");
        printf("\n");
        return;
    }
    st->ar[++(st->top)]=item;
}

float pop(stack* st){
    if(st->top<0){
        printf("Stack Underflow");
        printf("\n");
        return -1;
    }
    return st->ar[(st->top)--];
}
float evaluatePostfix(char exp[]){
    int i=0;
    stack st;
    st.top=-1;
    while(exp[i]!='\0'){
        if(exp[i]>=48 && exp[i] <=57){
            push(&st,(float)(exp[i]-'0'));
        }
        else{
            float secondOperand=pop(&st);
            float firstOperand=pop(&st);
            float result=operation(firstOperand,secondOperand,exp[i]);
            push(&st,result);
        }
        i++;
    }
    return pop(&st);
}

int main(){
    char exp[30];
    printf("Enter the postfix expression: ");
    scanf("%s",exp);
    float result=evaluatePostfix(exp);
    printf("Result: %.2f\n",result);
    return 0;
}