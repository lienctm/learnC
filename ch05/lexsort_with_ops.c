#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

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

// strcmp1 :compare 2 strings but A and a compare equal
int valid(char c) {
  return isalnum(c) || isspace(c);
  //return isalpha(c) || isspace(c);
}

int strcmp1(char *s, char *t, int fold, int dir) {
  int i = 0, j = 0;
  char a, b;

  while(s[i] != '\0' && t[j] != '\0') {
    if(dir) {
      while(s[i] != '\0' && !valid(s[i]))
        i++;
      while(t[j] != '\0' && !valid(t[j]))
        j++;
      //printf("s=%s, t=%s, i=%d, j=%d\n", s, t, i, j);
    }
    a = fold ? tolower(s[i]) : s[i];
    b = fold ? tolower(t[j]) : t[j];
    // a and b are not '\0' so 10 and 1, a=b='1'

    if(a != b)
      break;

    //if(s[i] == '\0' || t[j] == '\0')
    //  break;
    //i++;
    //j++;

    if (s[i] != '\0') i++;
    if (t[j] != '\0') j++;

  }
  a = fold ? tolower(s[i]) : s[i];
  b = fold ? tolower(t[j]) : t[j];

  return a - b;
}


void qsort1(
    char *s[], int left, int right, int fold, int dir, int r) {
  int i, last;

  if(left >= right)
    return;
  swap(s, left, (left + right) / 2);
  last = left;
  for(i = left + 1; i <= right; i++)
    if((r && strcmp1(s[i], s[left], fold, dir) > 0)
        || (!r && strcmp1(s[i], s[left], fold, dir) < 0))
      swap(s, ++last, i);
  swap(s, left, last);

  qsort1(s, left, last - 1, fold, dir, r);
  qsort1(s, last + 1, right, fold, dir, r);
}


void myfree(char **p, int n) {
  int k;
  for (k = 0; k < n; k++) {
    if (p[k] != NULL) free(p[k]);
  }
}


int main(int argc, char *argv[]) {
  int nlines;           // number of input lines read
  char *lineptr[MAXLINE];
  int fold = 0, dir = 0, r=0;
  char c;


  // read args start with -
  // loop through each char
  // switch(c) check for each case

  while(--argc > 0 && (*++argv)[0] == '-')
    while((c = *++argv[0]))
      switch(c) {
        case 'r':
          r = 1;
          break;
        case 'f':
          fold = 1;
          break;
        case 'd':
          dir = 1;
          break;
        defaul :
          printf("illegal option argument\n");
          break;
      }

  if((nlines = readlines(lineptr, MAXLINE)) >= 0) {
    qsort1(lineptr, 0, nlines -1, fold, dir, r);
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
