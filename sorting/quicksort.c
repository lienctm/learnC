#include<stdio.h>

void print(int s[], int n) {
  int i;
  for(i = 0; i < n; i++)
    printf("%d  ", s[i]);
  printf("\n");
}

void swap(int s[], int i, int j) {
  int c = s[i];
  s[i] = s[j];
  s[j] = c;
}

int partition(int x[],int left, int right) {
  int i, last;
  int pivot = x[left];
  last = left;
  for(i = left+1; i <= right ; i++) {
    if(x[i] < pivot)
      swap(x, i, ++last);
  }
  swap(x, left, last);
  return last;
}

void quicksort(int v[], int left, int right) {
  if(left >= right)
    return;
  int k = partition(v, left, right);
  quicksort(v, left, k-1);
  quicksort(v, k+1, right);
}

int main() {
  int A[] = {3, 1, 0, 8, 5, 9, 10};
  int n = 7;
  quicksort(A, 0, n-1);
  print(A, n);
}

