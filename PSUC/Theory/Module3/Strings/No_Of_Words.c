#include <stdio.h>

int main() {

   const int MAX = 100;
   char sent[MAX];
   int i = 0, count = 1;

   printf("Enter sentence:\n");
   gets(sent);
    
   while (sent[i] != '\0') {
      // Check for a space followed by a non-space (indicating a word boundary)
      if (sent[i] == ' ' && sent[i + 1] != ' ' && sent[i + 1] != '\0') {
         count++;
      }
      i++;
   }

   printf("No. of words = %d\n", count);
   return 0;

}
