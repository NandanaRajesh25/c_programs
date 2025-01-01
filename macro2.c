#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MACROS 10
#define MAX_LINES 50
#define MAX_ARGS 10

void GETLINE(FILE *input); 
void PROCESSLINE(FILE *input, FILE *expanded); 
void DEFINE(FILE *input);
void EXPAND(FILE *expanded);

FILE *input, *expanded;
char label[10], opcode[10], operand[25];
char line[50];
int namcount = 0;
int defcount = 0;
int EXPANDING = 0;
int curr;

struct namtab {
    char name[10];
    int start, end;
} mynamtab[MAX_MACROS];

struct deftab {
    char macroline[50];
} mydeftab[MAX_LINES];

struct argtab {
    char arg[25];
} myargtab[MAX_ARGS];

// Function to read a line from input or DEFTAB if expanding
void GETLINE(FILE *input) {
    if (EXPANDING) {
        strcpy(line, mydeftab[curr++].macroline);
    } else {
        fgets(line, sizeof(line), input);
    }

    // Parsing the line into label, opcode, and operand
    sscanf(line, "%s %s %s", label, opcode, operand);
}

// Process each line of the input
void PROCESSLINE(FILE *input, FILE *expanded) {
    int i;
    for (i = 0; i < namcount; i++) {
        if (strcmp(opcode, mynamtab[i].name) == 0) {
            EXPAND(expanded); // Expand macro if found
            return;
        }
    }

    if (strcmp(opcode, "MACRO") == 0) {
        DEFINE(input); // Define macro if MACRO keyword is found
    } else {
        fprintf(expanded, "%s", line); // Write the line to expanded file
    }
}

// Define a macro by adding it to NAMTAB and DEFTAB
void DEFINE(FILE *input) {
    int LEVEL = 1;
    int i, j = 0, k = 0;
    char param[3][9];

    // Add macro name to NAMTAB
    strcpy(mynamtab[namcount].name, label);
    mynamtab[namcount].start = defcount;

    // Add the prototype line to DEFTAB
    strcpy(mydeftab[defcount++].macroline, line);

    // Parse parameters from operand
    while (operand[i] != '\0') {
        if (operand[i] != ',') {
            param[j][k++] = operand[i];
        } else {
            param[j++][k] = '\0';
            k = 0;
        }
        i++;
    }
    param[j][k] = '\0';

    // Continue reading until MEND is found
    while (LEVEL > 0) {
        GETLINE(input);
        
        if (strcmp(opcode, "MACRO") == 0) {
            LEVEL++;
        } else if (strcmp(opcode, "MEND") == 0) {
            LEVEL--;
        }

        // Substitute positional notation for parameters in DEFTAB
        for (i = 0; i < 3; i++) {
            if (strcmp(operand, param[i]) == 0) {
                operand[0] = '?';
                operand[1] = '1' + i;
                operand[2] = '\0';
            }
        }

        strcpy(mydeftab[defcount++].macroline, line);
    }

    // End the macro definition in NAMTAB
    mynamtab[namcount++].end = defcount;
}

// Expand a macro by writing the expanded code to the output
void EXPAND(FILE *expanded) {
    int i, end, j = 0, k = 0;
    EXPANDING = 1;

    // Copy macro invocation as a comment
    fprintf(expanded, "// %s", line);

    // Setup arguments in ARGTAB from macro invocation
    for (i = 0; i < strlen(operand); i++) {
        if (operand[i] != ',') {
            myargtab[j].arg[k++] = operand[i];
        } else {
            myargtab[j++].arg[k] = '\0';
            k = 0;
        }
    }
    myargtab[j].arg[k] = '\0';

    // Find the macro definition in NAMTAB and set current pointer
    for (i = 0; i < namcount; i++) {
        if (strcmp(opcode, mynamtab[i].name) == 0) {
            curr = mynamtab[i].start;
            end = mynamtab[i].end;
            break;
        }
    }

    // Read each line of the macro definition from DEFTAB and expand it
    while (curr < end) {
        GETLINE(input);

        // Replace positional notation with actual arguments from ARGTAB
        int index = operand[1] - '1';
        if (operand[0] == '?' && index >= 0 && index < MAX_ARGS) {
            strcpy(operand, myargtab[index].arg);
        }

        fprintf(expanded, "%s\t%s\t%s\n", label, opcode, operand);
    }

    EXPANDING = 0;
}

int main() {
    input = fopen("input3.txt", "r");
    expanded = fopen("expanded.txt", "w");

    if (!input || !expanded) {
        printf("Error opening files.\n");
        return 1;
    }

    GETLINE(input);
    while (strcmp(opcode, "END") != 0) {
        PROCESSLINE(input, expanded);
        GETLINE(input);
    }

    fprintf(expanded, "%s", line); // Write END line
    printf("Macro processing completed.\n");

    fclose(input);
    fclose(expanded);
    return 0;
}
