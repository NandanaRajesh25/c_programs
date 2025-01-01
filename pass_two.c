#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Define the OPCODE table and corresponding codes
char *opcodes[] = {"LDA", "STA", "LDCH", "STCH"};
char *codes[] = {"33", "44", "53", "57"};
int num_opcodes = 4;

typedef struct {
    char label[10];
    int address;
} Symbol;

Symbol symbolTable[10];
int symbolCount = 0;

// Function to find opcode in the table
const char *getOpcodeCode(const char *opcode) {
    for (int i = 0; i < num_opcodes; i++) {
        if (strcmp(opcode, opcodes[i]) == 0) {
            return codes[i];
        }
    }
    return NULL;
}

// Function to add symbol to symbol table
void addSymbol(const char *label, int address) {
    strcpy(symbolTable[symbolCount].label, label);
    symbolTable[symbolCount].address = address;
    symbolCount++;
}

// Function to get the address of a symbol from the symbol table
int getSymbolAddress(const char *label) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].label, label) == 0) {
            return symbolTable[i].address;
        }
    }
    return -1; // Return -1 if symbol is not found
}

int main() {
    FILE *inputFile = fopen("intermediate.txt", "r");
    FILE *symbolFile = fopen("symtab.txt", "r");
    FILE *objectFile = fopen("object.txt", "w");
    FILE *listingFile = fopen("listing.txt", "w");

    char line[MAX_LINE_LENGTH];
    int startAddress = 0;
    int programLength = 0;
    int locationCounter = 0;
    char programName[10] = "**"; // Placeholder program name
    char textRecord[MAX_LINE_LENGTH] = "";
    int textRecordStart = -1;
    int textRecordLength = 0;

    // Pass 2: Process intermediate file line by line
    while (fgets(line, MAX_LINE_LENGTH, inputFile)) {
        char label[10], opcode[10], operand[10];
        int address;

        // Parse line
        sscanf(line, "%d %s %s %s", &address, label, opcode, operand);

        // Check if it's the start of the program
        if (strcmp(opcode, "START") == 0) {
            startAddress = address;
            locationCounter = startAddress;
            fprintf(objectFile, "H^%s^%06X^%06X\n", programName, startAddress, programLength);
            fprintf(listingFile, "%04X\t%s\t%s\t%s\n", address, label, opcode, operand);
            continue;
        }

        // Handle END directive
        if (strcmp(opcode, "END") == 0) {
            if (textRecordLength > 0) {
                fprintf(objectFile, "T^%06X^%02X%s\n", textRecordStart, textRecordLength, textRecord);
            }
            fprintf(objectFile, "E^%06X\n", startAddress);
            fprintf(listingFile, "%04X\t%s\t%s\t%s\n", address, label, opcode, operand);
            break;
        }

        // Check if opcode is in the table
        const char *opcodeCode = getOpcodeCode(opcode);
        char objectCode[10] = "";

        if (opcodeCode != NULL) {
            int symbolAddress = getSymbolAddress(operand);
            if (symbolAddress == -1) {
                printf("Error: Symbol %s not found\n", operand);
                exit(1);
            }
            sprintf(objectCode, "%s%04X", opcodeCode, symbolAddress);
        } else if (strcmp(opcode, "WORD") == 0) {
            sprintf(objectCode, "%06X", atoi(operand));
        } else if (strcmp(opcode, "BYTE") == 0) {
            if (operand[0] == 'C') {
                sprintf(objectCode, "%02X", operand[2]); // Convert char to hex
            } else if (operand[0] == 'X') {
                strncpy(objectCode, operand + 2, 2); // Copy hex value directly
                objectCode[2] = '\0';
            }
        }

        // If it's a label (e.g., RESW or RESB), add it to the symbol table
        if (strcmp(label, "**") != 0) {
            addSymbol(label, address);
            fprintf(symbolFile, "%s\t%04X\n", label, address);
        }

        // Write to listing file
        fprintf(listingFile, "%04X\t%s\t%s\t%s\t%s\n", address, label, opcode, operand, objectCode);

        // Handle text record
        if (strcmp(opcode, "RESW") == 0 || strcmp(opcode, "RESB") == 0) {
            if (textRecordLength > 0) {
                fprintf(objectFile, "T^%06X^%02X%s\n", textRecordStart, textRecordLength, textRecord);
                strcpy(textRecord, "");
                textRecordLength = 0;
            }
            continue;
        }

        if (textRecordLength == 0) {
            textRecordStart = address;
        }

        // Add object code to text record with '^' separator
        if (textRecordLength > 0) {
            strcat(textRecord, "^");
        }
        strcat(textRecord, objectCode);
        textRecordLength += strlen(objectCode) / 2; // Calculate length in bytes

        // Flush text record if it reaches 30 bytes
        if (textRecordLength >= 0x1E) {
            fprintf(objectFile, "T^%06X^%02X%s\n", textRecordStart, textRecordLength, textRecord);
            strcpy(textRecord, "");
            textRecordLength = 0;
        }

        locationCounter += 3; // Increment location counter (assuming all instructions are 3 bytes)
    }

    // Close files
    fclose(inputFile);
    fclose(symbolFile);
    fclose(objectFile);
    fclose(listingFile);

    printf("Pass 2 completed. Files generated: symbol.txt, object.txt, listing.txt\n");

    return 0;
}
