#include<stdio.h>
int main()
{

	int nf,np,found,i,j,flag,used,inc[30],frames[10],hit=0;
	printf("enter no of frames:");
	scanf("%d",&nf);
	printf("enter no of pages:");
	scanf("%d",&np);
	printf("enter incoming stream ");
	for(i=0;i<np;i++)
	{
		scanf("%d",&inc[i]);
	}
	printf("incoming\t");
	for(i=0;i<nf;i++)
	{
		printf("frame%d\t",i+1);
	}
	printf("\n");
	for(i=0;i<nf;i++)
	{
		frames[i]=-1;
	}

	used=0;
	for(i=0;i<np;i++)
	{
		flag=0;
		printf("%d\t",inc[i]);
		for(j=0;j<nf;j++)
		{
			if(frames[j]==-1)
			{
				flag=1;
				frames[j]=inc[i];
				break;
			}
		}
		
		
		if(flag==1)
		{
			for(j=0;j<nf;j++)
			{
				if(frames[j]==-1)
					printf("-\t");
				else
					printf("%d\t",frames[j]);
			}
			printf("\n");
			continue;
		}
		
		for(j=0;j<nf;j++)
		{
			if(frames[j]==inc[i])
			{
				flag=1;
				hit++;
			}
		}

		if(flag==1)
		{
			for(j=0;j<nf;j++)
			{
				printf("%d\t",frames[j]);
			}
			printf("\n");
			continue;
		}

		found=0;
		while(found==0)
		{
			found=1;
			for(j=used+1;j<i;j++)
			{
				if(inc[j]==inc[used])
	 			{
					used=used+1;
					found=0;
					break;
				}
	
			}
		}

		for(j=0;j<nf;j++)
		{
			if(frames[j]==inc[used])
			{
				frames[j]=inc[i];
				used++;
				break;
			}
		}
		
	
		for(j=0;j<nf;j++)
		{
			printf("%d\t",frames[j]);
		}
		printf("\n");
	}
	printf("\n total hit: %d",hit);
	return(0);
}
