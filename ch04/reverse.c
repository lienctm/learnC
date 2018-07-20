// Des : recursive version the function reverse(s)

#include<stdio.h>
#include<string.h>

void swap(char *s, int i, int j) {
  char c = s[i]; s[i] = s[j]; s[j] = c;
}

void rfunc(char *s, int start, int end) {
  if (start >= end)
    return;
  //rfunc(s, start+1, end-1);
  //swap(s, start, end);

  swap(s, start, end);
  rfunc(s, start+1, end-1);
}

int main() {
  char A[] = "THURSDAY";
  int n = strlen(A);
  rfunc(A, 0, n-1);
  printf("A after reverse : %s\n", A);
}
