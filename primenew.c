#include<stdio.h>
#include<math.h>
int main()
{
	int isprime,i,a,n=0;
	int N[7];
	int A[7];
	for(i=0;i<7;i++)
	{
		printf("enter number %d:",i+1);
		scanf("%d",&N[i]);
	}
	for(i=0;i<7;i++)
	{
		 isprime=1;
		 for(a=2;a<=N[i]-1;a++)
		{
			if (N[i]%a==0)
			{
				isprime=0;
				break;
   			}
		}
		if (isprime==1)
		{
			A[n]=N[i];
			n++;
		}
	}
	printf("prime nos are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",A[i]);
	}
	return(0);
}