#include<stdio.h>
#include<stdlib.h>
int item,a;
struct node
{
    int data;
    struct node*lptr,*rptr;
};
    struct node*root,*lc,*rc;
void main()
{
    root=(struct node*)malloc(sizeof(struct node));
    buildtree(root);
    printf("the tree is\n");
    preorder(root);
}

void buildtree(struct node*ptr)
{
    if(ptr==NULL)
    {
        printf("return");
    }
    else
    {
        printf("read the value to be inserted as item\n");
        ptr->data=item;
        ptr->lptr=NULL;
        ptr->lptr=NULL;
        printf("whether u need to create right or not\n");
        scanf("%d",&a);
        if(a==1)
        {
            lc=(struct node*)malloc(sizeof(struct node));
            ptr->lptr=lc;
            buildtree(lc);
        }
        else
        {
            buildtree(NULL);
        }
        printf("whether u need to create right or not\n");
        scanf("%d",&a);
        if(a==2)
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