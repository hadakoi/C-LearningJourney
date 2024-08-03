#include <stdio.h>

int towerOfHanoi(int n, char source, char destination, char auxiliary);

int main() {

   int n;  

   printf("Enter the number of disks: ");
   scanf("%d", &n);

   int totalMoves = towerOfHanoi(n, 'A', 'C', 'B');


   printf("Total number of moves: %d\n", totalMoves);

   return 0;
}

int towerOfHanoi(int n, char source, char destination, char auxiliary) {
   if (n == 1) {
      // Base case: Only one disk to move
      printf("Move disk 1 from %c to %c\n", source, destination);
      return 1;  // One move
   } 
   else {
      // Move n-1 disks from source to auxiliary, so they are out of the way
      int moves1 = towerOfHanoi(n - 1, source, auxiliary, destination);

      // Move the nth disk from source to destination
      printf("Move disk %d from %c to %c\n", n, source, destination);
      int moves2 = 1;  // One move

      // Move the n-1 disks from auxiliary to destination
      int moves3 = towerOfHanoi(n - 1, auxiliary, destination, source);

      // Total moves is the sum of all moves
      return moves1 + moves2 + moves3;
   }
}
