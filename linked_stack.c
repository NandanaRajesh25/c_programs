#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node stack;
stack * create();
stack * push(stack *t,int);
stack * pop(stack *t);
void display(stack *t);
int main()
{
	int op,data;
	stack *top=NULL;
	printf("\n1 : Push\n");
	printf("2 : Pop\n");
	printf("3 : Display stack\n");
	printf("0 : Exit\n");
	printf("Enter option:");
	scanf("%d",&op);
	do
	{
		switch(op)
		{
			case 1:
			{
				printf("Enter no to push: ");
				scanf("%d",&data);
				top=push(top,data);
				printf("Element inserted\n");
				break;
			}
			case 2:
			{
				top=pop(top);
				break;
			}
			case 3:
			{
				display(top);
				break;
			}
		}
		printf("\nEnter option:");
		scanf("%d",&op);
	}while (op!=0);
	return(0);
				
}

stack * create()
{
	stack *t;
	t=(stack *)malloc(sizeof(stack));
	t->data=0;
	t->next=NULL;
	return (t);
}

stack * push(stack *t,int x)
{
	stack *new;
	new=create();
	new->data=x;
	if (t==NULL)
	{
		new->next=NULL;
		t=new;
	}
	else
	{
		new->next=t;
		t=new;
	}
	return(t);
}

stack * pop(stack *t)
{
	if (t==NULL)
	{
		printf("Stack underflow");
		return(t);
	}
	else
	{
		printf("Element removed is %d",t->data);
		if(t->next==NULL)
		{
			free(t);
			t=NULL;
		}	
		else
		{
			stack *p=t->next;
			free(t);
			t=p;
		}
	}
	return(t);
}

void display(stack *t)
{
	stack *temp=t;
	if (temp==NULL)
		printf("Stack is empty");

	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
