#include <stdio.h>
#include <stdlib.h>
void insert();
void insertbeg();
void insertend();
void insertpos();
void delbeg();
void delend();
void delpos();
void display();


struct node
{
	int data;
	struct node *link;
};
	struct node*head,*new,*temp,*ptr,*ptr1,*temp1;
void main()
{
	int ch,op;
	do
	{
		printf("choose the operation to be performed:\n1-insertbeg()\n2-insertend()\n3-insertpos()\n4-delbeg()\n5-delend()\n6-delpos()\n7-display()\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insertbeg();
						break;
			case 2: insertend();
						break;
			case 3: insertpos();
						break;
			case 4: delbeg();
						break;
			case 5: delend();
						break;
			case 6: delpos();
						break;
			case 7: display();
						break;
			default: printf("invalid operation!\n");
		}
		printf("do you want to continue?\nif yes press 1\n");
		scanf("%d",&op);
	}while(op==1);
}

void insert()
{
	int item;
	printf("enter the element to be inserted:\n");
	scanf("%d",&item);
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->link=NULL;
}

void insertbeg()
{
	insert();
	if(head==NULL)
	{
		head=new;
		head->link=head;
	}
	else
	{
		ptr=head;
		while(ptr->link!=head)
		{
			ptr=ptr->link;
		}
		ptr->link=new;
		new->link=head;
		head=new;
	}
}

void insertend()
{
	insert();
	if(head==NULL)
	{
		head=new;
		head->link=head;
	}
	else
	{
		ptr=head;
		while(ptr->link!=head)
		{
			ptr=ptr->link;
		}
		ptr->link=new;
		new->link=head;
	}
}

void insertpos()
{
	int pos,i;
	insert();
	printf("enter the position at which node is to be inserted:\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		insertbeg();
	}
	else
	{
		ptr=head;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
		}
		new->link=ptr->link;
		ptr->link=new;
	}
}

void delbeg()
{
	if(head==NULL)
	{
		printf("LL is empty!\n");
	}
	else if(head->link==head)
	{
		temp=head;
		printf("Deleted item is %d\n",temp->data);
		head=NULL;
		free(temp);
	}
	else
	{	
		temp=head;
		printf("Deleted item is %d\n",temp->data);
		ptr=head;
		while(ptr->link!=head)
		{
			ptr=ptr->link;
		}
		ptr->link=head->link;
		head=head->link;
		free(temp);
	}
}

void delend()
{
	if(head==NULL)
	{
		printf("LL is empty!\n");
	}
	
	
		else if(head->link==head)
		{
			temp=head;
			printf("Deleted item is %d\n",temp->data);
			head=NULL;
			free(temp);
		}
		else
		{
			temp=head;
			while(temp->link!=head)
			{
				temp1=temp;
				temp=temp->link;
			}
				ptr=temp;
				printf("The deleted item is %d",ptr->data);
				temp1->link=head;
				free(temp);
			
			
		}
	}


void delpos()
{
	int pos,i;
	if(head==NULL)
	{
		printf("LL is empty!\n");
	}
	else
	{
		printf("enter the position from which node is to deleted:\n");
		scanf("%d",&pos);
		if(pos==1)
		{
			delbeg();
		}
		else
		{
			ptr=head;
			for(i=1;i<pos-1;i++)
			{
				ptr=ptr->link;
			}
			temp=ptr->link;
			printf("Deleted item is %d\n",temp->data);
			ptr->link=temp->link;
			free(temp);
		}
	}
}

void display()
{
	if(head==NULL)
	{
		printf("Linked List is empty!\n");
	}
	else
	{
		ptr=head;
		printf("Elements in the Linked List are: ");
		while(ptr->link!=head)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->link;
		}
		printf("%d\n",ptr->data);
	}
}

