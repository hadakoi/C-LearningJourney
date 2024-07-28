#include <stdio.h>

int main() {

   float num1, num2, result;
   char operator;

   
   printf("Enter an expression (e.g., 3 + 4): ");
   scanf("%f %c %f", &num1, &operator, &num2);

   // Evaluate the expression based on the operator
   if (operator == '+') {
      result = num1 + num2;
   } 
   else if (operator == '-') {
      result = num1 - num2;
   } 
   else if (operator == '*') {
      result = num1 * num2;
   } 
   else if (operator == '/') {
      if (num2 != 0) {
         result = num1 / num2;
      } 
      else {
         printf("Error: Division by zero is not allowed.\n");
         return 1; // Exit the program with an error code
      }
    } 
   else {
        printf("Error: Invalid operator.\n");
        return 1; // Exit the program with an error code
   }


   printf("The result is: %.2f\n", result);

    return 0;
    
}
