#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int start, int end);

int main() {

   char str[100];

   printf("Enter a string: ");
   gets(str); 

   if (isPalindrome(str, 0, strlen(str) - 1)) {
      printf("The string is a palindrome.\n");
   } 
   else {
      printf("The string is not a palindrome.\n");
   }

   return 0;

}


int isPalindrome(char str[], int start, int end) {
   // Base case: If start >= end, we've checked all characters
   if (start >= end) {
      return 1;  // The string is a palindrome
   }

   // Check if the characters at start and end positions are the same
   if (str[start] != str[end]) {
      return 0;  // The string is not a palindrome
   }

   // Recursive case: Check the next pair of characters
   return isPalindrome(str, start + 1, end - 1);
}
