/*
With the knowledge of modularization, function definition, function call etc.,
Write a function Largest to find the maximum of a given list of numbers. Also write a main program to read N numbers and find the largest among them using this
function.
*/

#include <stdio.h>

// Function to find the largest number in an array
int Largest(int numbers[], int size) {
   int max = numbers[0];
   for (int i = 1; i < size; i++) {
      if (numbers[i] > max) {
         max = numbers[i];
      }
   }
   return max;
}

int main() {

   int N;
    
   printf("Enter the number of elements: ");
   scanf("%d", &N);
    
   int numbers[N];
    
   printf("Enter %d numbers: \n", N);
   for (int i = 0; i < N; i++) {
      scanf("%d", &numbers[i]);
   }
    
   int largest = Largest(numbers, N);
    
   printf("The largest number is: %d\n", largest);
    
   return 0;

}
