#include<stdio.h>
#include<stdlib.h>
void insert();
void insert_beg();
void insert_end();
void insert_pos();
void del_beg();
void del_end();
void del_pos();
void display();
struct node
{
    int data;
    struct node*prev,*next;
}*head,*ptr,*new,*tail;

void insert()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted\n");
    scanf("%d",&item);
    new->data=item;
    new->prev=NULL;
    new->next=NULL;
}

void insert_beg()
{
    insert();
    if(head==NULL)
    {
        head=tail=new;
    }
    else
    {
        head->prev=new;
        new->next=head;
        head=new;
    }
}

void insert_end()
{
    insert();
    if(head==NULL)
    {
        head=tail=new;
    }
    else
    {
        tail->next=new;
        new->prev=tail;
        tail=new;
    }
}

void insert_pos()
{
    insert();
    printf("Enter the position\n");
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
            ptr=ptr->next;
        }
        ptr1=ptr;
        ptr1->next=new;
        new->prev=ptr1;
        new->next=ptr1->next;
        ptr1->next->prev=new;
    }
}