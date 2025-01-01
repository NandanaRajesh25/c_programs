#include<stdio.h>
int main()
{
	int i,j,k,x,status,np,nr,avail1;
	int completed[10],avail[20][20],need[20][20],alloc[20][20],max[20][20],safeseq[10],maxres[10];
	printf("enter no of processes");
	scanf("%d",&np);
	printf("enter no of resources");
	scanf("%d",&nr);
	printf("enter alloc matrix");
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	
	printf("enter max matrix");
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}

	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}

	printf("enter max resources for each process:");
	for(j=0;j<nr;j++)
	{
		scanf("%d",&maxres[j]);
	}
	
	printf("alloc matrix\n");
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
		{
			printf("%d\t",alloc[i][j]);
		}
		printf("\n");
	}

	printf("max matrix\n");
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
		{
			printf("%d\t",max[i][j]);
		}
		printf("\n");
	}
	
	printf("need matrix\n");
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
		{
			printf("%d\t",need[i][j]);
		}
		printf("\n");
	}

	
	k=0;
	for(i=0;i<nr;i++)
	{
		int sumalloc=0;
		for(j=0;j<np;j++)
		{
			sumalloc+=alloc[j][i];
		}
		avail1=maxres[i]-sumalloc;
		avail[k][i]=avail1;
	}
	
	printf("hi");
 
	x=0;
	status=0;
	for(i=0;i<np;i++)
	{
		completed[i]=0;
		safeseq[i]=0;
	}


	while(x<np)
	{
	for(i=0;i<np;i++)
	{
		if(completed[i]==0)
		{
			status=1;
			for(j=0;j<nr;j++)
			{
				if(need[i][j]>avail[k][j])
				{
					status=0;
					break;
				}
			}
			if(status==1)
			{
				safeseq[x++]=i;
				
				for(j=0;j<nr;j++)
				{
					avail[k+1][j]=avail[k][j]+alloc[i][j];
				}
				completed[i]=1;
				k++;
			}
		}
	}
	}

	printf("available matrix\n");
	for(i=0;i<k;i++)
	{
		for(j=0;j<nr;j++)
		{
			printf("%d\t",avail[i][j]);
		}
		printf("\n");
	}
	
	
	if(x==np)
	{
		printf("safe seq is:");
		for(i=0;i<x;i++)
		{
			printf("P%d ",safeseq[i]);
		}
	}
	else
	{
		printf("not safe");
	}

	return(0);

}
			
