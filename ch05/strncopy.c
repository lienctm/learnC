/* strncopy : copy the first n characters of t to s */

#include<stdio.h>

void strncopy( char s[], char t[], int n ) {
  int i = 0 ;
  while((s[i] = t[i]) != '\0' && i < n)
      i++;
}


int main() {
  char s[10] = "hello";
  char t[30] = "world cup";
  int n = 5;
  strncopy(s,t,n);
  printf("new string is : %s\n",s);
}
