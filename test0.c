#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int get_opcode(char *opcode,char *code)
{
	FILE *f1;
	f1=fopen("optab.txt","r");
	
	char operand1[10],mne[10];

	while(!feof(f1))
	{
		fscanf(f1,"%s\t%s",operand1,mne);
		if(strcmp(opcode,operand1)==0)
		{
			strcpy(code,mne);
			fclose(f1);
			return(1);
		}
	}
	fclose(f1);
	return(0);
}
	
int main()
{
	char label[10],opcode[10],operand[10],a[10],ad[10],code[10],symbol[10],addr[10];
	int start,address,len,actual_len,i;
	FILE *fp1,*fp2,*fp3,*fp4;
	fp1=fopen("intermediate.txt","r");
	fp2=fopen("symtab.txt","r");
	fp3=fopen("output.txt","w");
	fp4=fopen("objcode.txt","w");
	
	fscanf(fp1,"\t%s\t%s\t%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
		
		fprintf(fp4,"H^%s^00%s\n",label,operand);
		fscanf(fp1,"%d\t%s\t%s\t%s",&address,label,opcode,operand);
		start=address;
		fprintf(fp4,"T^00%d",address);
	}

	while(strcmp(opcode,"END")!=0)
	{
		if(strcmp(opcode,"BYTE")==0)
		{
			fprintf(fp3,"%d\t%s\t%s\t%s\t",address,label,opcode,operand);
			len=strlen(operand);
			actual_len=len-3;
			fprintf(fp4,"^");
			for(i=2;i<(actual_len+2);i++)
			{
				sprintf(a,"%x",operand[i]);
				fprintf(fp3,"%s",a);
				fprintf(fp4,"%s",a);
			}
			fprintf(fp3,"\n");
		}

		else if(strcmp(opcode,"WORD")==0)
		{
			len=strlen(operand);
			sprintf(ad,"%05d",atoi(operand));
			fprintf(fp3,"%d\t%s\t%s\t%s\t0%s\n",address,label,opcode,operand,ad);
			fprintf(fp4,"^0%s",ad);
		}
		
		else if((strcmp(opcode,"RESW")==0) || strcmp(opcode,"RESB")==0)
		{
			fprintf(fp3,"%d\t%s\t%s\t%s\n",address,label,opcode,operand);
		}


		else
		{
			if(get_opcode(opcode,code))
			{
				rewind(fp2);
				fscanf(fp2,"%s\t%s",symbol,addr);
				while(strcmp(operand,symbol)!=0)
					fscanf(fp2,"%s\t%s",symbol,addr);

				fprintf(fp3,"%d\t%s\t%s\t%s\t%s%s\n",address,label,opcode,operand,code,addr);
				fprintf(fp4,"^%s%s",code,addr);
			}
		}
		
		fscanf(fp1,"%d\t%s\t%s\t%s",&address,label,opcode,operand);
	}

	fprintf(fp3,"%d\t%s\t%s\t%s",address,label,opcode,operand);
	fprintf(fp4,"\nE^00%d",start);

	fclose(fp1);
	fclose(fp2);	
	fclose(fp3);	
	fclose(fp4);
	
	return(0);
}
		
				


