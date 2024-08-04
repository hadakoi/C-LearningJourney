#include <stdio.h>

int main() {

   const int MAX = 2000;
   char str[MAX];

   printf("Enter a string (terminate with #):\n");
   scanf("%[^#]", str); // read characters to str until a # character is encountered

   printf("You entered:\n");
   printf("%s\n", str);

   return 0;

}
