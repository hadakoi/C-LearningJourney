#include <stdio.h>

int main() {

   int var1 = 11;
   int var2 = 22;
   int var3 = 33;

   // Print the addresses of these variables
   printf("Address of var1: %p\n", &var1);
   printf("Address of var2: %p\n", &var2);
   printf("Address of var3: %p\n", &var3);

   return 0;

}
