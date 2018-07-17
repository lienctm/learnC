#include<stdio.h>

// strrindex: return index of t in s, or -1 if none
// occurence of t in s, or -1 if none

int strrindex(char s[], char t[]) {
  int i, j;
  int found = -1;
  i = 0;
  while(s[i] != '\0') {
    j = 0;
    while(t[j] == s[i+j] && t[j] != '\0')
      j++;
    if(t[j] == '\0')
      found = i;
    i++;
  }
  return found;
}

// strindex : return index of t in s, or -1 if none

int strindex(char s[], char t[]) {
  int i, j, k;
  for(i = 0; s[i] != '\0'; i++) {
    for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, j++) ;
    if(t[j] == '\0')
      return i;
  }
  return -1;
}

int main() {
  char s[] = "abcdeabef";
  char t[] = "ab";
  int k = strrindex(s, t);
  int m = strindex(s, t);
  printf("rightmost position of t in s is : %d\n", k);
  printf("indext of t in s is : %d\n", m);
}
