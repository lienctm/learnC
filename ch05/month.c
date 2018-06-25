// month_name: return name of n-th month

#include<stdio.h>

char *month(int n) {
  static char *name[] = {
    "Illegal month",
    "Janurary",
    "Februrary",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December" }
  ;
  return (n < 1 || n > 12) ? name[0] : name[n] ;
}

int main() {
  int i = 0;
  char *k;
  k = month(i);
  printf("This month is %s\n", k);
}
