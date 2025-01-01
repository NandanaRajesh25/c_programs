 #include<stdio.h>
int main()
{
	int n,i,k,count=0,a[50],b[50],temp=0;
	printf("enter no of elements in array:");
 	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("enter element ");
		scanf("%d",&a[i]);
	}
	for (i=0;i<n-1;i++)
	{
		for (k=0;k<n-1;k++)
		{
			if (a[k]>a[k+1])
			{
				temp=a[k];
				a[k]=a[k+1];
				a[k+1]=temp;
			}
		}
	}
	for (i=0;i<n-1;i++)
	{
		if (a[i]==a[i+1])
		{
			count++;
			for (k=i+1;k<n-count;k++)
			{
				temp=a[k]; 
				a[k]=a[k+1];
				a[k+1]=temp;
			}
		}
	}
	
	for (i=0;i<n-count;i++)
	{
		printf("%d\t",a[i]);
	}
	return(0);
}