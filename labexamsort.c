#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b);
//void insertionsort();

//void bubblesort();
void selectionsort();
int temp,n,choice,low,high,i,min,loc,k,j,mid,a[10],op,b[10];
void main()
{
    do
    {
        printf("1:selectionsort\n2:mergesort\n3:quicksort\n");
        printf("enter the sort u ned to perform\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:selectionsort();
                    break;
         /*   case 2:insertionsort();
                    break;
            case 3:bubblesort();
                    break;
            case 4:break;*/
            
        }
        printf("\nDo u want to continue/n....if yess press 5\n");
        scanf("%d",&choice);
    }while(choice==1);
    }


    void selectionsort()
    {
        printf("Enter the no:of elements to be sorted\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("the unsorted array elements are\n");
         for(i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }

        printf("\nthe passes are\n");
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
                if(min>a[j])
                {
                    min=a[j];
                    loc=i;
                }
            }
            if(loc!=i)
            {
                swap(&a[i],&a[loc]);
            }
            for(k=0;k<n;k++)
            {
                printf("%d\t",a[k]);
            }
            printf("\n");
        }
         printf("\nthe sorted array is\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }      
        printf("\n");
    
    }
/*
    void insertionsort()
    {
        printf("Enter the no:of elements to be sorted\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("the unsorted array elements are\n");
         for(i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }

        printf("the passes are\n");
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
        }
        for(k=0;k<n;k++)
        {
            printf("%d\t",a[k]);
        }
         printf("\nthe sorted array is\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }      
    }

    void bubblesort()
    {
        printf("Enter the no:of elements to be sorted\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("the unsorted array elements are\n");
         for(i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }

        printf("\nthe passes are\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }
        printf("\n");

        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    swap(&a[j],&a[j+1]);
                }
            }

            for(k=0;k<n;k++)
            {
                printf("%d\t",a[k]);
            }
            printf("\n");
        }   
        printf("\nthe sorted array is\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }        
    }*/

    void swap(int *a,int *b)
    {
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }