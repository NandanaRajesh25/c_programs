 #include<stdio.h>
int main()
{
	int n,i,k,count=0,a[50],b[50],temp=0,j;
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
	for (i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	for (i=0;i<n-count-1;i++)
	{
		if (a[i]==a[i+1])
		{
			printf("%d\n",a[i]);
			count++;
			for (j=i;j<n-1;j++)
			{
				a[j]=a[j+1];
			}
			
		}
	}
	printf("duplicate : %d\n",count);
	for (i=0;i<n-count;i++)
	{
		printf("%d\t",a[i]);
	}
	return(0);
}