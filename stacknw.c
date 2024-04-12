/*PROGRAM TO STACK IMPLEMENTATION*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3
int ch,n,s[MAX_SIZE],item,top=-1,c,i;
void push();
void pop();
void display();
void main()
{
do{
printf("1--push\t\t2--pop\t\t3--Display\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1 : push();
c=1;
break;
case 2 : pop();
c=1;
break;
case 3 : display();
c=1;
break;
default : printf("Enter any valid option\n");
c=1;
break;
}
}while(c=1);
}
void push()
{
//top=-1;
printf("Enter the element to be pushed\n");
scanf("%d",&item);
if(top>=MAX_SIZE-1)
{
printf("STACK OVERFLOW\nInsertion not possible\n");
}

else
{
top=top+1;
s[top]=item;
display();
}
}

void pop()
{
display();
if(top<0)
{
printf("STACK UNDERFLOW\nDeletion not possible\n");
}
else
{
printf("The deleted element is %d\n",s[top]);
top=top-1;
display();

}
}
void display()
{
printf("The current stack is\n");
for(i=0;i<=top;i++)
{
printf("%d\t",s[i]);
}
printf("\n");
}





/*SAMPLE OUTPUT
1--push         2--pop          3--Display
Enter your choice
1
Enter the element to be pushed
10
The current stack is
10
1--push         2--pop          3--Display
Enter your choice
1
Enter the element to be pushed
20
The current stack is
10      20
1--push         2--pop          3--Display
Enter your choice
1
Enter the element to be pushed
30
The current stack is
10      20      30
1--push         2--pop          3--Display
Enter your choice
1
Enter the element to be pushed
40
STACK OVERFLOW
Insertion not possible
1--push         2--pop          3--Display
Enter your choice
2
The current stack is
10      20      30
The deleted element is 30
The current stack is
10      20
1--push         2--pop          3--Display
Enter your choice
3
The current stack is
10      20
1--push         2--pop          3--Display
Enter your choice
2
The current stack is
10      20
The deleted element is 20
The current stack is
10
1--push         2--pop          3--Display
Enter your choice
2
The current stack is
10
The deleted element is 10
The current stack is

1--push         2--pop          3--Display
Enter your choice
3
The current stack is

1--push         2--pop          3--Display
Enter your choice
2
The current stack is

STACK UNDERFLOW
Deletion not possible
*/