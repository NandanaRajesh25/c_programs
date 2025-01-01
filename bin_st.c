#include<stdio.h>
#include<stdlib.h>



struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;

struct lifo
{
	node * stk[100];
	int top;
};
typedef struct lifo stack;

void createstack(stack *s);
void push(stack *s,node *item);
node * pop(stack *s);	
void inorder(node *r);
 
node * insert(node *r,int data);
node * delete(node *r,int data);
node * succ(node *p);

int main()
{
	int i,val,x;
	node *root=NULL;
	for(i=0;i<5;i++)
	{
		printf("enter element");
		scanf("%d",&val);
		root=insert(root,val);
	}
	inorder(root);
	for(i=0;i<5;i++)
	{
		printf("\nenter element to delete");
		scanf("%d",&x);
		root=delete(root,x);
		inorder(root);
	}
	return(0);
	  
}

void createstack(stack *s)
{
	s->top=-1;
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


node * create(int data)
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
}

node * insert(node *r,int data)
{
	node *newnode=create(data);
	if (r==NULL)
	{
		r=newnode;
		return(r);
	}
	node *current=r;
	node *parent=NULL;
	while(current!=NULL)
	{
		parent=current;
		if(data<current->data)
			current=current->left;
		else if(data>current->data)
			current=current->right;
		else if(data==current->data)
		{
			free(newnode);
			return(r);
		}
	}
	
	if(data<parent->data)
		parent->left=newnode;
	else
		parent->right=newnode;	

	return(r);
}

node * delete(node *r,int data)
{
	if (r==NULL)
	{
		printf("tree empty");
		return(r);
	}
	node *current=r;
	node *parent=NULL;
	int flag=0;
	while(current!=NULL && flag==0)
	{
		if(data<current->data)
		{
			parent=current;
			current=current->left;
		}
		else if(data>current->data)
		{
			parent=current;
			current=current->right;
		}
		else if(data==current->data)
			flag=1;
	}
	if (flag==0)
	{
		printf("element not found");
		return(r);
	}

	int op;
	if (current->left==NULL && current->right==NULL)
		op=1;
	else if(current->left==NULL || current->right==NULL)
		op=2;
	else
		op=3;
	
	if (op==1)
	{
		if (parent==NULL)
		{
			return(NULL);
		}
		else if(parent->left==current)
		{
			parent->left=NULL;
		}
		else 
		{
			parent->right=NULL;
		}
		free(current);
	}

	else if(op==2)
	{
		if(parent==NULL)
		{
			if(current->left==NULL)
				return current->right;
			else
				return current->left;
		}
		else if(parent->left==current)
		{
			if(current->left==NULL)
				parent->left=current->right;
			else
				parent->left=current->left;
		}
		else if(parent->right==current)
		{
			if(current->left==NULL)
				parent->right=current->right;
			else
				parent->right=current->left;
		}
		free(current);
	}

	else if(op==3)
	{
		node *ptr=succ(current);
		int item1=ptr->data;
		r=delete(r,item1);
		current->data=item1;
	}
	return(r);
}


node * succ(node *p)
{
	node *ptr1=p->left;
	while(ptr1->left!=NULL)
		ptr1=ptr1->left;
	return ptr1;
}

