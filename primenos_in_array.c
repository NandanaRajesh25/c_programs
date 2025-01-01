#include<stdio.h>
#include<math.h>
int main()
{
	int isprime,primenos=0,i,a;
	int N[7];
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
			primenos++;
		}
	}
	printf("number of prime nos are %d",primenos);
	return(0);
}