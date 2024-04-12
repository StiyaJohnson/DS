#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100
void pref(char infix[MAX],char prefix[MAX]);
int pop();
void push(char symbol);
int precedence(char symbol);
char infix[MAX],stack[MAX];
char prefix[MAX];
int top=-1,l;




void main()
{
    printf("Enter the infix expression:\n");
    gets(infix);
    l=strlen(infix);
    pref(infix,prefix);
   
    

}

void pref(char infix[MAX],char prefix[MAX])
{
    char next,symbol;
    int i,j=0;
    l=strlen(infix);
    for(i=l-1;i>=0;i--)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case ')':push(symbol);
                    break;
            case '(':while((next=pop())!=')')
                    {
                        prefix[j]=next;
                        j++;
                    }
                     break;
            case '^':while(precedence(stack[top])>precedence(symbol))
                        {
                            prefix[j]=pop();
                            j++;
                        }
                        push(symbol);
                        break;
            case '*':
            case '/':
            case '+':
            case '-':while(precedence(stack[top])>precedence(symbol))
                        {
                            prefix[j]=pop();
                            j++;
                        }
                        push(symbol);
                        break;
            default:prefix[j]=symbol;
                        j++;
                        break;
        }           
    }

    while( top!=-1)
    {
        prefix[j]=pop();
        j++;
   
    }
         prefix[j]='\0';
     printf("the prefix expression is\n");
     for(i=l-1;i>=0;i--)
     {
        printf("%c",prefix[i]);
     }
}


void push(char symbol)
{
   top++;
   stack[top]=symbol;
}

int pop()
{
    char del_item;
    del_item=stack[top];
    top--;
    return del_item;
}

int precedence(char symbol)
{
    switch(symbol)
    {
        case '^':return 3;
                    break;
        case '*':
        case '/':return 2;
                    break;
        case '+':
        case '-':return 1;
                    break;
        default:return 0;
                    break;
    }
}


