#include "page.h"
#include <stdio.h>
#include <stdlib.h>

#define ITERATIONS 10

void fillMemory(Page *MR[], Page *MS[], Page *MV[]) {
  int i;
  for (i = 0; i < (MR_SIZE + MS_SIZE); i++) {
    Page *page = buildPage(i);
    if (i < MR_SIZE) {
      page->isInMemory = TRUE;
      MR[i] = page;
    } else {
      page->isInMemory = FALSE;
      MS[i] = page;
    }

    MV[i] = page;
  }
}

int main(int argc, char **argv) {
  Page *MV[MV_SIZE];
  Page *MS[MS_SIZE];
  Page *MR[MR_SIZE];
  int i;
  fillMemory(MR, MS, MV);
  printf("MV\n");
  printMemory(MV, MV_SIZE);
  printf("MS\n");  
  printMemory(MS, MS_SIZE);
  printf("MR\n");
  printMemory(MR, MR_SIZE);

  /*for (i = 0; i < ITERATIONS; i++) {
    int random = rand() % (MR_SIZE + MS_SIZE);
    int inMemory = searchPageList(MV, random);
    if (inMemory) {
      printf("FOUND IN MEMORY\n");
      updateBits(MV, random);
    } else {
      swapPages(MV, MS, random);
    }
  }*/
  return 0;
}