#include <stdio.h>

// Recursive function to find the length of a string
int StrLen(char *str) {
   static int length = 0; // Static variable to keep track of the length
    
   if (*str != '\0') {
      length++;          // Increment length for each character
      StrLen(++str);    // Recursive call with incremented pointer
   }
   
   return length;        // Return the calculated length
}

int main() {
   char str[100];
   int length;

   printf("Enter a string: ");
   scanf("%[^\n]", str);

   length = StrLen(str);

   printf("The length of the string is: %d\n", length);

   return 0;
}

/*
Explanation
StrLen Function:

1. Static Variable: The length variable is declared as static, which means it retains its value across recursive calls. It is used to accumulate the length of the string.
Base Case: If *str (the current character pointed to by str) is not the null terminator '\0', the length is incremented and the function is called recursively with ++str (moving the pointer to the next character).
Return: Once the base case is reached (when *str is '\0'), the accumulated length is returned.
main Function:

2. Input: scanf("%[^\n]", str) reads a full line of input, including spaces, until a newline character is encountered.
Calculate Length: StrLen(str) is called to get the length of the input string.
Output: The length of the string is printed.

*/
