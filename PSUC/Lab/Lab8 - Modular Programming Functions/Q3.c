/*
With the knowledge of modularization, function definition, function call etc.,
Write a function IsPalin to check whether the given string is a palindrome or not.
Write a main function to test this function.
*/

#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int IsPalin(char str[]) {

   int left = 0;
   int right = strlen(str) - 1;
    
   while (left < right) {
      if (str[left] != str[right]) {
         return 0; // Not a palindrome
      }
      left++;
      right--;
   }
    
   return 1; // Palindrome
}

int main() {
   
   char str[100];
    
   printf("Enter a string: ");
   gets(str);  // Use gets to read the string
    
   if (IsPalin(str) == 1) {
      printf("The string is a palindrome.\n");
   } else {
      printf("The string is not a palindrome.\n");
   }
    
   return 0;

}
