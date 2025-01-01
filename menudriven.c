#include<stdio.h>
void sum(int,int,int,int,int [][20],int [][20]);
void transpose(int,int,int,int,int [][20],int [][20]);
void multiply(int,int,int,int,int [][20],int [][20]);
void display(int,int,int,int,int [][20],int [][20]);
int main()
{
	int r1,r2,c1,c2,i,j,n;
	int a[20][20],b[20][20];
	printf("enter no of rows nd columns in matrix 1:");
	scanf("%d%d",&r1,&c1);
	printf("enter no of rows nd columns in matrix 1:");
	scanf("%d%d",&r2,&c2);
	for (i=0;i<r1;i++)
	{
		for (j=0;j<c1;j++)
		{
			printf("enter element (%d,%d) of matrix 1",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	for (i=0;i<r2;i++)
	{
		for (j=0;j<c2;j++)
		{
			printf("enter element (%d,%d) of matrix 2",i+1,j+1);
			scanf("%d",&b[i][j]);
		}
	}
	do
	{
		printf("1-sum,2-transpose,3-multiply,4-display,5-exit");
		scanf("%d",&n);
		if (n==1)
		{
			sum(r1,r2,c1,c2,a,b);
		}
		else if (n==2)
		{
			transpose(r1,r2,c1,c2,a,b);
		}
		else if (n==3)
		{
			multiply(r1,r2,c1,c2,a,b);
		}
		else if (n==4)
		{
			display(r1,r2,c1,c2,a,b);
		}
	}while (n!=5); 
	return(0);
}

void sum(int x1,int x2,int y1,int y2,int p[20][20],int q[20][20])
{
	int i,j;
	int c[20][20];
	if (x1==x2 && y1==y2)
	{
		for (i=0;i<x1;i++)	
		{
			for (j=0;j<y1;j++)
			{
				c[i][j]=p[i][j]+q[i][j];
				printf("%d\t",c[i][j]);
			}
			printf("\n");
		}
	}
	return;
}

void transpose(int x1,int x2,int y1,int y2,int p[20][20],int q[20][20])
{
	int i,j;
	int c[20][20];
	for (i=0;i<y1;i++)	
	{
		for (j=0;j<x1;j++)
		{
			c[i][j]=p[j][i];
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	return;
}

void multiply(int x1,int x2,int y1,int y2,int p[20][20],int q[20][20])
{
	int i,j,k;
	int c[20][20];
	if (y1==x2)
	{
		for (i=0;i<x1;i++)	
		{
			for (j=0;j<y2;j++)
			{
				c[i][j]=0;
				for (k=0;k<y1;k++)
				{
					c[i][j]=c[i][j]+p[i][k]*q[k][j];
				}
			}
		}
		for (i=0;i<x1;i++)
		{
			for (j=0;j<y2;j++)
			{
				printf("%d\t",c[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("no of rows in 2nd nd columns in 1st don't match");
	}
	return;
}

void display(int x1,int x2,int y1,int y2,int p[20][20],int q[20][20])
{
	int i,j;
	for (i=0;i<x1;i++)	
	{
		for (j=0;j<y1;j++)
		{
			 printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
	for (i=0;i<x2;i++)
	{
		for (j=0;j<y2;j++)
		{
			printf("%d\t",q[i][j]);
		}
		printf("\n");
	}
	 return;
}

