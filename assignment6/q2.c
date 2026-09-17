/*
10/09/2026
A basic Calculator needs to evaluate expression already written in postfix from.
Requirements:
1.Evaluate given postfix expression
Input: 62+3*
*/

#include<stdio.h>
#define maxStack 100
float operation(float n1,float n2,char c){
    if(c=='+')return n1 + n2;
    else if(c=='-')return n1-n2;
    else if(c=='*')return n1*n2;
    return n1/n2;
}

float evaluatePostfix(char exp[]){
    int i=0,top=-1;
    float stack[maxStack];
    while(exp[i]!='\0'){
        if(exp[i]>=48 && exp[i] <=57){
            stack[++top]=(float)(exp[i]-'0');
        }
        else{
            stack[top-1]=operation(stack[top],stack[top-1],exp[i]);
            top--;
        }
        i++;
    }
    return stack[top];
}

int main(){
    char exp[30];
    printf("Enter the postfix expression: ");
    scanf("%s",exp);
    float result=evaluatePostfix(exp);
    printf("Result: %.2f\n",result);
    return 0;
}