#include <stdio.h>

int main() {

   int firstvalue = 5, secondvalue = 15;
   int *p1, *p2;

   p1 = &firstvalue;   // p1 points to the address of firstvalue
   p2 = &secondvalue;  // p2 points to the address of secondvalue

   *p1 = 10;           // Set the value at the address pointed to by p1 (i.e., firstvalue) to 10
   *p2 = *p1;          // Set the value at the address pointed to by p2 (i.e., secondvalue) to the value pointed to by p1 (i.e., 10)

   p1 = p2;            // Make p1 point to the same address as p2 (i.e., address of secondvalue)
   *p1 = 20;           // Set the value at the address pointed to by p1 (i.e., secondvalue) to 20

   printf("firstvalue is %d\n", firstvalue);  // Print the value of firstvalue
   printf("secondvalue is %d\n", secondvalue); // Print the value of secondvalue

   return 0;

}
