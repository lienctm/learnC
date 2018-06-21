/* strncat : concaternate the first n characters of t to end of s */

#include<stdio.h>

void strncat1(char s[], char t[], int n) {
  int i, j ;
  i = j = 0;
  while(s[i] != '\0')
    i++ ;
  while((s[i++] = t[j++]) != '\0' && (j < n))
    ;
}

int main() {
  char s[50] = "Hello, ";
  char t[50] = "world cup";
  int n = 5;
  strncat1(s, t, n);
  printf("After concaternate 2 strings : %s\n", s);
}
