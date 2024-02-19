#include<stdio.h>
int flag;
struct node
{
int value;
struct node *ltree;
struct node *rtree;
};
typedef struct node* NODE;
NODE getnode()
{
NODE x;
x=(NODE) malloc (sizeof(struct node));
x->ltree=NULL;
x->rtree=NULL;
return x;
}
NODE create(int item, NODE root)
{
NODE temp,cur,prev;
int i;
temp=getnode();
temp->value=item;
if(root==NULL)
{
root=temp;
return root;
}
prev=NULL;
cur=root;
while (cur!=NULL)
{
prev=cur;
if(temp->value==cur->value)
{
flag=1;
break;
}
cur=(temp->value<cur->value)?cur->ltree:cur->rtree;
}
if(flag==0)
{
if(temp->value<prev->value)
prev->ltree=temp;
else if(temp->value>prev->value)
prev->rtree=temp;
}
return root;
}
void in(NODE IN)
{
if(IN!=NULL)
{
in(IN->ltree);
printf("%d\t",IN->value);
in(IN->rtree);
}
}
void pre(NODE PRE)
{
if(PRE!=NULL)
{
printf("%d\t",PRE->value);
pre(PRE->ltree);
pre(PRE->rtree);
}
}
void post(NODE POST)
{
if(POST!=NULL)
{
post(POST->ltree);
post(POST->rtree);
printf("%d\t",POST->value);
}
}
void search(NODE root)
{
int item, found=0;
NODE cur;
printf("enter the element to be searched\n");
scanf("%d",&item); // read key
if(root==NULL)
{
printf("tree is empty\n");
return;
}
cur=root;
while(cur!=NULL)
{
if(item==cur->value)
{
found = 1;
printf("Found key %d in tree\n",cur->value);
}
if(item<cur->value)
cur=cur->ltree;
else
cur=cur->rtree;
}
if(found==0)
printf("Key not found\n");
}
void main()
{
int choice, item, n, i;
NODE root=NULL;
while(1)
{
printf("\n1. Create BST of N Integers");
printf("\n2. BST Traversal");
printf("\n3. Binary Search");
printf("\n4. Exit");
printf("\nEnter Your Choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("\n Enter number elements : ");
scanf("%d",&n);
for (i =0; i<n; i++)
{
printf("Enter the item to be inserted\n");
scanf("%d",&item);
root=create(item,root);
}
break;
case 2: if(root==NULL)
printf("Tree is empty\n");
else
{
printf("\n\nPREORDER traversal\n");
pre(root);
printf("\n\nINORDER traversal\n");
in(root);
printf("\n\nPOSTORDER traversal\n");
post(root);
}
break;
case 3: search(root);
break;
case 4: return;
default: printf("\n Invalid Choice\n");
}
}
}
