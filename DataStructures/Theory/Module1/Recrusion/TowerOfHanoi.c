#include <stdio.h>

void tower(int n, char source, char temp, char destination) {
   if (n == 1) {
      // Base case: Move disk 1 from source to destination
      printf("Move disk 1 from %c to %c\n", source, destination);
      return;
   }
   // Move n-1 disks from source to temp using destination as auxiliary
   tower(n - 1, source, destination, temp);

   // Move the nth disk from source to destination
   printf("Move disk %d from %c to %c\n", n, source, destination);

   // Move n-1 disks from temp to destination using source as auxiliary
   tower(n - 1, temp, source, destination);
}

int main() {
   int n;

   // Asking user for the number of disks
   printf("Enter the number of disks: ");
   scanf("%d", &n);

   printf("The moves are:\n");
   tower(n, 'A', 'B', 'C');

   return 0;
}
