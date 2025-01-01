#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	fp1=fopen("input.txt","r");
	fp2=fopen("optab.txt","r");
	fp3=fopen("symtab1.txt","w+");
	fp4=fopen("symtab2,txt","w+");
	fp5=fopen("output.txt","w+fp3");

	fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		start_addr=atoi(operand);
		locctr=start_addr;
		strcpy(name,label);
	}

	strcpy(s1,"*");
	fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{
		if(strcmp(label,"-")==0)
		{
			fscanf(fp2,"%s\t%s",code,mnemonic);
			while(!feof(fp2))
			{
				if(strcmp(code,opcode)==0)
				{
					m[i]=locctr+1;
					fprintf(fp3,"%s\t%s\n",code,s1);
					fprintf(fp5,"%s\t0000\n",mnemonic);
					lc=+3;
					i+=1;
					break;
				}
				else
				{
					 fscanf(fp2,"%s\t%s",code,mnemonic);
				}
			}
		}
		else
		{
			fseek(fp3,SEEK_SET,0);
			fscanf(fp3,"%s\t%s",symbol,symaddr);
			while(!feof(fp3))
			{
				if(strcmp(label,symbol)==0)
				{
					sprintf(lcs,"%d",locctr);
					fprintf(fp4,"%d\t%s\n",label,lcs);
					fsprintf(ms,"%d",m[j]);
					j=j+1;
					fprintf(fp5,"%s\t%s\n",ms,lcs);
					i+=1;
					break;
				}
				else
				{
					 fscanf(fp3,"%s\t%s",symbol,symaddr);
				}

				if(strcmp(mnemonic,"RESW")==0)
				{
					locctr+=3*atoi(operand);
				}
				else if(strcmp(mnemonic,"BYTE")==0)
				{
					strcpy(s2,"-");
					len=strlen(operand);
					locctr+=len-2;
					for(k=2;k<len;k++)
					{
						q[l]=operand[k];
						l+=1;
					}
					fprintf(f5,"%s\t%s\n",q,s2);
					break;
				}
				else if(strcmp(mnemonic,"RESB")==0)
				{		
					locctr+=atoi(operand);
				}
				else if(strcmp(mnemonic,"WORD")==0)
				{
					strcpy(s3,"#");
					locctr+=3;
					fprintf(f5,"%s\t%s\n",operand,s3);
				}
			}
			fseek(fp2,SEEK_SET,0);
			fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);

		}

		fseek(fp5,SEEK_SET,0);
		prgm_len=locctr-start_addr;
		printf("H^%s^%d^0%x",name,start_addr,prgm_len);
		printf("T^");
		printf("00%d^0%x",sa,prgm_len);
		fscanf(fp5,"%s\t%s",obj1,obj2);
		while(!feof(f5))
		{
			if(strcmp(obj2,"0000")==0)
			{
				printf("^%s%s",obj1,obj2);
			}
			else if(strcmp(obj2,"-")==0)
			{		

				printf("f");
				len1=strlen(obj1);
				for(k=0;k<len;k++)
				{			
					printf("%d",obj1[k]);
				}
			}
			else if(strcmp(obj,"#")==0)
			{		
				printf("^");
				printf("%s",obj1);
			}
			fscanf(fp5,"%s\%s",obj1,onj2);
		}
		fseek(fp5,SEEK_SET,0)
		fscanf(fp5,"%s\t%s",obj1,obj2;
		while(!feof(f5))
		{
			if(strcmp(obj2,"0000")!=0)
			{
				if(strcmp(obj2,"-")!=0)
				{
		
					if(strcmp(obj,"#")!=0)
					{		
						printf("%n");
					
						printf("T^%s^02^%s",obj1,obj2);
					}
				}
			}

			fscanf(	fp5,"%s\%s",obj1,onj2);
		}
		printf("\nE^00%d",start_addr);
		return(0);
	}
}
				
			

	