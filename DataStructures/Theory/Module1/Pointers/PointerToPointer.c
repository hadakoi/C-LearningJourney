#include <stdio.h>

int main(void) {
  int a = 10;      // Direct variable declaration and initialization
  int *p = &a;     // Pointer p points to the address of a
  int **q = &p;    // Pointer q points to the address of pointer p
  int ***r = &q;   // Pointer r points to the address of pointer q

  // 1. Directly print the value of a
  printf("Value of a (directly): %d\n", a);

  // 2. Print the value of a using pointer p
  // Dereference p once to get the value of a
  printf("Value of a (using pointer p): %d\n", *p);

  // 3. Print the value of a using pointer q
  // Dereference q once to get pointer p, then dereference p to get the value of a
  printf("Value of a (using pointer q): %d\n", **q);

  // 4. Print the value of a using pointer r
  // Dereference r once to get pointer q, dereference q to get pointer p,
  // and dereference p to get the value of a
  printf("Value of a (using pointer r): %d\n", ***r);

  return 0;
}
