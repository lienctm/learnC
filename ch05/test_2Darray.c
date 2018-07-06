#include<stdio.h>

int main() {
  int table[3][4]= {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}};

  int *p = table[0];
  int (*q)[4] = table;

  int i = 2, j = 3;
  int N = 4;

  int pval = *(p + i*N + j);
  //int qval = (*(q + i))[j];
  //int qval = q[i][j];
  int qval = *(*(q+i) + j);

  printf("value at table[%d][%d] using p: %d\n", i, j, pval);
  printf("value at table[%d][%d] using q: %d\n", i, j, qval);

}
