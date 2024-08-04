#include <stdio.h>

int main() {

   char string[30];
   int i, n = 0;
    
   printf("Enter the string:\n");
   gets(string); 

   // Calculate the length of the string
   for (i = 0; string[i] != '\0'; i++) {
       n++;
   }

   // Convert lowercase letters to uppercase
   for (i = 0; i < n; i++) {
      if (string[i] >= 'a' && string[i] <= 'z') {
         string[i] = string[i] - 32; // Convert to uppercase
      }
   }

   puts(string);

   return 0;

}
