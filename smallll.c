#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
};
    struct node*head=NULL,*ptr,*new;
    void smaller(struct node*head);
    void display();
int item,choice,small;
void main()
{
    do
    {
        printf("enter the data to be inerted:\n");
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

        printf("\ndo u want to add elements..if yes press 1\n");
        scanf("%d",&choice);

    }while(choice==1);
    display();
    smaller(head);
}

void smaller(struct node*head)
{
    if(head==NULL)
    {
        printf("no elements...so impossible to find smallest element\n");

    }
    else
    {
        ptr=head;
        small=head->data;
        while(ptr!=NULL)
        {
            if(small>ptr->data)
            {
                small=ptr->data;
            }
            ptr=ptr->link;
        }

        printf("\nThe smallest element is:%d\n",small);
    }
}


void display()
{
    if(head==NULL)
    {
        printf("the ll is empty\n");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
    }
}