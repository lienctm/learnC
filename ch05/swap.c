/* swap - normal function :
 * swap inside function
 * doesn't change the input */

#include<stdio.h>

void swap(int x, int y)  {
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  int x = 5, y = 10;
  swap(x, y);
  printf("result is : x = %d  y = %d\n", x, y);
}
