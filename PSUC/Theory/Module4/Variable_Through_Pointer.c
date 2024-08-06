#include <stdio.h>

int main() {
   
   int var1 = 11; // Declare an integer variable
   int var2 = 22; // Declare another integer variable
   int *ptr;      // Declare a pointer to an integer

   ptr = &var1;   // Make the pointer point to var1
   printf("%d\n", *ptr); // Print the value pointed to by ptr (11)

   ptr = &var2;   // Make the pointer point to var2
   printf("%d\n", *ptr); // Print the value pointed to by ptr (22)

   return 0;

}
