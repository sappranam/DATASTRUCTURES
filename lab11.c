#include<stdio.h>
int a[20][20], q[20],visited[20];
int n, i, j, f=0, r=-1;
void create_graph()
{
printf("\n Enter the number of cities: ");
scanf("%d",&n);
printf("\n Enter graph data in matrix form:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
return;
}
void bfs(int v)
{
for(i=1;i<=n;i++)
if(a[v][i] && !visited[i])
q[++r]=i;
if(f<=r)
{
visited[q[f]]=1;
bfs(q[f++]);
}
}
void main()
{
int v, choice;
while(1)
{
printf("\n1. Create a Digraph of N cities using Adjacency Matrix");
printf("\n2. Print all the nodes reachable from a given starting node in a digraph using BFS method") ;
printf("\n3. Exit");
printf("\n Enter Your Choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1: create_graph();
break;
case 2: printf("Enter the source vertex: ");
scanf("%d",&v);
if((v<1)||(v>n))
printf("\nEnter a valid source vertex");
else
{
for(i=1;i<=n;i++)
visited[i]=0;
visited[v]=1;
bfs(v);
printf("The reachable nodes from node %d:\n",v);
for(i=1;i<=n;i++)
if(visited[i] && i !=v)
printf("node %d\n",i);
}
break;
case 3:return;
default:printf("\nInvalid Choice");
}
}
}
