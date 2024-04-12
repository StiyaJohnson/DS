#include<stdio.h>
int binary_search(int *a,int low,int high,int n,int key);
int a[50],low,high,mid,pos,n,i,c,d,key;
void main()
{
        printf("Enter the array size\n");
        scanf("%d",&n);
        printf("Enter the array elements\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
        printf("Enter the key to be searched\n");
        scanf("%d",&key);
        low=0,high=n-1;
        d=binary_search(a,low,high,n,key);
        c=key;
        if(d==-1)
        {
                printf("%d not found",c);
        }
        else
        {
                printf("%d found at %d",c,d);
        }
}
int binary_search(int *a,int low,int high,int n,int key)
{
        mid=(low+high)/2;
        if(low>high)
        {
                return -1;
        }
        else
        {
                if(a[mid==key])
                {
                        return mid;
                }
                else if(a[mid]<key)
                {
                        low=mid+1;
                        return binary_search(a,low,high,n,key);
                }
                else
                {
                        high=mid-1;
                        return binary_search(a,low,high,n,key);
                }
        }
}

