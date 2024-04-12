#include<stdio.h>
#include<stdlib.h>
void insert();
void lowest();


struct node
{
    int data;
    struct node*lptr,*rptr;
};
    struct node *root=NULL,*new,*parent,*ptr,*ptr1;
    void preorder(struct node*ptr);
    void display();
  // void preorder(struct node*ptr);
    int item;
void main()
{
    int item,n,op;
   // ptr=root;
    do
    {
        printf("1:insert\t2:search lowest\t3:display preorder\n");
        printf("enter the operation u need to perform\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:insert();
                    break;
            case 2:lowest(root);
                    break; 

            case 3: display();
           
                    break;         
            default:printf("invalid");
        }
    printf("do u want to continue...if yess press1\n");
    scanf("%d",&n);
     } while(n==1);
}

void insert()
{
    struct node*ptr;
    printf("enter the element to be inserted\n");
    scanf("%d",&item);
    new=(struct node*)malloc(sizeof(struct node));
    new->lptr=NULL;
    new->rptr=NULL;
   ptr=root;
    if(ptr==NULL)
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
        if(item<parent->data)
        {
            parent->lptr=new;
        }    
        else
        {
            parent->rptr=new;
        }
    }
    


}


void lowest(struct node*ptr)
{
    ptr=root;
    
        if(ptr==NULL)
        {
            printf("tree is empty\n");
        }
        else
        {
    
         while(ptr!=NULL)
        {
            ptr=ptr->lptr;
         }
            ptr1=ptr;
            printf("the smallest element is %d",ptr1->data);
        }
    
}


void display()
{
    if(root==NULL)
    {
        printf("ll is empty\n");
    }
    else
    {
        printf("preorder representation is\n");
        preorder(root);
        
    }
    printf("\n");
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
