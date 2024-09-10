#include <stdio.h>

int main(void) {
    int a[5] = {10, 20, 30, 40, 50};
    int *ptr = a;  // Pointer points to the first element of the array

    // Accessing elements using pointer arithmetic
    printf("First element (*ptr): %d\n", *ptr);
    printf("Second element (*(ptr + 1)): %d\n", *(ptr + 1));

    return 0;
}

