#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50
char stack[MAX];
int i,top=-1;
int op1,op2,res,s[20];
char postfix[90],symb;
void push(int item)
{
top=top+1;
s[top]=item;
}
int pop()
{
int item;
item=s[top];
top=top-1;
return item;
}
void main()
{
printf("enter a postfix expression\n");
scanf("%s",&postfix[i]);
for(i=0;postfix[i]!='\0';i++)
{
symb=postfix[i];
if(isdigit(symb))
{
push(symb-'0');
}
else
{
op1=pop();
op2=pop();
{
switch(symb)
{
case '+':push(op1+op2);
	break;
case '-':if(op1>op2)
	{
	push(op1-op2);
	}
	else
	{
	push(op2-op1);
	}
	break;
case '*':push(op1*op2);
	break;
case '/':push(op1/op2);
	break;
default:printf("enter a valid expression");
	break;
}
}
}
}
res=pop();
printf("result=%d\n",res);
}
