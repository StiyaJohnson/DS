#include<stdio.h>
#include<stdlib.h>
void bfs(int v);
int front,vert,i,j,n,item,v,u;
char ch;
struct node
{
    int data;
    struct node*link;
    
};
    struct node*ptr=NULL,*new=NULL,*ptr1,*aptr[100];
void main()
{
    printf("How many vertices doo u need:\n");
    scanf("%d",&vert);
    for(i=1;i<=vert;i++)
    {
        aptr[i]=NULL;
    }
    for(i=1;i<=vert;i++)
    {
        printf("Enter the no:of adjascent vertices of index %d:\n",i);
        scanf("%d",&n);
       
        ptr1=aptr[i];
        for(j=1;j<=n;j++)
        {
            printf("Enter the adjascent vertex:\n");
            scanf("%d",&item);
            new=(struct node*)malloc(sizeof(struct node));
            new->data=item;
            new->link=NULL;
            if(ptr1==NULL)
            {
                aptr[i]=new;
                ptr=new;
            }
            else
            {
                ptr->link=new;
                ptr=new;
            }
        }
    }

    printf("Enter the vertex u need to start the traversal:\n");
    scanf("%d",&v);
    bfs(v);
}

void bfs(int v)
{
    if(aptr==NULL)
    {
        printf("graph is empty\n");
    }
    else
    {
        u=v;
        enqueue(u);
        while(front!=-1)
        {
            u=dequeue();
            if(search(visit,u)==FALSE)//if vertex not visited.
            {
                insert(visit,u);
                ptr=aptr[u];
                while(ptr!=NULL)
                {
                    enqueue(ptr->data);
                    ptr=ptr->link;
                }
            }
        }
    }
}

char search(int visit,int u)
{
    int flag=0;
    
}
