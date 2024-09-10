#include <stdio.h>

int main() {
  char c1 = 'A';
  char c2 = 'B';
  char c3 = 'C';

  // Printing the addresses of the characters
  printf("Address of c1: %p\n", &c1);
  printf("Address of c2: %p\n", &c2);
  printf("Address of c3: %p\n", &c3);

  // Printing the addresses of the characters using void*
  printf("Address of c1: %p\n", (void*)&c1);
  printf("Address of c2: %p\n", (void*)&c2);
  printf("Address of c3: %p\n", (void*)&c3);

  return 0;
}
