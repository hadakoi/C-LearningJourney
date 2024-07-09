/*


*/

#include <stdio.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_WORD_LENGTH 20

int main() {

   char sentence[MAX_SENTENCE_LENGTH];
   char word[MAX_WORD_LENGTH];
   int i, j, k, sentence_len, word_len, found;

   
   printf("Enter a sentence: ");
   fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

   // Remove newline character from the sentence if it exists
   for (i = 0; sentence[i] != '\0'; i++) {
      if (sentence[i] == '\n') {
         sentence[i] = '\0';
         break;
      }
   }
   sentence_len = i;

   
   printf("Enter the word to be deleted: ");
   scanf("%s", word);

   // Calculate the length of the word to be deleted
   for (word_len = 0; word[word_len] != '\0'; word_len++);

   // Search for the word in the sentence and delete it
   for (i = 0; i <= sentence_len - word_len; i++) {
      // Check if the word matches
      found = 1;
      for (j = 0; j < word_len; j++) {
         if (sentence[i + j] != word[j]) {
               found = 0;
               break;
         }
      }

      // If the word is found and it's not part of another word, delete it
      if (found && (i == 0 || sentence[i - 1] == ' ') && (sentence[i + word_len] == ' ' || sentence[i + word_len] == '\0')) {
         // Shift characters to the left to delete the word
         for (k = i; k <= sentence_len - word_len; k++) {
               sentence[k] = sentence[k + word_len + 1];
         }
         sentence_len -= word_len + 1; // Update the length of the sentence
         i--; // Recheck the current position for overlapping words
      }
   }


   printf("Modified sentence: %s\n", sentence);

   return 0;

}
