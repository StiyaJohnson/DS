/*LINEAR QUEUE OPERATIONS*/
#include<stdio.h>
#define MAX 3
int queue[MAX],front=-1,rear=-1,i;
void enqueue(int ele);
int dequeue();
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
				e=1;
				break;
			case 2:dequeue();
				
				e=1;
				break;
			case 3:display();
				e=1;
				break;
			default:printf("Enter any valid option\n");
				e=1;
				break;
		}
	       }while(e==1);
     }
 void enqueue(int ele)
    {
	 
	 if(rear==MAX-1)
	    {
		printf("Inserion not possible....Queue is full\n");
	    }
	 else
	   {
		if(front==-1)
		  {
			front=0;
		  }
	     rear=rear+1;
	     queue[rear]=ele;
	  }
     }

 int dequeue()
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
		front=front+1;
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
	for(i=front;i<=rear;i++)
	  {
		printf("%d\t",queue[i]);
          }
	}
    }






  /*SAMPLE OUTPUT
  Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
1
enter the element
10

Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
1
enter the element
20

Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
3
The current queue is
10      20
Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
1
enter the element
20

Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
1
enter the element
30
Inserion not possible....Queue is full

Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
3
The current queue is
10      20      20
Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
2
The deleted item is 10
Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
3
The current queue is
20      20
Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
2
The deleted item is 20
Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
2
The deleted item is 20
Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
3
Queue is empty

Enter the operation to be used
1-ENQUEUE 2-DEQUEUE 3-DISPLAY
2
Queue is empty...nothing to be deleted
*/








		