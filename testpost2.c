#include<stdio.h>
#include<stdlib.h>
struct lifo
{
	int str[100];
	int top;
};
typedef struct lifo stack;
void create(stack *s);
void push(stack *s,int);
int pop(stack *s);
int isp(char);
int icp(char);
int isoperand(char);
int isempty(stack *s);
int posteval(char arr[]);
int main()
{
	int i=0,j=0,temp;
	stack e;
	char exp[100],x,post[100];
	printf("Enter infix expression:");
	scanf("%s",exp);
	create(&e);
	x=exp[0];
	printf("\nPostfix conversion is: ");
	while (x!='\0')
	{
		if (isoperand(x))
		{
			printf("%c",x);
			post[j++]=x;
		}
		else if(x==')')
		{
			while (e.str[e.top]!='(')
			{
				temp=pop(&e);
				printf("%c",temp);
				post[j++]=temp;
			}
			pop(&e);
		}
		else
		{
			while((!isempty(&e)) && (isp(e.str[e.top])>=icp(x)))
			{
				temp=pop(&e);
				printf("%c",temp);
				post[j++]=temp;
				//printf("%c",pop(&e));
			}
			push(&e,x);
		}
		
		x=exp[++i];
	}
	while (!isempty(&e))
	{
		printf("%c",e.str[e.top]);
		post[j++]=e.str[e.top];
		pop(&e);
	}
	post[j]='\0';
	printf("\nstring is:%s",post);
	printf("\nEvaluated result is:%d ",posteval(post));
	return(0);
}

void create(stack *s)
{
	s->top=-1;
}

void push(stack *s,int item)
{
	if (s->top==99)
		printf("stack overflow");
	else
	{
		s->top++;
		s->str[s->top]=item;
	}
}

int pop(stack *s)
{
	if (!isempty(s))
		return(s->str[s->top--]);
}

int isp(char a)
{
	switch (a)
	{
		case '*':
			return 4;
                case '/':
                	return 4;
                case '+':
                case '-':
                	return 2;
                case '^':
                	return 5;
                case '(':
                	return 0;
	}
}

int icp(char a)
{
	switch (a)
	{
		case '*':
                	return 3;
           	case '/':
                	return 4;
           	case '+':
           	case '-':
                	return 1;
           	case '^':
                	return 6;
            	case '(':
                	return 9;
            	case ')':
                	return 0;
	}
}

int isoperand(char a)
{
	if (a=='+' || a=='-' || a=='*' || a=='/' || a=='(' || a==')')
		return(0);
	else
		return(1);
} 

int isempty(stack *s)
{
	if (s->top==-1)
		return(1);
	else
		return(0);
}

int posteval(char arr[])
{
	int i=0,val;
	char c1;
	stack eval;
	create(&eval);
	 
	while (arr[i]!='\0')
	{
		//fflush(stdin); 
		if (isoperand(arr[i]))
		{
			/*if (is_alpha(arr[i]))
			{*/
				printf("\nEnter value for %c: ",arr[i]);
				scanf("%d",&val); 
				push(&eval,val);
			/*}
			else if(is_digit(arr[i]))
			{
				push(&eval,arr[i]);
			}*/
		}
		else if(arr[i]=='+' || arr[i]=='-' || arr[i]=='*' || arr[i]=='/')
		{
			int no1,no2;
			no2=pop(&eval);
			no1=pop(&eval);
			switch (arr[i]) 
			{
                		case '+':
					//c1=(no1-'0'+no2-'0')+'0';
                    			push(&eval,no1+no2);
                    			break;
                		case '-':
					//c1=(no1-'0'-no2-'0')+'0';
                    			push(&eval,no1-no2);
                    			break;
                		case '*':
					//c1=((no1-'0')* (no2-'0'))+'0';
                    			push(&eval,no1*no2);
                    			break;
                		case '/':
                    			if (no2==0)
					{
                        			printf("Division by zero not possible\n");
                      				exit(1);
                    			}
					//c1=((no1-'0')/(no2-'0'))+'0';
                    			push(&eval,no1/no2);
                    			break;
            		}
		}
		i++;
	}
	int n=pop(&eval);
	return n;
}

 