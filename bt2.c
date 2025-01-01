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
	tree *tn;
    struct lifo *next;
};
typedef struct lifo stack;
tree * insert(tree *r,int data);
tree * create();
void inorder(tree *r);
void push(stack **s,tree *t);
tree * pop(stack **s);
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
	return(0);
}

/*tree * insert(tree *r,int data)
{
	tree *new;
	new=create();
	new->data=data;
	if (r==NULL)
	{
		r=new;
		return(r);
	}

	tree *ptr=r;
	while(1)
	{
		if(ptr->left==NULL)
		{
			ptr->left=new;
			break;
		}

else if(ptr->right==NULL)
{
ptr->right=new;
break;
}
else
ptr=ptr->left;

}
return(r);
}
*/

tree * create()
{
	tree *t;
	t=(tree *)malloc(sizeof(tree));
	t->data=0;
	t->left=NULL;
	t->right=NULL;
	return (t);

}

void inorder(tree *r)
{
	stack *s=NULL;
	tree *current=r;
	while(current!=NULL || s!=NULL)
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

void push(stack **top, tree *tn)
{
    stack *newel = (stack*)malloc(sizeof(stack));
    newel->tn = tn;
    newel->next = *top;
    *top = newel;
}

tree * pop(stack **top)
{
	if (*top == NULL)
	{
        	return NULL;
    	}
    	tree *pop_item = (*top)->tn;
    	stack *temp = *top;
    	*top = (*top)->next;
    	free(temp);
    	return pop_item;
}

tree* insert(tree* root, int data) 
{
    	tree* newNode = create();
	new->data=data;
	
    	if (root == NULL) 
	{
        	return newNode;
    	}

    // Create a queue for level order traversal
    	struct Queue* queue = createQueue(1000);

    // Enqueue the root
    	enqueue(queue, root);

   	 while (queue->front != -1) 
	{
        // Dequeue the front node and insert the data
        	tree* temp = dequeue(queue);

        	if (temp->left == NULL) 
		{
            		temp->left = newNode;
            		free(queue->array);
            		free(queue);
            		return root;
        	} 
		else 
		{
            		enqueue(queue, temp->left);
        	}

        	if (temp->right == NULL) 
		{
            		temp->right = newNode;
            		free(queue->array);
            		free(queue);
            		return root;
        	} 
		else 
		{
            		enqueue(queue, temp->right);
        	}
    	}

    	free(queue->array);
    	free(queue);
    	return root;
}
