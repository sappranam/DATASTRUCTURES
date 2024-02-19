#include<stdio.h>
#include<stdlib.h>
struct node
{
char ssn[12],name[20],dept[25],desig[20];
unsigned long long int phno;
float sal;
struct node *prev;
struct node *next;
};
typedef struct node *NODE;
NODE temp, FIRST=NULL, END=NULL;
NODE getnode()
{
NODE x;
x=(NODE) malloc (sizeof(struct node));
x->prev=NULL;
x->next=NULL;
return x;
}
void read()
{
temp=getnode();
printf("Enter SSN:");
scanf("%s",temp->ssn);
printf("Enter Name:");
scanf("%s",temp->name);
printf("Enter Dept:");
scanf("%s",temp->dept);
printf("Enter Designation:");
scanf("%s",temp->desig);
printf("Enter Phno:");
scanf("%llu",&temp->phno);
printf("Enter Salary:");
scanf("%f",&temp->sal);
return;
}
void create_DLL()
{
int n,i=1;
printf("Enter the number of Employees \n");
scanf("%d",&n);
while(i<=n)
{
printf("Enter the details of the %d employee\n", i++);
read();
if(FIRST==NULL)
{
FIRST=temp;
END=temp;
}
else
{
END->next=temp;
temp->prev=END;
END=temp;
}
}
}
void display_count()
{
temp=FIRST;
int count=0;
if(FIRST==NULL)
printf("the Employee detail is NULL and count is %d\n", count);
else
{
printf("Employee details:\n");
printf("SSN \t EMPLOYEE NAME \t DEPARTMENT \t DESIGNATION \t PHONE NUMBER \t SALARY");
while(temp!=NULL)
{
count++;
printf("\n%s\t %s\t %s\t %s\t %llu\t %0.2f",temp->ssn, temp->name, temp->dept,temp->desig,temp->phno,temp->sal);
temp=temp->next;
}
printf("\n Employee count is %d\n",count);
}
return;
}
void insertionfront()
{
printf("Enter the details of the employee\n");
read();
if(FIRST==NULL)
{
FIRST=temp;
END=temp;
}
else
{
temp->next=FIRST;
FIRST->prev=temp;
FIRST=temp;
}
}
void insertionend()
{
printf("Enter the details of the new employee\n");
read();
if(FIRST==NULL)
{
FIRST=temp;
END=temp;
}
else
{
END->next=temp;
temp->prev=END;
END=temp;
}
return;
}
void deletionfront()
{
temp=FIRST;
if(FIRST==NULL)
printf("List is empty\n");
else if(FIRST==END)
{
printf("deleted element is %s\n", temp->ssn);
FIRST=NULL;
END=NULL;
free(temp);
}
else
{
printf("deleted element is %s\n", temp->ssn);
FIRST =FIRST->next;
FIRST->prev=NULL;
free(temp);
}
return;
}
void deletionend()
{
temp = END;
if(FIRST==NULL)
printf("List is empty\n");
else if(FIRST==END)
{
printf("deleted element is %s\n", temp->ssn);
FIRST=NULL;
END=NULL;
free(temp);
}
else
{
printf("deleted element is %s\n", temp->ssn);
END=END->prev;
END->next=NULL;
free(temp);
}
return;
}
void main()
{
int choice;
while(1)
{
printf(" \n 1 - Create DLL of N Employees \n 2 - Display DLL \n 3 - Insertion at front \n 4 - Insertion at end");
printf("\n 5 - Deletion at front \n 6 - Deletion at end \n 7 - Exit\n");
printf("Enter Your Choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1: create_DLL();
break;
case 2: display_count();
break;
case 3: insertionfront();
break;
case 4: insertionend();
break;
case 5 : deletionfront();
break;
case 6: deletionend();
break;
case 7: return;
default: printf("Invalid Choice\n");
}
}
}
