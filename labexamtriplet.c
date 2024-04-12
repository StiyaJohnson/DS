#include<stdio.h>
void main()
{
    int i,j,r1,c1,a[10][10],nz=0,Triplet[10][10];
    printf("Enter the no of rows:\n");
    scanf("%d",&r1);
    printf("Enter the no of columns:\n");
    scanf("%d",&c1);
    printf("Enter the elements:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Entered array elements are:\n");
     for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
           if(a[i][j]!=0)
           {
                nz++;
                Triplet[nz][0]=i;
                Triplet[nz][1]=j;
                Triplet[nz][2]=a[i][j];
           }
        }
    }
     Triplet[0][0]=r1;
     Triplet[0][1]=c1;
     Triplet[0][2]=nz;
     printf("The entered triplet representation is:\n"); 
     for(i=0;i<=nz;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",Triplet[i][j]);
        }
         printf("\n");
    }
}