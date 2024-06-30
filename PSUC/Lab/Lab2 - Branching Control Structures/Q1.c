/*  
With the help of various branching control constructs like if, if-else and switch case statements 
Check whether the given number is odd or even
*/

#include <stdio.h>

int main(){

int num;
printf("Enter a Number: ");
scanf("%d", &num)

if (num % 2 == 0) { // The % operator checks for remainders.for eg 10/2 = 5 and there will be no remainder however 9/2 is 4 with 1 remainder hence odd
    printf("%d is even.\n", num);
} else {
    printf("%d is odd.\n", num);
}

}


