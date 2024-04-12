#include<stdio.h>
#define MAX 8
int a[MAX],lval,rval,root,i;
char ch;
void buildtree(int a[],int i,int m)
{
a[i]=m;
printf("Do u want left node (y/n) : ");
scanf(" %c",&ch);
if(ch=='y')
{
printf("Enter the value to be inserted : ");
scanf("%d",&lval);
buildtree(a,2*i,lval);
}
printf("Do u want right node (y/n) : ");
scanf(" %c",&ch);
if(ch=='y')
{
printf("Enter the value to be inserted : ");
scanf("%d",&rval);
buildtree(a,(2*i)+1,rval);
}
return;


}
void main()
{

for(i=1;i<=MAX;i++)
{
a[i]=-1;
}
printf("Enter the root value : ");
scanf("%d",&root);
buildtree(a,1,root);
printf("the array elements are\n");
for(i=1;i<=MAX;i++)
{
if(a[i]!=-1)
{
printf("%d",a[i]);
}
else
{
printf("_");
}

}
}