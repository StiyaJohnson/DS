/*CIRCULAR QUEUE OPERATIONS*/
#include<stdio.h>
#define MAX 2
int queue[MAX],front=-1,rear=-1,i;
void enqueue(int ele);
void dequeue();
void display();
int main()
  {
		int option,e,d,ele;
		do
	     {
		printf("\nEnter the operation to be used\n");
		printf("1-ENQUEUE 2-DEQUEUE 3-DISPLAY\n");
		scanf("%d",&option);
		switch(option)
			{
			case 1:printf("enter the element\n");
				scanf("%d",&ele);
				enqueue(ele);
				break;
			case 2:dequeue();
				break;
			case 3:display();
				break;
			default:printf("invalid choice\n");
				break;
		}
            printf("\n");
            printf("Do you want to continue\n");
            printf("1--Yes\t2--No\n");
            scanf("%d",&e);
	       }while(e==1);
     }
 void enqueue(int ele)
    {
	 
	 if(front==(rear+1)%MAX)
	    {
		printf("Inserion not possible....Queue is full\n");
	    }
	 else
	   {
		if(front==-1)
		  {
			front=0;
			rear=0;
			queue[rear]=ele;
		  }
		else
		{
	     		rear=(rear+1)%MAX;
	     		queue[rear]=ele;
	 	 }
 	    }
     }

 void dequeue()
   {
	int del_item;
	if(front==-1)
	  {
		printf("Queue is empty...nothing to be deleted\n");
	  }
	else
	  {
		del_item=queue[front];
		printf("The deleted item is %d",del_item);

		if(front==rear)
		   {
			front=-1;
			rear=-1;
		   }
		else
		  {
			front=(front+1)%MAX;
		  }
		
	}
 }
  void display()
    {
	if(front==-1)
	  {
		printf("Queue is empty\n");
	  }
	else
	 {
 		printf("The current queue is\n");
		i=front;
		while(i!=rear)
		{
			printf("%d ",queue[i]);
			i=(i+1)%MAX;
		}
	  
		printf("%d\t",queue[rear]);
          }
	}






    /*SAMPLE OUTPUT
    Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
1
enter the element
50

Do you want to continue
1--Yes  2--No
1

Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
1
enter the element
40

Do you want to continue
1--Yes  2--No
1

Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
3
The current queue is
50 40
Do you want to continue
1--Yes  2--No
1

Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
1
enter the element
70
Inserion not possible....Queue is full

Do you want to continue
1--Yes  2--No
1

Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
2
The deleted item is 50
Do you want to continue
1--Yes  2--No
*/
    
		
					