/*
Convert the given temperature in Fahrenheit to Centigrade. [Hint: C=5/9(F-32)]
*/

#include <stdio.h>
#include <math.h>

int main(){

   float fahrenheit, centigrade;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Convert Fahrenheit to Centigrade using the formula
    centigrade = (5.0 / 9.0) * (fahrenheit - 32);

    printf("Temperature in Centigrade: %.2f\n", centigrade);

   return 0;
    
}