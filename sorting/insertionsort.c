#include<stdio.h>

void print(int s[], int n) {
  int i;
  for(i = 0; i < n; i++)
    printf("%d\t", s[i]);
  printf(" \n");
}

void swap(int s[], int i, int j) {
  int temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

void insertionsort(int s[], int n) {
  int i, j;
  for(i = 1; i < n; i++ ) {
    j = i;
    for(j > 0; s[j] < s[j-1]; j--)
      swap(s, j, j-1);
  }
}

int main() {
  int a[] = {1, 20, 8, 19, 12};
  int n = 5;
  insertionsort(a, n);
  print(a, n);
}
