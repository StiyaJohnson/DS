#include<stdio.h>
#include<stdlib.h>
void insert();
int n,item;
struct node
{
    int data;
    struct node*link;
};
    struct node*head=NULL,*new,*ptr1,*ptr;
void main()
{
    int op;
    do
    {
        printf("ENTER THE OPERATION....\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:insert();
                    break;
            default:printf("invalid\n");
                    break;          
        }
        printf("do u want to continue....if yess press 1\n");
        scanf("%d",&n);

    }while(n==1);
    printf("The reversed sll is\n");
    while(head->link!=NULL)
    {
    ptr=head;
    while(ptr->link!=NULL)
    {
        ptr1=ptr;
        ptr=ptr->link;
    }
    printf("%d ",ptr->data);
    ptr1->link=NULL;
    }
    printf("%d ",head->data);    
}

void insert()
{
    printf("Enter the data u need to insert\n");
    scanf("%d",&item);
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=NULL;
   if(head==NULL)
    {
        head=new;
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;
    }
}