/*
To copy one string to another using Recursion
*/

#include <stdio.h>

void copyString(char source[], char destination[], int index);

int main() {
   char source[100], destination[100];

   printf("Enter the source string (end with #): ");
   scanf("%[^#]", source);

   copyString(source, destination, 0);

   printf("Copied string: %s\n", destination);

   return 0;
}

void copyString(char source[], char destination[], int index) {
   destination[index] = source[index];

   if (source[index] == '\0') {
      return;
   } 
   else {
      copyString(source, destination, index + 1);
   }
}

/*
Recursive Call Tree

copyString("Hello", destination[], 0)
|
|-- destination[0] = 'H'
|-- copyString("Hello", destination[], 1)
    |
    |-- destination[1] = 'e'
    |-- copyString("Hello", destination[], 2)
        |
        |-- destination[2] = 'l'
        |-- copyString("Hello", destination[], 3)
            |
            |-- destination[3] = 'l'
            |-- copyString("Hello", destination[], 4)
                |
                |-- destination[4] = 'o'
                |-- copyString("Hello", destination[], 5) // Base case: source[5] == '\0'
                    |
                    |-- destination[5] = '\0'
                    |
                    |-- Return to previous calls
                |-- Return
            |-- Return
        |-- Return
    |-- Return
|-- Return

*/