#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct p
{
	int exp;
	int coeff;
};
struct p p1[MAX],p2[MAX],p3[MAX];
int t1,t2,i,k,j;
void main()
{
	printf("Enter the highest power of polynomial 1:\n");
    scanf("%d", &t1);
    printf("Enter the details of first polynomial:\n");
    for (i = t1; i >= 0; i--) 
    {
        printf("The coefficient of x^%d : ", i);
        scanf("%d", &p1[i].coeff);
        p1[i].exp = i;
    }

    printf("Enter the highest power of polynomial 2:\n");
    scanf("%d", &t2);
    printf("Enter the details of second polynomial:\n");
    for (i = t2; i >= 0; i--) 
    {
        printf("The coefficient of x^%d : ", i);
        scanf("%d", &p2[i].coeff);
        p2[i].exp = i;
    }
    for (i = 0; i <= t1; i++) 
    {
        for (j = 0; j <= t2; j++) 
        {
        
				k=p1[i].exp+p2[j].exp;
				p3[k].coeff=p3[k].coeff+p1[i].coeff*p2[j].coeff;
				p3[k].exp=k;
			}
	}
	 int max_power = 0;
    for (i = 0; i < MAX; i++) 
    {
        if (p3[i].coeff != 0) 
        {
            max_power = p3[i].exp;
      	}
     }
     printf("Resultant polynomial is :\n");
    for (i = max_power; i >= 0; i--) 
    {
        if (p3[i].coeff != 0) 
        {
            if (i == 0) 
            {
                printf("%d", p3[i].coeff);
            } 
            else 
            {
                printf("%dx^%d ", p3[i].coeff, p3[i].exp);
            }
            if (i > 0) 
            {
                printf("+ ");
            }
        }
    }
   
  

    printf("\n");
         

}
