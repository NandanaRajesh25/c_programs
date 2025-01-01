#include<stdio.h>
#include<stdlib.h>


struct node
{
	int exp;
	int coeff;
	struct node *next;
};
typedef struct node node;

node * insert(node *start,int c,int e);
node * create(int c,int e);
node * add(node *p1,node *p2);
void display(node *start);
int main()
{
	int i,co,ex;
	node *poly1=NULL;
	node *poly2=NULL;
	for(i=0;i<3;i++)
	{
		printf("enter coeff and exp of poly 1: ");
		scanf("%d%d",&co,&ex);
		poly1=insert(poly1,co,ex);
	}
	display(poly1);
	printf("\n");
	for(i=0;i<2;i++)
	{
		printf("enter coeff and exp of poly 2: ");
		scanf("%d%d",&co,&ex);
		poly2=insert(poly2,co,ex);
	}
	node *result=add(poly1,poly2);
	
	display(poly2);
	printf("\n");
	display(result);
	return(0);
}


node * insert(node *start,int c,int e)
{
	node *newnode=create(c,e);
	if (start==NULL)
	{
		start=newnode;
		return start;
	}
	node *ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	return(start);
}

node * create(int c,int e)
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->exp=e;
	new->coeff=c;
	new->next=NULL;
	return(new);
}

node * add(node *p1,node *p2)
{
	node *result=NULL;
	node *ptr1=p1;
	node *ptr2=p2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->exp==ptr2->exp)
		{
			int sum=ptr1->coeff+ptr2->coeff;
			result=insert(result,sum,ptr1->exp);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->exp>ptr2->exp)
		{
			result=insert(result,ptr1->coeff,ptr1->exp);
			ptr1=ptr1->next;
		}
		else
		{
			result=insert(result,ptr2->coeff,ptr2->exp);
			ptr2=ptr2->next;
		}
	}
	while(ptr1!=NULL)
	{
		result=insert(result,ptr1->coeff,ptr1->exp);
		ptr1=ptr1->next;
	}
	while(ptr2!=NULL)
	{
		result=insert(result,ptr2->coeff,ptr2->exp);
		ptr2=ptr2->next;
	}
	return(result);
}

void display(node *start)
{
	if(start==NULL)
	{
		printf("zero poly");
		return;
	}
	node *ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->exp!=0)
			printf("%dx^%d",ptr->coeff,ptr->exp);
		else
			printf("%d",ptr->coeff);
		if(ptr->next!=NULL)
			printf("+");
		ptr=ptr->next;
	}
	return;
}