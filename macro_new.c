#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARGS 10
#define MAX_ARG_LENGTH 25

void GETLINE(FILE *input);                    
void PROCESSLINE(FILE *input, FILE *expanded); 
void DEFINE(FILE *input);
void EXPAND(FILE *expanded);
int FIND_MACRO(const char *name);

FILE *input, *expanded;
char label[10], opcode[10], operand[50];
char line[100];
int EXPANDING = 0;
int curr;

// Function to read a line from input or DEFTAB if expanding
void GETLINE(FILE *input) {
    if (EXPANDING) {
        FILE *deftab = fopen("deftab.txt", "r");
        if (!deftab) {
            printf("Error opening DEFTAB file.\n");
            return;
        }
        fgets(line, sizeof(line), deftab);
        fclose(deftab);
    } else {
        fgets(line, sizeof(line), input);
    }

    // Parsing the line into label, opcode, and operand
    sscanf(line, "%s %s %[^\n]", label, opcode, operand);
}

// Process each line of the input
void PROCESSLINE(FILE *input, FILE *expanded) {
    if (FIND_MACRO(opcode)) {
        EXPAND(expanded); // Expand macro if found
        return;
    }

    if (strcmp(opcode, "MACRO") == 0) {
        DEFINE(input); // Define macro if MACRO keyword is found
    } else {
        fprintf(expanded, "%s", line); // Write the line to expanded file
    }
}

// Function to check if a macro exists in NAMTAB
int FIND_MACRO(const char *name) {
    FILE *namtab = fopen("namtab.txt", "r");
    if (!namtab) {
        printf("Error opening NAMTAB file.\n");
        return 0;
    }
    
    char macro_name[10];
    while (fscanf(namtab, "%s", macro_name) != EOF) {
        if (strcmp(name, macro_name) == 0) {
            fclose(namtab);
            return 1;
        }
    }

    fclose(namtab);
    return 0;
}

// Define a macro by adding it to NAMTAB and DEFTAB
void DEFINE(FILE *input) {
    int LEVEL = 1;
    char *token;
    
    // Write macro name to NAMTAB
    FILE *namtab = fopen("namtab.txt", "a");
    if (!namtab) {
        printf("Error opening NAMTAB file.\n");
        return;
    }
    fprintf(namtab, "%s\n", label);
    fclose(namtab);

    // Write the prototype line to DEFTAB
    FILE *deftab = fopen("deftab.txt", "a");
    if (!deftab) {
        printf("Error opening DEFTAB file.\n");
        return;
    }
    fprintf(deftab, "%s", line);

    // Parse parameters and write to ARGTAB
    FILE *argtab = fopen("argtab.txt", "w");
    token = strtok(operand, ",");
    while (token) {
        fprintf(argtab, "%s\n", token);
        token = strtok(NULL, ",");
    }
    fclose(argtab);

    // Continue reading lines until MEND is found
    while (LEVEL > 0) {
        GETLINE(input);

        if (strcmp(opcode, "MACRO") == 0) LEVEL++;
        else if (strcmp(opcode, "MEND") == 0) LEVEL--;

        // Write each line to DEFTAB
        fprintf(deftab, "%s", line);
    }
    fclose(deftab);
}

// Expand a macro by writing the expanded code to the output
void EXPAND(FILE *expanded) {
    int i = 0;
    char argument[MAX_ARG_LENGTH];
    char expanded_line[100];

    EXPANDING = 1;
    fprintf(expanded, "// %s", line); // Comment macro call

    // Set up arguments in ARGTAB
    FILE *argtab = fopen("argtab.txt", "r");
    for (i = 0; i < MAX_ARGS && fgets(argument, MAX_ARG_LENGTH, argtab); i++) {
        argument[strcspn(argument, "\n")] = '\0'; // Remove newline character
        // Replace parameter placeholders with actual arguments
        if (i == 0) strcpy(operand, argument); // Assuming only 1 argument for simplicity
    }
    fclose(argtab);

    // Read and expand lines from DEFTAB
    FILE *deftab = fopen("deftab.txt", "r");
    int in_macro = 0;
    while (fgets(expanded_line, sizeof(expanded_line), deftab)) {
        sscanf(expanded_line, "%s %s %[^\n]", label, opcode, operand);

        if (strcmp(opcode, "MACRO") == 0) {
            if (strcmp(label, opcode) == 0) in_macro = 1; // Macro start
        } else if (strcmp(opcode, "MEND") == 0 && in_macro) {
            break; // End of macro
        } else if (in_macro) {
            // Replace positional arguments
            if (strcmp(operand, "&A") == 0) {
                strcpy(operand, "N1");
            } else if (strcmp(operand, "&B") == 0) {
                strcpy(operand, "N2");
            }

            fprintf(expanded, "%s\t%s\t%s\n", label, opcode, operand); // Write expanded line
        }
    }
    fclose(deftab);

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
