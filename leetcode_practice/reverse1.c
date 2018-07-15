// des: reverse k characters counting from the begining of string

#include<stdio.h>

char my_reverse(char s[], int k) {
  int i, j;
  for(i = 0 ,j = k-1; i < j; i++, j--) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

int main() {
  char a[] = "answer";
  int k = 2;
  my_reverse(a, k);
  printf("result: %s\n", a);
}
