#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int coeff;
    int exp;
    struct poly*link;
};
    struct poly *head,*new,*ptr,*poly1,*poly2,*ptr1,*ptr2; 
    int i,t1,e,c;

struct poly*readpoly()
{
    int t1,i,t2,c1,e1,c2,e2;
    head=NULL;
    printf("Enter the no:of terms of polynomial\n");
    scanf("%d",&t1);
    for(i=1;i<=t1;i++)
    {
       new=(struct poly*)malloc(sizeof(struct poly));
       printf("Enter the coeff of %d term\n",i);
       scanf("%d",&c1);
       printf("Enter the exponent of %d term\n",i);
       scanf("%d",&e1);
       new->coeff=c1;
       new->exp=e1;
       new->link=NULL;
       if(head==NULL)
       {
            head=new;
            ptr=new;

       }
       else
       {
            ptr->link=new;
            ptr=new;
       }


    }

    
    
}

struct poly*addpoly(struct poly*p,struct poly *q)
{
    struct poly *head1=NULL;
    poly1=p;
    poly2=q;
    while(poly1!=NULL && poly2!=NULL)
    {
        new=(struct poly*)malloc(sizeof(struct poly));
        new->link==NULL;
        if(poly1->exp==poly2->exp)
        {
            new->coeff=poly1->coeff+poly2->coeff;
            new->exp = poly1->exp;
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        else if(poly1->exp<poly2->exp)
        {
            new->coeff=poly2->coeff;
            new->exp = poly2->exp;
            poly2 = poly2->link;    
        }
        else if(poly1->exp>poly2->exp)
        {
            new->coeff=poly1->coeff;
            new->exp = poly1->exp;
            poly1 = poly1->link;    
        }
        if(head1==NULL)
        {
            head=new;
            ptr1=new;
        }
        else
        {
            ptr1->link=new;
            ptr1=new;
        }
    }

    while(poly1!=NULL)
    {
        new=(struct poly*)malloc(sizeof(struct poly));
        new->coeff=poly1->coeff;
        new->exp = poly1->exp;
        new->link==NULL;
        poly1 = poly1->link;
        ptr1->link=new;
        ptr1=new;
        
    }
      
       while(poly2!=NULL)
    {
        new=(struct poly*)malloc(sizeof(struct poly));
        new->coeff=poly2->coeff;
        new->exp = poly2->exp;
        new->link==NULL;
        poly2 = poly2->link;
        ptr1->link=new;
        ptr1=new;

    }

    return head1;
    
}


void display(struct poly*head1)
{
    if(head1!=NULL)
    {
       printf("polynomial is\n");
       ptr2=head1;
       while(ptr2->link!=NULL)
       {
            printf("%d x^%d+",ptr2->coeff,ptr2->exp);
            ptr2=ptr2->link;
       }
       if(ptr2->exp==0)
       {
            printf("%d",ptr2->coeff);
       }
       else if(ptr2->exp==1)
       {
            printf("%d x",ptr2->coeff);
       }
       else
       {
              printf("%d x^%d",ptr2->coeff,ptr2->exp);
       }

       printf("\n");


    }
}













void main()
{
    struct node*p,*q,*resultant;
    p=readpoly();
    display(p);
    q=readpoly();
    display(q);
    resultant=addpoly(p,q);
    printf("resultant is\n");
    display(resultant);
} 