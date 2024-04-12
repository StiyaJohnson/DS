#include <stdio.h>
#include <stdlib.h>
int height_tree(struct node *ptr);
void preorder(struct node*ptr);
void buildtree(struct node*ptr);
int val, choice, countleft = 0, countright = 0;
struct node
{
    int data;
    struct node *lptr, *rptr, *ptr;
};
struct node *lc, *rc, *root, *ptr1;

void main()
{
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    buildtree(root);
    printf("The entered tree is\n");
    preorder(root);
    printf("The height of tree is\n");
    height_tree(root);
}

void preorder(struct node*ptr)
{
    if (ptr == NULL) // base case
    {
        return;
    }
    else
    {
        printf("%d", ptr->data);
        preorder(ptr->lptr);
        preorder(ptr->rptr);
    }
}

void buildtree(struct node*ptr)
{

    if (ptr == NULL)
    {
        return;
    }
    printf("Enter the vale to be inserted\n");
    scanf("%d", &val);
    ptr->data = val;
    ptr->lptr = NULL;
    ptr->rptr = NULL;

    printf("Whether u need to create left child....if yes press 1\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        lc = (struct node *)malloc(sizeof(struct node));
        ptr->lptr = lc;
        buildtree(lc);
    }
    else
    {
        buildtree(NULL);
    }

    printf("Whether u need to create right child ....if yes press 2\n");
    scanf("%d", &choice);
    if (choice == 2)
    {
        rc = (struct node *)malloc(sizeof(struct node));
        ptr->rptr = rc;
        buildtree(rc);
    }
    else
    {
        buildtree(NULL);
    }
}

int height_tree(struct node *ptr)
{
    if (ptr == NULL)
    {
        return -1;
    }
    else
    {
        int height_left = height_tree(ptr->lptr);
        int height_right = height_tree(ptr->rptr);
        return((height_left>height_right?height_left:height_right)+1);
    }

   

    

    
}