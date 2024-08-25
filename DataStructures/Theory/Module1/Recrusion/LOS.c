#include <stdio.h>

int find_len(char str[], int index) {
    if (str[index] == '\0') {
        return 0;
    }
    return 1 + find_len(str, index + 1);
}

int main() {

   char str[100];
   int length;

   printf("Enter a string: ");
   scanf("%[^\n]", str);

   length = find_len(str, 0);

   printf("The length of the string is: %d\n", length);

   return 0;
   
}
