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

float getch(void);
void ungetch(float);

int getfloat (float *pn) {

}
