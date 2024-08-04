#include <stdio.h>
#include <string.h> // Include string.h for strcpy

int main() {
   // Combine the multi-line string into a single string literal
   char str1[] = "Tiger, tiger, burning bright\n"
                  "in the forests of the night";
    
   const int MAX = 80;
   char str2[MAX];
    
   // Copy str1 to str2
   strcpy(str2, str1);
    
   // Display str2
   printf("%s", str2);

   return 0;

}
