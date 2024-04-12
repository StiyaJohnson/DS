#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
};
    struct node*head=NULL,*ptr,*new,*ptr1,*ptr2;
    void display();
    int small(struct node*head);
    int large(struct node*head);
    void seclargest(int largest,int smallest,struct node*head);
    
int item,choice,largest,second,smallest;
void main()
{
    do
    {
        printf("enter the data to be inserted:\n");
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
    printf("\nthe entered elements are\n");
    display();
    smallest=small(head);
    printf("\nThe smallest element is:%d\n",smallest);
    largest=large(head);
      printf("\nThe largest element is:%d\n",largest);
     seclargest( largest,smallest,head);
    
}

int small(struct node*head)
{
     ptr=head;
        smallest=head->data;
        while(ptr!=NULL)
        {
            if(smallest>ptr->data)
            {
                smallest=ptr->data;
            }
            ptr=ptr->link;
        }
        return smallest;
     //   printf("\nThe smallest element is:%d\n",smallest);
}

int large(struct node*head)
{

        ptr=head;
        largest=head->data;
        while(ptr!=NULL)
        {
            if(largest<ptr->data)
            {
                largest=ptr->data;
            }
            ptr=ptr->link;
        }
        return largest;
      //  printf("\nThe largest element is:%d\n",largest);

}    

void seclargest(int largest,int smallest,struct node*head)
{
    ptr=head;
    int large,second;
    large=largest;
    second=smallest;
    while(ptr!=NULL)
    {
        if(ptr->data>large)
        {
            second=large;
            large=ptr->data;
        }
        else if(ptr->data>second && ptr->data!=largest)
        {
            second=ptr->data;
        }
        ptr=ptr->link;
    }

    printf("\nthe secondlargest element is %d",second);
}
        



void display()
{
    struct node*ptr;
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
        printf("\n");
    }
}