// Reading and Displaying a number given by User

#include <stdio.h>

int main(){

    int num; // creates a variable num to store an integer
 
    printf("Enter the Number: \n");
    scanf("%d", &num); 
    // Input for the Number uses & as an address for the variable

    printf("The Number Read is: %d", num);

    return 0;

}