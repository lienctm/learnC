/* strcmp : compare the fist character that is difference between 2 strings
 * return < 0 if s<t, 0 if s=t, > 0 if s>t */

#include<stdio.h>

int strcmp1( char *s, char *t) {
  int i;
  for(i = 0; s[i] == t[i]; i++)
    if(s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

int main() {
  char *s = "AAABCDEF";
  char *t = "AAAHACDD";
  int k = strcmp1(s, t);
  printf("result is : %d\n", k);

}
