#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char line[50],addr[20];
	int i,j,hexaddr,start;
	FILE *fp1,*fp2;
	fp1=fopen("objcode.txt","r");
	printf("enter start addr:");
	scanf("%x",&start);
	
	do
	{
		fscanf(fp1,"%s",line);
		strcat(line,"$");
		if(line[0]=='T')
		{
			for(i=2,j=0;i<7,j<7;i++,j++)
			{
				addr[j]=line[i];
				addr[j+1]='\0';
			}
			fp2=fopen("temp.txt","r+");;
			fprintf(fp2,"%s",addr);
			rewind(fp2);
			fscanf(fp2,"%x",&hexaddr);
			fclose(fp2);
			i=9;
			while(line[i]!='$')
			{
				if(line[i]=='^')
					i++;
				printf("%x\t%c%c\n",hexaddr+start,line[i],line[i+1]);
				hexaddr=hexaddr+1;
				i+=2;
				
			}
		}
	}
	while(!feof(fp1));
	
	fclose(fp1);

	return(0);
}
	
				
			