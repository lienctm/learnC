/* strcat - pointer version */

#include<stdio.h>
#include<string.h>

void strcat1(char *s, char *t)  {
  while(*s != '\0')
    s++;
  while((*s++ = *t++) != '\0')    /* copy t to s */
    ;
}

int main() {
  char s[55] = "Today is ";
  char t[55] = "Monday, June 18, 2018";
  strcat1(s, t);
  printf("new string is : %s\n", s);
}

