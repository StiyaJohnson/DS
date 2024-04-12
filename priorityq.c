#include<stdio.h>

void enqueue(int item,int prior);
void dequeue();
void display();
int i,size,choice,op,item,d,prior,hoice;
int front=-1,rear=-1;

struct pq
{
    int item,priority;
}queue[5];

void main()
{
    printf("priority queue operation\n");
    printf("enter size\n");
    scanf("%d",&size);
    do
    {
    
    printf("1:enqueue\n2:dequeue\n3:display\n");
    printf("enter the operation u need to perform\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:printf("enter the item u need to enter and priority\n");
                scanf("%d%d",&item,&prior);
                enqueue(item,prior);
                break;
        case 2:dequeue();
                break;
               
        case 3:display();
                break;
    }

    printf("\ndo u want to continue...if yes press 1 to continue\n");
    scanf("%d",&choice);
    }while(choice==1);

}


void enqueue(int item,int prior)
{
    int loc;
    if(front==0 && rear==size-1)
    {
        printf("INSERTION not posssible....queueu is full\n ");
    }
     
    
        else if(front==-1)            //insertion posiible
        {
            front=0;
            rear=0;
            queue[rear].item=item;
            queue[rear].priority=prior;
        }
        
        
        else  
        {
            if(rear==size-1)
             {
                for(i=front;i<=rear;i++)    //shifting to left
                {
                    queue[i-1]=queue[i];
                    front=front-1;
                    rear=rear-1;
                }
             }
             
            for(i=rear;i>=front;i--)        //comparing prioriies
            {
                if(queue[i].priority<prior)
                {
                    break;
                }
            }   
                loc=i+1;
                for(i=rear;i>=loc;i--)
                {
                    queue[i+1]=queue[i];
                }
                queue[loc].item=item;
                queue[loc].priority=prior;
                rear++;
            
        }
    

}


void dequeue()
{
    if(front==-1)
    {
        printf("queue is empty\n");
    }
    else if(front==rear)        //single elemnt
    {
        printf("The deleted item is %d",queue[front].item);
        front=rear=-1;
    }
    else        //normal deletion
    {
        printf("The deleted item is %d",queue[front].item);
        front=front+1;
    }
}

void display()
{
    if(front==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i].item);
        }
    }
}