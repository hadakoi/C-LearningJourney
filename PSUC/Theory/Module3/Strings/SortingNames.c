#include <stdio.h>
#include <string.h>

int main() {

   char string[30][30], temp[30]; // declares an array of strings where each array index holds a string.
   int no, i, j;
    
   printf("Enter the number of strings:\n");
   scanf("%d", &no);
    
   printf("Enter the strings:\n");
   for (i = 0; i < no; i++) {
      gets(string[i]); // Read each string
   }
    
   // Sort the strings in alphabetical order
   for (i = 0; i < no - 1; i++) {
      for (j = i + 1; j < no; j++) {
         if (strcmp(string[i], string[j]) > 0) {
               strcpy(temp, string[i]);
               strcpy(string[i], string[j]);
               strcpy(string[j], temp);
         }
      }
   }
    
   printf("The sorted array is:\n");
   for (i = 0; i < no; i++) {
      puts(string[i]); 
   }

   return 0;

}
