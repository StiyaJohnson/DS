#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node* read(int item);
int op,i,item,a;
struct node
{
    int data;
    struct node*prev,*next;
};
  struct node*head=NULL,*ptr,*new,*tail=NULL;
void main()
{
    printf("Enter the no of terms in the list\n");
    scanf("%d",&n);
    printf("Enter the elements to the list\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        head=read(a);
    }
    printf("Original list\t:");
    display (head);
    printf("Enter the element to be deleted\n");
    scanf("%d",&e);
    if(head->data==e)
    {
        printf("The element already present in front\n");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            while(ptr->data!=e)
            {
                ptr=ptr->next;
            }
            temp=ptr;
            ptr->prev->next=ptr->next;
            if(ptr->next!=NULL)
            {
                ptr->next->prev=ptr->prev;
            }

        }
    }
       

struct node* read(int item);
{
             new=(struct node*)malloc(sizeof(struct node));
            printf("Enter the data u need to enter\n");
            scanf("%d",&item);
            new->prev=NULL;
            new->data=item;
            new->next=NULL;
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
            return head;
}
void display(struct node *head)
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}