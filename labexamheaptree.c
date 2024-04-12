#include<stdio.h>
#include<stdlib.h>


int temp,left,right,lc,rc,parent,n,i,a[7],item;
void main()
{
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=1;i<=n;i++)
    {
        printf("Enter the element to be inserted\n");
        scanf("%d",&item);
        
        n=n+1;
        a[n]=item;
        i=n;
        parent=i/2;
        while(parent>0 && a[parent]<a[i])
        {
            temp=a[parent];
            a[parent]=a[i];
            a[i]=temp;
            i=parent;
            parent=i/2;
        }
    }
    printf("the passes are\n");
    while(n>1)
    {
        temp=a[1];
        a[1]=a[n];
        a[n]=a[temp];
        n=n-1;
        i=1;
        while(i<=n)
        {
            lc=2*i;
            rc=(2*i)+1;
            if(lc<=n)
            {
                left=a[lc];
            }
            else
            {
                left=-1;
            }
            if(rc<=n)
            {
                right=a[rc];

            }
            else
            {
                right=-1;
            }
            if(a[i]>=left && a[i]>=right)
            {
                break;
            }
            else
            {
                if(left>=right && left>=a[i])
                {
                    temp=a[i];
                    a[i]=a[lc];
                    a[lc]=temp;
                }
                else if(right>=a[i] && a[i]<=right)
                {
                    temp=a[i];
                    a[i]=a[rc];
                    a[rc]=temp;
                }
            }
        }   
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
    }