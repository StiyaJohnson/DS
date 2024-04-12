#include<stdio.h>
#include<stdlib.h>
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
    struct node*next;
    struct node*prev;
};
    struct node*head,*tail,*new,*ptr,*n,*temp;
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
	new->prev=NULL;
    new->next=NULL;
}
void insertbeg()
{
    insert();
    if(head==NULL)
    {
        head=tail=new;
    }
    else
    {
        new->next=head;
        new->prev=NULL;
        head->prev=new;
        head=new;
    }
}
void insertend()
{
    insert();
    if(head=NULL)
    {
         head=tail=new;
    }
    else
    {
        tail->next=new;
        new->prev=tail;
       
        tail=new;
    }
}
void insertpos()
{
    int pos,item,i;
    printf("Enter the position do u need to enter the node\n");
    scanf("%d",&pos);
    
    if(pos==1)
    {
        insertbeg();
    }
    else
    {
        insert();
        ptr=head;
        for(i=1;i<pos-1;i++)
        {
           ptr=ptr->next; 
        }
        n=ptr->next;
        new->next=ptr->next;
        new->prev=ptr;
        n->prev=new;
        ptr->next=new;
    }
    
}
void delbeg()
{
    if(head==NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        if(head==tail)
        {
            temp=head;
            printf("The deleted item is %d",temp->data);
            head=tail=NULL;
            free(temp);
        }
        else
        {
            temp=head;
            printf("The deleted item is %d",temp->data);
            head=temp->next;
            head->prev=NULL;
            free(temp);                                                                                                                                                                                                                                                                                                                                                 
        }
    }
}
void delend()
{
    if(head==NULL)
    {
        printf("LL is empty\n");
    }

    else if(head==tail)
    {
        temp=head;
        printf("The deleted item is %d",temp->data);
        head=tail=NULL;
        free(temp);
    }
    else
    {
        temp=tail;
        tail=temp->prev;
        tail->next=NULL;
        printf("The deleted item is %d",temp->data);
        free(temp);
    }
}
void delpos()
{
    int pos,item,i;
    printf("Enter the position to be inserted\n");
    scanf("%d",&pos);
    printf("Enter the element to be inserted\n");
    scanf("%d",&item);
    if(pos==1)
    {
        delbeg();
    }
    else
    {
            temp=head;
            for(i=1;i<pos-1;i++)
            {
                
                temp=temp->next;
            }
            ptr=temp;
            printf("THe deleted item is %d",ptr->data);
            temp->next->prev=temp->prev;
            if(temp->next!=NULL)
            {
                temp->next->prev=temp->prev;
            }
            else
            {
                delend();
            }
            free(ptr);
    }
}
void display()
{
    if(head==NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        printf("The current LL is\n");
        ptr=head;
        while(ptr->next!=NULL)
        {
            printf("%d",ptr->data);
            ptr=ptr->next;
        }
        printf("%d\t",ptr->data);
    }
}

