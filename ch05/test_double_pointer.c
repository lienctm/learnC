int main() {
  int *p[5];
  int **q = p; // p is an address

  int x = 5;
  int *p1 = &x;
  int **q1 = &p1;
}
