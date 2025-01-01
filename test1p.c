#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char label[10],operand[10],opcode[10],code[10],mne[10];
	int start_addr,locctr,prgmlen;
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	
	fp1=fopen("input.txt","r");
	fp2=fopen("optab.txt","r");
	fp3=fopen("intermediate.txt","w");
	fp4=fopen("symtab.txt","w");
	fp5=fopen("prgmlen.txt","w");
	
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
		fscanf(fp2,"%s\t%s",code,mne);
		
		while(strcmp(code,"END")!=0)
		{
			if(strcmp(opcode,code)==0)
			{
				locctr+=3;
				break;
			}
			fscanf(fp2,"%s\t%s",code,mne);
		}
		if(strcmp(opcode,"WORD")==0)
		{
			locctr+=3;
		}
		if(strcmp(opcode,"RESW")==0)
		{
			locctr+=3*atoi(operand);
		}
		else if(strcmp(opcode,"RESB")==0)
		{
			locctr+=atoi(operand);
		}
		else if(strcmp(opcode,"BYTE")==0)
		{
			++locctr;
		}
		
		fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);

	}
	
	fprintf(fp3,"%d\t%s\t%s\t%s",locctr,label,opcode,operand);

	prgmlen=locctr-start_addr;
	fprintf(fp5,"%d",prgmlen);
	
	fclose(fp1);	
	fclose(fp2);
	fclose(fp3);	
	fclose(fp4);
	fclose(fp5);
	
	return(0);
}
	
			
