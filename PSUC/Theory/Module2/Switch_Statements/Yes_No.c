#include <stdio.h>

int main() {

   int choice;

   printf("Enter your choice: 1-yes, 2-no\n");
   scanf("%d", &choice);

   switch (choice) {
      case 1:
         printf("YESSSSSSS......\n"); // Case 1: User chose "yes"
         break;
      case 2:
         printf("NOOOOOO......\n"); // Case 2: User chose "no"
         break;
      default:
         printf("DEFAULT CASE.......\n"); // Default case: Any other input
    }

   printf("The choice is %d\n", choice);

   return 0;

}
