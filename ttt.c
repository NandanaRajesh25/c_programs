#include <stdio.h> 
#include <stdlib.h>

#define FRAMES 3

int findLRU(int frames[], int n, int counter[]) {
  int i, min = counter[0], minIndex = 0;
  for (i = 1; i < n; ++i) {
    if (counter[i] < min) { // Find minimum counter value (least recently used)
      min = counter[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void lru(int pages[], int n) {
  int frames[FRAMES];
  int counter[FRAMES] = {0}; // Array to store access time for each frame
  int page_faults = 0;
  int i, j;

  for (i = 0; i < FRAMES; ++i) {
    frames[i] = -1;
  }

  for (i = 0; i < n; ++i) {
    int flag = 0;
    for (j = 0; j < FRAMES; ++j) {
      if (frames[j] == pages[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      int pos = findLRU(frames, FRAMES, counter);
      frames[pos] = pages[i];
      counter[pos] = i; // Update counter for the new frame
      ++page_faults;

      printf("Page %d inserted into frame %d\n", pages[i], pos);
    }

    // Update counter only for the accessed frame (if a fault occurred)
    if (flag == 0) {
      counter[pos]++;
    }

    printf("Current frames: ");
    for (j = 0; j < FRAMES; ++j)
      printf("%d ", frames[j]);
    printf("\n");
  }
  printf("Total Page Faults: %d\n", page_faults);
}

int main() {
  int pages[100]; // Assuming maximum length of reference string is 100
  int n, i;

  printf("Enter the number of pages in the reference string: ");
  scanf("%d", &n);

  printf("Enter the reference string: ");
  for (i = 0; i < n; ++i)
    scanf("%d", &pages[i]);

  lru(pages, n);

  return 0;
}
