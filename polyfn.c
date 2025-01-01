#include<stdio.h>
#define max 101
struct polynomial
{
	int deg;
	int coeff[max];
};
typedef struct polynomial poly;
void zero(poly *p);
int iszero(poly *p);
int coef(poly *p,int);
int lead_exp(poly *p);
void attach(poly *p,int,int);
void remove1(poly *p,int);
void add(poly *x,poly *y,poly *z);
void printpoly(poly *p);
int main()
{
	int i,isze,co,newco,newex,op,ans,maxex ;
	poly a,b,c;
	zero(&a);
	zero(&b);
	zero(&c);
	printf("enter deg of poly 1:");
	scanf("%d",&a.deg);
	for (i=0;i<a.deg+1;i++)
	{
		printf("enter coeff for expon %d: ",i);
		scanf("%d",&a.coeff[i]);
	}
	printf("enter deg of poly 2:");
	scanf("%d",&b.deg);
	for (i=0;i<b.deg+1;i++)
	{
		printf("enter coeff for expon %d: ",i);
		scanf("%d",&b.coeff[i]);
	}
	printf("\n1 : Check if poly is zero\n");
	printf("2 : Get coefficient\n");
	printf("3 : Get degree\n");
	printf("4 : Attach term\n");
	printf("5 : Remove term\n");
	printf("6 : Polynomial Addition\n");
	printf("7 : Display polynomial\n");
	printf("0 : Exit\n");
	printf("enter option: ");
	scanf("%d",&op);
	
	do
	{
		switch(op)
		{
		case 1:
		{
			isze=iszero(&a);
			if (isze==1)
				printf("zero poly");
			else
				printf("not zero");
			break;
		}
		case 2:
		{
			printf("enter exponent to find coeff: ");
			scanf("%d",&co);
			ans=coef(&a,co);
			printf("%d",ans);
			break;
		}
		case 3:
		{
			maxex=lead_exp(&a);
			printf("%d",maxex);
			break;
		}
		case 4:
		{
			printf("enter coeff nd exp to attach: ");
			scanf("%d%d",&newco,&newex);
			attach(&a,newco,newex);
			//printpoly(&a);
			break;
		}
		case 5:
		{
			printf("enter exp to remove:");
			scanf("%d",&newex);
			remove1(&a,newex);
			break;	
		}
		case 6:
		{
			add(&a,&b,&c);
			//printpoly(&c);
			break;
		}
		case 7:
		{
			printpoly(&a);
			break;
		}
		};
		printf("\nenter option: ");
		scanf("%d",&op);
	}
	while (op!=0);
	return(0);
	
}

void printpoly(poly *p)
{
	int i;
	int pos=0;
	for (i=0;i<p->deg;i++)
	{
		if(p->coeff[i]!=0)
		{
			printf("%dx^%d + ",p->coeff[i],i);
		}
	}
	printf("%dx^%d",p->coeff[i],i);
}

void zero(poly *p)
{
	int i;
	p->deg=0;
	for(i=0;i<max+1;i++)
	{
		p->coeff[i]=0;
	}
}

int iszero(poly *p)
{
	int flag=1,i;
	for(i=0;i<max+1;i++)
	{
		if (p->coeff[i]!=0)
		{
			flag=0;
			break;
		}
	}
	if (flag==0)
		return(0);
	else
		return(1);
}

int coef(poly *p,int expon)
{
	if(p->coeff[expon]!=0)
		return(p->coeff[expon]);
	else
		return(0);
}

int lead_exp(poly *p)
{
	return(p->deg);
}

void attach(poly *p,int c,int expon)
{
	if (p->coeff[expon]!=0)
	{
		printf("error\n")	;
		//return(p);
	}
	else
	{
		p->coeff[expon]=c;
		if (expon>p->deg)
			p->deg=expon;
		printpoly(p);
		//return(p);
	}
}

void remove1(poly *p,int expon)
{
	if(p->coeff[expon]==0)
	{
		printf("error");
		//return(p);
	}
	else
	{
		p->coeff[expon]=0;
		printpoly(p);
		//return(p);
	}
}

void add(poly *x,poly *y,poly *z)
{
	int i,maxexp;
	/*poly sum;
	zero(&sum);*/
	if(!iszero(x) && !iszero(y))
	{
		z->deg=(lead_exp(x)>lead_exp(y)?lead_exp(x):lead_exp(y));
		
		for (i=0;i<z->deg+1;i++)
		{
			z->coeff[i]=x->coeff[i]+y->coeff[i];
		}
		printf("worked");
	}
	printpoly(z);
}

	