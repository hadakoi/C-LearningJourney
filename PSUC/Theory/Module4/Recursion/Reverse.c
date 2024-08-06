#include <stdio.h>

// Function to reverse the digits of a number
int rev(int num, int reversed) {
   if (num == 0) {
      return reversed; // Base case: return the accumulated reversed number
   } 
   else {
      // Recursive call with num/10 and updated reversed number
      return rev(num / 10, reversed * 10 + num % 10);
   }
}

int main() {

   int num;
    
   printf("Enter number: ");
   scanf("%d", &num);

   if (num < 0) {
      printf("Negative numbers are not supported.\n");
   } 
   else {
   // Call the rev function with the initial reversed number set to 0
      printf("Reversed number: %d\n", rev(num, 0));
   }

   return 0;

}
