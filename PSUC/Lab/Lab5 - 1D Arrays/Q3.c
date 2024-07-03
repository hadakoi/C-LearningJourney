/*
With the knowledge of 1D arrays
Insert an element into a 1D array, by getting an element and the position from the user.
*/

int main(){

   int n, i, pos, element;

   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);

   int arr[n + 1]; // as we are adding an element we need to increase seize by one

   printf("Enter the elements of the array:\n");
   for (i = 0; i < n; i++) {
      printf("Element %d: ", i + 1);
      scanf("%d", &arr[i]);
   }

   printf("Enter the element to be inserted: ");
   scanf("%d", &element);
   printf("Enter the position (1 to %d) where the element should be inserted: ", n + 1);
   scanf("%d", &pos);

   if (pos < 1 || pos > n + 1) { // needs to check if the position is 0 or the position is greater than all the array indexes
      printf("Invalid position!\n");
      return 1;
   }

   // Shift elements to the right from the last element to the position
   for (i = n; i >= pos; i--) {
      arr[i] = arr[i - 1];
   }

   // Insert the new element
   arr[pos - 1] = element;

   // Update the number of elements
   n++;

   printf("Array after insertion:\n");
   for (i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   return 0;

}