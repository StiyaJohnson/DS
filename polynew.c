#include<stdio.h>	

struct poly

{	                          

 int co;

 int ex;

}p1[10],p2[10],p3[10];

void main()

{

 int t1,t2,i,j,k,e,c;

 printf("Enter the no of terms in first polynomial\n");

 scanf("%d",&t1);

 for(i=0;i<t1;i++)

 {

  printf("Enter the coefficient\n");

  scanf("%d",&c);

  printf("Enter the exponent\n");

  scanf("%d",&e);

  

  p1[i].ex=e;

  p1[i].co=c;

  

 }

 for(i=0;i<t1-1;i++)

 {

  printf("%dx^%d+",p1[i].co,p1[i].ex);

 }
printf("The first polynomial is\n");
printf("%dx^%d",p1[t1-1].co,p1[t1-1].ex);

printf("\n");

 printf("Enter the no of terms in second polynomial\n");

 scanf("%d",&t2);

 for(j=0;j<t2;j++)

 {

  printf("Enter the coefficient\n");

  scanf("%d",&c);

  printf("Enter the exponent\n");

  scanf("%d",&e);

  

  p2[j].ex=e;

  p2[j].co=c;

  

 }

 for(i=0;i<t2-1;i++)

 {

  printf("%dx^%d+",p2[i].co,p2[i].ex);

  

 }
 printf("The second polynomial is\n");

printf("%dx^%d\n",p2[t2-1].co,p2[t2-1].ex);

printf("\n");

 i=0,j=0,k=0;

 while(i<t1&&j<t2)

 {

 if(p1[i].ex==p2[j].ex)

 {

  p3[k].ex=p1[i].ex;

  p3[k].co=p1[i].co+p2[j].co;

  

  i++;

  j++;

  k++;

  

 }

 else if(p1[i].ex>p2[j].ex)

 {

  p3[k].ex=p1[i].ex;

  p3[k].co=p1[i].co;

  i++;

  k++;

 }

 else

 {

  p3[k].ex=p2[j].ex;

  p3[k].co=p2[j].co;

  j++;

  k++;

 }

 }

 while(i<t1)

 {

  p3[k].ex=p1[i].ex;

  p3[k].co=p1[i].co;

  i++;

  k++;

 }

 while(j<t2)

 {

  p3[k].ex=p2[j].ex;

  p3[k].co=p2[j].co;

  j++;

  k++;

 }

 printf("\n");

 printf("The final result is\n");

 for(i=0;i<k-1;i++)

 {

  printf("%dx^%d+",p3[i].co,p3[i].ex);

 }

 printf("%dx^%d",p3[k-1].co,p3[k-1].ex);

 printf("\n");

}

