#include<stdio.h>
int fact(int);
int factorial(int);
int main()
{
	int n,f1,f2;
	printf("enter no to find factorial");	
	scanf("%d",&n);
	f1=fact(n);
	f2=factorial(n);
	printf("factorial by non recursion is %d\n",f1);
	printf("factorial by recursion is %d\n",f2);
	return(0);
}

int fact(int a)
{
	int fact=0,i;
	if (a!=0)
	{
		fact=1;
		for (i=1;i<=a;i++)
		{
			fact=fact*i;
		}
	}
	return(fact);
}

int factorial(int a)
{
	if (a==1)
	{
		return(1);
	}
	else
	{
		return(a*fact(a-1));
	}
}