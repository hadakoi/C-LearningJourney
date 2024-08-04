#include <stdio.h>
#include <string.h>

int main() {
   
   char s1[90]; // Buffer size increased to accommodate concatenation
   char s2[50];
    
   printf("Enter the first string:\n");
   gets(s1); // Read the first string

   printf("Enter the second string:\n");
   gets(s2); // Read the second string

   // Concatenate s2 to the end of s1
   strcat(s1, s2);
    
   printf("Concatenated string is:\n");
   printf("%s\n", s1);

   return 0;

}

