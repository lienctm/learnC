// Des : strrindex returns the position of the rightmost
// occurence of t in s, or  -1 if there is none.

#include<stdio.h>

int my_strrindex(char s[], char t[]) {
  int i, j;
  i = 0;
  int found = -1;
  while(s[i] != '\0') {
    j = 0;
    while(t[j] == s[i+j] && t[j] != '\0')
      j++;
    if(j > 0 && t[j] == '\0')
      found = i;
    i++;
  }
  return found;
}

int main() {
  char s[50] = "hello summer, summer is comming";
  char t[50] = "summer";
  int k = my_strrindex(s, t);
  printf("rightmost position of t in s is: %d\n", k);
}
