#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[50];
int i;
void push(char item);
struct node
{
    char data;
    struct node*prev,*next;
};
  struct node*head=NULL,*ptr,*new,*tail=NULL;
void main()
{
    printf("Enter a string\n");
    gets(str);
    for(i=0;i<strlen(str);i++)
    {
        push(str[i]);
    }
    printf("The reversed string is\n");
    for(ptr=tail;ptr->prev!=NULL;ptr=ptr->prev)
    {
        printf("%c",ptr->data);
    }
    printf("%c\n",ptr->data);
}
void push(char item)
{
        new=(struct node*)malloc(sizeof(struct node));
        new->data=item;
        new->prev=NULL;
        new->next=NULL;
        if(head==NULL)
        {
            head=tail=new;
            head->next=NULL;
        }
        else
        {
            tail->next=new;
            new->prev=tail;
            tail=new;
        }
}