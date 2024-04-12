#include<stdio.h>
#include<stdlib.h>
char ch;
int item,key;
struct node
{
    int data;
    struct node*lptr,*rptr;
} *ptr,*lc,*rc,*root,*ptr1;
void buildtree(struct node*ptr);
void preorder(struct node*ptr);
struct node*search(struct node*ptr,int key);
void main()
{
    root=(struct node*)malloc(sizeof(struct node));
    buildtree(root);
    printf("The current tree is\n");
    preorder(root);
    printf("\nEnter the element to be searched\n");
    scanf("%d",&key);
    struct node*ptr1=search(root,key);
    if(ptr1==NULL)
    {
        printf("element not found\n");
    }
    else
    {
        printf("Element found\n");
    }
    
}

void buildtree(struct node*ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        printf("Enter the data to be stored\n");
        scanf("%d",&item);
        ptr->data=item;
        ptr->lptr=NULL;
        ptr->rptr=NULL;
        printf("DO u need left node...(y/n)\n");
        scanf(" %c",&ch);
        if(ch=='y')
        {
            lc=(struct node*)malloc(sizeof(struct node));
            ptr->lptr=lc;
            buildtree(lc);
        }
        else
        {
            buildtree(NULL);
        }
        printf("Do u need right node...(y/n)\n");
        scanf(" %c",&ch);
        if(ch=='y')
        {
            rc=(struct node*)malloc(sizeof(struct node));
            ptr->rptr=rc;
            buildtree(rc);
        }
        else
        {
            buildtree(NULL);
        }
        

    }
}

void preorder(struct node *ptr)
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
struct node*search(struct node*ptr,int key)
{
    if(ptr->data==key)
    {
        return ptr;
    }
    else
    {
        ptr1=NULL;
        if(ptr->lptr=NULL)
        {
            ptr1=search(ptr->lptr,key);
        }
        if(ptr->rptr!=NULL)
        {
            ptr1=search(ptr->rptr,key);
        }
            return ptr1;
    }
}