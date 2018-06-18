#include<stdio.h>

float getch(void);
void ungetch(float);

int main() {
  char buf[100];
  int i = -1;

  char getch() {
    if(i < 0)
      return getch();
    else
      return buf[i--];
  }

  void ungetch(char c) {
    buf[++i] = c;
  }
}
