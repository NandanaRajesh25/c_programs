#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

};
typedef struct Node tree;

struct fifo 
{
    	tree * str[100];
	int front;
	int rear;
};
typedef struct fifo queue;

struct lifo
{
	tree * ar[100];
    	int top;
};
typedef struct lifo stack;

tree * create();
tree * insert(tree *root,int item);
void inorder(tree *r);
void create_stack(stack *s);
void push(stack *s,tree *t);
tree * pop(stack *s);
void search(tree *r,int key);
void delete(tree *r,int item);
tree * succ(tree *t);

int main()
{
	
	int n,x,i,key,d_item;
	
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
	printf("\nenter element to search:");
	scanf("%d",&key);
	search(root,key);
	printf("\nenter element to delete:");
	scanf("%d",&d_item);
	delete(root,d_item);
	inorder(root);
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


tree * insert(tree * root, int data) 
{
    	tree * newNode = create();
	newNode->data=data;
   	 if (root == NULL) 
	{
        	return newNode;
    	}

    	tree *current = root;
    	tree *parent = NULL;

    	while (current != NULL) 
	{
        	parent = current;

        	if (data < current->data) 
		{
            		current = current->left;
        	} 
		else if (data > current->data) 
		{
           		 current = current->right;
        	} 
		else 
		{
            // Duplicate values are not allowed in this example.
            		free(newNode);
            		return root;
        	}
    	}

    	if (data < parent->data) 
	{
        	parent->left = newNode;
    	} 
	else 
	{
        	parent->right = newNode;
    	}

    return root;
}

void search(tree *r,int key)
{
	tree *ptr=r;
	int flag=0;
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			printf("element found: %d",ptr->data);
			flag=1;
			break;
		}
		else if(ptr->data<key)
		{
			ptr=ptr->right;
		}
		else 
		{
			ptr=ptr->left;
		}
	}
	if(flag==0)
	{
		printf("element not found");
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

void delete(tree *r,int item)
{
	tree *current=r;
	int flag=0;
	int op=0;
	int item1=0;
	tree *parent=NULL;
	while(current!=NULL && flag==0)
	{
		if(item<current->data)
		{
			parent=current;
			current=current->left;
		}
		else if(item>current->data)
		{
			parent=current;
			current=current->right;
		}
		else if(current->data==item)
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("item does not exist");
		return;
	}
	
	if(current->left==NULL && current->right==NULL)
	{
		op=1;
	}
	else if(current->left!=NULL && current->right!=NULL)
	{
		op=2;
	}
	else
	{
		op=3;
	}
	
	switch(op)
	{
		case 1:
		{
			if(parent->left==current)
				 parent->left=NULL;
			else
				parent->right=NULL;
			printf("element deleted: %d\n",current->data);
			free(current);
			return;
		}

		case 2:
		{
    			if (parent->left == current)
    			{
        			if (current->left == NULL)
       				{
            				parent->left = current->right;
        			}
        			else
        			{
            				parent->left = current->left;
        			}
    			}
    			else
    			{
        			if (parent->right == current)
        			{
            				if (current->left == NULL)
            				{
                				parent->right = current->right;
            				}
            				else
           		 		{
                				parent->right = current->left;
            				}
        			}
    			}
    			printf("element deleted: %d\n", current->data);
    			free(current);
    			return;
		}

		case 3:
		{
			tree *ptr1=succ(current);
			if(ptr1!=NULL)
			{
				item1=ptr1->data;
				delete(r,item1);
				current->data=item1;
			}
			else
			{
				printf("no successor");
			}
			return;
		}
	}
}
			
			
tree * succ(tree *t)
{
	tree *ptr1=t->right;
	if(ptr1!=NULL)
	{
		while(ptr1->left!=NULL)
		{
			ptr1=ptr1->left;
		}
	}
	return(ptr1);
}

		
		
			
				
		
			