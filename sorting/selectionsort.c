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

void selectionsort(int s[], int n) {
  int i, j, k;
  for(i = 0; i < n-1; i++ ) {
    int v = s[i];
    k = i;
    for(j = i+1; j < n; j++) {
      if(v  > s[j]) {
        v = s[j];
        k = j;
      }
    }
    swap(s, i, k);
/* row 17-26: find min index from i(1 -> n-1)*/
  }
}

int main() {
  int a[] = {1, 20, 8, 15, 19};
  int n = 5;
  selectionsort(a, n);
  print(a, n);
}
