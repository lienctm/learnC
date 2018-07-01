#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINE 100
#define MAXLEN  100
#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
  if((allocbuf + ALLOCSIZE - allocp) >= n) {
    allocp += n;
    return allocp - n;
  }
  else
    return 0;
}

int getline1(char *s, int lim) {
  int i, c;

  i = 0;
  while(i < lim - 1 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if(c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = getline1(line, MAXLEN)) > 0) {
    if(nlines >= maxlines || (p = alloc(len)) == NULL) {
      return -1;
    }
    else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  int i;

  for(i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);

}

void swap(void *v[], int i, int j) {
  void *tmp;

  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

void qsort1(
    void *s[], int left, int right, int (*comp)(const void *, const void *)) {
  int i, last;

  if(left >= right)
    return;
  swap(s, left, (left + right) / 2);
  last = left;
  for(i = left + 1; i <= right; i++)
    if((*comp)(s[i], s[left]) < 0)
      swap(s, ++last, i);
  swap(s, left, last);
  qsort1(s, left, last - 1, comp);
  qsort1(s, last + 1, right, comp);
}

int numcmp(const char *s1, const char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if(v1 > v2)
    return 1;
  if(v1 < v2)
    return -1;
  else
    return 0;
}

int main(int argc, char *argv[]) {
  int nlines;           // number of input lines read
  int numeric = 0;
  char *lineptr[MAXLINE];

  if(argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;        // numeric sort
  if((nlines = readlines(lineptr, MAXLINE)) >= 0) {
    qsort1((void **)lineptr, 0, nlines -1,
        (int (*)(const void *, const void *))(numeric ? numcmp : strcmp));
    printf("-----------------------\n");
    writelines(lineptr, nlines);
    return 0;
  }
  else {
    printf("error : too big to sort\n");
    return 1;
  }
}
