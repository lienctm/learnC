#include<stdio.h>

int main() {
  unsigned char a = 9;     // 00001001
  printf("a << 1 = %u\n", a << 1);  // 0010010
  printf("a >> 1 = %u\n", a >> 1);  // 0000100

  int k = 3;
  unsigned char a1, a2, a3 ,a4;

  a1  = a | (1 << k);  // set bit k
  printf("after set bit: a = %u\n", a1);

  a2 = a & (~(1 << k));  // clear bit k
  printf("after clear bit: a = %u\n", a2);

  a3 = a & (a - 1);  // clear last 1
  printf("after clear last 1: a = %u\n", a3);

  a4 = a & (~(a - 1));  // keep only last 1
  printf("keep only last 1: a = %u\n", a4);
}
