#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node
{
	int coef;
	int exp;
	struct Node *next;
};
typedef struct Node term;
term * create();
term * insert(term *t,int,int);
term * add(term *p1, term *p2);
term* multiply(term *p1, term *p2);
void display(term *t);
int main()
{
	int n1,n2,co,ex,i;
	term *poly1=NULL;
	term *poly2=NULL;
	printf("enter no of terms in poly 1:");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		printf("enter co and exp in poly 1:");
		scanf("%d%d",&co,&ex);
		poly1=insert(poly1,co,ex);
	}
	printf("enter no of terms in poly 2:");
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	{
		printf("enter co and exp in poly 2:");
		scanf("%d%d",&co,&ex);
		poly2=insert(poly2,co,ex);
	}
	printf("poly 1:\n");
	display(poly1);
	printf("poly 2:\n");
	display(poly2);
	term *sum=NULL;
	term *mul=NULL;
	sum=add(poly1,poly2);
	mul=multiply(poly1,poly2);
	printf("sum:\n");
	display(sum);
	printf("product\n");
	display(mul);
	return(0);
}

term * create()
{
	term *t;
	t=(term *)malloc(sizeof(term));
	t->coef=0;
	t->exp=0;
	t->next=NULL;
	return (t);
	
}

term * insert(term *t,int x,int y)
{
	term *new;
	new=create();
	new->coef=x;
	new->exp=y;
	new->next=NULL;
	if (t==NULL)
	{
		t=new;
	}
	else
	{
		term *p=t;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=new;
	}
	return(t);
}

void display(term *t)
{
	if (t == NULL) 
	{
        	printf("0\n");
        	return;
    	}

    	while (t != NULL) 
	{
        	printf("%dx^%d", t->coef, t->exp);
        	t = t->next;
        	if (t != NULL) 
		{
            		printf(" + ");
        	}
    	}
   	printf("\n");
}

term * add(term *p1, term *p2) 
{
	term* result = NULL;
    	while (p1 != NULL && p2 != NULL) 
	{
        	if (p1->exp == p2->exp) 
		{
			int sum = p1->coef + p2->coef;
            		if (sum != 0) 
			{
                		result=insert(result, sum, p1->exp);
            		}
           	 	p1 = p1->next;
            		p2 = p2->next;
            		
        	} 	
		else if (p1->exp > p2->exp) 
		{
            		result=insert(result, p1->coef, p1->exp);
            		p1 = p1->next;
       	 	} 
		else 
		{
            		
			result=insert(result, p2->coef, p2->exp);
            		p2 = p2->next;
        	}
   	}

    	while (p1 != NULL) 
	{
        	result=insert(result, p1->coef, p1->exp);
        	p1 = p1->next;
    	}
	
    	while (p2 != NULL) 
	{
        	result=insert(result, p2->coef, p2->exp);
        	p2 = p2->next;
    	}
    	return result;
}

term* multiply(term *p1, term *p2)
{
	term* result1 = NULL;
    	while (p1 != NULL) 
	{
        	term* temp = p2;
        	while (temp != NULL) 
		{
            		result1=insert(result1, p1->coef * temp->coef, p1->exp + temp->exp);
            		temp = temp->next;
        	}
        	p1 = p1->next;
    	}
    	return result1;
}

