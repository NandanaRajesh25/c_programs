#include<stdio.h>
#include<stdlib.h>
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
void display(queue *q);
int main()
{
	int op,item,de_item;
	queue a;
	create(&a);
	printf("\n1 : enqueue operation\n");
	printf("2 : dequeue operation\n");
	printf("3 : check if queue is empty\n");
	printf("4 : check if queue is full\n");
	printf("5 : display queue\n");
	printf("0 : Exit\n");
	printf("enter operation:");
	scanf("%d",&op);
	do
	{
		switch(op)
		{
		case 1:
		{
			printf("enter element to enqueue:");
			scanf("%d",&item);
			enqueue(&a,item);
			printf("element inserted\n");
			break;
		}
		case 2:
		{
			de_item=dequeue(&a);
			printf("removed element is %d\n",de_item);
			break;
		}
		case 3:
		{
			if(isempty(&a))
				printf("queue is empty\n");
			else
				printf("queue is not empty\n");
			break;
		}
		case 4:
		{
			if(isfull(&a))
				printf("queue is full\n");
			else
				printf("queue is not full\n");
			break;
		}
		case 5:
		{
			printf("elements in queue are:\n");
			display(&a);
			break;	
		}
		}
	printf("enter operation:");
	scanf("%d",&op);
	}
	while (op!=0);
	return(0);
	
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
		exit(0);
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

void display(queue *q) 
{
	if (isempty(q))  
		printf("Queue is empty\n");
	else 
	{
        	int i = q->front;
        	while (i != q->rear) 
		{
            		printf("%d \t", q->ar[i]);
            		i = (i + 1) % 100;
        	}
       		printf("%d\n", q->ar[q->rear]);
    	}
}

