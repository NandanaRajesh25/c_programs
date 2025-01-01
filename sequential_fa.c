#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

struct node {
    int data;
};

struct node memBlock[SIZE];

int check(int start, int size) {
    for (int i = start; i < start + size; i++) {
        if (memBlock[i].data == 1) {
            return 1;
        }
    }
    return 0;
}

void sequential() {
    int start, size;

    printf("\nStart block: ");
    scanf("%d", &start);
    printf("\nLength of the file: ");
    scanf("%d", &size);

    if (start < 0 || start + size > SIZE) {
        printf("\nInvalid start block or size.\n");
        return;
    }

    if (check(start, size) == 0) {
        for (int i = start; i < start + size; i++) {
            memBlock[i].data = 1;
            printf("%d ------- Allocated\n", i);
        }
    } else {
        printf("\nFile cannot be allocated\n");
    }
}

int main() {
    int d;

    // Initialize the memory blocks
    for (int i = 0; i < SIZE; i++) {
        memBlock[i].data = 0;
    }

    do {
        printf("\n1. Sequential\n2. Exit\n");
        scanf("%d", &d);
        switch (d) {
            case 1:
                sequential();
                break;
            case 2:
                break;
            default:
                printf("Try again\n");
        }
    } while (d != 2);

    return 0;
}
