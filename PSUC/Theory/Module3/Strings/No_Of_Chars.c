#include <stdio.h>

int main() {

   const int Max = 100;  
   char sent[Max];
   int i = 0, count = 0; // initialize counters

   printf("Enter sentence:\n");
   gets(sent);           
   puts(sent);         

   // count the number of characters in the string
   while (sent[i] != '\0') { // \0 stabds for the end of the string entered by the user.
      count++; 
      i++;
   }

   printf("No of chars = %d\n", count); // print the number of characters

   return 0;

}
