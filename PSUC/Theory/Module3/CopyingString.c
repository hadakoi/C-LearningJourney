#include <stdio.h>
#include <string.h> // gives us the strlen function

int main() {
   char str1[] = "Manipal Institute of Technology";
   const int MAX = 80;
   char str2[MAX]; 
    
   // Copy str1 to str2
   for (int j = 0; j < strlen(str1); j++) {
      str2[j] = str1[j];
   }

   str2[strlen(str1)] = '\0'; // insert NULL at the end

   printf("%s\n", str2);

   return 0;

}
