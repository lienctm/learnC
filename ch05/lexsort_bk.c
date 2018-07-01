/* sort string :
 * read lines of input - sort - print */

#include<stdio.h>
#include<string.h>
#define MAXLINES 5000    /* max lines are sorted */
#define MAXLEN  1000     /* max length of input line */
#define ALLOCSIZE 100000

int getline1(char *s, int lim) {
  int c, i;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
  if(allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  }
  else
    return 0;
}

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = getline1(line, MAXLEN)) > 0)
    if(nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

void swap(char *v[], int i, int j) {
  char *tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

void qsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if(left >= right)
    return;
  swap(v, left, (left+right) / 2);
  last = left;
  for(i = left + 1; i <= right; i++)
    if(strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void writelines(char *lineptr[], int nlines) {
  int i;

  for(i = 0; i < nlines; i++)
    printf(" %s\n", lineptr[i]);
}

/* sort input lines */
int main() {
  int nlines;            /* number of input lines read */
  char *lineptr[MAXLINES];    /* array[] of pointer to char */

  if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  }
  else {
    printf("error: input too big to sort\n");
    return 1;
  }
}
