#include<stdio.h>
#include <stdlib.h>
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
int posteval(char expression[]);
int main()
{
	int i=0,j=0;
	stack e;
	char exp[100],x,post[100],temp;
	printf("enter infix expression:");
	scanf("%s",exp);
	create(&e);
	x=exp[0];
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
	printf("\n%s",post);
	printf("\n eval result is:%d ",posteval(post));
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
	if (a=='+' || a=='-' || a=='*' || a=='/' || a=='(' || a==')')
		return(0);
	else
		return(1);
} 


int is_alpha(char a)
{
	if ((a>=65 && a<=90) || (a>=97 && a<=122))
		return(1);
	else
		return(0);
}

int is_digit(char a)
{
	if (a>=30 && a<=39)
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

int posteval(char expression[])
 {
    stack eval;
    create(&eval);

    for (int i = 0; expression[i]; i++) 
	{
        if (is_alpha(expression[i])) 
	{
            char value;
            printf("Enter value for %c: ", expression[i]);
            scanf(" %c", &value);
            push(&eval, value);
        } 
	else if (is_digit(expression[i])) 
	{
            int value = 0;
            while (is_digit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Backtrack one character
            push(&eval, value + '0'); // Convert numeric value to character and push
        } 
	else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') 
	{
            char operand2 = pop(&eval);
            char operand1 = pop(&eval);

            switch (expression[i]) 
		{
                case '+':
                    push(&eval, operand1 + operand2 - '0'); // Convert back to numeric and push
                    break;
                case '-':
                    push(&eval, operand1 - operand2 + '0');
                    break;
                case '*':
                    push(&eval, operand1 * operand2 - '0');
                    break;
                case '/':
                    if (operand2 == '0') {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(&eval, operand1 / operand2 + '0');
                    break;
            }
        }
    }

    return pop(&eval) - '0'; // Convert the result character to an integer
}

 



 



