#include <stdio.h>

void copy(char str1[], char str2[], int index){
   str2[index] = str1[index]; 

   if (str1[index] == '\0')
      return;

   copy(str1, str2, index + 1);
}

int main(){
   char source[100], destination[100];

   printf("Enter the source string:\n");
   scanf("%s", source);

   // Initialize destination with empty string (optional, for clarity)
   destination[0] = '\0';

   copy(source, destination, 0);

   printf("The copied string is: %s\n", destination);

   return 0;
}
