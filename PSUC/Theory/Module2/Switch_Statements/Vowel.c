#include <stdio.h>

int main() {

   char ch;

   printf("Enter a character: ");
   scanf("%c", &ch);

    // Switch statement to determine if the character is a vowel
   switch(ch) {

      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
         // If the character is a vowel, print "Vowel"
         printf("Vowel\n");
         break;
   
      default:
         // If the character is not a vowel, print "Not a Vowel"
         printf("Not a Vowel\n");
   }

   return 0;

}
