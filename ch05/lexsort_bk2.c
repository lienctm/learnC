/* Description : this program is used to sort inputs into alphabetic order
 * 3 sorting steps : read input, sort, and print */

#include<stdio.h>
#include<string.h>

#define MAXLINES   5000         /* max lines to be sorted */
#define MAXLEN     1000         /* max length of input lines */
#define ALLOCSIZE  10000

/* getline : read line into s, return lenght */
int getline1(char s[], int lim) {
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

char *alloc(int n) {
  if(allocbuf + ALLOCSIZE - allocp >= n) {
    allocp = allocp + n;
    return allocp - n;
  }
  else
    return 0;          /* don't have enough room */
}

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = getline1(line, MAXLEN)) > 0)
    if(nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

void swap(char *v[], int i, int j) {
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int numcmp(const char* a, const char* b) {
  return *a - *b;
}

void qsort2(char *v[], int left, int right, int (*f)(const char*, const char*)) {
  int i, last;

  if(left >= right)
    return ;
  swap(v, left, (left + right) / 2);
  last = left;
  for(i = left+1; i <= right; i++)
    //if((*f)(v[i], v[left]) < 0)
    if(f(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort2(v, left, last-1, f);
  qsort2(v, last+1, right, f);
}

int main2() {
  int select = 0; // 0 if compare string, 1 if comapre number
  //int (*func)(const char*, const char*) = select? numcmp : strcmp;
  int (*func)(const char*, const char*) = select? &numcmp : &strcmp;
  char *v[100];
  qsort2(v, 0, 99, func);
  return 1;
}

void qsort(char *v[], int left, int right) {
  int i, last;

  if(left >= right)
    return ;
  swap(v, left, (left + right) / 2);
  last = left;
  for(i = left+1; i <= right; i++)
    if(strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}


void writelines(char *lineptr[],  int nlines) {
  int i;

  for(i = 0; i < nlines; i++)
    printf(" %s\n", lineptr[i]);
}

int main() {
  int nlines;                /* number of input lines */
  char *lineptr[MAXLINES];

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
