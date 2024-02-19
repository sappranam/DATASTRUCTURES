#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
char stack[MAX];
int top=-1;
void push(char item)
{
if(top>=MAX-1)
{
printf("STCK OVERFLOW\n");
return;
}
stack[++top]=item;
}
char pop()
{
if(top<0)
{
printf("STACK UNDERFLOW\n");
return -1;
}
return stack[top--];
}
int precedence(char symbol)
{
switch(symbol)
{
case '+':
case '-':
return 2;
case '*':
case '/':
return 3;
case '^':
return 4;
case '(':
case ')':
return 1;
}
return 0;
}
void infixToPostfix(char infix[],char postfix[])
{
int i,j;
char symbol;
stack[++top]='#';
j=0;
for(i=0;i<strlen(infix);i++)
{
symbol=infix[i];
if(isalnum(symbol))
postfix[j++]=symbol;
else
if(symbol=='(')
push(symbol);
else
if(symbol==')')
{
while(stack[top]!='(')
postfix[j++]=pop();
pop();
}
else
{
while(precedence(stack[top])>=precedence(symbol))
postfix[j++]=pop();
push(symbol);
}
}
while(stack[top]!='#')
postfix[j++]=pop();
postfix[j]='\0';
}
int main()
{
char infix[MAX],postfix[MAX];
printf("enter the infix expression:\n");
gets(infix);
infixToPostfix(infix,postfix);
printf("postfix expression:%s\n",postfix);
return 0;
}
