#include<stdio.h>

#include<string.h>

#include<stdlib.h>
#define MAX 4
int i, front=0, rear=0;
char item, q[MAX];
void insert(char item)
{
 if(front==(rear+1)%MAX)
 {
 printf("Circular Queue Overflow\n");
 return;
 }
 rear=(rear+1)%MAX;
 fflush(stdin);
 scanf("%c", &item);
 q[rear]=item;
}
void delete()
{
 if(front==rear)
 {
 printf("\n Circular Queue Underflow\n");
return;
 }
 front=(front+1)%MAX;
 printf("\n Deleted Charcter is: %c", q[front]);
}
void display()
{
int i;
if(front==rear)
{
printf("\n Circular Queue is Empty\n");
return;
}
printf("\n content of queue is:\n");
for(i=(front+1)%MAX; i!=rear; i=(i+1)%MAX)
 printf("%c\t", q[i]);
 printf("%c\t",q[i]);
}
void main()
{
int choice;
while(1)
{
 printf("\n Circular Queue Operations");
 printf("\n Enter the choice");
 printf("\n 1.insert\n 2.delete\n 3.Display\n 4.exit\n ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: printf("Enter the character to be inserted: ");
scanf("%c”, &item);
insert(item);
break;
case 2: delete();
 break;
case 3: display();
 break;
case 4: exit(0);
 break;
default: printf ("\n invalid choice\n");
}
}

  
}