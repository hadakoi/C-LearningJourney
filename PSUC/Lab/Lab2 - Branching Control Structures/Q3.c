/*
With the help of various branching control constructs like if, if-else and switch case statements
Compute all the roots of a quadratic equation using switch case statement.
*/

#include <stdio.h>
#include <math.h>

int main(){
   int a, b, c;
   int discriminant, root1, root2, realPart, imaginaryPart;
   int flag;

   // Input coefficients
   printf("Enter coefficients a, b and c: ");
   scanf("%d %d %d", &a, &b, &c);

   // Calculate discriminant
   discriminant = b * b - 4 * a * c;
   
   // Create the flag to be used in switch case
   if(discriminant > 0){
      flag = 1;
   }
   else if(discriminant == 0){
      flag = 0;
   }
   else{
      flag = -1;
   }


   switch (flag) {
        case 1: // discriminant > 0
            printf("Equation will have Two Distinct and real roots \n");
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("Two distinct and real roots: %d and %d\n", root1, root2);
            break;

        case 0: // discriminant == 0
            printf("Equation will have One real and repeated root \n");
            root1 = -b / (2 * a);
            printf("One real and repeated root: %d\n", root1);
            break;

        case -1: // discriminant < 0
            printf("Equation will have Two Complex Roots \n");
            realPart = -b / (2 * a);
            imaginaryPart = sqrt(-discriminant) / (2 * a);
            printf("Two complex roots: %d + %di and %d - %di\n", realPart, imaginaryPart, realPart, imaginaryPart);
            break;

        default:
            printf("Something went wrong!\n");
            break;
    }

    return 0;

}