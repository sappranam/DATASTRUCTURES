#include<stdio.h>

#include<stdlib.h>

struct node
{
char usn[20],name[10],branch[5];
unsigned long long int phno;
int sem;
struct node *link;
};
typedef struct node *NODE;
NODE temp,FIRST=NULL;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
x->link=NULL;
return x;
}
void read()
{
temp=getnode();
printf("Enter USN:");
scanf("%s",temp->usn);
printf("Enter NAME:");
scanf("%s",temp->name);
printf("Enter Branch:");
scanf("%s",temp->branch);
printf("Enter phone number:");
scanf("%llu",&temp->phno);
printf("Enter Semester:");
scanf("%d",&temp->sem);
}
void create_SSL()
{
int n,i;
printf("Enter the number of students:");
scanf("%d",&n);
for(i=1;i<=n;i++) 
{
printf("\n enter the details of %d student\n", i);
read(); 
if(FIRST==NULL)
FIRST=temp; 
else
{
temp->link=FIRST;
FIRST=temp;
}
}
}
void display_count()
{
int count=1;
temp=FIRST;
printf("student details:\n");
if(FIRST==NULL)
printf("student details is NULL and count is 0\n");
else
{
printf("\nUSN\tNAME\tBRANCH\tphone\tsemester\n");
while(temp->link!=NULL)
{
count++;
printf("%s\t%s\t%s\t%llu\t%d\n",temp->usn,temp->name,temp->branch,temp->phno,temp->sem);
temp=temp->link;
}
printf("%s\t%s\t%s\t%llu\t%d",temp->usn,temp->name,temp->branch,temp->phno,temp->sem);
printf("\nstudent count is%d\n",count);
}
return;
}
void insert_front()
{
printf("Enter the details of student \n");
read();
if(FIRST==NULL)
FIRST=temp;
else
{
temp->link=FIRST;
FIRST=temp;
}
}
NODE insert_end()
{
NODE last=FIRST;
printf("Enter the details of student\n");
read();
if(FIRST==NULL)
FIRST=temp;
else
{
while(last->link!=NULL)
last=last->link;
last->link=temp;
}
return FIRST;
}
void delete_front()
{
temp=FIRST;
if(FIRST==NULL)
printf("List is empty\n");
else
{
printf("deleted element is %s\n",temp->usn);
FIRST=FIRST->link; 
free(temp);
}
return;
}
void delete_end()
{
NODE last=NULL;
temp=FIRST;
if(FIRST==NULL)
printf("list is empty\n");
else if(FIRST->link==NULL)
{
printf("deleted element is %s\n",temp->usn);
free(FIRST);
FIRST=NULL;
}
else
{
while(temp->link!=NULL)
{
last=temp;
temp=temp->link;
}
last->link=NULL;
printf("deleted elemnt is %s\n", temp->usn);
free(temp);
}
return;
}
void main()
{
int choice;
while(1)
{
printf("\n 1.Create SSL\n 2.Display SSL\n 3.Insert front\n 4.insert end\n 5.delete front\n 6.delete end\n 7.Exit\n");
printf("enter your choice\n");
scanf("%d", &choice);
switch(choice)
{
case 1: create_SSL();
 break;
case 2:display_count();
 break;
case 3:insert_front();
 break;
case 4:insert_end();
 break;
case 5:delete_front();
 break;
case 6:delete_end();
 break;
case 7:return;
default: printf("\n invalid choice");
}
}
}

