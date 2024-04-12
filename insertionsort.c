#include<stdio.h>
#include<stdlib.h>
int temp,n,i,k,j,a[10];
void main()
{
    printf("Enter the no of elements to be sorted\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The unsorted elements are \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nThe passes are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");

    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0 && temp<a[j];j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;  
         for(k=0;k<n;k++)
         {
            printf("%d\t",a[k]);
         }    
         printf("\n");       
    }
    printf("The sorted array after insertion sort is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}