/* swap - normal function :
 * swap inside funtion
 * doesn't change the input */

#include<stdio.h>

void swap(int x, int y)   {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

int main () {
  int x = 1 , y = 12;
  swap(x,y);
  printf("result is: x = %d  y = %d\n", x, y);
}



