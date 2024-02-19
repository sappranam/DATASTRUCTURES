#include<stdio.h>
#include<stdlib.h>
#define MAX 4
void push(item);
void pop();
void display(item);
void pallindrome(item);
void main()
{
int item,choice,s,top,b;

printf("**MENU**\n");
printf("1:Push\n 2:Pop\n 3:Display\n 4:Pallindrome\n");
printf("Enter your choice:\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("Enter the element to be pushed\n");
	scanf("%d",&item);
        push(item);
        break;
case 2: pop();
        break;
case 3: display();
        break;
case 4: printf("enter a number\n");
	pallindrome();
	printf("enter a number\n");
	scanf("%d",&b);
        break;
default: printf("Invalid choice\n");
}
}
void push(item)
{
int s[50],top=-1;
if (top==MAX-1)
{
printf("OVERFLOW\n");
}
else
{
top=top+1;
s[top]=item;
}
}
void pop()
{ 
int s[50],top=-1;
if(top==-1)
{
printf("UNDERFLOW");
}
else
{
item=s[top];
printf("poped item:%d",item);
top=top-1;
}
}
void display(item)
{
int i,s[MAX],top=MAX;
for(i=top;i>=0;i--)
{
printf("%d\n",s[top]);
}
}
void pallindrome(item)
{
int i,s[50],top=MAX,flag;
for(i=0;i<=top/2;i++)
{
if(s[i]!=s[top-1])
{
flag=0;
break;
}
}
if(flag==0)
{
printf("It is not pallindrome\n");
}
else
{
printf("It is a pallindrome\n");
}
}










