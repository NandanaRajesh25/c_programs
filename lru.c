#include <stdio.h>

// Function to display the frames
void displayFrames(int frames[], int n) {
    printf("Frames: ");
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf(" ");
        } else {
            printf("%d ", frames[i]);
        }
    }
    printf("\n");
}

// Function to check if a page is present in frames
int isInFrames(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

// Function to find the index of the least recently used page
int findLRUIndex(int frames[], int n, int used[]) {
    int min = used[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (used[i] < min) {
            min = used[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int numFrames, numPages, pageFaults = 0;
    
    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    int frames[numFrames];
    int used[numFrames];  // Array to keep track of recently used status

    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;  // Initialize frames as empty
        used[i] = 0;     // Initialize all pages as not recently used
    }

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    int pages[numPages];
    printf("Enter the page reference string: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    printf("\n");

    for (int i = 0; i < numPages; i++) {
        int page = pages[i];

        if (!isInFrames(frames, numFrames, page)) {  // Page fault
            int index = findLRUIndex(frames, numFrames, used);
            frames[index] = page;
            pageFaults++;
        }

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1) {
                used[j]++;  // Increment the recently used counter for all pages in frames
            }
        }

        displayFrames(frames, numFrames);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
