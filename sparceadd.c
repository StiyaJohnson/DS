/*ADDITION OF SPARCE*/
#include<stdio.h>
void main()
{
	int r1,c1,r2,c2,i,j,a[50][50],b[50][50],nza=0,nzb=0,q=0,ta[50][50],tb[50][50],c[50][50],m,n;
	printf("enter row size and column size of the 1st sparce matrix\n");
	scanf("%d%d",&r1,&c1);
	printf("enter row size and column size of the 2nd sparce matrix\n");
	scanf("%d%d",&r2,&c2);
	if(r1==r2&&c1==c2)
	{
		printf("enter elements into 1st matrix\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		printf("the 1st matrix entered is:\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				printf("%d\t",a[i][j]);
			}
			printf("\n");
		}
		printf("enter elements into 2nd matrix\n");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				scanf("%d",&b[i][j]);
			}
		}
		printf("the 2nd matrix entered is:\n");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				printf("%d\t",b[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				if(a[i][j]!=0)
				{
					nza++;
					ta[nza][0]=i;
					ta[nza][1]=j;
					ta[nza][2]=a[i][j];
				}
			}
		}
		ta[0][0]=r1;
		ta[0][1]=c1;
		ta[0][2]=nza;
		printf("the triplet representation of the 1st sparce matrix is:\n");
		for(i=0;i<=nza;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d\t",ta[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				if(b[i][j]!=0)
				{
					nzb++;
					tb[nzb][0]=i;
					tb[nzb][1]=j;
					tb[nzb][2]=b[i][j];
				}
			}
		}
		tb[0][0]=r2;
		tb[0][1]=c2;
		tb[0][2]=nzb;
		printf("the triplet representation of the 2nd sparce matrix is:\n");
		for(i=0;i<=nzb;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d\t",tb[i][j]);
			}
			printf("\n");
		}
	}
	    
	else
	{
	    printf("addition not possible\n");
	}
	m=1;
	n=1;
    while(m<=nza&&n<=nzb)
        {
            if(ta[m][0]==tb[n][0]&&ta[m][1]==tb[n][1])
            {
                q++;
                c[q][0]=ta[m][0];
                c[q][1]=ta[m][1];
                c[q][2]=ta[m][2]+tb[n][2];
                m++;
                n++;
            }
            else if(ta[m][0]==tb[n][0])
            {
                if(ta[m][1]<tb[n][1])
                {
                    q++;
                    c[q][0]=ta[m][0];
                    c[q][1]=ta[m][1];
                    c[q][2]=ta[m][2];
                    m++;
                }
                else
                {
                    q++;
                    c[q][0]=tb[n][0];
                    c[q][1]=tb[n][1];
                    c[q][2]=tb[n][2];
                    n++;
                }
                
            }
            else
            {
                 if(ta[m][0]<tb[n][0])
                {
                    q++;
                    c[q][0]=ta[m][0];
                    c[q][1]=ta[m][1];
                    c[q][2]=ta[m][2];
                    m++;
                }
                else
                {
                    q++;
                    c[q][0]=tb[n][0];
                    c[q][1]=tb[n][1];
                    c[q][2]=tb[n][2];
                    n++;
                }    
            }
        }
        while(m<=nza)
        {
            q++;
            c[q][0]=ta[m][0];
            c[q][1]=ta[m][1];
            c[q][2]=ta[m][2];
            m++;    
        }
        while(n<=nzb)
        {
            q++;
            c[q][0]=tb[n][0];
            c[q][1]=tb[n][1];
            c[q][2]=tb[n][2];
            n++;    
        }
        c[0][0]=ta[0][0];
        c[0][1]=ta[0][1];
        c[0][2]=q;
        printf("the triplet representation of the resultant matrix is:\n");
	    for(i=0;i<=q;i++)
	    {
		    for(j=0;j<3;j++)
		    {
		    	printf("%d\t",c[i][j]);
		    }
		    printf("\n");
    	}
        

}










/*SAMPLE OUTPUT
enter row size and column size of the 1st sparce matrix
3
4
enter row size and column size of the 2nd sparce matrix
3
4
enter elements into 1st matrix
0
0
9
0
0
5
0
0
2
0
7
0
the 1st matrix entered is:
0       0       9       0
0       5       0       0
2       0       7       0
enter elements into 2nd matrix
0
8
0
7
0
0
0
6
9
0
0
5
the 2nd matrix entered is:
0       8       0       7
0       0       0       6
9       0       0       5
the triplet representation of the 1st sparce matrix is:
3       4       4
0       2       9
1       1       5
2       0       2
2       2       7
the triplet representation of the 2nd sparce matrix is:
3       4       5
0       1       8
0       3       7
1       3       6
2       0       9
2       3       5
the triplet representation of the resultant matrix is:
3       4       8
0       1       8
0       2       9
0       3       7
1       1       5
1       3       6
2       0       11
2       2       7
2       3       5
*/


