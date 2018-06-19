/* strcat - normal function
 * concatenate the string t to the end of the string s */

#include<stdio.h>
#include<string.h>

void strcat1(char s[], char t[])   {
  int i, j;

  i = j = 0;
  while(s[i] != '\0')      /* assume that s has enough space to concatenate */
    i++;
  while((s[i++] = t[j++]) != '\0')  /* copy t to the end of s */
    ;
}

int main() {
  char s[50] = "hello,";
  char t[30] = "world";
  strcat(s,t);
  printf(" new string is : %s \n", s);
}
