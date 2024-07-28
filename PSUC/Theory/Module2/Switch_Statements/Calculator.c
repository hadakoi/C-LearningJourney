#include <stdio.h>

int main() {

   float value1, value2, result;
   char operator; 

   
   printf("Type in your expression (e.g., 3.5 + 4.2):\n");
   scanf("%f %c %f", &value1, &operator, &value2);

    
   switch (operator) {

      case '+':
         result = value1 + value2; 
         printf("%f\n", result);
         break;

      case '-':
         result = value1 - value2;
         printf("%f\n", result);
         break;

      case '*':
         result = value1 * value2;
         printf("%f\n", result);
         break;

      case '/':
         if (value2 == 0) {
            printf("Division by zero.\n"); 
         } 
         else {
            result = value1 / value2; 
            printf("%f\n", result);
         }
         break;

      default:
            printf("Unknown operator\n"); 
            break;

   }

    return 0;
    
}
