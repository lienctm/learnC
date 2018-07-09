#include<stdio.h>

void print(int s[], int n) {
  int i;
  for(i = 0; i < n; i++)
    printf("%d\t", s[i]);
  printf(" \n");
}

void swap(int s[], int i, int j) {
  int c = s[i];
  s[i] = s[j];
  s[j] = c;
}

void insertionsort(int s[], int n) {
  int i, j;
  for(i = 1; i < n; i++) {
    for(j = i; j >= 0; j--) {
      if(s[j] < s[j-1])
        swap(s, j, j-1);
      else
        break;
    }
  }
}

int main() {
  int a[] = {20, 12, 30, 15, 8, 35};
  int k = 6;
  insertionsort(a, k);
  print(a, k);
}
