#include<stdio.h>
int main() {
  int x=5;
  int y=10;

  int const *p = &x;

  printf("%d \n", x);
}
