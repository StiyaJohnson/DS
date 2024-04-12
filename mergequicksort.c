#include<stdio.h>
//void mergesort(int low,int high);
//void merge(int low,int mid,int high);
void quicksort(int low,int high);
void swap(int *a,int *b);
int a[10],i,j,n,low,high,op,ch,b[10],k;
void main()
{
    printf("Enter the limit\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The unsorted array elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    do
    {
       printf("\n1:MERGE SORT\n2:QUICK SORT\n");
       printf("Enter the operation u need to perform\n");
       scanf("%d",&op);
       switch(op)
       {
          /*  case 1:low=0,high=n-1;
                    mergesort(low,high);
                    printf("The sorted array is\n");
                     for(i=0;i<n;i++)
                     {
                          printf("%d\n",a[i]);
                     }
                    break;*/

            case 2:low=0,high=n-1;
                    quicksort(low,high);
                    printf("The sorted array is\n");
                     for(i=0;i<n;i++)
                     {
                          printf("%d\n",a[i]);
                     }
                    break;
            default:printf("invalid\n");
                    break;
       }                    
       printf("\nDo u want to continue...if yes press 1\n");
       scanf("%d",&ch);

    } while (ch==1);
    
}

/*void mergesort(int low,int high)
{
    int mid;
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
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++,k++;
        }
        else
        {
            b[k]=a[j];
            j++,k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
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
} */

void quicksort(int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=a[low];
        i=low;
        j=high;
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
        swap(&a[j],&pivot);
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