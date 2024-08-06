#include <stdio.h>

int main() {

   int value = 10;    // Regular integer variable
   int *ptr;          // Pointer to an integer

   // Initialize the pointer
   ptr = &value;
   // can also be initalised like int *ptr = &value;

   // Print value using the pointer
   printf("Value: %d\n", *ptr);   // Dereference pointer to get the value (10)
   printf("Address of value: %p\n", ptr); // Address stored in pointer

   // Modify the value using the pointer
   *ptr = 20;
   printf("New value: %d\n", value);  // Direct access to 'value' should reflect the change (20)

   return 0;

}
