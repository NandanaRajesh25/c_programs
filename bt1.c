#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

};
typedef struct Node tree;

struct lifo
{
	tree * ar[100];
    	int top;
};
typedef struct lifo stack;

struct fifo 
{
    	tree * str[100];
	int front;
	int rear;
};
typedef struct fifo queue;

tree * create();
void create_queue(queue *q);
void enqueue(queue *q,tree *t);
tree * dequeue(queue *q);
void create_stack(stack *s);
void push(stack *s,tree *t);
tree * pop(stack *s);
tree * insert(tree *r,int data);
void inorder(tree *r);
void preorder(tree *r);
void postorder(tree *r);
void levelorder(tree *r);

int main()
{
	int n,x,i;
	
	tree *root=NULL;
	printf("enter no of elements to insert ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter element ");
		scanf("%d",&x);
		root=insert(root,x);
	}
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	levelorder(root);
	return(0);
}

tree * create()
{
	tree *t;
	t=(tree *)malloc(sizeof(tree));
	t->data=0;
	t->left=NULL;
	t->right=NULL;
	return (t);
	
}

void create_queue(queue *q)
{
	q->front=q->rear=-1;
}

void enqueue(queue *q,tree *t)
{
	if (q->rear==99)
	{
		printf("queue is full");
	}
	else
	{
		if (q->front==-1)
			q->front = q->rear = 0;
		else if(q->rear!=99)
	 		q->rear = (q->rear + 1) % 100;
		q->str[q->rear] = t;
	}
}

tree * dequeue(queue *q)
{
	if (q->front==-1)
	{
		printf("queue is empty\n");
		return NULL;
	}
	else 
	{
		tree *p = q->str[q->front];
		if (q->front == q->rear) 
            		q->front = q->rear = -1;
       		else 
            		q->front = (q->front + 1) % 100;
		return(p);
        }
}

void create_stack(stack *s)
{
	s->top=-1;
}

void push(stack *s,tree *t)
{
	
	if (s->top==99)
	{
		printf("stack overflow");
		return;
	}
	s->top++;
	
	s->ar[s->top]=t;
	
	return;
	
}

tree * pop(stack *s)
{
	if (s->top!=-1)
		return(s->ar[s->top--]);
}

tree * insert(tree *r,int data)
{
	tree *new;
	new=create();
	new->data=data;
	if (r==NULL)
	{
		r=new;
		return(r);
	}
	
	queue q;
	create_queue(&q);
	enqueue(&q,r);
	while(q.front!=-1)
	{
		tree *current=dequeue(&q);
		if (current->left==NULL) 
		{
            		current->left = new;
            		return r;
        	} 
		else 
		{
            		enqueue(&q,current->left);
        	}

        	if (current->right==NULL) 
		{
            		current->right = new;
            		return r;
        	} 
		else 
		{
            		enqueue(&q, current->right);
        	}
    	}
	
}

void inorder(tree *r)
{
	stack s;
	create_stack(&s);
	tree *current=r;
	while(current!=NULL || s.top!=-1)
	{
		
		while(current!=NULL)
		{
			
			push(&s,current);
			current=current->left;
			
		}
		current=pop(&s);
		printf("%d\t",current->data);
		current=current->right;
		
	}
}

void preorder(tree *r)
{
	stack s;
	create_stack(&s);
	tree *current=r;
	if(current==NULL)
	{
		return;
	}
	push(&s,current);
	while(s.top!=-1)
	{
		current=pop(&s);
		printf("%d\t",current->data);
		if(current->right!=NULL)
		{
			push(&s,current->right);
		}
		if(current->left!=NULL)
		{
			push(&s,current->left);
		}
	}
}
	
void postorder(tree *r)
{
	stack s1;
	create_stack(&s1);
	stack s2;
	create_stack(&s2);
	tree *current=r;
	push(&s1,current);
	while(s1.top!=-1)
	{
		current=pop(&s1);
		push(&s2,current);
		if (current->left!=NULL)
			push(&s1,current->left);
		if (current->right!=NULL)
			push(&s1,current->right);
	}
	while(s2.top!=-1)
	{
		current=pop(&s2);
		printf("%d\t",current->data);
	}
}	

void levelorder(tree *r)
{
	queue q;
	create_queue(&q);
	enqueue(&q,r);
	tree *current=r;
	while(q.front!=-1)
	{
		current=dequeue(&q);
		printf("%d\t",current->data);
		if (current->left==NULL) 
            		enqueue(&q,current->left);

        	if (current->right!=NULL) 
            		enqueue(&q, current->right);
    	}
}