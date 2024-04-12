#include<stdio.h>
#include<stdlib.h>
void insert_beg();
void insert_end();
void insert_pos();
void del_beg();
void del_end();
void del_pos();
void display();
int op,choice,pos,i,item,del_item;
struct node
{
    int data;
    struct node*link;
};
    struct node*head=NULL,*new,*ptr,*temp,*temp1;

void main()
{
    printf("1:insertion at beginning\n2:insertion at end\n3:insertion at part pos\n4:del at beg\n5:del at end\n6:del at part ps\n");
    do
    {
   
    
    printf("enter the operation u need to perform\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:insert_beg();
                break;;
        case 2:insert_end();
                break;
        case 3:insert_pos();
                break;   
        case 4:del_beg();
                break;
        case 5:del_end();
                break;
         case 6:del_pos();

                break;
        case 7:display();
                break;

        case 8:break;

    }
    printf("\ndo u want to continue...if yes press 9\n");
    scanf("%d",&choice);
    }while(choice==9);

}

void insert()
{
    printf("enter the element to be inserted\n");
    scanf("%d",&item);
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=NULL;
}

void insert_beg()
{
    insert();
    if(head==NULL)      //empty ll
    {
        head=new;

    }
    else
    {
       new->link=head;
       head=new;
    }
}

void insert_end()
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

void insert_pos()
{
    insert();
    printf("enter the position to be entered\n");
    scanf("%d",&pos);
    if(pos==1)
    {
        insert_beg();
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

void del_beg()
{
    if(head== NULL)
    {
        printf("deletion not possi...ll is empty\n");
    }
    else
    {
        temp=head;
        del_item=temp->data;
        printf("%d is the deleted item",del_item);
        head=temp->link;
        free(temp);
    }
}


void del_end()
{
    if(head== NULL)
    {
        printf("deletion not possi...ll is empty\n");
    }
    else
    {
        if(head->link==NULL)
        {
            temp=head;
            printf("the deleted item is %d",temp->data);
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
        ptr=temp;
        printf("the deleted item is %d",ptr->data);
        temp1->link=NULL;
        free(ptr);
        }


    }
}

void del_pos()
{
    if(head== NULL)
    {
        printf("deletion not possi...ll is empty\n");
    }
    else
    {
        printf("enter the position to be deleted\n");
        scanf("%d",&pos);
        if(pos==1)
        {
            del_beg();
        }
        else
        {
            ptr=head;
            for(i=1;i<pos-1;i++)
            {
                ptr=ptr->link;
            }
            temp=ptr->link;
            ptr->link=temp->link;
            printf("the deleted item is %d",temp->data);
            free(temp);
        }
    }
}

void display()
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
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
         printf("%d\t",ptr->data);
    }
}