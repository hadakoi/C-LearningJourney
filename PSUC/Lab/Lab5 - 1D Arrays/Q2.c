/*
With the knowledge of 1D arrays
Arrange the given elements in a 1D array in ascending and descending order using bubble sort method. [Hint: use switch case (as case ‘a’ and case ‘d’) to specify the order].
*/

#include <stdio.h>

int main(){

   int n, i, j, x, temp;
   char Flag; // this is used to specify wether its a or d

   printf("Enter Length of the Array: ");
   scanf("%d", &n);

   int arr[n];

   for(x=0 ; x<n ; x++){
      printf("Enter Element %d : ", x+1);
      scanf("%d", &arr[x]);
   }

   printf("Now enter 'a' for Ascending or 'd' for Descending: ");
   scanf(" %c", &Flag); // must leave a whitespace before the %c

   switch(Flag){

      case 'a':
         for(i=0 ; i < n-1 ; i++){
            for(j=0 ; j < n-i-1 ; j++){
               if(arr[j] > arr[j+1]){
                  temp = arr[j];
                  arr[j] = arr[j+1];
                  arr[j+1] = temp;
               }
            }
         }
         break;
      
      case 'd':
        for(i=0 ; i < n-1 ; i++){
            for(j=0 ; j < n-i-1 ; j++){
               if(arr[j] < arr[j+1]){
                  temp = arr[j];
                  arr[j] = arr[j+1];
                  arr[j+1] = temp;
               }
            }
         }
         break;

      default:
            printf("Invalid order choice.\n");
            return 1;
    }

   printf("Sorted Array is : ");
   for(x=0;x<n;x++){
      printf("%d ", arr[x]);
   }

   return 0;
   
}












