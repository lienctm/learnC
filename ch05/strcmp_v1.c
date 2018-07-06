// Description :compare 2 strings(s, t) but a and A compare equal
// return 0 if s = t, 1 if s > t, -1 if s < t

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int valid(char c) {
  return isalpha(c) || isspace(c);
}

int strcmp1(char *s, char *t, int fold, int dir) {
  int i = 0, j = 0;
  char a = fold ? tolower(*s) : *s;
  char b = fold ? tolower(*t) : *t;

  while(s[i] != '\0' && t[j] != '\0') {
    if(dir) {
      while(s[i] != '\0' && !valid(s[i]))
        i++;
      while(t[j] != '\0' && !valid(t[j]))
        j++;
    }
    a = fold ? tolower(s[i]) : s[i];
    b = fold ? tolower(t[j]) : t[j];

    if(a != b)
      break;

    i++; j++;
  }
  return a - b;
}

int main() {
  char s[] = "Sep tember";
  char t[] = "SEPtember";
  int f = 1, d = 1;
  int k = strcmp1(s, t, f, d);
  printf("result is %d\n", k);
}

