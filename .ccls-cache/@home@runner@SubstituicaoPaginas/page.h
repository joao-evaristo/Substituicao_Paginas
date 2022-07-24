#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS 8
#define TRUE 1
#define FALSE 0
#define MV_SIZE 10
#define MS_SIZE 5
#define MR_SIZE 5

typedef struct Page {
  int isInMemory;
  int id;
  int bits[BITS];
} Page;

typedef struct RealPage {
  Page page;
  int data;
} RealPage;

Page *buildPage(int id) {
  int i;
  Page *page = (Page*) malloc(sizeof(Page));
  for (i = 0; i < BITS; i++) {
    page->bits[i] = 0;
  }

  page->id = id;
  page->isInMemory = FALSE;
  return page;
}

void printIsInMemory(int value) {
  if (value) {
    printf("True, ");
  } else {
    printf("False, ");
  }
}

void printBits(int *bits) {
  int i;
  for (i = 0; i < BITS; i++) {
    printf("%d ", bits[i]);
  }
}

void printMemory(Page *memoryList[], int length) {
  int i;
  for (i = 0; i < length; i++) {
    printf("{ ");
    printf("id: %d, ", memoryList[i]->id);
    printf("isInMemory: ");
    printIsInMemory(memoryList[i]->isInMemory);
    printf("bits: ");
    printBits(memoryList[i]->bits);
    printf(" }");
    printf("\n");
  }
}
