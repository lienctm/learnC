 /* Purpose : want to check the different size of array and pointer */

#include <stdio.h>

int main() {
  int a[15];      /* a: array[15] of int */
  printf("size of a[15] is %d\n", sizeof(a));

  int (*b)[15];   /* b: pointer to array[15] of int */
  //int *b = a;    // OK;
  printf("size of *b is %d\n", sizeof(b));

  char c[15];
  printf("size of c[] is %d\n", sizeof(c));

  char *d;
  printf("size of *d is %d\n", sizeof(d));
}

