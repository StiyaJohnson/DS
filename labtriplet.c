#include<stdio.h>
int nza,nzb,sum[10][10],m,n,r1,r2,i,j,c1,c2,a[10][10],b[10][10],c[10][10],nz1=0,nz2,Triplet2[10][10],Triplet1[10][10];
void main()
{
    
    printf("enter the no:of rows of 1st sparce matrix\n");
    scanf("%d",&r1);
    printf("enter the no:of col of 1st sparce matrix\n");
    scanf("%d",&c1);
    printf("entr the elements\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
     printf("the entered elements are \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

   for(i=0;i<r1;i++)
   {
    for(j=0;j<c1;j++)
    {
        if(a[i][j]!=0)
        {
            nz1++;
            Triplet1[nz1][0]=i;
            Triplet1[nz1][1]=j;
            Triplet1[nz1][2]=a[i][j];
        }
    }
   }
    Triplet1[0][0]=r1;
    Triplet1[0][1]=c1;
    Triplet1[0][2]=nz1; 
   printf("the triplet represen is\n");
   for(i=0;i<=nz1;i++)
   {
    for(j=0;j<3;j++)
    {
        printf("%d\t",Triplet1[i][j]);
    }
    printf("\n");
   }
    int q=0,Transpose[10][10];
   printf("the transpose is\n");
   Transpose[0][0]=Triplet1[0][1];
   Transpose[0][1]=Triplet1[0][0];
   Transpose[0][2]=Triplet1[0][2];

    for(i=0;i<c1;i++)
    {
        for(j=0;j<=nz1;j++)
        {
            if(Triplet1[j][1]==i)
            {
                q++;
                Transpose[q][0]=Triplet1[j][1];
                Transpose[q][1]=Triplet1[j][0];
                Transpose[q][2]=Triplet1[j][2];
            }
        }
    }

    for(i=0;i<=nz1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",Transpose[i][j]);
        }
        printf("\n");
    }

/*
    printf("enter the no:of rows of 2nd sparce matrix\n");
    scanf("%d",&r2);
    printf("enter the no:of col of 2nd sparce matrix\n");
    scanf("%d",&c2);
    printf("entr the elements\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
     printf("the entered elements are \n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }

   for(i=0;i<r2;i++)
   {
    for(j=0;j<c2;j++)
    {
        if(b[i][j]!=0)
        {
            nz2++;
            Triplet2[nz2][0]=i;
            Triplet2[nz2][1]=j;
            Triplet2[nz2][2]=b[i][j];
        }
    }
   }
    Triplet2[0][0]=r2;
    Triplet2[0][1]=c2;
    Triplet2[0][2]=nz2; 
   printf("the triplet represen is\n");
   for(i=0;i<=nz2;i++)
   {
    for(j=0;j<3;j++)
    {
        printf("%d\t",Triplet2[i][j]);
    }
    printf("\n");
   }

m=1,n=1;
int k=1;
nza=Triplet1[0][2],nzb=Triplet2[0][2];
if(Triplet1[0][0]==Triplet2[0][0] && Triplet1[0][1]==Triplet2[0][1])
{
    while(m<=nza && n<=nzb)
    {
        if(Triplet1[m][0]<Triplet2[n][0] )
        {
            sum[k][0]=Triplet1[m][0];
            sum[k][1]=Triplet1[m][1];
            sum[k][2]=Triplet1[m][2];
            k++;
            m++;
        }
        else if(Triplet1[m][0]>Triplet2[n][0] )
        {
            sum[k][0]=Triplet2[n][0];
            sum[k][1]=Triplet2[n][1];
            sum[k][2]=Triplet2[n][2];
            k++;
            n++;
        }
        else if(Triplet1[m][0]==Triplet2[n][0] )
        {
            if(Triplet1[m][1]<Triplet2[n][1])
            {
                sum[k][0]=Triplet1[m][0];
                 sum[k][1]=Triplet1[m][1];
                 sum[k][2]=Triplet1[m][2];
                  k++;
                  m++;
            }
            else if(Triplet1[m][1]>Triplet2[n][1])
            {
                sum[k][0]=Triplet2[n][0];
                 sum[k][1]=Triplet2[n][1];
                 sum[k][2]=Triplet2[n][2];
                  k++;
                  n++;
            }
            else if(Triplet1[m][1]==Triplet2[n][1])
            {
                sum[k][0]=Triplet2[n][0];
                 sum[k][1]=Triplet2[n][1];
                 sum[k][2]=Triplet1[m][2]+Triplet2[n][2];
                  k++;
                  n++;
                  m++;
            }

        }
    }

    while(m<=Triplet1[0][2])
    {
         sum[k][0]=Triplet1[m][0];
        sum[k][1]=Triplet1[m][1];
        sum[k][2]=Triplet1[m][2];
        k++;
        m++;
    }
     while(n<=Triplet2[0][2])
    {
         sum[k][0]=Triplet2[n][0];
        sum[k][1]=Triplet2[n][1];
        sum[k][2]=Triplet2[n][2];
        k++;
        n++;
    }
    
         sum[0][0]=Triplet1[0][0];
         sum[0][1]=Triplet1[0][1];
         sum[0][2]=k-1;


printf("the resultant is\n");
         for(i=0;i<=k-1;i++)
            {
                 for(j=0;j<3;j++)
                 {
                    printf("%d\t",sum[i][j]);
                 }
                 printf("\n");
            }
}*/
}