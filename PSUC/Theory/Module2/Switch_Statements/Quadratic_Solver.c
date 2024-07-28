#include <stdio.h>
#include <math.h> 

int main() {

   float a, b, c; 
   float discriminant, root1, root2, realPart, imaginaryPart; 

   printf("Enter coefficients a, b, and c: ");
   scanf("%f %f %f", &a, &b, &c);

   discriminant = b * b - 4 * a * c;

    
   switch ((discriminant > 0) - (discriminant < 0)) { //  evaluates to 1 if the discriminant is positive, 0 if it is zero, and -1 if it is negative.

      case 1: // discriminant > 0
         root1 = (-b + sqrt(discriminant)) / (2 * a);
         root2 = (-b - sqrt(discriminant)) / (2 * a);
         printf("Roots are real and different.\n");
         printf("Root 1 = %.2f\n", root1);
         printf("Root 2 = %.2f\n", root2);
         break;

      case 0: // discriminant == 0
         root1 = root2 = -b / (2 * a);
         printf("Roots are real and same.\n");
         printf("Root 1 = Root 2 = %.2f\n", root1);
         break;

      case -1: // discriminant < 0
         realPart = -b / (2 * a);
         imaginaryPart = sqrt(-discriminant) / (2 * a);
         printf("Roots are complex and different.\n");
         printf("Root 1 = %.2f + %.2fi\n", realPart, imaginaryPart);
         printf("Root 2 = %.2f - %.2fi\n", realPart, imaginaryPart);
         break;

      default:
         printf("Unexpected condition encountered.\n");
    }

   return 0;

}
