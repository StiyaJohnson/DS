#include<stdio.h>
#include<math.h>
#define MAX 50
int poly1[MAX],poly2[MAX],poly3[MAX];
struct poly
{
	int exp;
	int coeff;
};
    struct poly poly1[10],poly2[10],poly3[10];

void main()
	
    {
    	
		int t1,t2,i,j,k;
		printf("Enter no of terms of polynomial 1:\n");
		scanf("%d",&t1);
		printf("Enter the first polynomial:\n");
		for(i=t1;i>=0;i--)
		{
			printf("Enter the coeff of x^%d:",i);
			scanf("%d",&poly1[i].coeff);
			poly1[i].exp=i;
		}
        printf("The first polynomial is\n");
        for(i=t1;i>=0;i--)
        {
            if(i==0)
		    {
			    printf("+%d",poly1[i].coeff);
			    break;
		    }
	    	else
		    {
			    printf("+");
		    }
		printf("%dx^%d",poly1[i].coeff,poly1[i].exp);
	}
	printf("\n");
        
		printf("Enter no of terms of polynomial 2:\n");
		scanf("%d",&t2);
		
		printf("Enter the second polynomial:\n");
		for(i=t2;i>=0;i--)
		{
			printf("Enter the coeff of x^%d:",i);
			scanf("%d",&poly2[i].coeff);
			poly2[i].exp=i;
		}
		i=0,j=0,k=0;
		while(i<=t1 && j<=t2)
		{
			if(poly1[i].exp==poly2[j].exp)
			{
				poly3[k].exp=poly1[i].exp;
				poly3[k].coeff=poly1[i].coeff+poly2[j].coeff;
				i++,j++,k++;
			}
			else if(poly1[i].exp>poly2[j].exp)
			{
				poly3[k].exp=poly1[i].exp;
				poly3[k].coeff=poly1[i].coeff;
				i++,k++;
			}
			else if(poly1[i].exp<poly2[j].exp)
			{
				poly3[k].exp=poly2[j].exp;
				poly3[k].coeff=poly2[j].coeff;
				j++,k++;
			}
		}
	while(i<=t1)
	{
		poly3[k].exp=poly1[i].exp;
		poly3[k].coeff=poly1[i].coeff;
		k++,i++;
	}
	while(j<=t2)
	{
		
		poly3[k].exp=poly2[j].exp;
		poly3[k].coeff=poly2[j].coeff;
		k++,j++;
	}
	printf("The resultant polynomial is\n:");
	for(i=k-1;i>=0;i--)
	{
		if(i==0)
		{
			printf("+%d",poly3[i].coeff);
			break;
		}
		else
		{
			printf("+");
		}
		printf("%dx^%d",poly3[i].coeff,poly3[i].exp);
	}
	printf("\n");
 }
			
 	
		
