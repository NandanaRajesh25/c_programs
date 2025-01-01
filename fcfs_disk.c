#include<stdio.h>
int main()
{
	int i,j,nf,np,rep,temp[10],inc_st[20],count=0,flag=0,hit=0,fault=0;
	printf("enter no of frames:");
	scanf("%d",&nf);
	printf("enter no of pages:");
	scanf("%d",&np);
	printf("enter inc stream");
	for(i=0;i<np;i++)
	{
		scanf("%d",&inc_st[i]);
	}
	for(i=0;i<nf;i++)
	{
		temp[i]=-1;
	}
	printf("incoming\t");
	for(i=0;i<nf;i++)
	{
		printf("frame%d\t",i+1);
	}
	printf("\n");
	for(i=0;i<np;i++)
	{
		printf("%d\t",inc_st[i]);
		for(j=0;j<nf;j++)
		{
			if(temp[j]==inc_st[i])
			{
				flag=1;
				hit++;
				break;
			}
		}
		for(j=0;j<nf;j++)
		{
			if(temp[j]==-1)
			{
				flag=2;
				temp[j]=inc_st[i];
				fault++;
				break;
			}
		}
		
		switch(flag)
		{
			case 1: 
			case 2:
			{
				for(j=0;j<nf;j++)
				{
					printf("%d\t",temp[j]);
				}
				break;
			}
			case 0:
			{
				rep=inc_st[count];
				count++;
				for(j=0;j<nf;j++)
				{
					if(temp[j]==rep)
					{
						temp[j]=inc_st[i];
						fault++;
						break;
					}
				}
				for(j=0;j<nf;j++)
				{
					printf("%d\t",temp[j]);
				}
				break;
			}
		}
		printf("\n");
		flag=0;
	}
	printf("no of page fault: %d\n",fault);
	printf("no of page hit: %d\n",hit);
	return(0);
}				
			