#include<stdio.h>
struct process
{
	int pid;
	int at;
	int bt;
	int ct;
	int wt;
	int tat;
	int flag;
	int prio;
};
typedef struct process prs;

int main()
{
	int x,i,j,over,n,curr_pid=0,curr_time=0,index=0,gantt[20];
	prs arr[10],temp1;
	printf("\nenter no of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter pid,at,bt,prio: ");
		scanf("%d%d%d%d",&arr[i].pid,&arr[i].at,&arr[i].bt,&arr[i].prio);
		arr[i].ct=arr[i].wt=arr[i].tat=arr[i].flag=0;
		
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i].at>arr[j].at || (arr[i].at==arr[j].at && arr[i].prio>arr[j].prio))
			{
				temp1=arr[i];
				arr[i]=arr[j];
				arr[j]=temp1;
			}
		}
	}
	for(i=0;i<20;i++)
	{
		gantt[i]=0;
	}
	over=0;
	x=0;
	gantt[x++]=arr[0].at;
	gantt[x++]=arr[0].pid+100;
	arr[0].flag=1;
	arr[0].ct=arr[0].at+arr[0].bt;
	over=1;
	curr_time=arr[0].ct;
	gantt[x++]=curr_time;
	while(over<n)
	{
		for(i=0;i<n;i++)
		{
			if(arr[i].flag==0 && arr[i].at<curr_time)
			{
				curr_pid=arr[i].pid;
				index=i;
				for(j=0;j<n;j++)
				{
					if(arr[j].flag==0 && arr[j].at<curr_time && arr[j].prio<arr[i].prio)
					{
						curr_pid=arr[j].pid;
						index=j;
					}
				}
				gantt[x++]=curr_pid+100;
				curr_time+=arr[index].bt;
				arr[index].ct=curr_time;
				gantt[x++]=curr_time;
				arr[index].flag=1;
				over++;
				break;
			}
		}
	}

	for(i=0;i<x;i++)
	{
		printf("%d\t",gantt[i]);  
	}
	
	return(0);
}