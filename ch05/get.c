#include<stdio.h>

char buf[100];
int i = -1;

char getch() {
  if( i < 0 )
    return getchar();
  else
    return buf[i--];
}

void ungetch( char c ) {
  buf[++i] = c;
}
