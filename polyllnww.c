#include<stdlib.h>
#include<stdio.h>
int term;
struct poly
{
    int coeff;
    int exp;
    struct poly*link;
};
struct poly*ptr,*head,*new,*p1,*p2,*p3;

struct poly*readpoly()
{
    int c,i,e;
    head=NULL;
    printf("Enter the no of terms\n");
    scanf("%d",&term);
    for(i=1;i<=term;i++)
    {
        new=(struct poly*)malloc(sizeof(struct poly));
        printf("Enter the coefficient of %d term\n",i);
        scanf("%d",&c);
        printf("Enter the exponent of %d term\n",i);
        scanf("%d",&e);
        new->coeff=c;
        new->exp=e;
        new->link=NULL;
        if(head==NULL)
        {
            head=new;;
            ptr=new;
        }
        else
        {
            ptr->link=new;
            ptr=new;
        }

    }
    return head;
}


struct poly*addpoly(struct poly*poly1,struct poly*poly2)
{
    struct poly*head1=NULL;
    p1=poly1;
    p2=poly2;
    p3=head1;
    while(p1!=NULL && p2!=NULL)
    {
         new=(struct poly*)malloc(sizeof(struct poly));
         new->link=NULL;
        if(p1->exp==p2->exp)
        {
            
            new->coeff=p1->coeff+p2->coeff;
            new->exp=p1->exp;
            p1=p1->link;
            p2=p2->link;
        }
        else if(p1->exp>p2->exp)
        {
            new->coeff=p1->coeff;
            new->exp=p1->exp;
            p1=p1->link;
           
        }
        else
        {
            new->coeff=p2->coeff;
            new->exp=p2->exp;
            p2=p2->link;
        }
        if(head1==NULL)
        {
            head1=new;
            p3=new;
        }
        else
        {
            p3->link=new;
            p3=new;
        }
    }

    while(p1!=NULL)
    {
        new=(struct poly*)malloc(sizeof(struct poly));
        new->coeff=p1->coeff;
        new->exp=p1->exp;
        new->link=NULL;
        p1=p1->link;
        p3->link=new;
        p3=new;
    }
    while(p2!=NULL)
    {
        new=(struct poly*)malloc(sizeof(struct poly));
        new->coeff=p2->coeff;
        new->exp=p2->exp;
        new->link=NULL;
        p2=p2->link;
        p3->link=new;
        p3=new;
    }
    return head1;

   
}

void display(struct poly*head1)
{
    if(head1!= NULL)
    {
        printf("The polynomial is\n");
        ptr=head1;
        while(ptr->link!=NULL)
        {
            printf("%dx^%d+",ptr->coeff,ptr->exp);
            ptr=ptr->link;
        }
        if(ptr->exp==0)
        {
            printf("%d",ptr->coeff);
        }
        else if(ptr->exp==1)
        {
            printf("%dx",ptr->coeff);
        }
        else
        {
            printf("%dx%d",ptr->coeff,ptr->exp);
        }
    }
    printf("\n");
}

void main()
{
    struct poly*p1,*p2,*p3;

    p1=readpoly();
    display(p1);
    p2=readpoly();
    display(p2);
    p3=addpoly(p1,p2);
    printf("resultant\n");
    display(p3);

}


