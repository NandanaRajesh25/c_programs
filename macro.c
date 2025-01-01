#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MACROS 10
#define MAX_LINES 50
#define MAX_ARGS 10
#define MAX_ARG_LENGTH 25

void GETLINE(FILE *input);                    
void PROCESSLINE(FILE *input, FILE *expanded); 
void DEFINE(FILE *input);
void EXPAND(FILE *expanded);
void WRITE_NAMTAB();
void WRITE_DEFTAB();
void WRITE_ARGTAB();

FILE *input, *expanded;
char label[10], opcode[10], operand[50];
char line[100];
int namcount = 0;
int defcount = 0;
int EXPANDING = 0;
int curr;

struct namtab {
    char name[10];
    int start, end;
} mynamtab[MAX_MACROS];

struct deftab {
    char macroline[100];
} mydeftab[MAX_LINES];

struct argtab {
    char arg[MAX_ARG_LENGTH];
} myargtab[MAX_ARGS];

// Function to read a line from input or DEFTAB if expanding
void GETLINE(FILE *input) {
    if (EXPANDING) {
        strcpy(line, mydeftab[curr++].macroline);
    } else {
        fgets(line, sizeof(line), input);
    }

    // Parsing the line into label, opcode, and operand
    sscanf(line, "%s %s %[^\n]", label, opcode, operand);
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
    int i = 0, arg_count = 0;
    char *token;

    // Add macro name to NAMTAB
    strcpy(mynamtab[namcount].name, label);
    mynamtab[namcount].start = defcount;

    // Add the prototype line to DEFTAB
    strcpy(mydeftab[defcount++].macroline, line);

    // Parse parameters from operand (comma-separated)
    token = strtok(operand, ",");
    while (token && arg_count < MAX_ARGS) {
        strcpy(myargtab[arg_count++].arg, token);
        token = strtok(NULL, ",");
    }

    // Continue reading until MEND is found
    while (LEVEL > 0) {
        GETLINE(input);
        
        if (strcmp(opcode, "MACRO") == 0) {
            LEVEL++;
        } else if (strcmp(opcode, "MEND") == 0) {
            LEVEL--;
        }

        // Substitute positional notation for parameters in DEFTAB
        for (i = 0; i < arg_count; i++) {
            if (strstr(line, myargtab[i].arg)) {
                char placeholder[3] = {'?', '1' + i, '\0'};
                char *pos = strstr(line, myargtab[i].arg);
                strncpy(pos, placeholder, 2);  // Replace parameter with placeholder (e.g., ?1, ?2)
            }
        }

        strcpy(mydeftab[defcount++].macroline, line);
    }

    // End the macro definition in NAMTAB
    mynamtab[namcount++].end = defcount;
}

// Expand a macro by writing the expanded code to the output
void EXPAND(FILE *expanded) {
    int i, end, arg_count = 0;
    char *token;
    EXPANDING = 1;

    // Copy macro invocation as a comment
    fprintf(expanded, "// %s", line);

    // Parse arguments from operand and store them in ARGTAB
    token = strtok(operand, ",");
    while (token && arg_count < MAX_ARGS) {
        strcpy(myargtab[arg_count++].arg, token);
        token = strtok(NULL, ",");
    }

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

        // Skip MACRO and MEND lines
        if (strcmp(opcode, "MACRO") == 0 || strcmp(opcode, "MEND") == 0) {
            continue;
        }

        // Replace placeholders with actual arguments
        for (i = 0; i < arg_count; i++) {
            char placeholder[3] = {'?', '1' + i, '\0'};
            char *pos = strstr(line, placeholder);
            if (pos) {
                strcpy(pos, myargtab[i].arg);
            }
        }

        fprintf(expanded, "%s\t%s\t%s\n", label, opcode, operand);
    }

    EXPANDING = 0;
}

// Function to write NAMTAB to a file without index or headings
void WRITE_NAMTAB() {
    FILE *namtab_file = fopen("namtab.txt", "w");
    if (!namtab_file) {
        printf("Error opening NAMTAB file.\n");
        return;
    }

    for (int i = 0; i < namcount; i++) {
        fprintf(namtab_file, "%s %d %d\n", mynamtab[i].name, mynamtab[i].start, mynamtab[i].end);
    }
    fclose(namtab_file);
    printf("NAMTAB written to namtab.txt\n");
}

// Function to write DEFTAB to a file without index or headings
void WRITE_DEFTAB() {
    FILE *deftab_file = fopen("deftab.txt", "w");
    if (!deftab_file) {
        printf("Error opening DEFTAB file.\n");
        return;
    }

    for (int i = 0; i < defcount; i++) {
        fprintf(deftab_file, "%s\n", mydeftab[i].macroline);
    }
    fclose(deftab_file);
    printf("DEFTAB written to deftab.txt\n");
}

// Function to write ARGTAB to a file without index or headings
void WRITE_ARGTAB() {
    FILE *argtab_file = fopen("argtab.txt", "w");
    if (!argtab_file) {
        printf("Error opening ARGTAB file.\n");
        return;
    }

    for (int i = 0; i < MAX_ARGS && myargtab[i].arg[0] != '\0'; i++) {
        fprintf(argtab_file, "%s\n", myargtab[i].arg);
    }
    fclose(argtab_file);
    printf("ARGTAB written to argtab.txt\n");
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

    // Write tables to separate files
    WRITE_NAMTAB();
    WRITE_DEFTAB();
    WRITE_ARGTAB();

    fclose(input);
    fclose(expanded);
    return 0;
}
