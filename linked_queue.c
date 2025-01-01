#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node term;
struct fifo
{
	struct Node *front;
	struct Node *rear;
};
typedef struct fifo queue;
void create_queue(queue *q);
term * create_node();
queue * enqueue(queue *q,int);
int dequeue(queue *q);
void display(queue *q);
int main()
{
	int op,data,de_item;
	queue *q;
	create_queue(q);
	printf("\n1 : Enqueue\n");
	printf("2 : Dequeue\n");
	printf("3 : Display queue\n");
	printf("0 : Exit\n");
	printf("Enter operation: ");
	scanf("%d",&op);
	do
	{
		switch(op)
		{
		case 1:
		{
			printf("Enter element to enqueue: ");
			scanf("%d",&data);
			q=enqueue(q,data);
			printf("Element inserted\n");
			break;
		}
		case 2:
		{
			de_item=dequeue(q);
			if (de_item!=-1)
				printf("Removed element is %d\n",de_item);
			break;
		}
		case 3:
		{
			printf("Elements in queue are:\n");
			display(q);
			break;	
		}
		}
	printf("\nEnter operation: ");
	scanf("%d",&op);
	}
	while (op!=0);
	return(0);
	
}

void create_queue(queue *q)
{
	q->front=NULL;
	q->rear=NULL;
}

term * create_node()
{
	term *t;
	t=(term *)malloc(sizeof(term));
	t->data=0;
	t->next=NULL;
	return (t);
	printf("hi");
}

queue * enqueue(queue *q,int item)
{
	term *new;
	new=create_node();
	new->data=item;
	if (q->front == NULL) 
	{
        	q->front = new;
    	} 
	else 
	{
        	q->rear->next = new;
    	}

    	q->rear = new;
    	new->next = q->front;
	return(q);
}

int dequeue(queue *q)
{
	if (q->front == NULL) 
	{
        	printf("Circular Queue is empty.\n");
        	return(-1);
    	}

   	int data = (q->front)->data;
    	struct Node *temp = q->front;

    	if (q->front == q->rear) 
	{
        	q->front = NULL;
        	q->rear = NULL;
    	} 
	else 
	{
        	q->front = (q->front)->next;
        	(q->rear)->next = q->front;
    	}

    	free(temp);
    	return data;
}

void display(queue *q) 
{
    	if (q->front == NULL) 
	{
        	printf("Circular Queue is empty.\n");
        	return;
    	}

    	struct Node *p = q->front;
    	do 
	{
        	printf("%d\t", p->data);
        	p = p->next;
    	} 
	while (p != q->front);
    		printf("\n");
}

