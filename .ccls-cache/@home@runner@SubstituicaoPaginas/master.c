#include "page.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void fillMemory(Page MR[], Page MS[], int MR_SIZE, int MS_SIZE) {
  int i;
  for (i = 0; i < MR_SIZE; i++) {
      MR[i] = buildPage(i);
  }

  for (i = MR_SIZE; i < (MR_SIZE + MS_SIZE); i++) {
      MS[i - MR_SIZE] = buildPage(i);
  }
}

int main(int argc, char **argv) {
  int MS_SIZE = atoi(argv[1]);
  int MR_SIZE = atoi(argv[2]);
  int ITERATIONS = atoi(argv[3]);
  int PAGES = atoi(argv[4]);
  int found = 0;
  int swaps = 0;
  Page MS[MS_SIZE];
  Page MR[MR_SIZE];
  int i, j;
  fillMemory(MR, MS, MR_SIZE, MS_SIZE);
  printf("MR\n");  
  printMemory(MR, MR_SIZE);
  printf("MS\n");
  printMemory(MS, MS_SIZE);
  srand(time(NULL));
  for (i = 0; i < ITERATIONS; i++) { 
    for (j = 0; j < PAGES; j++) {
      int randomId = rand() % (MR_SIZE + MS_SIZE);
      printf("ramdomId: %d\n", randomId);
      int inMemory = findPage(MR, MR_SIZE, randomId);
      if (inMemory) {
        printf("FOUND IN MEMORY\n");
        updateBits(MR, MR_SIZE, randomId);
        found++;
      } else {
        printf("FAZER SWAP\n");
        swapPage(MR, MS, MR_SIZE, MS_SIZE, randomId);
        updateBits(MR, MR_SIZE, randomId);
        swaps++;
      }
      //printMemory(MR, MR_SIZE);
    }
  }
  printf("METRICS: \n");
  printf("SWAPS: %d\n", swaps);
  printf("FOUND IN MEMORY: %d\n", found);
  return 0;
}
