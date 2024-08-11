#include <stdio.h>

int main() {

    int x, y, t, *a, *b;
    a = &x; // 'a' is a pointer to 'x'
    b = &y; // 'b' is a pointer to 'y'

    printf("Enter the values of x and y: \n");
    scanf("%d %d", a, b); // Read values into 'x' and 'y' via pointers 'a' and 'b'

    t = *a; // t now holds the value of x (since 'a' points to x)
    *a = *b; // Assign the value of y to x (since 'b' points to y and '*b' is the value of y)
    *b = t; // Assign the original value of x (stored in t) to y

    printf("x = %d \n", x); // Print the new value of x
    printf("y = %d", y); // Print the new value of y

    return 0;

}
