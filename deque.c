#include<stdio.h>
#include<stdlib.h>
#define max 100
struct fifo
{
	int front;
	int rear;
	int ar[max];
};
typedef struct fifo queue;
void create(queue *q);
void insert_rear(queue *q,int);
int delete_front(queue *q);
int isempty(queue *q);
int isfull(queue*q);
void display(queue *q);
void insert_front(queue *q,int item);
int delete_rear(queue *q);
int main()
{
	int op,item,de_item;
	queue a;
	create(&a);
	printf("\n1 : enqueue at rear operation\n");
	printf("2 : dequeue at front operation\n");
	printf("3 : check if queue is empty\n");
	printf("4 : check if queue is full\n");
	printf("5 : display queue\n");
	printf("6 : enqueue at front operation\n");
	printf("7 : dequeue at rear operation\n");
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
			insert_rear(&a,item);
			printf("element inserted\n");
			break;
		}
		case 2:
		{
			de_item=delete_front(&a);
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
		case 6:
		{
			printf("enter element to enqueue:");
			scanf("%d",&item);
			insert_front(&a,item);
			printf("element inserted\n");
			break;
		}
		case 7:
		{
			de_item=delete_rear(&a);
			printf("removed element is %d\n",de_item);
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
	if((q->rear + 1) % max == q->front)
		return(1);
	else
		return(0);
}

void insert_rear(queue *q,int item)
{
	if (isfull(q))
		printf("queue is full");
	else 
	{
		if (isempty(q))
			q->front = q->rear = 0;
		else if(!isfull(q))
	 		q->rear = (q->rear + 1) % max;
		q->ar[q->rear] = item;
	}
}

int delete_front(queue *q)
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
            		q->front = (q->front + 1) % max;
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
            		i = (i + 1) % max;
        	}
       		printf("%d\n", q->ar[q->rear]);
    	}
}

void insert_front(queue *q,int item)
{
	if (isfull(q))
		printf("queue is full");
	else 
	{
		if (isempty(q))
			q->front = q->rear = 0;
		else if(!isfull(q))
	 		q->front = (q->front - 1 +max) % max;
		q->ar[q->front] = item;
	}
}

int delete_rear(queue *q)
{
	if (isempty(q))
	{
		printf("queue is empty\n");
		exit(0);
	}
	else 
	{
		int item = q->ar[q->rear];
		if (q->front == q->rear) 
            		q->front = q->rear = -1;
       		else 
            		q->rear = (q->rear - 1 +max) % max;
		return(item);
        }
}

