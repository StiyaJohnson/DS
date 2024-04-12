/*PROGRAM OF TRIPLET REPRESENTATION*/
#include<stdio.h>
void main()
{
int a[10][10],r,c,i,j,Triplet[10][3],nz=0;
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
printf("The triplet representation of given sparse matrix\n");
for(i=0;i<=nz;i++)
{
for(j=0;j<3;j++)
{
printf("%d\t",Triplet[i][j]);
}
printf("\n");
}
}





/*SAMPLE OUTPUT
Enter the rows and column of sparse matrix
4
4
Enter the array elements
3
0
0
6
8
0
9
1
0
1
0
0
2
0
5
0
The given sparse matrix:
3       0       0       6
8       0       9       1
0       1       0       0
2       0       5       0
The triplet representation of given sparse matrix
4       4       8
0       0       3
0       3       6
1       0       8
1       2       9
1       3       1
2       1       1
3       0       2
3       2       5
*/