#include<stdio.h>
int main()
{
	int n,i,k,j=0,a[50],b[50],temp=0;
	printf("enter no of elements in array:");
 	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("enter element ");
		scanf("%d",&a[i]);
	}
	for (i=0;i<n;i++)
	{
		for (k=i;k<n;k++)
		{
			if (a[k]>a[k+1])
			{
				temp=a[k];
				a[k]=a[k+1];
				a[k+1]=temp;
			}
		}
	}
	for (i=0;i<n;i++)
 	{
		if (a[i]!=a[i+1])
 		{
			b[j]=a[i];
			j++;
		}
	}
	printf("array after removing duplicates are:");
	for (i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return(0);
}