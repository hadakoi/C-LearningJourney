#include <stdio.h>

// Define an enum for traffic light states
enum TrafficLight {
    RED, // taken as 0
    YELLOW, // taken as 1 
    GREEN // taken as 2
};

int main() {

   enum TrafficLight currentLight;  // Variable to hold the current traffic light state
   int input;  // Variable to store user input

   
   printf("Enter the current traffic light state (0 for RED, 1 for YELLOW, 2 for GREEN): ");
   scanf("%d", &input);  // Read the input from the user

   currentLight = (enum TrafficLight)input;  // Cast the input to the enum type
   
   /*
   This line casts the integer input to the enum type enum TrafficLight. By doing this,
   input is treated as a value of the TrafficLight enum. 
   If the user enters 0, it will be interpreted as RED, 1 as YELLOW, and 2 as GREEN.
   */

   // Use a switch statement to print the appropriate message based on the traffic light state
   switch (currentLight) {
      case RED:
         printf("Stop, the light is RED.\n");
         break;
      case YELLOW:
         printf("Caution, the light is YELLOW.\n");
         break;
      case GREEN:
         printf("Go, the light is GREEN.\n");
         break;
      default:
         printf("Invalid input.\n");
         break;
   }

   return 0;

}
