// code to find if a number is odd or even

#include <stdio.h>

int main(){

int x;
printf("input an integer : ");
scanf("%d" ,&x);

if ((x % 2) == 0) { // if there is no remainder its even
printf("It is an even number\n");
} 

if ((x % 2) == 1) { // if there is a remainder its odd
printf("It is an odd number\n");
}

return 0;

}