//Description : comparing between const pointer & pointer to const

#include<stdio.h>
int main() {
  int x= 1, y = 10;

  int * const ptr1 = &x;  // Constant pointer to int
  ptr1 = &y;  // Error <no change address>
  *ptr1 = 10;  // Ok

  const int *ptr2 = &x; // Pointer to constant int
  ptr2 = &y;  // Ok
  *ptr2 = 1;  // Error <no change value>
}
