#include<stdio.h>
void main()
{
		int i,flag=0,n,e,a[50],index;
		printf("enter the limit");
        scanf("%d",&n);
        printf("Enter the array elements\n");
        for(i=0;i<n;i++)
		{
			scanf("%d\n",&a[i]);
		}
		printf("Enter the element to be searched\n");
		scanf("%d",&e);
		for(i=0;i<n;i++)
		{
			if(a[i]==e)
			{
				flag=1;
                index=i;
				break;	
			}
		}
		if(flag==1)
		{
			printf("element is found at pos %d\n",index);
		}
		else
		{
			printf("element is not found\n");
		}
	}