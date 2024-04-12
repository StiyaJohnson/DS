#include<stdio.h>
#include<stdlib.h>
int t1,i,t2,c,e;
struct node*readpoly();
struct node* addpoly(struct node*phead,struct node*rhead); 

void display(struct node*head);
struct node
{
    int coeff;
    int exp;
    struct node*link;
};
    struct node*phead,*qhead,*rhead,*head1,*ptr,*ptr1,*new;


    struct node*readpoly()
    {
        struct node*head=NULL;
        printf("enter the no:of terms of  poly:\n");
        scanf("%d",&t1);
        for(i=1;i<=t1;i++)
        {
            new=(struct node*)malloc(sizeof(struct node));
            printf("enter the coefficient of %d term:\n",i);
            scanf("%d",&c);
            printf("enter the exponent of %d term:\n",i);
            scanf("%d",&e);
            new->coeff=c;
            new->exp=e;
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
        return head;
    }


    struct node* addpoly(struct node*phead,struct node*rhead)
    {
        head1=NULL;
        struct node*p1,*p2;
        p1=phead;
        p2=rhead;
        while(p1!=NULL && p2!=NULL)
        {
            new=(struct node*)malloc(sizeof(struct node));
            new->link==NULL;
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
                ptr1=new;
            }
            else
            {
                ptr1->link=new;
                ptr1=new;
            }
        }
        while(p1!=NULL)
        {
            new=(struct node*)malloc(sizeof(struct node));
            new->coeff=p1->coeff;
            new->exp=p1->exp;
            new->link=NULL;
            p1=p1->link;
            ptr1->link=new;
            ptr1=new;
        }
        while(p2!=NULL)
        {
            new=(struct node*)malloc(sizeof(struct node));
            new->coeff=p2->coeff;
            new->exp=p2->exp;
            new->link=NULL;
            p2=p2->link;
            ptr1->link=new;
            ptr1=new;
        }
        return head1;
    }





    void display(struct node*head)
    {
        if(head==NULL)
        {
            printf("ll is empty\n");
        }
        else
        {
            ptr=head;
            while(ptr->link!=NULL)
            {
                printf("%dx^%d+",ptr->coeff,ptr->exp);
                ptr=ptr->link;
            }
            if(ptr->exp==1)
            {
                printf("%dx",ptr->coeff);
            }
           else if(ptr->exp==0)
            {
                printf("%d",ptr->coeff);
            }
            else
            {
                printf("%dx^%d",ptr->coeff,ptr->exp);
            }
        }
    }

    void main()
    {
        struct node *phead,*qhead,*rhead;
        phead=readpoly();
        display(phead);
        qhead=readpoly();
        display(qhead);
        rhead=addpoly(phead,qhead);
        printf("the result is:\n");
        display(rhead);

    }