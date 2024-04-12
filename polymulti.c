#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct poly
{
    int exp;
    int coeff;
}poly1[20],poly2[20],poly3[20];
int t1,t2,i,j,k;
void main()
{
        printf("Enter the no of terms of poly 1\n");
        scanf("%d",&t1);
        printf("Enter the details of poly 1\n");
        for(i=t1;i>=0;i--)
        {
                printf("Enter the coefficient of x^%d\n",i);
                scanf("%d ",&poly1[i].coeff);
                poly1[i].exp=i;
        }
         printf("Enter the no of terms of poly 2\n");
         scanf("%d",&t2);
         printf("Enter the details of poly 1\n");
         for(i=t2;i>=0;i--)
         {
                printf("Enter the coefficient of x^%d\n",i);
                scanf("%d ",&poly2[i].coeff);
                poly2[i].exp=i;
         }
            for(i=0;i<=t1;i++)
            {
                    for(j=0;j<=t2;j++)
                    {
                        k=poly1[i].exp+ poly2[j].exp;
                        poly3[k].coeff=poly3[k].coeff+poly1[i].coeff*poly2[j].coeff;
                        poly3[k].exp=k;   
                    }
            }
            int max=0;
            for(i=0;i<MAX;i++)
            {
                        if (poly3[i].coeff!=0)
                        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
                                 max=poly3[i].exp;                                                                                                                                                                                                               
                        }
            }
            printf("The resultant polynomial is \n");
            for(i=max;i>=0;i--)                                                                                                                                                                                                                                                                                                                                                                                                         
            {
                        if(poly3[i].coeff!=0)
                        {
                                if(i==0)
                                {
                                        printf("%d",poly3[i].coeff);

                                }
                                else{
                                        printf("%dx^%d",poly3[i].coeff,poly3[i].exp);

                                    }
                                    if(i>0)
                                    {
                                         printf("+");
                                    }
                        }
                        

            }

}