#include<stdio.h>
void main()
{
     int m=1,n=1,k=1, i,j,r1,c1,r2,c2,sum[10][10],a[10][10],b[10][10],nz1=0,nz2=0,Triplet1[10][10],Triplet2[10][10],nza,nzb;
    printf("Enter the no of rows for 1st sparce matrix:\n");
    scanf("%d",&r1);
    printf("Enter the no of columns for 1st sparce matrix:\n");
    scanf("%d",&c1);
    printf("Enter the elements to the 1st sparce matrix:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("The first sparce matrix is :\n");
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
     printf("The entered triplet representation of 1st sparce matrix  is:\n"); 
     for(i=0;i<=nz1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",Triplet1[i][j]);
        }
         printf("\n");
    }
      printf("Enter the no of rows for 2nd sparce matrix:\n");
    scanf("%d",&r2);
    printf("Enter the no of columns for 2nd sparce matrix:\n");
    scanf("%d",&c2);
    printf("Enter the elements to the 2nd sparce matrix:\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("The 2nd sparce matrix is :\n");
     for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d ",b[i][j]);
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
     printf("The entered triplet representation of 1st sparce matrix  is:\n"); 
     for(i=0;i<=nz2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",Triplet2[i][j]);
        }
         printf("\n");
    }
     nza=Triplet1[0][2],nzb=Triplet2[0][2];
    if (Triplet1[0][0]==Triplet2[0][0] && Triplet1[0][1]==Triplet2[0][1])
    {
        while(m<=nza && n<=nzb)
        {
            if(Triplet1[m][0]<Triplet2[n][0])
            {
                sum[k][0]=Triplet1[m][0];
                sum[k][1]=Triplet1[m][1];
                sum[k][2]=Triplet1[m][2];
                m++;
                k++;
            }
            else if(Triplet1[m][0]>Triplet2[n][0])
            {
                sum[k][0]=Triplet2[n][0];
                sum[k][1]=Triplet2[n][1];
                sum[k][2]=Triplet2[n][2];
                k++;
                n++;
            }
            else if(Triplet1[m][0]==Triplet2[n][0])
            {
                if(Triplet1[m][1]<Triplet2[n][1])
                {
                    sum[k][0]=Triplet1[m][0];
                    sum[k][1]=Triplet1[m][1];
                    sum[k][1]=Triplet1[m][2];
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
                    sum[k][0]=Triplet1[m][0];
                    sum[k][1]=Triplet1[m][1];
                    sum[k][0]=Triplet1[m][2]+Triplet2[n][2];
                    m++;
                    n++;
                    k++;
                }
            }
        }
         while(m<=Triplet1[0][2])
        {
            sum[k][0]=Triplet1[m][0];
            sum[k][1]=Triplet1[m][1];
            sum[k][2]=Triplet1[m][2];
            m++;
            k++;
        }
         while(n<=Triplet2[0][2])
        {
            sum[k][0]=Triplet2[n][0];
            sum[k][1]=Triplet2[n][1];
            sum[k][2]=Triplet2[n][2];
            n++;
            k++;
        }
        sum[0][0]=Triplet1[0][0];
        sum[0][1]=Triplet1[0][1];
        sum[0][2]=k-1;
        printf("The resultant matrix is :\n");
        for(i=0;i<=k-1;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d ",sum[i][j]);
            }
            printf("\n");
        }


        
    }
    else
    {
        printf("ADDITION NOT POSSIBLE\n");
    }
}
