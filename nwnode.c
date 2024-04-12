#include<stdio.h>
#include<stdlib.h>
int op,n,item,pos,i,del_item;
void insert();
void insertbeg();
void insertend();
void insertpos();
void delbeg();
void delend();
void delpos();
void display();
struct node
{
int data;
struct node*link;
}*head,*temp,*temp1,*ptr,*ptr1,*new,*c;
void main()
{
do
{
    printf("1--insertbeg\t2--insertend\t3--insertpos\t4--delbeg\t5--delend\t6--delpos\t7--display\n");
    printf("Enter the operation to be performed\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:insertbeg();
                break;
        case 2:insertend();
                break;
        case 3:insertpos();
                break;
        case 4:delbeg();
                break;
        case 5:delend();
                break;
        case 6:delpos();
                break;
        case 7:display();
                break;
    }
        printf("\nDo you want to continue\n");
        scanf("%d",&n);
}while(n==1);

}
void insert()
{
    printf("Enter the item to be inserted\n");
    scanf("%d",&item);
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=NULL;
}
void insertbeg()
{
    insert();
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        ptr=head;
        new->link=ptr;
        head=new;
    }
}
void insertend()
{
    insert();
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
void insertpos()
{
        insert();
        printf("Enter the position\n");
        scanf("%d",&pos);
       
        if(pos==1)
        {
            insertbeg();
        }
        else
        {
            ptr=head;
            for(i=1;i<pos-1;i++)
            {
               
                ptr=ptr->link;
            }
                new->link=ptr->link;
                ptr->link=new;

        }
}

void delbeg()
{
if(head==NULL)
    {
            printf("Nothing to be deleted....empty LL");
    }
    else
    {
        if(head->link==NULL)
        {
                temp=head;
                del_item=temp->data;
                printf("The deleted item is %d",del_item);
                head=NULL;
                free(temp);

        }
        else
        {
                temp=head;
                del_item=temp->data;
                printf("The deleted item is %d",del_item);
                head=temp->link;
                free(temp);
        }
    }
}
void delend()
{
        if(head==NULL)
        {
            printf("Empty LL...nothing to delete");
        }
        else
        {
             if(head->link==NULL)
             {
                temp=head;
                del_item=temp->data;
                printf("The deleted item is %d",del_item);
                head=NULL;
                free(temp);

            }
            else
            {
                temp=head;
                while(temp->link!=NULL)
                {
                    temp1=temp;
                    temp=temp->link;

                }
                c=temp;
                c->link=NULL;
                del_item=c->data;
                printf("The deleted item is %d",del_item);
                free(temp);

            }
            
        }
}
void delpos()
{
     if(head==NULL)
        {
            printf("Empty LL...nothing to delete");
        }
     else
     {
            printf("Enter the position\n");
            scanf("%d",&pos);
            if(pos==1)
            {
                    delbeg();
            }
            else
            {
                ptr=head;
                for(i=1;i<pos-1;i++)
                {
                    ptr=ptr->link;
                }
                ptr1=ptr;
                printf("The deleted item is %d",ptr1->data);
                ptr->link=ptr1->link;
                free(ptr1);
            }
     }
}
void display()
{
    printf("The current LL is\n");
    ptr=head;
    while(ptr->link!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    printf("%d",ptr->data);

}
    




