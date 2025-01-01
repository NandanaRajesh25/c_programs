#include<stdio.h>
#include<stdlib.h>
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
int is_alpha(char);
int is_digit(char);
//int posteval(char arr[]);
int evaluatePostfix(char postfix[]);
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
	printf("\n eval result is:%d ",evaluatePostfix(post));
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
	if (a>=48 && a<=57)
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

/*int posteval(char arr[])
{
	int i=0,result=0,value=0,val;
	char re[10],temp1,temp2,c1;
	stack eval;
	create(&eval);
	 
	while (arr[i]!='\0')
	{
		fflush(stdin); 
		if (isoperand(arr[i]))
		{
			//printf("isoperand");
			if (is_alpha(arr[i]))
			{
				printf("\nenter value for %c: ",arr[i]);
				scanf("%d",&val);
				//fflush(stdin); 
				//printf("val =%c",val);
				//printf("req char=%c",val+'0');
				push(&eval,val+'0');
			}
			else if(is_digit(arr[i]))
			{
				//printf("digit");
				//value=(arr[i]-'0');
				push(&eval,arr[i]);
			}
		}
		else if(arr[i]=='+' || arr[i]=='-' || arr[i]=='*' || arr[i]=='/')
		{
			//int p1,p2;
			char no1,no2;
			no2=pop(&eval);
			//p2=no2-'0';
			
			no1=pop(&eval);
			//p1=no1-'0';
			//printf("no1=%c", no1);
			//no2=temp2-'0';
			//no1=temp1-'0';
			switch (arr[i]) 
			{
                		case '+':
					c1=(no1-'0'+no2-'0')+'0';
					//printf("result= %d",c1-'0');
                    			push(&eval,c1);
                    			break;
                		case '-':
					c1=(no1-'0'-no2-'0')+'0';
					//printf("re  sult= %c",c1);
                    			push(&eval,c1);
                    			break;
                		case '*':
					c1=((no1-'0')* (no2-'0'))+'0';
					//printf("result= %d",c1-'0');
                    			push(&eval,c1);
                    			break;
                		case '/':
                    			if (no2-'0' ==0);
					{
                        			printf("Division by zero\n");
                      				exit(1);
                    			}
					c1=((no1-'0')/(no2-'0'))+'0';
					//printf("result= %c",c1);
                    			push(&eval,c1);
                    			break;
            		}
		}
		i++;
	}
	int n=pop(&eval) -'0';
	//printf("last res=%d", n);
	return n;	
//return pop(&eval) -'0';
}*/

int evaluatePostfix(char postfix[]) {
    stack q;
    create(&q);
    
    int i = 0;
    char c;

    while ((c = postfix[i++]) != '\0') {
        if (is_digit(c) || is_alpha(c)) {
            push(&q, c);
        } else {
            // Perform operation for operators (+, -, *, /, etc.)
            int operand2 = pop(&q) - '0';
            int operand1 = pop(&q) - '0';

            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", c);
                    exit(1);
            }
            push(&q, result + '0');
        }
    }

    if (q.top != 0) {
        printf("Invalid expression.\n");
        exit(1);
    }

    return q.str[0] - '0';
}

	