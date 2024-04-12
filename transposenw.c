/*PROGRAM TRANSPOSE OF A MATRIX*/
#include<stdio.h>
void main()
{
	int a[10][10],r,c,i,j,Triplet[10][3],nz=0,Transpose[10][10],q;
	printf("Enter the rows and column of sparse matrix\n");
	scanf("%d%d",&r,&c);
	printf("Enter the array elements\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		scanf("%d",&a[i][j]);
		}
	}
	printf("The given sparse matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		 printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		  if (a[i][j]!=0)
		  {
		  		nz++;
		  		Triplet[nz][0]=i;
		  		Triplet[nz][1]=j;
		  		Triplet[nz][2]=a[i][j];
		  }
		}
	}
	Triplet[0][0]=r;
	Triplet[0][1]=c;
	Triplet[0][2]=nz;
	printf("The triplet representation of entered sparse matrix\n");
	for(i=0;i<=nz;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("%d\t",Triplet[i][j]);
		}
		printf("\n");
	}
	Transpose[0][0]=Triplet[0][1];
	Transpose[0][1]=Triplet[0][0];
	Transpose[0][2]=Triplet[0][2];
	for(i=0,q=0;i<c;i++)
	{
		for(j=1;j<=nz;j++)
		{
			if(Triplet[j][1]==i)
			{
				q++;
				Transpose[q][0]=Triplet[j][1];
				Transpose[q][1]=Triplet[j][0];
				Transpose[q][2]=Triplet[j][2];
			}
		}
	
	}
	printf("The transpose of given matrix is:\n");
	for(i=0;i<=nz;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",Transpose[i][j]);
		}
		printf("\n");
	}
}




/*SAMPLE OUTPUT
Enter the rows and column of sparse matrix
2
3
Enter the array elements
1
0
0
2
0
0
The given sparse matrix:
1       0       0
2       0       0
The triplet representation of entered sparse matrix
2       3       2
0       0       1
1       0       2
The transpose of given matrix is:
3       2       2
0       0       1
0       1       2
*/








