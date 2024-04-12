#include<stdio.h>
#include<stdlib.h>
void mergesort(int low,int high);
void merge(int low,int mid,int high);
int temp,n,low,high,i,k,j,mid,a[10],b[10];
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
    mergesort(low,high);
    printf("The sorted array elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}   

   void mergesort(int low,int high)
   { 
     low=0,high=n-1;
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
                while(a[i]<=pivot)
                {
                    i++;
                }
                while(a[j]>=pivot)
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