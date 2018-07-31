#include<stdio.h>

int main() {
  int s[6] = { 10, 20, 30, 40, 50, 60 };
  int a[2] = { 10, 20 };
  int b[3][2] = {{10, 20}, {30, 40}, {50, 60}};

  int *p[6];    // p: array[6] of pointer to int
  p[0] = &s[0];
  p[1] = &s[1];
  p[2] = &s[2];
  printf("%d, %d, %d\n", *p[0], *p[1], *p[2]);  // print: 10, 20, 30

  int (*q)[2];  // q: pointer to array[2] of int
  //q = &s;   < ERROR >: imcompatible pointer type
  //q = &a;
  // *q = a;   < ERROR > *q on the left: assign to array
  //int *qq = *q; // *q on the right: address of the first element of array
  q = &b[0];
  *q[0] = b[0][0];
  *q[1] = b[1][0];
  *q[2] = b[2][0];
  printf("%d, %d, %d\n", *q[0], *q[1], *q[2]);  // print: 10, 30, 50
}


