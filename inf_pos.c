#include<stdio.h>
struct lifo
{
	char str[100];
	int top;
};
typedef struct lifo stack;
void create(stack *s);
void push(stack *s,char);
char pop(stack *s);
int isp(char);
int icp(char);
int isoperand(char);
int isempty(stack *s);
int main()
{
	int i=0;
	stack e;
	char exp[100],x;
	printf("enter infix expression:");
	scanf("%s",exp);
	create(&e);
	x=exp[0];
	while (x!='\0')
	{
		if (isoperand(x))
		{
			printf("%c",x);
		}
		else if(x==')')
		{
			while (e.str[e.top]!='(')
			{
				printf("%c",pop(&e));
			}
			pop(&e);
		}
		else
		{
			while(isp(e.str[e.top])>=icp(x))
			{
				printf("%c",pop(&e));
			}
			push(&e,x);
		}
		
		x=exp[++i];
	}
	while (!isempty(&e))
	{
		printf("%c",e.str[e.top]);
		pop(&e);
	}
	return(0);
}

void create(stack *s)
{
	s->top=-1;
}

void push(stack *s,char item)
{
	if (s->top==99)
		printf("stack overflow");
	else
	{
		s->top++;
		s->str[s->top]=item;
	}
}

char pop(stack *s)
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
	if ((a>=97 && a<=122) || (a>=65 && a<=90)) 
		return(1);
	else
		return(0);
} 

int isempty(stack *s)
{
	if (s->top==-1)
		return(1);
	else
		return(0);
}

	
	