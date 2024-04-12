#include<stdio.h>
#include<stdlib.h>
void ins();
struct node* search(struct node*ptr,int key);
int item,op,key,o;
struct node
{
    int data;
    struct node*lptr,*rptr;
}*new,*ptr,*root,*parent,*s;
void main()
{
    do
   {
        ins();
        printf("Do you want to continue...if yes press 1\n");
        scanf("%d",&op);
     }   while(op==1);
        do
       {
        printf("Enter the key to be searched\n");
        scanf("%d",&key);
        s= search(root,key);
        if(s==NULL)
        {
            printf("element not found\n");
        }
        else
        {
            printf("elemnt found\n");
        }
       printf("Do u want to continue...if yes press 1\n");
       scanf("%d",&o);
       }while(o==1);  




}


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
            return ptr;
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
}  

