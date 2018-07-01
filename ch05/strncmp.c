/* strncomp : compare n characters of t and s
 * return < 0 if s < t, 0 if s = t, > 0 if s >t */

#include<stdio.h>

int strncmp1(char *s, char *t, int n) {
  int i = 0;
  while(n == 0)
    return 0;
  while((s[i] == t[i]) != '\0' && s[i] != '\0' && i < n)
    i++;
  return s[i] - t[i];
}

int main() {
  char *s = "EXCERCISE";
  char *t = "EXCITEMENT";
  int n = 4;
  int k = strncmp1(s, t, n);
  printf(" result is : %d\n", k);
}
