#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINE 100
#define MAXLEN  100

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
    if(nlines >= maxlines || (p = (char*) malloc(len*sizeof(char))) == NULL) {
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

void swap(char *v[], int i, int j) {
  char *tmp;

  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

void qsort1(
    char *s[], int left, int right, int (*comp)(const char*, const char *)) {
  int i, last;

  if(left >= right)
    return;
  swap(s, left, (left + right) / 2);
  last = left;
  for(i = left + 1; i <= right; i++)
    //if(comp(s[i], s[left]) < 0) // OK
    if((*comp)(s[i], s[left]) > 0)
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

void myfree(char **p, int n) {
  int k;
  for (k = 0; k < n; k++) {
    if (p[k] != NULL) free(p[k]);
  }
}

int main(int argc, char *argv[]) {
  int nlines;           // number of input lines read
  int numeric = 0;
  char *lineptr[MAXLINE];

  if(argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;        // numeric sort
  if((nlines = readlines(lineptr, MAXLINE)) >= 0) {

    //int (*f)(const char *, const char *) = numeric ? numcmp : strcmp; // OK
    int (*f)(const char *, const char *) = numeric ? &numcmp : &strcmp;

    qsort1(lineptr, 0, nlines -1, f);
    printf("-----------------------\n");
    writelines(lineptr, nlines);

    myfree(lineptr, nlines);
    return 0;
  }
  else {
    myfree(lineptr, nlines);
    printf("error : too big to sort\n");
    return 1;
  }
}
