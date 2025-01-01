/* #include<stdio.h>
int main()
{
	int a[5];
	for(int i=0;i<5;i++)
	{
		printf("\nenter value:");
		scanf("%d",&a[i]);
		
	}
	for(int i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}
	return(0);
}
*/


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int r,c,**a;
	printf("enter row nd column of array");
	scanf("%d%d",&r,&c);
	a=(int **)malloc(r*c*sizeof(int));
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("\nenter value:");
			scanf("%d",*(a+i)+j);
		}
		
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("%d\t",*(*(a+i)+j));
		}
		printf("\n");
	}
	return(0);
}

/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,*a;
	printf("enter size of array");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		printf("\nenter value:");
		scanf("%d",a+i);
		
	}
	for(int i=0;i<n;i++)
	{
		printf("%d\t",*(a+i));
	}
	return(0);
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p;
	p=(int *)malloc(sizeof(int));
	printf("enter value");
	scanf("%d",p);
	printf("value is: %d",*p);
}
*/