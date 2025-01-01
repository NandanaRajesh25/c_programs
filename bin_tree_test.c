#include<stdio.h>
#include<stdlib.h>



struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;

	

struct fifo
{
	node * arr[100];
	int front;
	int rear;
};
typedef struct fifo queue;


struct lifo
{
	node * stk[100];
	int top;
};
typedef struct lifo stack;

node * createnode(int val);
void createqueue(queue *q);
void createstack(stack *s);
void enqueue(queue *q,node *item);
node * dequeue(queue *q);
void push(stack *s,node *item);
node * pop(stack *s);
node * insert(node *r,int data);
void inorder(node *r);

int main()
{
	int i,x;
	node *root=NULL;
	for(i=0;i<7;i++)
	{
		printf("enter a value:");
		scanf("%d",&x);
		root=insert(root,x);
	}
	inorder(root);
	return(0);
}

		

node * createnode(int val)
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->data=val;
	new->left=NULL;
	new->right=NULL;
	return (new);
}

void createqueue(queue *q)
{
	q->front=q->rear=-1;
}

void createstack(stack *s)
{
	s->top=-1;
}


void enqueue(queue *q,node *item)
{
	if(q->rear==99)
	{
		printf("queue full");
		return;
	}
	else
	{
		if (q->front==-1)
		{
			q->front=q->rear=0;
		}
		else if(q->rear!=99)
		{
			q->rear=(q->rear+1)%100;
		}
		q->arr[q->rear]=item;
	}
}


node * dequeue(queue *q)
{
	if(q->front==-1)
	{
		printf("queue empty");
		return NULL;
	}
	else
	{
		node* item=q->arr[q->front];
		if (q->front==q->rear)
		{
			q->front=q->rear=-1;
		}
		else
		{
			q->front=(q->front+1)%100;
		}
		return (item);
	}
}

void push(stack *s,node *item)
{
	if(s->top==99)
	{
		printf("stack full");
		return;
	}
	else
	{
		s->top++;
		s->stk[s->top]=item;
	}
}

node * pop(stack *s)
{
	if(s->top==-1)
	{
		printf("stack empty");
		return NULL;
	}
	else
	{
		node *item=s->stk[s->top];
		s->top--;
		return (item);
	}
}

node * insert(node *r,int data)
{
	node *newnode=createnode(data);
	if(r==NULL)	
	{
		r=newnode;
		return (r);
	}
	queue q;
	createqueue(&q);
	enqueue(&q,r);
	while(q.front!=-1)
	{
		node *current=dequeue(&q);
		if(current->left==NULL)
		{
			current->left=newnode;
			return(r);
		}
		else
		{
			enqueue(&q,current->left);
		}
		if(current->right==NULL)
		{
			current->right=newnode;	
			return(r);
		}
		else
		{
			enqueue(&q,current->right);
		}
	}
}
	
void inorder(node *r)
{
	if(r==NULL)
	{
		printf("tree empty");
		return;
	}
	else
	{
		stack s;
		createstack(&s);
		node *current=r;
		while(current!=NULL || s.top!=-1)
		{
			while(current!=NULL)
			{
				push(&s,current);
				current=current->left;
			}
			current=pop(&s);
			printf("%d",current->data);
			current=current->right;
		}
	}
}


			
			
		
	