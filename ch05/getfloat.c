/* date 06/17/18
 *
 */

#include<stdio.h>
#include<ctype.h>
#define SIZE 100

int main() {
  int n;
  float array[SIZE];
  int getfloat (float *);

  for(n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);

  int i;
  for( i = 0; i< n; i++)
    printf("%.3f\n", array[i]);
  printf(" \n");
}

int getch(void);
void ungetch(int);

int getfloat (float *pn) {
  int c, sign;
  float power;

  while(isspace(c = getch()));  /* skip white space */

  if(!isdigit(c) && c != EOF && c != '-' && c != '+') {
    ungetch(c);
    return 0;   /* it is not number */
  }

  sign = (c == '-') ? -1 : 1;

  if(c == '+' || c == '-')
    while(isspace(c = getch()));

  for(*pn = 0; isdigit(c); c = getch())
    *pn = *pn * 10 + (c - '0');

  if(c == '.')
    c = getch();

  for(power = 1.0; isdigit(c); c = getch()) {
    *pn = *pn * 10 + (c - '0');
    power *= 10.0;
  }
  *pn = (*pn *sign) / power;

  if(c != EOF)
    ungetch(c);
  return c;
}
