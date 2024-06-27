/*
Input radius to find the volume and surface area of a sphere. [Hint: volume = (4πr3)/3, Area=4πr2]
*/

#include <stdio.h>
#include <math.h>

int main(){

   float radius, volume, surfaceArea;
   const float PI = 3.14;

   printf("Enter the radius of the sphere: ");
   scanf("%lf", &radius);

   // Calculate the volume of the sphere
   volume = (4.0 / 3.0) * PI * pow(radius, 3);

   // Calculate the surface area of the sphere
   surfaceArea = 4 * PI * pow(radius, 2);

    
   printf("Volume of the sphere = %.2lf cubic units\n", volume);
   printf("Surface area of the sphere = %.2lf square units\n", surfaceArea);

   return 0;
    
}
