#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node term;
term * create();
term * insert_f(term *t,int);
term * insert_r(term *t,int);
term * insert_m(term *t);
term * delete_f(term *t);
term * delete_r(term *t);
term * delete_m(term *t);
void display(term *t);
int main()
{
	int op,data;
	term *start=NULL;
	//create(start);
	printf("\n1 : Insert node at front\n");
	printf("2 : Insert node at rear\n");
	printf("3 : Insert node after given element\n");
	printf("4 : Delete node at front\n");
	printf("5 : Delete node at rear\n");
	printf("6 : Delete node whose data is given\n");
	printf("5 : Display linked list\n");
	printf("0 : Exit\n");
	printf("Enter option:");
	scanf("%d",&op);
	do
	{
		switch(op)
		{
			case 1:
			{
				printf("Enter no to insert: ");
				scanf("%d",&data);
				start=insert_f(start,data);
				printf("Element inserted\n");
				break;
			}
			case 2:
			{
				printf("Enter no to insert: ");
				scanf("%d",&data);
				start=insert_r(start,data);
				printf("Element inserted\n");
				break;
			}
			
			case 3:
			{
				
				start=insert_m(start);
				
				break;
			}

			case 4:
			{
				start=delete_f(start);
				break;
			}
	
			case 5:
			{
				start=delete_r(start);
				break;
			}

			case 6:
			{
				start=delete_m(start);
				break;	
			}
			case 7:
			{
				display(start);
				break;
			}
		}
		printf("\nEnter option:");
		scanf("%d",&op);
	}while (op!=0);
	return(0);
				
}

term * create()
{
	term *t;
	t=(term *)malloc(sizeof(term));
	t->data=0;
	t->next=NULL;
	return (t);
	
}


term * insert_f(term *t,int x)
{
	term *new;
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

term * insert_r(term *t,int x)
{
	term *new;
	new=create();
	new->data=x;
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

term * insert_m(term *t)
{
	int x,y,flag=0;
	
	if (t==NULL)
	{
		printf("List is empty,cannot insert after any given element");
		return(t);
	}
	else
	{
		printf("Enter no to insert: ");
		scanf("%d",&x);
		printf("Enter data after which element is to be inserted: ");
		scanf("%d",&y);
		term *new;
		new=create();
		new->data=x;
		term *p=t;
		if (p->next==NULL && p->data==y)
		{
			new->next=p->next;
			p->next=new;
			flag=1;
		}
		else
		{
			while(p->next!=NULL)
			{
				if (p->data==y)
				{
					new->next=p->next;
					p->next=new;
					flag=1;
					break;
				}
				p=p->next;
			}
		}
		if (flag!=1 && p->next==NULL)
		{
			if (p->data==y)
			{
				new->next=p->next;
				p->next=new;
				flag=1;
			}
		}

			/*if(p->data!=y)
				p=p->next;
			else
			{
				flag=1;
				if(p->next==NULL)
				{
					new->next=NULL;
					p->next=new;
					break;
				}
				else
				{
					new->next=p->next;
					p->next=new;
					break;
				}
			}*/
		
		
	}
	if (flag==0)
		printf("No matching data");
	else
		printf("Element inserted");
	return(t);
}

term * delete_f(term *t)
{
	if (t==NULL)
	{
		printf("No elements in list to delete");
		return(t);
	}
	else
	{
		if(t->next==NULL)
		{
			free(t);
			t=NULL;
		}	
		else
		{
			term *p=t->next;
			free(t);
			t=p;
		}
		printf("Element deleted");
	}
	return(t);
}

term * delete_r(term *t)
{
	if (t==NULL)
	{
		printf("No elements in list to delete");
		return(t);
	}
	else
	{
		if(t->next==NULL)
		{
			free(t);
			t=NULL;
		}
		else
		{
			term *p=t;
			while((p->next)->next!=NULL)
			{
				p=p->next;
			}
			free(p->next);
			p->next=NULL;
		}
		printf("Element deleted");
	}
	return(t);
}


term *delete_m(term *t) 
{
	int x, flag = 0;
    	if (t == NULL) 
	{
        	printf("No elements in list to delete\n");
        	return(t);
   	}

   	printf("Enter element to delete: ");
   	scanf("%d", &x);

    	term *prev = NULL;
    	term *p=t;

    	while (p!= NULL) 
	{
        	if (p->data == x) 
		{
            		if (prev != NULL) 
			{
                		prev->next=p->next;
                		free(p);
                		flag=1;
           		} 
			else 
			{
				term *temp = t;
                		t=t->next;
                		free(temp);
                		flag=1;
            		}
            		printf("Element deleted\n");
            		break;
       		}

        	prev=p;
        	p=p->next;
    	}

    	if (flag == 0) 
	{
        	printf("No matching data\n");
    	}

    	return(t);
}


void display(term *t)
{
	term *temp=t;
	if (temp==NULL)
		printf("No data in linked list");

	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
