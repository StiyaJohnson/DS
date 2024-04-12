#include<stdio.h>
#include<stdlib.h>
void enqueue(int item);
void dequeue();
void display();
int item,choice;
struct node
{
    int data;
    struct node*link;
};
struct node *front=NULL,*rear=NULL,*new,*temp;

void main()
{
    int n;
    printf("queue using LL\n");
    do
    {
    
        printf("1:enqueue\n2:dequeue\n3:display\n");
        printf("enter ur choice\n");
        scanf("%d",&n);
            switch(n)
            {
                case 1:printf("enter the item to be pushed\n");
                        scanf("%d",&item);
                        enqueue(item);
                        break;
                case 2:dequeue();
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


void enqueue(int item)
{

    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=NULL;
    if(front==NULL && rear==NULL)
    {
       front=rear=new;
    }
    else
    {
        
        rear->link=new;
        rear=new;
    }
}


void dequeue()
{
    if(front==NULL && rear==NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        temp=front;
        printf("The deleted element is %d",front->data);
        if(temp->link==NULL)
        {
            front=rear=NULL;
            free(temp);
        }
        else
        {
        front=front->link;
        free(temp);
        }
    }

}


void display()
{
    if(front==NULL && rear==NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        temp=front;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
    }
}