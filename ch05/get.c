#include<stdio.h>

char buf[100]; // a buffer of storage
int i = -1;    // last position in buffer containing a char

// in the book: pos: next available position (pos = 0)

char getch() {
  if( i < 0 )
    return getchar();
  else
    return buf[i--];
}

void ungetch( char c ) {
  buf[++i] = c;
}
