/* Purpose of this function is extending binsearch function
 * by return first or last index occurence that found */

#include<stdio.h>

int binsearch( int target, int n, int s[])
{
  int mid, low, high, found;

  low = 0;
  high = n-1;
  found = -1;

  while(low <= high)
  {
    mid = (low + high) / 2;
    if(target < s[mid])
      high = mid - 1;
    else if(target > s[mid])
      low = mid + 1;
    else {
      found = mid;
      //return found;     // to know the target is founded
      high = mid - 1;  // to find the first occurence
      //low = mid + 1;   // to find the last occurence
    }
  }
  return found;  // where the target is founded at first or last occurence
}

int main()
{
  int s[] = {4, 5, 20, 20, 20, 20, 20, 20, 20, 20, 20, 10};
  int n = 12;
  int t = 20;
  int index = binsearch(t, n, s); //function call
  printf("found location %d \n", index);

}
