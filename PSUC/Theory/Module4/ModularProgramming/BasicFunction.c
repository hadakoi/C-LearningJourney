#include <stdio.h>

// Function declaration (optional if function is defined before main) also known as prototype 
void DisplayMessage();

int main() {
   // Call the DisplayMessage function
   DisplayMessage();
    
   return 0;
}

// Function definition
void DisplayMessage() {
   printf("Hello from function DisplayMessage\n");
}
