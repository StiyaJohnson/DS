#include<stdio.h>
int n,i;
struct process
{
    int process_id,arrival,burst,tat,waiting;
}p[10];
void main()
{
    printf("Enter the no: of processes\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the burst time of %d process\n",i);
        scanf("%d",&p[i].burst);
    }

    p[1].waiting=0;
    p[1].tat=p[1].burst;
    for(i=2;i<=n;i++)
    {
        p[i].waiting=p[i-1].tat;
        p[i].tat=p[i].burst+p[i].waiting;
    }

    printf("PROCESS ID\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t%d\t%d\t%d",i,p[i].burst,p[i].waiting,p[i].tat);
    }
}