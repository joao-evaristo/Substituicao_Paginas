#include <stdio.h>
#include <stdlib.h>

Page buildVirtual(int id) {
  int i;
  Page page;
  for(i = 0; i < BITS; i++) {
    page.bits[i] = 0;
  }

  page.id = id;
  page.isInMemory = FALSE;
  return page;
}


RealPage buildReal(Page virtualPage, int data) {
  RealPage page;
  page.page = virtualPage;
  page.data = data;
  return page;
}
