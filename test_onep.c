#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char label[10],opcode[10],operand[10],mne[10],opnd[10],s1[5],s2[5],s3[5],sym[10],symaddr[10],obj1[10],obj2[10],name[10],lcs[10],ms[10],q[10];
	int i=0,j=0,k=0,l=0,len,len1,m[10],locctr,start_addr,prgmlen;
	FILE *f1,*f2,*f3,*f4,*f5;
	f1=fopen("input.txt","r");
	f2=fopen("optab.txt","r");
	f3=fopen("symtab.txt","w+");
	f4=fopen("symtab1.txt","w+");
	f5=fopen("output.txt","w+");

	fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		start_addr=atoi(operand);
		locctr=start_addr;
		strcpy(name,label);
	}
	else
	{
		locctr=0;
	}
	strcpy(s1,"*");
	strcpy(s2,"-");
	strcpy(s3,"#");

	fscanf(f1,"%s\t%s\t%s",label,opcode,operand);

	while(strcmp(opcode,"END")!=0)
	{
		if(strcmp(label,"-")==0)
		{
			fscanf(f2,"%s\t%s",mne,opnd);
			while(!feof(f2))
			{
				if(strcmp(mne,opcode)==0)
				{
					m[i]=locctr+1;
					fprintf(f3,"%s\t%s\n",operand,s1);
					fprintf(f5,"%s\t0000\n",opnd);
					i=i+1;
					locctr=locctr+3;		
					break;
				}
				else
				{
					fscanf(f2,"%s\t%s",mne,opnd);
				}
			}
		}
		else
		{
			fseek(f3,SEEK_SET,0);
			fscanf(f3,"%s\t%s",sym,symaddr);
			while(!feof(f3))
			{
				if(strcmp(label,sym)==0)
				{
					sprintf(lcs,"%d",locctr);
					fprintf(f4,"%s\t%s\n",sym,lcs);
					sprintf(ms,"%d",m[j]);
					fprintf(f5,"%s\t%s\n",ms,lcs);
					j=j+1;
					i=i+1;
					break;
				}
				else
				{
					fscanf(f3,"%s\t%s",sym,symaddr);
				}
			
		
				if(strcmp(opcode,"RESW")==0)
				{	
					locctr=locctr+3*atoi(operand);
				}
				else if(strcmp(opcode,"RESB")==0)
				{
					locctr=locctr+atoi(operand);
				}
				else if(strcmp(opcode,"BYTE")==0)
				{
					len=strlen(operand);
					locctr=locctr+len-2;
					for(k=2;k<len;k++)
					{
						q[j]=operand[k];
						j=j+1;
					}
					fprintf(f5,"%s\t%s",q,s2);
					break;
				}
				else if(strcmp(opcode,"WORD")==0)
				{
					locctr=locctr+3;
					fprintf(f5,"%s\t%s",operand,s3);
					break;
				}
			
			}
		}

		fseek(f2,SEEK_SET,0);
		fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
	}

	prgmlen=locctr-start_addr;
	printf("H^%s^%d^0%x\n",name,start_addr,prgmlen);
	printf("T^00%d^0%x",start_addr,prgmlen);
	fseek(f5,SEEK_SET,0);
	fscanf(f5,"%s\t%s",obj1,obj2);
	while(!feof(f5))
	{
		if(strcmp(obj2,"0000")==0)
		{
			printf("^%s%s",obj1,obj2);
		}
		else if(strcmp(obj2,s2)==0)
		{
			printf("^");
			len1=strlen(obj1);
			for(l=0;l<len1;l++)
			{
				printf("%d",obj1[l]);
			}
		}
		else if(strcmp(obj2,s3)==0)
		{
			printf("^");
			printf("%s",obj1);
		}
		
		fscanf(f5,"%s\t%s",obj1,obj2);
	}

	fseek(f5,SEEK_SET,0);
	fscanf(f5,"%s\t%s",obj1,obj2);
	while(!feof(f5))
	{
		if(strcmp(obj2,"0000")!=0)
		{
			if(strcmp(obj2,s2)!=0)
			{
				if(strcmp(obj2,s3)!=0)
				{
					printf("\n");
					printf("T^%s^02^%s",obj1,obj2);
				}
			}
		}
		fscanf(f5,"%s\t%s",obj1,obj2);
	}

	printf("\nE^00%d",start_addr);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	fclose(f5);
	
	return(1);
}
	

				

		
	
		