#include<stdio.h>

unsigned getbits(unsigned x, int p, int n) {
  return(x >> (p+1-n)) & ~(~0 << n);
}

int main() {
  int x = 49, p = 5, n = 3;
  int y = getbits(49, 5, 3);
  printf("y = %u\n", y);

}
