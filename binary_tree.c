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

struct QueueNode 
{
    struct TreeNode* data;
    struct QueueNode* next;
};
tree * insert(tree *r,int data);
tree * create();
void inorder(tree *r);
void push(stack **s,tree *t);
tree * pop(stack **s);
struct QueueNode* createQueueNode(struct TreeNode* data);
void enqueue(struct QueueNode** front, struct QueueNode** rear, struct TreeNode* data);
struct TreeNode* dequeue(struct QueueNode** front, struct QueueNode** rear);
void insertLevelOrder(struct TreeNode** root, int data);
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
		root=insertLevelOrder(&root,x);
	}
	inorder(root);
	return(0);
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

struct QueueNode* createQueueNode(struct TreeNode* data) 
{
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct QueueNode** front, struct QueueNode** rear, struct TreeNode* data) 
{
    struct QueueNode* newNode = createQueueNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}


struct tree* dequeue(struct QueueNode** front, struct QueueNode** rear) 
{
    if (*front == NULL) {
        return NULL;
    }
    struct tree* data = (*front)->data;
    struct QueueNode* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return data;
}


void insertLevelOrder(struct tree** root, int data) 
{
    struct tree* newNode = create(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;

    enqueue(&front, &rear, *root);

    while (front != NULL) {
        struct TreeNode* temp = dequeue(&front, &rear);

        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            enqueue(&front, &rear, temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            enqueue(&front, &rear, temp->right);
        }
    }
}

	
		
			
