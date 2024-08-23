/*
To check whether a given String is Palindrome or not, using Recursion
*/

#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int start, int end);

int main() {
    char str[100];

    printf("Enter a string (end with #): ");
    scanf("%[^#]", str);

    if (isPalindrome(str, 0, strlen(str) - 1)) {
        printf("The string is a palindrome.\n");
    } 
    else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char str[], int start, int end) {
   if (start >= end) {
      return 1;
   }

   if (str[start] != str[end]) {
      return 0;
   }

   return isPalindrome(str, start + 1, end - 1);
}

/*
Call Tree

isPalindrome("abcba", 0, 4)
|
|-- Compare 'a' and 'a'
|-- isPalindrome("abcba", 1, 3)
    |
    |-- Compare 'b' and 'b'
    |-- isPalindrome("abcba", 2, 2) // Base case: start >= end
        |
        |-- Return 1 // The string is a palindrome
    |
    |-- Return 1 // The string is a palindrome
|
|-- Return 1 // The string is a palindrome
*/