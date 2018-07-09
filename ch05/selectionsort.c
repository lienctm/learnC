#include<stdio.h>

void print(int x[], int n) {
  int i;
  for(i = 0; i < n; i++)
    printf("%d\t", x[i]);
  printf("\n");
}

void swap(int s[], int i, int j) {
  int c;
  c = s[i];
  s[i] = s[j];
  s[j] = c;
}

int selectionsort(int x[], int n) {
  int i, j, k;
  for(i = 0; i < n; i++) {
    k = i;
    for(j = i + 1; j < n; j++) {
      if(x[j] < x[k])
        k = j;
    }
    swap(x, i, k);
  }
}

int main() {
  int a[] = {20, 12, 30, 15, 8, 35};
  int k = 6;
  selectionsort(a, k);
  print(a, k);
}
