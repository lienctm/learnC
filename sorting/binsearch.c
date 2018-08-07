#include<stdio.h>

int binsearch( int target, int n, int s[])
{
  int mid, low, high;

  low = 0;
  high = n-1;

  while(low <= high)
  {
    mid = (low + high) / 2;
    if(target < s[mid])
      high = mid - 1;
    else if(target > s[mid])
      low = mid + 1;
    else
      return mid; //found: return index
  }
  return -1; // not found
}

int main()
{
  int s[] = {4, 5, 8, 10, 15, 20, 27};
  int n = 7;
  int t = 20;
  // print -1 if not found
  // print index of position if found
  int index = binsearch(t, n, s); //function call
  printf("found location %d \n", index);

}
