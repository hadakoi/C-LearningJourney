#include <stdio.h>

#define MAX_LENGTH 100 // Define the maximum length for the input string

int main() {

   // Declare a character array with enough space to hold the input string
   char name[MAX_LENGTH];

   // Prompt the user to enter a string
   printf("Enter a string (up to %d characters): \n", MAX_LENGTH - 1);

   // Read a line of input from the user, including spaces, until a newline is encountered
   scanf(" %[^\n]", name);

   // Declare a pointer to the character array and initialize it
   char *cptr = name;

   // Traverse the string using the pointer to find the null terminator
   while (*cptr != '\0') {
      cptr++; // Move the pointer to the next character
   }

   // Calculate the length of the string
   int length = cptr - name; // Length of the string excluding the null terminator

   printf("Length of the string = %d\n", length);

   return 0;
   
}
