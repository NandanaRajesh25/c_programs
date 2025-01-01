#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *new, *temp, *last, *first;

struct node memBlock[50];

int flag;

int check(int start, int size) {
    for (int i = start; i < start + size; i++) {
        if (memBlock[i].data == 1) {
            return 1;
        }
    }
    return 0;
}

void linked() {
    int start, size;

    printf("\nStart block: ");
    scanf("%d", &start);
    printf("\nLength of the file: ");
    scanf("%d", &size);

    flag = check(start, size);

    if (flag == 0) {
        for (int i = start; i < start + size; i++) {
            memBlock[i].data = 1;
            new = (struct node *)malloc(sizeof(struct node));
            if (new == NULL) {
                printf("Memory allocation failed\n");
                return;
            }
            new->data = i;
            new->link = NULL;

            if (first == NULL) {
                first = new;
                last = new;
            } else {
                last->link = new;
                last = new;
            }
        }

        temp = first;
        printf("Allocated blocks:\n");
        while (temp != NULL) {
            printf("%d ------ Allocated.\n", temp->data);
            temp = temp->link;
        }
    } else {
        printf("File NOT allocated. Some blocks are already allocated.\n");
    }
}

int main() {
    int d;

    do {
        printf("\n1. Allocate memory using linked list\n2. Exit\n");
        scanf("%d", &d);
        switch (d) {
            case 1:
                linked();
                break;
            case 2:
                break;
            default:
                printf("Try again\n");
        }
    } while (d != 2);

    return 0;
}
