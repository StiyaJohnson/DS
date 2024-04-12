#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int arr[MAX],front,fpos,frear,rear,temp,i,item,del_item;
void enqueuerear();
void enqueuefront();
void dequeuerear();
void dequeuefront();
void display();
int op,choice;
void main()
{
    printf("1:enqueue rear\n2:dequeue front\n3:enqueue front\n4:dequeue rear\n");
    do
    {
        printf("enter the operation u need to perform\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:enqueuerear();
                    break;
            case 2:dequeuefront();
                    break;
            case 3:enqueuefront();
                    break;
            case 4:dequeuerear();
                    break;
            case 5:display();
                    break;
            case 6:break;
        }

        printf("\ndo u want to continue....if yes press 7\n");
        scanf("%d",&choice);
    }while(choice==7);
}


void enqueuerear()
{
    printf("enter the element u need to insert\n");
    scanf("%d",&item);
    if(front==(rear+1)%MAX)
    {
        printf("insertion not possible....queue is full\n");
    }
    else        //insertion possible
    {
        if(front==-1)       //queue is empty
        {
            front=rear=0;
            arr[rear]=item;
        }
        else    //normal insertion
        {
            rear=(front+1)%MAX;
            arr[rear]=item;
        }
    }
}


void dequeuefront()
{
    if(front==-1)       //queue is empty
    {
        printf("deletion not possible....since queue is empty\n.");
    }
    else        //deletion possible
    {
        del_item=arr[front];
        printf("The deleted item is %d",del_item);
        if(front==rear)     //only single elemnt exists
        {
            front=rear=-1;
        }
        else        //Nnormal deletion
        {
            front=(front+1)%MAX;
        }
        
    }
}


void enqueuefront()
{
    printf("enter the element u need to insert\n");
    scanf("%d",&item);
    if(front==-1)       //empty queue
    {
        front=rear=0;
        arr[front]=item;
    }
    else
    {
    if(front==0)        //extreme left
    {
        temp=MAX-1;
    }
    else
    {
        temp=front-1;
    }
    if(temp==rear)
    {
        printf("queue is full\n");
    }
    else
    {
        front=temp;
        arr[front]=item;
    }
    }

}


void dequeuerear()
{
    if(rear==-1)   //deletion not possible
    {
        printf("queue is empty\n");
    }
    else    //deletion is possible
    {
        del_item=arr[rear];
        printf("the deleted item is %d",del_item);
        if(front==rear)     //single element
        {
            front=rear=-1;
        }
        else
        {
            if(rear==0) //extreme left
            {
                rear=MAX-1;
            }
            else
            {
                rear=rear-1;
            }
        }        
    }
}



void display()
{
    fpos=front;
    frear=rear;
    if(fpos==-1)
    {
        printf("no elemnets\n");
    }
    else
    {
        printf("queue elements are\n");
        if(fpos<=frear)
        {
            while(fpos<=frear)
            {
                printf("Q[%d]=%d\t",fpos,arr[fpos]);
                fpos++;
            }

        }
        else
        {
            while(fpos<=MAX-1)
            {
                printf("Q[%d]=%d",fpos,arr[fpos]);
                fpos++;
            }
            fpos=0;
            while(fpos<=frear)
            {
                printf("Q[%d]=%d",fpos,arr[fpos]);
                fpos++;
            }
        }
    }

}




