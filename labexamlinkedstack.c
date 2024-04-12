#include<stdio.h>
#include<stdlib.h>
void push(int item);
void pop();
void display();
int item,choice;
struct node
{
    int data;
    struct node*link;
};
struct node *top=NULL,*new,*temp;

void main()
{
    int n;
    printf("Stack using LL\n");
    do
    {
    
        printf("1:push\n2:pop\n3:display\n");
        printf("enter ur choice\n");
        scanf("%d",&n);
            switch(n)
            {
                case 1:printf("enter the item to be pushed\n");
                        scanf("%d",&item);
                        push(item);
                        break;
                case 2:pop();
                        break;
                case 3:display();
                        break;
                default:printf("enter valid option\n");
                        break;
            }
            printf("do u want to continue\n...if yess press 4\n");
            scanf("%d",&choice);

        }while(choice==4);
    
}

void push(int item)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=NULL;
    if(top==NULL)
    {
        top=new;
    }
    else
    {
        new->link=top;
        top=new;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("stack is empty\n");

    }
    else
    {
        temp=top;
        printf("The popped element is %d",temp->data);
        if(temp->link==NULL)
        {
            top=NULL;
            free(temp);
        }
        else
        {
            top=temp->link;
            free(temp);
        }
    }
}

void display()
{
    if(top==NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->link;
        }
    }
}