#include<stdio.h>
#include<math.h>
void th(int n, char s,char t,char d)
{
if(n==0)
{
return;
}
th((n-1),s,d,t);
printf("move %d from %c-%c\n",n,s,d);
th((n-1),t,s,d);
}
void main()
{
int n;
printf("enter the number of disks:");
scanf("%d",&n);
th(n,'a','b','c');
printf("total moves=%f\n",pow(2,n)-1);
}
