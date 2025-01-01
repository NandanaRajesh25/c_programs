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
void findturnaroundtime(prs a[],int x);
void findwaitingtime(prs a[],int x);
void ganttchart(prs a[],int x);

int main()
{
	prs arr[10],temp;
	int n,i,j;
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
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("\n");
	findcomptime(arr,n);
	printf("\n");
	findturnaroundtime(arr,n);
	printf("\n");
	findwaitingtime(arr,n);
	printf("\n");
	ganttchart(arr,n);	
	return(0);
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

void findturnaroundtime(prs a[],int x)
{
	int sum,i;
	float avgtat=0;
	sum=0;
	for(i=0;i<x;i++)
	{
		a[i].tat=a[i].ct-a[i].at;
		sum=sum+a[i].tat;
		printf("turn around time of pid %d is %d\n",a[i].pid,a[i].tat);
	}
	avgtat=sum/x;
	printf("avg tat is %f\n",avgtat);
}

void findwaitingtime(prs a[],int x)
{
	int sum,i;
	float avgwt=0;
	sum=0;
	for(i=0;i<x;i++)
	{
		a[i].wt=a[i].tat-a[i].bt;
		sum=sum+a[i].wt;
		printf("waiting time of pid %d is %d\n",a[i].pid,a[i].wt);
	}
	avgwt=sum/x;
	printf("avg wtt is %f\n",avgwt);
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
