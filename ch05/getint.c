/* created by Lien Cao
 * dated 06/16/2018
 * Description:
 * this program parses a sequence of characters
 * into integeres
 * This demonstrates how to use pointer to return multiple values in C
 */


#include<stdio.h>
#include<ctype.h>
#define SIZE 100

int main() {
  int n, array[SIZE], getint(int *);
  for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++);

  int i;
  for(i = 0; i < n; i++)
    printf("%d\t", array[i]);
  printf(" \n");
}

int getch(void);
void ungetch(int);

int getint(int *pn)
{
  int c, sign;

  while(isspace(c = getch())); /* get until c is not space */

  if( !isdigit(c) && c != EOF && c != '-' && c != '+' ) {
    ungetch(c);
    return 0;
  }

  sign = ( c == '-' ) ? -1 : 1;
  if(c == '+' || c == '-')
    while(isspace(c = getch()));

  for( *pn = 0; isdigit(c); c = getch() )
    *pn = *pn * 10 + (c - '0');

  *pn *= sign;

  if( c != EOF )
    ungetch(c);

  return c;
}

