#include<stdio.h>
int main()
 {
	int a[50][50],i,j,row,col,k=0,b[50][50],c[50][50],kc=0;
	printf("Enter the no: of rows and columns:\n");
	scanf("%d %d",&row,&col);
	printf("Enter the sparce matrix elements\n");
	for(i=0;i<row;i++)
  	     {
		for(j=0;j<col;j++)
 		    {
			scanf("%d ",&a[i][j]);
		    }
             }
	printf("The sparce matrix is \n");
	for(i=0;i<row;i++)
	     {
	        for(j=0;j<col;j++)
		    {
		        printf("%d ",a[i][j]);
 		    }
			printf("\n");
	     }
	for(i=0;i<row;i++)
	   {
 	      for(j=0;j<col;j++)
 		   {
			if(a[i][j]!=0)
			    {
				k++;
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=a[i][j];
                             }
		   }
           }
	b[0][0]=row;
	b[0][1]=col;
	b[0][2]=k;
	printf("The triplet representation is\n");
	for(i=0;i<b[0][2]+1;i++)
	   {
	      for(j=0;j<3;j++)
 		{
		    printf("%d " ,b[i][j]);
		}
		    printf("\n");
  	   }
	c[0][0]=row;
	c[0][1]=col;
	c[0][2]=b[0][2];
	for(i=0;i<row;i++)
	    {
		for(j=1;j<b[0][2]+1;j++)
		    {
                      
                       if(b[j][1]==i)
                           
			   {
                                 kc++;
				c[kc][0]=b[j][1];
				c[kc][1]=b[j][0];
				c[kc][2]=b[j][2];
			    }
                     }
            }
	printf("The transpose representation is\n");
	for(i=0;i<b[0][2]+1;i++)
	   {
	      for(j=0;j<3;j++)
 		{
		    printf("%d " ,c[i][j]);
		}
		    printf("\n");
  	   }
 }
				
		        