#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX_SIZE 100
char infix[MAX_SIZE],symbol,next,postfix[MAX_SIZE];
int i,j,stack[MAX_SIZE],top=-1;
void post(char infix[MAX_SIZE]);
int precedence(char s);
void evalpost(char postfix[MAX_SIZE]);
void push(char s);
char pop();
void main()
{
    printf("Enter the postfix expression:\n");
    gets(infix);
    post(infix);

}

void post(char infix[MAX_SIZE])
{
    int j=0;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(':push(symbol);
                        break;
            case ')':while((next=pop())!='(')
                        {
                            postfix[j]=next;
                            j++;

                        }   
                        break;
            case '+':
            case '-':  
            case '*':
            case '/':while(precedence(stack[top])>=precedence(symbol))
                        {
                            postfix[j]=pop();
                            j++;
                        }
                        push(symbol);
                        break;
            case '^': while(precedence(stack[top])>precedence(symbol))
                        {
                            postfix[j]=pop();
                            j++;
                        }
                        push(symbol);
                        break;
            default:postfix[j]=symbol;
                    j++;
                    break;  
        }      
    }

    while(top!=-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("postfix expression is:\n");
    puts(postfix);
    evalpost(postfix);
}

int precedence(char s)
{
    switch(s)
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
void push(char s)
{
    top++;
    stack[top]=s;
}

char pop()
{
    char del_item;
    
    del_item=stack[top];
     top--;
    
    return del_item;
    
}

void evalpost(char postfix[MAX_SIZE])
{
    char op;
    int symbol,x,y,result,eval;
    for(i=0;i<strlen(postfix);i++)
    {
        symbol=postfix[i];
        
        if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^')
        {
            op=symbol;
            y=pop();
              x=pop();
            switch(op)
            {
                case '+':result=x+y;
                            break;
                case '-':result=x-y;
                            break;
                case '*':result=x*y;
                            break;
                case '/':result=x/y;
                            break;
                case '^':result=pow(x,y);
                            break;
                default:printf("invalid op\n");
                            break;
            }
            push(result);
        }
        else
        {
            push(symbol-'0');
        }
    }   
        eval=pop();
        printf("The evaluated result is %d ",eval);
    
}