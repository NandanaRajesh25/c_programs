#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display();

// Function to find the opcode in optab.txt and return the corresponding code
int get_opcode(char *opcode, char *code)
{
	FILE *optab = fopen("optab.txt", "r");
    	char mnemonic[10];
   	char machine_code[10];

    // Read each line from optab.txt to search for the matching mnemonic
    	while (!feof(optab))
    	{
		fscanf(optab, "%s\t%s", mnemonic, machine_code);
       		if (strcmp(opcode, mnemonic) == 0)
        	{
            		strcpy(code, machine_code); // Copy the machine code to the code buffer
            		fclose(optab);
            		return 1; // Indicate success
        	}
    	}

    	fclose(optab);
    	return 0; // Opcode not found
}

int main()
{
	char a[10], ad[10], label[10], opcode[10], operand[10], symbol[10], code[10];
    	int start, diff, i, address, add, len, actual_len, finaddr, prevaddr, j = 0;

    	FILE *fp1, *fp2, *fp3, *fp4;
    	fp1 = fopen("output.txt", "w");
    	fp2 = fopen("symtab.txt", "r");
    	fp3 = fopen("intermediate.txt", "r");
   	fp4 = fopen("objcode.txt", "w");

    	fscanf(fp3, "\t%s\t%s\t%s", label, opcode, operand);
    	if (strcmp(opcode, "START") == 0)
   	{
        	fprintf(fp1, "\t%s\t%s\t%s\n", label, opcode, operand);
        	fprintf(fp4, "H^%s^00%s\n", label, operand);
        	fscanf(fp3, "%d\t%s\t%s\t%s", &address, label, opcode, operand);
        	start = address;
        	fprintf(fp4, "T^00%d^", address);
    	}
    
    	while (strcmp(opcode, "END") != 0)
    	{
        	if (strcmp(opcode, "BYTE") == 0)
        	{
        		fprintf(fp1, "%d\t%s\t%s\t%s\t", address, label, opcode, operand);
            		len = strlen(operand);
            		actual_len = len - 3;
            		fprintf(fp4, "^");
            		for (i = 2; i < (actual_len + 2); i++)
            		{
                		sprintf(ad, "%X", operand[i]);
                		fprintf(fp1, "%s", ad);
                		fprintf(fp4, "%s", ad);
            		}
            		fprintf(fp1, "\n");
        	}

        	else if (strcmp(opcode, "WORD") == 0)
        	{
            		len = strlen(operand);
            		sprintf(a, "%05d", atoi(operand));
            		fprintf(fp1, "%d\t%s\t%s\t%s\t0%s\n", address, label, opcode, operand, a);
            		fprintf(fp4, "^0%s", a);
        	}

        	else if ((strcmp(opcode, "RESB") == 0) || (strcmp(opcode, "RESW") == 0))
        	{
        		fprintf(fp1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
        	}

        	else
        	{
            		if (get_opcode(opcode, code))
            		{

                		rewind(fp2);
                		fscanf(fp2, "%s\t%d", symbol, &add);
                		while (strcmp(operand, symbol) != 0)
                    			fscanf(fp2, "%s\t%d", symbol, &add);
                		fprintf(fp1, "%d\t%s\t%s\t%s\t%s%d\n", address, label, opcode, operand, code, add);
                		fprintf(fp4, "^%s%d", code, add);
            		}
        	}

        	fscanf(fp3, "%d\t%s\t%s\t%s", &address, label, opcode, operand);
    	}

    	fprintf(fp1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
    	fprintf(fp4, "\nE^00%d", start);

    	fclose(fp4);
    	fclose(fp3);
    	fclose(fp2);
    	fclose(fp1);

    	display();

    	return 0;
}

void display()
{
    char ch;
    FILE *fp1, *fp2, *fp3, *fp4;

    printf("\nIntermediate file is converted into object code");

    printf("\n\nThe contents of Intermediate file:\n\n");
    fp3 = fopen("intermediate.txt", "r");
    ch = fgetc(fp3);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp3);
    }
    fclose(fp3);

    printf("\n\nThe contents of Symbol Table:\n\n");
    fp2 = fopen("symtab.txt", "r");
    ch = fgetc(fp2);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp2);
    }
    fclose(fp2);

    printf("\n\nThe contents of Output file:\n\n");
    fp1 = fopen("output.txt", "r");
    ch = fgetc(fp1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp1);
    }
    fclose(fp1);

    printf("\n\nThe contents of Object code file:\n\n");
    fp4 = fopen("objcode.txt", "r");
    ch = fgetc(fp4);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp4);
    }
    fclose(fp4);
}