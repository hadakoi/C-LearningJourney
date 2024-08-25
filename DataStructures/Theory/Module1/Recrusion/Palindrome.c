#include <stdio.h>
#include <string.h> 

int isPalindrome(char *inputString, int leftIndex, int rightIndex){
   // Base case: If indices have crossed or are equal, it means the string is a palindrome
    if (leftIndex >= rightIndex)
      return 1;

   // If characters at the current indices are the same, move inward
   if (inputString[leftIndex] == inputString[rightIndex])
      return isPalindrome(inputString, leftIndex + 1, rightIndex - 1);

   return 0;
}

int main(){
   char inputString[100];
    
   printf("Enter a string for palindrome check:\n");
   scanf("%s", inputString);

   // Call the isPalindrome function and print the result
   if (isPalindrome(inputString, 0, strlen(inputString) - 1))
      printf("%s is a Palindrome\n", inputString);
   else
      printf("%s is not a Palindrome\n", inputString);

   return 0;
}
