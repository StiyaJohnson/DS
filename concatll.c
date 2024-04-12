#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};
    struct node*head1=NULL,*head2=NULL,*ptr,*ptr1,*new,*temp,*head,*l1;
    struct node* insertend();
void concatinate(struct node*head1,struct node*head2);
void insert();
void display(struct node*head1);
int n1,n2,i,item;
void main()
{

    struct node *p,*q;
    printf("how many elements u need to enter\n");
    scanf("%d",&n1);
    for(i=1;i<=n1;i++)
    {
    head1=insertend();
    }
    display(head1);
     printf("\nhow many elements u need to enter\n");
    scanf("%d",&n2);
    for(i=1;i<=n2;i++)
    {
    head2=insertend();
    }
   
    display(head2);
    printf("\nthe concatinated ll is\n");
    concatinate(head1,head2);
    display(head1);
}
void insert()
{
    printf("enter the data to be inserted\n");
    scanf("%d",&item);
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=NULL;
}

struct node* insertend()
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
    return head;
}

void concatinate(struct node*head1,struct node*head2)
{
if(head1==NULL)
{
    head1=head2;
}
    return;

    ptr1=head1;
   
    while(ptr1->link!=NULL)
    {
        ptr1=ptr1->link;
    }
   
   ptr1->link=head2;
   
}

void display(struct node*head)
{
   
    if(head==NULL)
    {
        printf("ll is empty");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
    }
}

