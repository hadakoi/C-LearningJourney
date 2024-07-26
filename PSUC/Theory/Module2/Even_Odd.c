// code to find if a number is odd or even

#include <stdio.h>

int main(){
int x;
printf("input an integer\n");
scanf("%d" ,&x);

if ((x % 2) == 0) {
printf("It is an even number\n");
}

if ((x % 2) == 1)
{
printf("It is an odd number\n");
}

return 0;

}