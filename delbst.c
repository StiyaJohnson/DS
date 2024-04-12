#include<stdio.h>
#include<stdlib.h>
void ins();
struct node*inorder_succ(struct node*ptr);
void inorder(struct node*ptr);
void delbst();
void preorder(struct node*ptr);
void postorder(struct node*ptr);
struct node* search(struct node*ptr,int key);
void display(struct node*root);
int item,op,key,o;
struct node
{
    int data;
    struct node*lptr,*rptr;
}*new,*ptr,*root,*parent,*s,*inorder_succ_ptr;



void ins()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted\n");
    scanf("%d",&item);
    new->data=item;
    new->lptr=NULL;
    new->rptr=NULL;
    ptr=root;
    if(root==NULL)
    {
        root=new;
    }
    else
    {
        while(ptr!=NULL)
        {
            parent=ptr;
            if(item<ptr->data)
            {
                ptr=ptr->lptr;
            }
            else
            {
                ptr=ptr->rptr;
            }
        }
        if(parent->data>item)
        {
            parent->lptr=new;
        }    
        else
        {
            parent->rptr=new;
        }
    }

}

struct node* search(struct node*ptr,int key)
{
    while(ptr!=NULL)
    {
         if(ptr->data==key)
         {
            printf("element found\n");
            break;
        }
         else if (ptr->data<key)
         {
             ptr=ptr->rptr;
             search(ptr,key);
        }
        else
        {
            ptr=ptr->lptr;
            search(ptr,key);

        }
    }
    if(ptr==NULL)
    {
        printf("element not found\n");
            }
}  

void del_bst()
{
    int flag=0,del;
    ptr=root;
    printf("Enter the node which is to be deleted\n");
    scanf("%d",&del);
    while(ptr!=NULL)
    {
        if(del==ptr->data)
        {
            flag=1;
        }
       else if(del<ptr->data)
       {
            parent=ptr;
            ptr=ptr->lptr;
       }
       else
       {
            parent=ptr;
            ptr=ptr->rptr;
       }
        
    }

    if(flag==0)
    {
        printf("Deletion not possible\n");
    }
    else
    {
        if((ptr->lptr==NULL && ptr->rptr==NULL))//no children//
        {
            if(parent->lptr==ptr)//parent's left child is to be deleted//
            {
                parent->lptr==NULL;
            }
            else
            {
                parent->rptr==NULL;
            }

         }
         else if(ptr->lptr!=NULL && ptr->rptr!=NULL)//has 2 childre//
        {
            inorder_succ_ptr=inorder_succ(ptr);
            item=inorder_succ_ptr->data;
            del_bst(inorder_succ_ptr->data);
            ptr->data=item;
        }
        else//has only 1 child//
        {
            if(parent->lptr==ptr)
            {
                if(ptr->lptr==NULL)
                {
                    parent->lptr=ptr->rptr;
                }
                else
                {
                    parent->lptr=ptr->lptr;
                }
            }
            else//parent's rigtht is the node to be deleted node//
            {
                if(ptr->lptr==NULL)
                {
                    parent->rptr=ptr->rptr;
                }
                else
                {
                    parent->rptr=ptr->lptr;
                }
            }
        }
    }
} 



struct node*inorder_succ(struct node*ptr)
{
    ptr=ptr->rptr;
    while(ptr->lptr!=NULL)
    {
        ptr=ptr->lptr;
    }
    return ptr;
}

void preorder(struct node*ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        printf("%d\t",ptr->data);
        preorder(ptr->lptr);
        preorder(ptr->rptr);
    }


}

void inorder(struct node*ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        inorder(ptr->lptr);
        printf("%d\t",ptr->data);
        inorder(ptr->rptr);
    }
} 


void postorder(struct node*ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        postorder(ptr->lptr);
        postorder(ptr->rptr);
        printf("%d\t",ptr->data);
    }
} 


void display(struct node *root)
{
    ptr=root;
    if(ptr==NULL)
    {
        printf("Tree ie empty\n");
    }
    else
    {
        printf("\npreorder representation is\n");
        preorder(ptr);
        printf("\nInorder representation is\n");
        inorder(ptr);
        printf("\nPostorder representation is\n");
        postorder(ptr);
    }
}

void main()
{
	int ch,val;
	do
	{
		printf("\nEnter 1:Insert 2:Delete 3:Search 4:Display 5:Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ins();
			       break;
			case 2:del_bst();
			       break;
			case 3:printf("Enter the value of node to search : ");
			       scanf("%d",&val);
			       search(root,val);
			       break;
			case 4:display(root);
			       break;
			case 5:break;
			default:printf("Invalid input\n");
		}
	}while(ch<5);
}




