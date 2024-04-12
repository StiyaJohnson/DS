#include<stdio.h>
#define MAX 8
int a[MAX],i,lval,rval,root;
char ch;
void buildtree(int a[],int i,int val)
{
a[i]=val;
printf("do u need a left node(y/n)..\n");
scanf(" %c",&ch);
if(ch=='y')
{
printf("Enter the value of node to be entered\n");
scanf("%d",&lval);
buildtree(a,2*i,lval);
}
printf("Do u need right node(y/n)...\n");
scanf(" %c",&ch);
if(ch=='y')
{
printf("Enter the value of node to be entered\n");
scanf("%d",&rval);
buildtree(a,2*i+1,rval);
}
return;
}

void main()
{
for(i=1;i<MAX;i++)
{
a[i]=-1;
}
printf("Enter the value of root\n");
scanf("%d",&root);
buildtree(a,1,root);
printf("The array representation is : ");
for(i=1;i<MAX;i++)
{
if(a[i]!=-1)
{
printf("%d ",a[i]);
}
else
{
printf(" _ ");
}
}
} 