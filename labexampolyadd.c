#include<stdio.h>
#include<stdlib.h>
int t1,i,t2,c,e;
struct node
{
    int coeff;
    int exp;
}p1[20],p2[20],p3[20];
void main()
{
    printf("enter the no:of terms of first polynomial\n");
    scanf("%d",&t1);
    for(i=1;i<=t1;i++)
    {
        printf("enter the coeff of% d term:\n",i);
        scanf("%d",&c);
        printf("enter the exponenet of %d term:\n",i);
        scanf("%d",&e);
        p1[i].coeff=c;
        p1[i].exp=e;
    }
    printf("the entered polynomial is:\n");
    for(i=1;i<t1;i++)
    {
        printf("%dx^%d+",p1[i].coeff,p1[i].exp);
    }
    printf("%dx^%d",p1[i].coeff,p1[i].exp);



    printf("\nenter the no:of terms of second polynomial\n");
    scanf("%d",&t2);
    for(i=1;i<=t2;i++)
    {
        printf("enter the coeff of% d term:\n",i);
        scanf("%d",&c);
        printf("enter the exponenet of %d term:\n",i);
        scanf("%d",&e);
        p1[i].coeff=c;
        p1[i].exp=e;
    }
    printf("the entered polynomial is:\n");
    for(i=1;i<t2;i++)
    {
        printf("%dx^%d+",p1[i].coeff,p1[i].exp);
    }
    printf("%dx^%d",p1[i].coeff,p1[i].exp);

    int i,j,k;
    i=0,j=0,k=0;

    while(i<t1 && j<t2)
    {
        if(p1[i].exp==p2[j].exp)
        {
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].exp=p1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(p1[i].exp>p2[j].exp)
        {
            p3[k].coeff=p1[i].coeff;
            p3[k].exp=p1[i].exp;
            i++;
            k++;
        }
        else
        {
            p3[k].coeff=p2[j].coeff;
            p3[k].exp=p2[j].exp;
            j++;
            k++;
        }
    }

    while(i<t1)
    {
        p3[k].coeff=p1[i].coeff;
        p3[k].exp=p1[i].exp;
        i++;
        k++;
    }
    while(j<t2)
    {
        p3[k].coeff=p2[j].coeff;
        p3[k].exp=p2[j].exp;
        j++;
        k++;
    }

    printf("\nthe resultant polynomial is:\n");
    for(i=0;i<k-1;i++)
    {
        printf("%dx^%d+",p3[i].coeff,p3[i].exp);
    }
    printf("%dx^%d",p3[i].coeff,p3[i].exp);

}

