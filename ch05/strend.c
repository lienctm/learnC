#include<stdio.h>

int strend(char s[], char t[]) {
  int i, j;
  i = j = 0;

  while(s[i] != '\0')
    i++;
  while(t[j] != '\0')
    j++;

  while(i >= 0 && j >= 0 && (s[i] == t[j])) {
    i-- ;
    j-- ;
  }
  if(j < 0)
    return 1;   /* found  t occurs at the end of s */
  else
    return 0;   /* not found */
}

int main() {
  char s[] = "World cup 2018";
  char t[] = "2018";
  int x = strend(s,t);
  int y = strend(t,s);
  printf(" result of x is : %d\n", x);
  printf(" result of y is : %d\n", y);
}
