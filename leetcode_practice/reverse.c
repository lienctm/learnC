#include<stdio.h>
#include<string.h>

// reverse string :

void reverse(char s[]) {
  int i, j, c;
  for(i = 0 ,j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

// reverse integer :

int reverse1(int n) {
  int rev = 0;
  while(n != 0) {
    int k = n%10;
    n /= 10;
    rev = 10 * rev + k;
  }
  return rev;
}

int main() {
  char s[] = "Monday";
  reverse(s);
  printf("case 1 - reverse string: %s\n", s);

  int n = 6789;
  int m = reverse1(n);
  printf("case 2 - reverse integer: %d\n", m);
}
