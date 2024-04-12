/*QUEUE USING LINKED LIST*/
#include<stdio.h>
#include<stdlib.h>
int item;
void enqueue(int item);
void dequeue();
void display();
struct node
{
    int data;
    struct node*link;
};
struct node*front=NULL,*rear=NULL,*temp,*new,*ptr;

void main()
{
        int n,option;
        printf("Queue using LL\n");
        do
        {
        printf("1--enqueue\n2--dequeue\n3--display\n");
        printf("Enter your choice\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("Enter the item to be inserted\n");
                   scanf("%d",&item);
                   enqueue(item);
                    break;
            case 2: dequeue();
                    break;
            case 3:display();
                    break;
            default:printf("invalid");
                    break;
        }
        printf("\nDo u want to continue.....if yes press 1 \n");
        scanf("%d",&option);
    }while(option==1);
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
                printf("Queue is empty");
        }
        else
        {
            ptr=front;
            printf("The deleted item is %d",ptr->data);
            if(ptr->link==NULL)
            {
                
                 rear=front=NULL;
                 free(ptr);
            }
            else
            {
               ptr=front;
                front=front->link;
                free(ptr);
            }
        }
}

void display()
{
        if(front==NULL && rear==NULL)
        {
                printf("queue is empty");
        }
        else
        {
                 printf("The items in the LL are");
                ptr=front;
                while(ptr!=NULL)
                 {
                           
                        printf("%d\t",ptr->data);
                        ptr=ptr->link;
                }
                
        }
}















































/*SAMPLE OUTPUT
Queue using LL
1--enqueue
2--dequeue
3--display
Enter your choice
1
Enter the item to be inserted
10

Do u want to continue.....if yes press 1 
1
1--enqueue
2--dequeue
3--display
Enter your choice
2
The deleted item is 10
Do u want to continue.....if yes press 1 
1
1--enqueue
2--dequeue
3--display
Enter your choice
3
queue is empty
Do u want to continue.....if yes press 1 
1
1--enqueue
2--dequeue
3--display
Enter your choice
2
Queue is empty
Do u want to continue.....if yes press 1 
*/