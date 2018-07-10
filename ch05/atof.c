// atof : convert string to double

#include<stdio.h>
#include<ctype.h>

double atof(char s[]) {
  int i, sign;
  double val, power;

  for(i = 0; isspace(s[i]); i++);  // skip white space
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-')
    i++;
  for(val = 0.0; isdigit(s[i]); i++)
    val = 10 * val + (s[i] - '0');
  if(s[i] == '.')
    i++;
  for(power = 1.0; isdigit(s[i]); i++) {
    val = 10 * val + (s[i] - '0');
    power *= 10.0;
  }
  return val * sign / power;
}

int main() {
  char s[] = "   -150.2";
  double t = atof(s);
  printf("%.2f\n", t);
}

