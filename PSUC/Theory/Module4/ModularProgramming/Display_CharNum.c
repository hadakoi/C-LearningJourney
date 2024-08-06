#include <stdio.h>

// Function definition
void dispChar(int n, char c) {
   printf("You have entered %d & %c\n", n, c);
}

int main() {

   int no; 
   char ch;
    
   printf("Enter a number & a character: \n");
   scanf("%d %c", &no, &ch);
    
   dispChar(no, ch); // Function call
    
   return 0;
   
}
