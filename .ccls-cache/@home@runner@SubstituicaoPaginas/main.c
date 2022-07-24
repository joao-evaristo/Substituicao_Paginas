#include <stdio.h>

#define nbits 8
#define npages 6
int pages[npages][nbits];

void init() {
  int i, j;
  for(i = 0; i < npages; i++) {
    for(j = 0; j < nbits; j++) {
      pages[i][j] = 0;
    }
  }
}

void printPages() {
  int i, j;
  for(i = 0; i < npages; i++) {
    printf("Page %d: ", i);
    for(j = 0; j < nbits; j++) {
      printf("%d ", pages[i][j]);
    }
    printf("\n");
  }
}

void addR(int *r) {
  int i;
  for(i = 0; i < npages; i++) {
    pages[i][0] = r[i];
  }
}

void attPage() {
  int i, j;
  for(i = 0; i < npages; i++) {
    for(j = nbits - 1; j >= 0; j--) {
      if(j == 0) {
        pages[i][j] = 0;
      } else {
        pages[i][j] = pages[i][j - 1];
      }
    }
  }
}

int main() {
  init();
  int rBits1[] = {0, 0, 0, 0, 0, 1};
  printf("Momento 1.\n\n");
  printPages();
  int i;
  int n = 2; // num iteracoes
  addR(rBits1);
  printf("\nMomento 2.\n\n");
  printPages();
  attPage();
  int rBits2[] = {1, 1, 0, 1, 0, 0};
  addR(rBits2);
  printf("\nMomento 3.\n\n");
  printPages();
  attPage();
  int rBits3[] = {1, 0, 1, 1, 0, 1};
  addR(rBits3);
  printf("\nMomento 4.\n\n");
  printPages();
  return 0;
}