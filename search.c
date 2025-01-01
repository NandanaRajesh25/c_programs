#include<stdio.h>
#include<stdlib.h>
#define max 10
void linear(int arr[],int n,int ele);
void binary(int arr[],int n,int ele);
void bubble(int arr[],int n);
int main()
{
	int n,a[max],i,ele,op;
	printf("enter number of elements in array");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\n1.linear,2.binary :");
	scanf("%d",&op);
	do
	{
	switch(op)
	{
		case 1:
		{
			printf("enter element to search");
			scanf("%d",&ele);
			linear(a,n,ele);
			break;
		}
		case 2:
		{
			printf("enter element to search");
			scanf("%d",&ele);
			bubble(a,n);
			binary(a,n,ele); 
			break;
		}
	}
	printf("\n1.linear,2.binary :");
	scanf("%d",&op);
	}
	while(op!=0);
	return(0);
}

void linear(int arr[],int n,int ele)
{
	int i;
	for (i=0;i<n;i++)
	{
		if (arr[i]==ele)
		{
			printf("element found");
			return;
		}
	}
	printf("element not found");
	return;
}

void binary(int arr[],int n,int ele)
{
	int l=0,h=n-1,m;
	while(l<=h)
	{
		m=(l+h)/2;
		if(ele==arr[m])
		{
			printf("element found");
			return;
		}
		else if(ele>arr[m])
		{
			l=m+1;
		}
		else
		{
			h=m-1;
		}
	}
	printf("element not found");
}

void bubble(int arr[],int n)
{
	int i,temp=0;
	for(i=0;i<n;i++)
	{
		if (arr[i]>arr[i+1])
		{
			temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
		}
	}
}
	
	