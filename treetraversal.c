
#include<stdio.h>
#include<stdlib.h>
char ch;
int item,option,num;
struct node
{
    int data;
    struct node*lptr,*rptr;
} *ptr,*lc,*rc,*root;
void buildtree(struct node*ptr);
void preorder(struct node*ptr);
void inorder(struct node*ptr);
void postorder(struct node*ptr);
void main()
{
    
    do
    {
    
        printf("1--preorder\t2--preorder\t3--inorder\t4--postorder\n");
        printf("Which traversal u need to perform\n");
         scanf("%d",&option);
         switch(option)
        {
             case 1:root=(struct node*)malloc(sizeof(struct node));
                     buildtree(root);
                     break;
             case 2:preorder(root);
                     break;
             case 3:inorder(root);
                     break;
             case 4:postorder(root);
                     break;
            default:printf("invalid\n");
                    break;
         }    
             printf("Do u want to continue...if yes press 1 to continue\n");
            scanf("%d",&num);
    }while(num==1);
 

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
    buildtree(root);
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
     buildtree(root);
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        inorder(ptr->lptr);
        printf("%d",ptr->data);
        inorder(ptr->rptr);
    }
}
void postorder(struct node*ptr)
{
     buildtree(root);
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        postorder(ptr->lptr);
         postorder(ptr->rptr);
        printf("%d",ptr->data);
        
    }
}
