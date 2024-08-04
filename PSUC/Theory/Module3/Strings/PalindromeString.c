#include <stdio.h>
#include <string.h>

int main() {

   char str[30];
   int i, n, flag = 1;
    
   printf("Enter the string:\n");
   gets(str); // Read the string

   // Find the string length
   for (i = 0; str[i] != '\0'; i++);
   n = i; // Length of the string
    
   // Check if the string is a palindrome
   for (i = 0; i < n / 2; i++) {
      if (str[i] != str[n - i - 1]) {
         flag = 0;
         break;
      }
   }

   if (flag == 1)
      printf("It's a Palindrome\n");
   else
      printf("Not a Palindrome\n");

   return 0;

}
