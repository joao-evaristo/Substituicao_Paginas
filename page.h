#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BITS 8
#define TRUE 1
#define FALSE 0
#define MV_SIZE 10
#define MS_SIZE 5
#define MR_SIZE 5

typedef struct Page {
  int id;
  int bits[BITS];
} Page;

typedef struct RealPage {
  Page page;
  int data;
} RealPage;

void fillBits(int *bits) {
  int i;
  for (i = 0; i < BITS; i++) {
    bits[i] = 0;
  }
}

Page buildPage(int id) {
  int i;
  Page page;
  fillBits(page.bits);

  page.id = id;
  return page;
}

void printBits(int *bits) {
  int i;
  for (i = 0; i < BITS; i++) {
    printf("%d ", bits[i]);
  }
}

void printMemory(Page *memoryList, int length) {
  int i;
  for (i = 0; i < length; i++) {
    printf("{ ");
    printf("id: %d, ", memoryList[i].id);
    printf("bits: ");
    printBits(memoryList[i].bits);
    printf("}");
    printf("\n");
  }
}

int findPage(Page *MR, int id) {
    int i;
    for (i = 0; i < MR_SIZE; i++) {
        if (MR[i].id == id) {
            return TRUE;
        }
    }
    return FALSE;
}

int power(int a, int b) {
    int i;
    int pow = 1;
    for (i = 0; i < b; i++) {
        pow *= a;
    }
    return pow;
}

int byteToInt(int *byte) {
    int i, j;
    int number = 0;
    for (i = 0, j = BITS-1; i < BITS; i++, j--) {
        if(byte[i]) {
           number += (int) power(2, j); 
        }
    }

    return number;
}

void updateBits(Page *mem, int len, int id) {
  int i, j;
  for(i = 0; i < len; i++) {
    for(j = BITS - 1; j >= 0; j--) {
      if(j == 0) {
        mem[i].bits[j] = 0;
      } else {
        mem[i].bits[j] = mem[i].bits[j - 1];
      }
    }

    if (mem[i].id == id) {
        mem[i].bits[0] = 1;
    }
  }
}

void swapPage(Page *MR, Page *MS, int id_page){
  int i;
  int oldest = 255;
  int oldest_index = 0;
  Page page_aux;
  for (i = 0; i < MR_SIZE; i++) {
    int current = byteToInt(MR[i].bits);
    if(current < oldest) {
      oldest_index = i;
      oldest = current;
      if (!current) {
        break;
      }
    }
  }
  
  fillBits(MR[oldest_index].bits);
  for (i = 0; i < MS_SIZE; i++) {
    if (MS[i].id == id_page) {
      page_aux = MS[i];
      MS[i] = MR[oldest_index];
      MR[oldest_index] = page_aux;
    }
  }
}