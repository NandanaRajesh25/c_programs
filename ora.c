#include <stdio.h>
#include <stdlib.h>

// Structure to represent a page entry
struct Page {
    int pageNumber;
    int frequency;
};

// Function to check if a page is already in memory
int isInMemory(struct Page* frames, int numOfFrames, int pageNumber) {
    for (int i = 0; i < numOfFrames; i++) {
        if (frames[i].pageNumber == pageNumber) {
            return 1; // Page is in memory
        }
    }
    return 0; // Page is not in memory
}

// Function to find the least frequently used page in memory
int findLFU(struct Page* frames, int numOfFrames) {
    int minFrequency = frames[0].frequency;
    int index = 0;

    for (int i = 1; i < numOfFrames; i++) {
        if (frames[i].frequency < minFrequency) {
            minFrequency = frames[i].frequency;
            index = i;
        }
    }

    return index;
}

int main() {
    int numOfFrames, numOfPages;
    printf("Enter the number of frames: ");
    scanf("%d", &numOfFrames);

    printf("Enter the number of pages: ");
    scanf("%d", &numOfPages);

    int* pageString = (int*)malloc(numOfPages * sizeof(int));
    printf("Enter the page reference string: ");
    for (int i = 0; i < numOfPages; i++) {
        scanf("%d", &pageString[i]);
    }

    struct Page* frames = (struct Page*)malloc(numOfFrames * sizeof(struct Page));
    for (int i = 0; i < numOfFrames; i++) {
        frames[i].pageNumber = -1; // Initialize page numbers in frames to -1
        frames[i].frequency = 0; // Initialize frequency of each frame to 0
    }

    int pageFaults = 0;

    // Simulate LFU page replacement algorithm
    for (int i = 0; i < numOfPages; i++) {
        int currentPage = pageString[i];

        if (!isInMemory(frames, numOfFrames, currentPage)) {
            int index = findLFU(frames, numOfFrames);
            frames[index].pageNumber = currentPage;
            frames[index].frequency = 1;
            pageFaults++;

            // Print frames after each page replacement
            printf("Frames after page %d insertion: ", currentPage);
            for (int j = 0; j < numOfFrames; j++) {
                printf("%d ", frames[j].pageNumber);
            }
            printf("\n");
        } else {
            for (int j = 0; j < numOfFrames; j++) {
                if (frames[j].pageNumber == currentPage) {
                    frames[j].frequency++;
                    break;
                }
            }
        }
    }

    printf("Number of page faults: %d\n", pageFaults);

    free(pageString);
    free(frames);

    return 0;
}
