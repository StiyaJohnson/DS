#include<stdio.h>
int n,i,j,time_taken=0,temp,pt=0,gt=0,turnaround=0;
float wait,turn;
struct process
{
    int at,bt,wt,tt;
    char name;
}p[10];

struct gant
{
    int starting,ending,completion;
    char gantname;
}g[10];
void main()
{
    printf("Enter the no:of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the name of processes\n");
        scanf("%c",&p[i].name);
        printf("Enter the arrival time of proces\n");
        scanf("%d",&p[i].at);
        printf("Enter the burst time of process\n");
        scanf("%d",&p[i].bt);
    }

    printf("The processes before sort are\n");
    for(i=0;i<n;i++)
    {
        printf("%c\t%d\t%d\t\n",p[i].name,p[i].at,p[i].bt);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    printf("The details aftr sorting are\n");
    for(i=0;i<n;i++)
    {
        printf("%c\t%d\t%d\n",p[i].name,p[i].at,p[i].bt);
    }

    while(pt<n)
    {
        if(time_taken>=p[pt].at)
        {
            strcpy(g[gt].gantname,p[pt].name);
            g[gt].starting=time_taken;
            time_taken=time_taken+p[pt].bt;
            g[gt].completion=time_taken;
            p[pt].wt=g[gt].starting-p[pt].at;
            p[pt].tt=g[gt].completion-p[pt].at;
            gt++;
            pt++;
        }
        else
        {
            strcpy(g[gt].gantname,"idle");
            g[gt].starting=time_taken;
            g[gt].completion=p[pt].at;
            time_taken=g[gt].completion;
            gt++;
        }
    }

    printf("The details after gant chart are\n");
    printf("Name\tArrival\tBurst\tWaiting\tTurnaround\n");
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt);
        wait=wait+p[i].wt;
        turnaround=turnaround+p[i].tt;
    }

    printf("\n");
    printf("\n");
    for(i=0;i<gt;i++)
    {
        printf("%s\t",g[i].gantname);
    }
    printf("\n");
    printf("%d\t",g[gt].starting);
    for(i=0;i<gt;i++)
    {
        printf("%d\t",g[i].completion);
    }

    printf("\n");

    printf("average waiting time is= %f\n",wait/n);
    printf("average turnaround time is=%f\n",turn/n );
}