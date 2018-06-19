/* swap : pointer version
 * working with the address of input */

#include<stdio.h>

void swap( int *px, int *py) {
  int temp = *px;
  *px = *py;
  *py = temp;
}

int main() {
  int x = 10, y = 12;
  swap(&x, &y);    /* working at address of x,y */
  printf("result is : x = %d  y = %d\n", x, y);
}
