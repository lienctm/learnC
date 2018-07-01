// Description : print lines that match pattern and print line number

#include<stdio.h>
#include<string.h>

#define MAXLINE  1000

int getline1( char *s, int lim)  {
  int i, c;

  i = 0;
  while( --lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if(c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int main(int argc, char *argv[]) {
  int c, except = 0, number = 0, found = 0;
  char line[MAXLINE];
  int lineno = 0;

  // *++argv : a pointer to an argument string
  // (*++argv)[0] : the 1st character of an argument string
  // *(++argv[0]) : the next character of an argument string

  while(--argc > 0 && (*++argv)[0] == '-')
    while((c = *(++argv[0])))
      switch(c) {
        case 'x' :
          except = 1;
          break;
        case 'n' :
          number = 1;
          break;
        default :
          printf("illegal option argument %c\n", c);
          argc = 0;
          found = -1;
          break;
      }
  if(argc != 1)
    printf("find -x -n pattern\n");
  else
    while(getline1(line, MAXLINE) > 0) {
      lineno++;
      if((strstr(line, *argv) != NULL) != except) {
        if(number)
          printf("%d: ", lineno);
        printf("%s", line);
        found++;
      }
    }
  return found;
}

