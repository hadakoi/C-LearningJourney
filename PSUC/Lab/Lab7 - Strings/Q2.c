/*
write this C program
Input a string and toggle the case of every character in the input string.
*/

#include <stdio.h>

int main() {

    char str[100];
    int i = 0;

   printf("Enter a string: ");
   gets(str);  

   // Toggle the case of each character
   while (str[i] != '\0') {
      if (str[i] >= 'a' && str[i] <= 'z') {
         str[i] = str[i] - 'a' + 'A'; // Convert lowercase to uppercase
      } else if (str[i] >= 'A' && str[i] <= 'Z') {
         str[i] = str[i] - 'A' + 'a'; // Convert uppercase to lowercase
      }
      i++;
   }

    printf("Toggled string: %s", str);

    return 0;

}
