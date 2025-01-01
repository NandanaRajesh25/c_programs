#include<stdio.h>
struct process
{
	int pid;
	int at;
	int bt;
	int ct;
	int wt;
	int tat;
};
typedef struct process prs;

void findcomptime(prs a[],int x);
//void findturnaroundtime(prs a[],int x);
//void findwaitingtime(prs a[],int x);
void ganttchart(prs a[],int x);

int main()
{
	prs arr[10],temp1,temp;
	float avgwait=0,avgturn=0;
	int n,i,j,over=0,sum_wait=0,sum_turnaround=0,count=0,time=0,start=0;
	printf("\nenter no of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\enter pid,at,bt: ");
		scanf("%d%d%d",&arr[i].pid,&arr[i].at,&arr[i].bt);
		arr[i].ct=arr[i].wt=arr[i].tat=0;
		
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i].at>arr[j].at)
			{
				temp1=arr[i];
				arr[i]=arr[j];
				arr[j]=temp1;
			}
		}
	}

	while(over<n)
            {
                        count=0;
                        for(i=over;i<n;i++)
                        {
                                    if(arr[i].at<=time)
                                   	 count++;
                                    else
                                   	 break;
                        }
                        if(count>1)
                        {
                                    for(i=over;i<over+count-1;i++)
                                    {
                                                for(j=i+1;j<over+count;j++)
                                                {
                                                            if(arr[i].bt>arr[j].bt)
                                                            {
                                                                        temp=arr[i];
                                                                        arr[i]=arr[j];
                                                                        arr[j]=temp;
                                                                         
                                                            }
                                                }                     
                                    }
                        }
                        start=time;
                        time+=arr[over].bt;
                        // printf("p[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",pr[over],
                              //      at[over],bt[over],start,time,time-at[over]-bt[over],time-at[over]);
                        sum_wait+=time-arr[over].at-arr[over].bt;


                        sum_turnaround+=time-arr[over].at;
                        over++;
            }
		avgwait=(float)sum_wait/(float)n;
            avgturn=(float)sum_turnaround/(float)n;
            printf("Average waiting time is %f\n",avgwait);
            printf("Average turnaround time is %f\n",avgturn);
	
	printf("\n");
	findcomptime(arr,n);
	printf("\n");
	ganttchart(arr,n);
            return 0;
		
	
}

void findcomptime(prs a[],int x)
{
	int sum,i;
	sum=0;
	for(i=0;i<x;i++)
	{
		sum=sum+a[i].bt;
		a[i].ct=sum;
		printf("comp time of pid %d is %d\n",a[i].pid,a[i].ct);
	}
}

void ganttchart(prs a[],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("--------");
	}
	printf("\n");
	for(i=0;i<x;i++)
	{
		printf("|   %d   ",a[i].pid);
	}
	printf("|");
	printf("\n");
	for(i=0;i<x;i++)
	{
		printf("--------");
	}
	printf("\n");
	printf("0       ");
	for(i=0;i<x;i++)
	{
		printf("%d       ",a[i].ct); 
	}

}
