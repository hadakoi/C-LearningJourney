/*
write these C programs without using STRING-HANDLING functions
Count the number of words in a sentence.
*/

#include <stdio.h>

int main() {
   
   char sentence[1000];
   int wordCount = 0;
   int inWord = 0;

   printf("Enter a sentence: ");
   fgets(sentence, sizeof(sentence), stdin);

   for (int i = 0; sentence[i] != '\0'; i++) {
      if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t') {
         inWord = 0;
      } else if (inWord == 0) {
         inWord = 1;
         wordCount++;
      }
   }

   printf("Number of words: %d\n", wordCount);

   return 0;

}

