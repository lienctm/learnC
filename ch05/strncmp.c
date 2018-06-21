/* strncomp : compare n characters of t and s
 * return < 0 if s < t, 0 if s = t, > 0 if s >t */

#include<stdio.h>

int strncmp1(char *s, char *t, int n) {
  int i;

  if( n == 0 )
    return 0;

  for(i = 0; s[i] != '\0' && s[i] == t[i] && i < n -1; i++) ;
  return s[i] - t[i];
}

int main() {
  char *s = "FEBRUARY";
  char *t = "FEED";
  int n = 1;
  int k = strncmp1(s, t, n);
  printf(" result is : %d\n", k);
}
