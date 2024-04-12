#include<stdio.h>
#include<stdlib.h>
void insert();
void insert_beg();
void insert_end();
void insert_pos();
void del_beg();
void del_end();
void del_pos();
void display();
struct node
{
        int data;
        struct node*link;
}*head,*ptr,*temp,*ptr1;
int item,pos,op,i;
void main()
{
        do
        {
                printf("Enter the operation u need to perform\n");
                printf("1-Insert at beg\n2-Insert at end\n3-Insert at pos\n4-Delete from beg\n4-Delete from end\n5-delete from pos\n6-Display\n");
                scanf("%d",&op); 
                switch(op)
                {
                    case 1:insert_beg();
                            break;
                    case 2:insert_end();
                            break;  
                    case 3:insert_pos();
                            break;
                    case 4:del_beg();
                            break;
                    case 5:del_end();
                            break;    
                    case 6:del_pos();
                            break; 
                    case 7:display();
                            break;                                    
                } 
                printf("Do u need to continue\n");
                printf("1--yes\t2==no\n");
                scanf("%d",&op);

                }while(op==1;)       
 }       
        
}