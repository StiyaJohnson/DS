#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void creategraph();
 void bfstraversal(int v);
 void dfstraversal(int v);
  void push(int t);
  int pop();
   bool search(int  v);
  void insert(int v);
   int dequeue();
   void enqueue(int v)
#define MAX 10
int i,vertices,op,top=-1,front=-1,v,rear=-1,vertex,adjnmbr,item,choice ,ch,a[];
bool visited[];
struct node
{
    int data;
    struct node*link;
};
    struct node*head[5],*new,*ptr;


    void main()
    {
        int choice;
        for(int i=1;i<=MAX;i++)
        {
            head[i]=NULL;
        }
        for(i=1;i<=MAX;i++)
        {
            visited[i]=NULL;
        }

        do
        {
            printf("1:creategragh\n2:bfs traversal\n3:dfs traversal4:eziting\n");
            printf("enter the operation u need to perform\n");
            scanf("%d",&op);
            switch(op)
            {
                case 1:creategraph();
                        break;
                case 2:printf("enter the vertex u need to start the bfs traversal\n");
                        scanf("%d",&v);
                        bfstraversal(v);
                        break; 
                case 3: printf("enter the vertex u need to start the dfs traversal\n");
                        scanf("%d",&v);
                        dfstraversal(v);
                        break;  
                case 4:break;
                        
            }

            printf("whether u need to continue\n");
            scanf("%d",&ch);



        }while(ch==5);
        
    }

    void bfstraversal(int v)
    {
            struct node*ptr;
            if(head[v]==NULL)
            {
                printf("grapgh is empty\n");
            }
            else
            {
            enqueue(v);
            while(front!=-1)
            {
                v=dequeue();
                if(!search(v))
                {
                    printf("%d\t",v);
                    insert(v);
                    ptr=head[v];
                    while(ptr!=NULL)
                    {
                        enqueue(ptr->data);
                        ptr=ptr->link;
                    }
                }
            }
            }
    }



    void dfstraversal(int v)
    {
        struct node*ptr;
            if(head[v]==NULL)
            {
                printf("grapgh is empty\n");
            }
            else
            {
            push(v);
            while(top!=-1)
            {
                v=pop();
                if(!search(v))
                {
                    printf("%d\t",v);
                    insert(v);
                    ptr=head[v];
                    while(ptr!=NULL)
                    {
                        push(ptr->data);
                        ptr=ptr->link;
                    }
                }
            }
            }

            printf("\n");
    }
    

    void push(int t)
    {
        if(top!=MAX-1)
        {
            a[top++]=t;
        }
    }

    int pop()
    {
        if(top!=-1)
        {
            int del;
            del=a[top];
            top--;
            return del;
        }
        else
        {
            return -1;
        }
    }


    int dequeue()
    {
        if(front==-1 && rear==-1)
        {
            printf("queue is empty\n");
            return -1;
        }
        else if(front==rear)
        {
            int temp;
            temp=a[front];
            front=rear=-1;
            return temp;
        }
        else
        {

            int temp;
            temp=a[front];
            front=front+1;
            return temp;
        }   
    }

    void enqueue(int v)
    {
        if(front==-1 && rear==-1)
        {
            rear++;
            front++;
            a[rear]=v;
        }
        else
        {
            rear++;
            a[rear]=v;
        }
    }



    void insert(int v)
    {
        visited[v]=true;
    }

    bool search(int  v)
    {
        return visited[v];
    }











void creategragh()
 {
    printf("enter the no:of vertices\n");
    scanf("%d",&vertices);
    for(i=1;i<=vertices;i++)
    {
        struct node*ptr=NULL;
        printf("enter the vertex\n");
        scanf("%d",&vertex);
        printf("enter the no: of adjacent vertices of %d ",vertex);
        scanf("%d",&adjnmbr);
        for(i=1;i<=adjnmbr;i++)
        {
            new=(struct node*)malloc(sizeof(struct node));
            printf("enter the data to be inserted\n");
            scanf("%d",&item);
            new->data=item;
            new->link=NULL;
            if(head[vertex]==NULL)
            {
                head[vertex]=new;
                ptr=new;
            }
            else
            {
                ptr->link=new;
                ptr=ptr->link;
            }
        }
    }
    

 }


 
