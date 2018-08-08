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

// Partition array into 3 sub arrays A, B and C
// A < pivot : B = pivot : C > pivot

int partition(int x[],int left, int right) {
  int i, last1 = left-1, last2 = left;
  int pivot = x[left];

  for(i = left+1; i <= right ; i++) {
    if(x[i] > pivot)
      ;
    else if(x[i] == pivot) {
      last2++;
      swap(x, i, last2);
    }
    else {
      last1++;
      last2++;
      swap(x, i, last1);
      swap(x, i, last2);
    }
  }
  return last1 + 1;
}

void quicksort(int v[], int left, int right) {
  if(left >= right)
    return;
  int k = partition(v, left, right);
  quicksort(v, left, k-1);
  quicksort(v, k+1, right);
}

int main() {
  int A[] = {10, 7, 15, 6, 10, 19, 1};
  int n = 7;
  //partition(A, 0, n-1);
  quicksort(A, 0, n-1);
  print(A, n);
}

