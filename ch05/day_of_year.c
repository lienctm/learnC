// day_of_year :conver the month and day into the day of year
// note : non-leap year or leap year

#include<stdio.h>

static char daytab[2][13] = {
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ,
  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int day_of_year(int year, int month, int day) {
  int i, leap;

  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  for(i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

int main() {
  int k;
  k  = day_of_year(2018, 6, 25);
  printf(" %d\n", k);

}
