// Des : convert characters to integers, pointer version

#include<stdio.h>
#include<ctype.h>

int my_atoi(char *s) {
  int i, sign, val;
  char *p = s;
  p[i] = *(p+i);

  for(i = 0; isspace(p[i]); i++)  ;
  sign = (p[i] == '-') ? -1 : 1;
  if(p[i] == '-')
    i++;
  for(val = 0; isdigit(p[i]); i++)
    val = 10 * val + (p[i] - '0');
  return val *sign;
}

int main() {
  char a[] = "   -888";
  int k = my_atoi(a);
  printf("result is: %d\n", k);
}
