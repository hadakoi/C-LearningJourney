#include <stdio.h>

int main() {

   char name[15];

   // Declare a pointer to a character and initialize it to point to the first element of the array
   char *cptr = name;

   // Prompt the user to enter a word
   printf("Enter some word to find its length: \n");

   scanf("%s", name);

   // Traverse the string using the pointer to find the end
   while (*cptr != '\0') {
      cptr++;
   }

   // Calculate the length of the string by subtracting the original pointer value from the end pointer value
   printf("Length = %ld\n", cptr - name);

   return 0;

}
