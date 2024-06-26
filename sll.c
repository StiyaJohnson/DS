/*SINGLY LINKED LIST OPERATIONS*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
}*head,*new,*temp,*ptr,*ptr1;

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
	}
	else
	{
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
}

void insertpos()
{
	int pos,i;
	insert();
	printf("enter the position at which node is to be inserted:\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		if(head==NULL)
		{
			head=new;
		}
		else
		{
			new->link=head;
			head=new;
		}
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
	else
	{
		temp=head;
		printf("Deleted item is %d\n",temp->data);
		head=temp->link;
		free(temp);
	}
}

void delend()
{
	if(head==NULL)
	{
		printf("LL is empty!\n");
	}
	else
	{
		if(head->link==NULL)
		{
			temp=head;
			printf("Deleted item is %d\n",temp->data);
			head=NULL;
			free(temp);
		}
		else
		{
			ptr=head;
			while(ptr->link!=NULL)
			{
				ptr1=ptr;
				ptr=ptr->link;
			}
			temp=ptr;
			printf("Deleted item is %d\n",temp->data);
			ptr1->link=NULL;
			free(temp);
		}
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
			temp=head;
			printf("Deleted item is %d\n",temp->data);
			head=temp->link;
			free(temp);
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
		while(ptr->link!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->link;
		}
		printf("%d\n",ptr->data);
	}
}

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






























/*SAMPLE OUTPUT
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
1
enter the element to be inserted:
10
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
2
enter the element to be inserted:
20
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
7
Elements in the Linked List are: 10     20
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
3
enter the element to be inserted:
2
enter the position at which node is to be inserted:
2 
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
7
Elements in the Linked List are: 10     2       20
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
4
Deleted item is 10
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
5
Deleted item is 20
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
7
Elements in the Linked List are: 2
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
6
enter the position from which node is to deleted:
1
Deleted item is 2
do you want to continue?
if yes press 1
1
choose the operation to be performed:
1-insertbeg()
2-insertend()
3-insertpos()
4-delbeg()
5-delend()
6-delpos()
7-display()
7
Linked List is empty!
do you want to continue?
if yes press 1
*/
