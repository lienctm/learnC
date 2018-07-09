// Description : this function return pointer to 1st occurence of t in s,
// or NULL if not present.

#include<stdio.h>
#include<string.h>

char*  my_strstr(char *s, char *t) {
  int i, k;
  i = 0;

  while (s[i] != '\0') {
    k = 0;
    while (t[k] != '\0' && t[k] == s[i+k])
      k++;
    if (k > 0 && t[k] == '\0')
      return (s+i);
    i++;
  }
  return NULL;

// Description : the function below for strstr(s,t) that return
// the position of the 1st occurence of t in s, or -1 if not present

  //int N = strlen(s);
  //int L = strlen(t);

  //for(i = 0; i <= N-L; i++) {
  //  for(j = 0; j < L; j++) {
  //    if(t[j] != s[i+j]) break;
  //    else {
  //      if (t[j+1] == '\0')
  //        return i;
  //    }
  //    if(t[j] == s[i+j])
  //    {
  //      if (t[j+1] == '\0')
  //        return i;
  //    }
  //    else
  //      break; // not match
  //  }
  //}
  //return -1;  // not found
}


int main() {
  char s[50] = "today i learn";
  char t[50] = "learn";
  char* k = my_strstr(s,t);
  printf("result : %s\n", k);
  //int k = my_strstr(s,t);
  //printf("result : %d\n", k);
}
