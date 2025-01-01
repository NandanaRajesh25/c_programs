#include<stdio.h>
struct process
{
	int pid;
	int at;
	int bt;
	int ct;
	int wt;
	int tat;
	int rt;
	int flag;
};
typedef struct process prs;

struct fifo
{
	int front;
	int rear;
	int ar[100];
};
typedef struct fifo queue;

void create(queue *q);
void enqueue(queue *q,int);
int dequeue(queue *q);
int isempty(queue *q);
int isfull(queue*q);

void tabular(prs a[],int x);
void timecalc(prs a[],int x);
void ganttchart(int gc[],prs a[],int count);

int main()
{
	prs arr[10],temp1,temp;
	float avgwait=0,avgturn=0;
	int n,i,j,timeq,index,curr_time,curr_pid,count=0,gantt[20];
	queue a,gc;
	create(&a);
	create(&gc);
	
	printf("\nenter no of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter pid,at,bt: ");
		scanf("%d%d%d",&arr[i].pid,&arr[i].at,&arr[i].bt);
		arr[i].ct=arr[i].wt=arr[i].tat=0;
		arr[i].rt=arr[i].bt;
		
	}
	printf("\nenter time quantum:  ");
	scanf("%d",&timeq);
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
	
	enqueue(&a,arr[0].pid);
	arr[0].flag=1;
	curr_time=0;
	enqueue(&gc,arr[0].at);
	//enqueue(&gc,arr[0].pid+1000);

	while(!isempty(&a))
	{
		curr_pid=dequeue(&a);
		enqueue(&gc,curr_pid);
		
		for(i=0;i<n;i++)
		{
			if(arr[i].pid==curr_pid)
			{
				index=i;
				break;
			}

		}

		if(arr[index].rt>=timeq)
		{
			arr[index].rt-=timeq;
			curr_time+=timeq;
			arr[index].ct=curr_time;
			//add pid and curr_time to gantt chart
			
				enqueue(&gc,curr_time);
							
		
			for(i=0;i<n;i++)
			{
				if (arr[i].flag!=1 && arr[i].at<=curr_time)
				{
					enqueue(&a,arr[i].pid);
					arr[i].flag=1;
				}
			}
			if(arr[index].rt!=0)  
				enqueue(&a,curr_pid);
		}
		
		else
		{
			curr_time+=arr[index].rt;
			arr[index].rt=0;
			arr[index].ct=curr_time;

			//add pid and curr_time to gantt chart
			enqueue(&gc,curr_time);
						

			for(i=0;i<n;i++)
			{
				if (arr[i].flag!=1 && arr[i].at<=curr_time)
				{
					enqueue(&a,arr[i].pid);
					arr[i].flag=1;
				}
			}
		}
		
	}
	
	//int count=0;
	while (!isempty(&gc)) 
	{
     		int item = dequeue(&gc);
        	gantt[count]=item;
		count++;
    	}

	/*printf("%d %d\n",gc.front,gc.rear);*/
	/*for(i=0;i<count;i++)
	{
		
		printf("%d\n",gantt[i]);
		
	}*/
	//printf("%d\n",count);
	printf("\n");
	ganttchart(gantt,arr,count);
	printf("\n");
	timecalc(arr,n);
	printf("\n");
	tabular(arr,n);
	return(0);
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

void ganttchart(int gc[],prs a[],int count)
{
	int i;
	printf("-");
	if (a[0].at!=0)
	{
		for(i=1;i<count;i+=2)
		{
			printf("--------");
			printf("-");
		}
	}
	else
	{
		for(i=1;i<count-1;i+=2)
		{
			printf("--------");
			printf("-");
		}
	}	
	printf("\n");
	printf("|");
	if (a[0].at!=0)
	{
		printf("   /    |");
	}
	for(i=1;i<count-1;i+=2)

	{
		printf("   P%d   |",gc[i]);
	}
	printf("\n");
	printf("-");
	if (a[0].at!=0)
	{
		for(i=1;i<count;i+=2)

		{
			printf("--------");
			printf("-");
		}
	}
	else
	{
		for(i=1;i<count-1;i+=2)

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
		for(i=0;i<count-1;i+=2)

		{
			if(gc[i]<9)
				printf("%d        ",gc[i]); 
			else
				printf("%d       ",gc[i]);
		}
	}
	else
	{
		//printf("h        ");
		for(i=0;i<count;i+=2)

		{
			if(gc[i]<9)
				printf("%d        ",gc[i]); 
			else
				printf("%d       ",gc[i]);

		}
	}

}


void timecalc(prs a[],int x)
{
	int i;
	float sumtat=0,sumwt=0,avgtat,avgwt;
	for(i=0;i<x;i++)
	{
		a[i].tat=a[i].ct-a[i].at;
		sumtat+=a[i].tat;
		a[i].wt=a[i].tat-a[i].bt;
		sumwt+=a[i].wt;
	}
	avgtat=sumtat/x;
	avgwt=sumwt/x;
	printf("\nAverage tat is %f\n",avgtat);
	printf("\nAverage wt is %f\n",avgwt);
}
	

void create(queue *q)
{
	q->front=-1;
	q->rear=-1;
}

int isempty(queue *q)
{
	if(q->front == -1 && q->rear == -1)
		return(1);
	else
		return(0);
}

int isfull(queue*q)
{
	if((q->rear + 1) % 100 == q->front)
		return(1);
	else
		return(0);
}

void enqueue(queue *q,int item)
{
	if (isfull(q))
		printf("queue is full");
	else 
	{
		if (isempty(q))
			q->front = q->rear = 0;
		else if(!isfull(q))
	 		q->rear = (q->rear + 1) % 100;
		q->ar[q->rear] = item;
	}
}

int dequeue(queue *q)
{
	if (isempty(q))
	{
		printf("queue is empty\n");
		return(0);
	}
	else 
	{
		int item = q->ar[q->front];
		if (q->front == q->rear) 
            		q->front = q->rear = -1;
       		else 
            		q->front = (q->front + 1) % 100;
		return(item);
        }
}