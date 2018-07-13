// Des: extend atof to handle scientific notation

#include<stdio.h>
#include<ctype.h>

double my_atof(char s[]) {
  int i, e, sign, esign;
  double val, power;

  for(i = 0; isspace(s[i]); i++);  // skipe white space
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

  if((s[i] == 'e' || s[i] == 'E')) {
    i++;
    e = 0;
    esign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '+' || s[i] == '-')
      i++;

    for( ; isdigit(s[i]); i++)
      e = e * 10 + (s[i] - '0');

    for(i = 0; i < e; i++)
    {
      if (esign < 0)
        power *= 10.0;
      else
        power /= 10.0;
    }
  }
  return val * sign / power;
}

int main() {
  char s[] = "   123.45e-6";
  double k = my_atof(s);
  printf("%.8f\n", k);
}
