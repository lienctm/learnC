/* PRACTICE BY REWRITE - Date 06/17/18
 * Getint : return 2 valuse by seperate paths
 * Demonstrate how to use pointer to return many values */

#include<stdio.h>
#include<ctype.h>
#define SIZE 100

int main () {
  int n, array[SIZE], getint(int *);
  for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++);

  int i;
  for(i = 0; i < n; i++)
    printf(" %d\t", array[i]);
  printf(" \n");
}

int getch(void);
void ungetch(int);

int getint(int *pn) {
  int c, sign;
  while(isspace(c = getch()));  /* get until c is not space */

  if(!isdigit(c) && c != EOF && c != '-' && c != '+') {
    ungetch(c);
    return 0;        /* it is not number */
  }

  sign = (c == '-') ? -1 : 1;
  if(c == '-' || c == '+')
    while(isspace(c = getch()));   /* skip white space */
  for(*pn = 0; isdigit(c); c = getch())
    *pn = *pn * 10 + (c - '0');
  *pn *= sign;

  if(c != EOF)
    ungetch(c);
  return c;
}
