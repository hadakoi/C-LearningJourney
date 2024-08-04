#include <stdio.h>

int main() {

   char str[70];
   char temp;
   int i, n = 0;

   printf("Enter the string:\n");
   gets(str); // Read the string

   // Calculate the length of the string
   for (i = 0; str[i] != '\0'; i++) {
      n++;
   }

   // Reverse the string
   for (i = 0; i < n / 2; i++) {
      temp = str[i];
      str[i] = str[n - i - 1];
      str[n - i - 1] = temp;
   }

   printf("Reversed string is:\n");
   puts(str); 

   return 0;

}
