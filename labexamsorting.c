#include<stdio.h>
#include<stdlib.h>
void selectionsort();
//void insertionsort(int a[],int n);
void bubblesort();
//void mergesort(int a[],int n);
//void quicksort(int a[],int n);
int i,j,n,a[10],op,choice,temp,k;

void bubblesort()
{
    printf("Enter the no:of elements:\n");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The unsorted array elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t ",a[i]);
    }
    printf("\n");
    printf("The passes are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");

     
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        for(k=0;k<n;k++)
        {
            printf("%d\t",a[k]);
        }
        printf("\n");
    }
    printf("The sorted array using bubble sort is:\n");
                for(i=0;i<n;i++)
                {
                    printf("%d \t",a[i]);
                }

} 

void selectionsort()
{
     int min,loc;
    printf("Enter the no:of elements:\n");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The unsorted array elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d \t",a[i]);
    }
    printf("\n");
     printf("The passes are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
     printf("\n");
   
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
            min=a[j];
            loc=j;
            }
        }
        if(i!=loc)
        {
            temp=a[i];
            a[i]=a[loc];
            a[loc]=temp;
        }
        for(k=0;k<n;k++)
        {
            printf("%d\t",a[k]);
        }
        printf("\n");

    }
     printf("The sorted array using selection sort  is:\n");
                for(i=0;i<n;i++)
                {
                    printf("%d \t",a[i]);
                }

}

    
    void main()
    { 
    
      
    printf("Which sorting u need to perform.....\n1:selection sort\n2:bubble sort\n3:insertion sort\n4:merge sort\n5:quick sort\n");
    do
    {
    
    printf("Enter the operation:\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:selectionsort();
                
                break;
        case 2:bubblesort();
                
                break;
        /*case 3:insertionsort(a,n);
                printf("The sorted array is:\n");
                for(i=0;i<n;i++)
                {
                    printf("%d ",a[i]);
                }
                break;
        case 4:mergesort(a,n);
                printf("The sorted array is:\n");
                for(i=0;i<n;i++)
                {
                    printf("%d ",a[i]);
                }
                break;
        case 5:quicksort(a,n);
                printf("The sorted array is:\n");
                for(i=0;i<n;i++)
                {
                    printf("%d ",a[i]);
                }
                break;*/
        default:printf("invalid opertaion\n");
                break;
    }
    printf("\nDo u want to continue:\n");
    scanf("%d",&choice);

}while(choice==1);

}

