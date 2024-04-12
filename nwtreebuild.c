#include<stdio.h>
#define MAX 8
int a[MAX],i,lval,rval,root;
char ch;

void buildtree(int a[],int i,int val)
{

    if(i==0)
    {
        return;
    }
    else
    {
        a[i]=val;
        printf("do u want left child (y/n) : ");
        scanf(" %c",&ch);
        if(ch=='y')
        {
            printf("Enter the value to be inserted\n");
            scanf("%d",&lval);
            buildtree(a,2*i,lval);
        }        
        else
        {
            buildtree(a,0,0);
        }
        printf("do u want right child or not(y/n) : ");
        scanf(" %c",&ch);
        if(ch=='y')
        {
            printf("Enter the value to be created\n");
            scanf("%d",&rval);
            buildtree(a,(2*i)+1,rval);

        }
        else
        {
            buildtree(a,0,0);
        }
    }
        
    
}
void main()
{
    for(i=1;i<=MAX;i++)
    {
        a[i]=-1;
    }
    printf("Enter the value of root node\n");
    scanf("%d",&root);
    buildtree(a,1,root);
    printf("The array representation is \n");
    for(i=1;i<=MAX;i++)
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