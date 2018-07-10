// atoi : convert string to integer

#include<stdio.h>
#include<ctype.h>

int atoi(char s[]) {
  int i, sign, val;

  for(i = 0; isspace(s[i]); i++); // skip white space
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '-' || s[i] == '+')
    i++;
  for(val = 0; isdigit(s[i]); i++)
    val = 10 * val + (s[i] - '0');
  return val * sign;
}

int main() {
  char s[] = "   -2050";
  int k = atoi(s);
  printf("%d\n", k);
}
