#include <stdio.h>

// Function prototype
int Reverse(int num);

int main() {

   int n, r;
    
   printf("Enter a number:\n");
   scanf("%d", &n);
    
   r = Reverse(n); // Call the Reverse function
   printf("Reversed number = %d\n", r); // Print the reversed number
    
   return 0;

}

// Function definition
int Reverse(int num) {
   
   int rev = 0;
   int digit;
    
   while (num != 0) {
      digit = num % 10;       // Extract the last digit
      rev = (rev * 10) + digit; // Append the digit to the reversed number
      num = num / 10;         // Remove the last digit from the number
   }
    
   return rev; // Return the reversed number

}
