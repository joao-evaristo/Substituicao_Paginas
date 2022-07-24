#include "page.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ITERATIONS 10

void fillMemory(Page MR[], Page MS[]) {
  int i;
  for (i = 0; i < MR_SIZE; i++) {
      MR[i] = buildPage(i);
  }

  for (i = MR_SIZE; i < (MR_SIZE + MS_SIZE); i++) {
      MS[i - MR_SIZE] = buildPage(i);
  }
}

int main(int argc, char **argv) {
  Page MS[MS_SIZE];
  Page MR[MR_SIZE];
  int i;
  fillMemory(MR, MS);
  printf("Memória Real:\n");  
  printMemory(MR, MR_SIZE);
  printf("Memória de Swap:\n");
  printMemory(MS, MS_SIZE);
  srand(time(NULL));
  for (i = 0; i < ITERATIONS; i++) {  
    int randomId = rand() % (MR_SIZE + MS_SIZE);
    printf("%d\n", randomId);
    int inMemory = findPage(MR, randomId);
    if (inMemory) {
      printf("FOUND IN MEMORY\n");
      updateBits(MR, MR_SIZE, randomId);
    } else {
      swapPage(MR, MS, randomId);
      updateBits(MR, MR_SIZE, randomId);
      printf("FAZER SWAP\n");
    }
    printMemory(MR, MR_SIZE);
  }
  return 0;
}