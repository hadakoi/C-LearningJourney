#include <stdio.h>

void copyString(char source[], char destination[], int index);

int main() {

    char source[100], destination[100];

   printf("Enter the source string: ");
   gets(source); 

   copyString(source, destination, 0);

   printf("Copied string: %s\n", destination);

   return 0;

}


void copyString(char source[], char destination[], int index) {
   destination[index] = source[index];  // Copy current character

   // Base case: If the end of the string is reached, stop recursion
   if (source[index] == '\0') {
      return;
   } 
   else {
   // Recursively copy the next character
      copyString(source, destination, index + 1);
   }
   
}
