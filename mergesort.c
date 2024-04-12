#include<stdio.h>
int n,i,a[10];
void main()
{   
    printf("Enter the limit\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The entered array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    do
    {
        printf("1:Merge sort\t2:Quick sort\n");
        printf("Which operation u need to perform\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:merge sort();
                    
        }

    }
   






}