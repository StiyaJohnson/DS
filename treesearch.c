#include<stdio.h>
#define MAX 8
int a[MAX],lval,rval,root,i,key,m;
char ch;
int search(int a[],int index,int key);
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

int search(int a[],int index,int key)
{
        if(a[index]==key)
        {
            return index;
        }
        else
        {
            if(2*i<=MAX)
            {
               x= search(a,2*i,key);
            }
             if(2*i+1<=MAX)
            {
                x=search(a,2*i+1,key);
            }
        }
        return i;
    
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
        printf("Enter the node to be searched : ");
        scanf("%d",&key);
        m=search(a,1,key);
        if(m==0)
        {
            printf("element not found\n");
        }
        else
        {
            printf("element found at index %d",m);
        }
}
        
        
