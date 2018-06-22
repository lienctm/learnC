#include<stdio.h>
#include<string.h>
#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

/* getline : read line into s,
 * return length ( how many character is read in line ) */

int getline1(char *s, int lim) {
  int c, i;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if(c == '\n') {
    s[i] = c;
    ++i ;
  }
  s[i] = '\0';
  return i;
}

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* alloc(n) : return pointer to n characters */

char *alloc(int n) {
  if((allocbuf + ALLOCSIZE - allocp) >= n ) {
    allocp += n;
    return allocp - n;
  }
  else
    return 0;
}

/* readline : read input lines from screen */

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = getline1(line, MAXLEN)) > 0)
    if(nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';    /* delete new line */
      strcpy(p, line);
      //p = lineptr[nlines++];
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writeline : write input line */

 void writelines(char *lineptr[], int nlines) {
   int i;

   for(i = 0; i < nlines; i++)
     printf("%s\n", lineptr[i]);
 }

/* quicksort : sorting by using pivot */

void swap(char *v[], int i, int j) {
  char* tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

void qsort(char *v[], int left, int right) {
  int i, last;

  if(left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for(i= left + 1; i <= right; i++)
    if(strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

int main() {
  int nlines;
  char *lineptr[MAXLINES];

  if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    printf("--------------------\n");
    writelines(lineptr, nlines);
    return 0;
  }
  else {
    printf("error : input too big to sort\n");
    return 1;
  }
}
