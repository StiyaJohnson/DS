#include<stdio.h>
#include<stdlib.h>
int item;
void push(int item);
void pop();
void display();
struct node
{
    int data;
    struct node*link;
};
struct node*top=NULL,*new,*temp,*ptr;

void main()
{
        int n,option;
        printf("Stack using LL\n");
        do
        {
        printf("1--push\n2--pop\n3--display\n");
        printf("Enter your choice\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("Enter the item to be pushed\n");
                   scanf("%d",&item);
                   push(item);
                    break;
            case 2: pop();
                    break;
            case 3:display();
                    break;
            default:printf("invalid");
                    break;
        }
        printf("Do u want to continue.....if yes press 1 \n");
        scanf("%d",&option);
    }while(option==1);
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
                printf("Stack is empty");
        }
        else
        {
            temp=top;
            printf("The deleted item is %d",temp->data);
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
                printf("Stack is empty");
        }
        else
        {
                 printf("The items in the LL are");
                ptr=top;
                while(ptr!=NULL)
                 {
                           
                        printf("%d\t",ptr->data);
                        ptr=ptr->link;
                }
                
        }
}