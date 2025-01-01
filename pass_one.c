#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	char label[10],opcode[10],operand[10],mnemonic[10],code[10];
	int locctr,start_addr,prgm_len;
	fp1=fopen("input.txt","r");
	fp2=fopen("optab.txt","r");
	fp3=fopen("intermediate.txt","w");
	fp4=fopen("symtab.txt","w");
	fp5=fopen("length.txt","w");

	fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		start_addr=atoi(operand);
		locctr=start_addr;
		fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
		fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
	}
	else
	{	
		locctr=0;
	}
	while(strcmp(opcode,"END")!=0)
	{	
		fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
		if(strcmp(label,"**")!=0)
		{
			fprintf(fp4,"%s\t%d\n",label,locctr);	
		}
		
		fscanf(fp2,"%s\t%s",code,mnemonic);
		while(strcmp(code,"END")!=0)
		{	
			
			if(strcmp(code,opcode)==0)
			{
				locctr+=3;
				break;
			}
			fscanf(fp2,"%s\t%s",code,mnemonic);
		}
			if(strcmp(opcode,"WORD")==0)
			{
				locctr+=3;
			}
			else if(strcmp(opcode,"RESW")==0)
			{
				locctr+=3*atoi(operand);
			}
			else if(strcmp(opcode,"RESB")==0)
			{
				locctr+=atoi(operand);
			}
			else if(strcmp(opcode,"BYTE")==0)
			{
				locctr++;
			}
			fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
	}
	
	
	fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
	prgm_len=locctr-start_addr;
	fprintf(fp5,"%d",prgm_len);
		
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);

	return(0);
}



		
			




