#include<stdio.h>
#include<stdlib.h>
void mergesort(int low,int high);
void swap(int *a,int *b);
void merge(int low,int mid,int high);
void quicksort(int low,int high);
int temp,n,choice,low,high,i,k,j,mid,a[10],op,b[10];
void main()
{
    do
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
    
    
        printf("\nwhich operation u need to perform...1:mergesort\n...2:quicksort\n:\n");
        printf("Enter the operation:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:low=0,high=n-1;
                    mergesort(low,high);
                    printf("The sorted array elements aftr mergesort is:\n");
                    for(i=0;i<n;i++)
                    {
                        printf("%d\t",a[i]);
                    }
                    printf("\n");
                    break;
            case 2:low=0,high=n-1;
                    quicksort(low,high);
                    printf("The sorted array elements aftr quicksort is\n");
                    for(i=0;i<n;i++)
                    {
                        printf("%d\t",a[i]);
                    }
                    printf("\n");
                    break;
            default:printf("invalid operation\n");
                    break;
        }

        printf("\nDo u want to continue/n....if yess press 1\n");
        scanf("%d",&choice);
    }while(choice==1);


}


void mergesort(int low,int high)
   { 
     
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }

    }

    void merge(int low,int mid,int high)
    {
        int k;
        k=low,i=low,j=mid+1;
        while(i<=mid && j<=high)
        {
            if(a[i]<a[j])
            {
                b[k]=a[i];
                i++;
                k++;
            }
            else
            {
                b[k]=a[j];
                j++;
                k++;
            }
        }

        while(i<=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
        while(j<=high)
        {
            b[k]=a[j];
            k++;
            j++;
        }

        for(i=low;i<=high;i++)
        {
            a[i]=b[i];
        }
        
    }

        
void quicksort(int low,int high)
  {
        int pivot;
        if(low<high)
        {
            pivot=a[low];
            i=low,j=high;
            while(i<j)
            {
                while(a[i]<pivot)
                {
                    i++;
                }
                while(a[j]>pivot)
                {
                    j--;
                }
                if(i<j)
                {
                    swap(&a[i],&a[j]);
                }

            }
            swap(&a[i],&pivot);
            quicksort(low,j-1);
            quicksort(j+1,high);
        } 
  }


void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
    