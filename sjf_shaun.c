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

void tabular(prs a[],int x);
void ganttchart(prs a[],int x);
void calcavg(prs a[],int x);

int main() 
{
	prs arr[10],temp1,temp;
	float avgwait=0,avgturn=0;
	int n,i,j,over=0,sum_wait=0,sum_turnaround=0,count=0,time=0,start=0;
	printf("\nenter no of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter pid,at,bt: ");
		scanf("%d%d%d",&arr[i].pid,&arr[i].at,&arr[i].bt);
		arr[i].ct=arr[i].wt=arr[i].tat=0;
		
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i].at>arr[j].at || (arr[i].at==arr[j].at && arr[i].bt>arr[j].bt) )
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


        	if (arr[0].at!= 0) 
		{
           		if (over == 0) 
			{
                		time = arr[0].at + arr[0].bt;
                		start = arr[0].at;
            		} 
			else 
			{
                		start = time;
                		time += arr[over].bt;
            		}

        	} 
		else 
		{
            		start = time;
            		time += arr[over].bt;
        	}

        	arr[over].wt = time - arr[over].at - arr[over].bt;
        	arr[over].tat = time - arr[over].at;
        	arr[over].ct = time;
		over++;
	
	}
  
	tabular(arr,n);
	printf("\n");
	calcavg(arr,n);
	printf("\n");
	ganttchart(arr,n);
	
   	return (0);
}


void tabular(prs a[],int x)
{
	int i,j;
	prs temparr[10],temp1;
	for(i=0;i<x;i++)
	{
		temparr[i]=a[i];
	}
	for(i=0;i<x;i++)
		{  
			for(j=i+1;j<x;j++)
			{
				if(temparr[i].pid>temparr[j].pid)
				{
					temp1=temparr[i];
					temparr[i]=temparr[j];
					temparr[j]=temp1;
				}
			}
		}

	printf("\n\nProcess\t|Arrival time\t|burst time\t|completion time|waiting time\t|Turnaround time\n\n");
	for(i=0;i<x;i++)
	{
		 printf("p[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", temparr[i].pid, temparr[i].at, temparr[i].bt, temparr[i].ct, temparr[i].wt, temparr[i].tat);
	}
}

void ganttchart(prs a[],int x)
{
	int i;
	printf(" ");
	if (a[0].at!=0)
	{
		for(i=0;i<x+1;i++)
		{
			printf("--------");
			printf("-");
		}
	}
	else
	{
		for(i=0;i<x;i++)
		{
			printf("--------");
			printf("-");
		}
	}	
	printf("\n");
	printf("|");
	if (a[0].at!=0)
	{
		printf("   /    |",a[i].pid);
	}
	for(i=0;i<x;i++)
	{
		printf("   %d    |",a[i].pid);
	}
	printf("\n");
	printf(" ");
	if (a[0].at!=0)
	{
		for(i=0;i<x+1;i++)
		{
			printf("--------");
			printf("-");
		}
	}
	else
	{
		for(i=0;i<x;i++)
		{
			printf("--------");
			printf("-");
		}
	}	
	printf("\n");
	if (a[0].at!=0)
	{
		printf("0        ");
		printf("%d        ",a[0].at);
		for(i=0;i<x;i++)
		{
			printf("%d        ",a[i].ct); 
		}
	}
	else
	{
		printf("0        ");
		for(i=0;i<x;i++)
		{
			printf("%d        ",a[i].ct); 
		}
	}

}

void calcavg(prs a[],int x)
{
	int i;
	float avgtat,avgwt,sumtat=0,sumwt=0;
	for(i=0;i<x;i++)
	{
		sumtat+=a[i].tat;
		sumwt+=a[i].wt;
	}
	avgtat=sumtat/x;
	avgwt=sumwt/x;
	printf("Average waiting time is %f\n", avgwt);
    	printf("Average turnaround time is %f\n", avgtat);
}