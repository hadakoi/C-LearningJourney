#include <stdio.h>

int main() {

    // Loop through numbers from 1 to 10
    for (int i = 1; i <= 10; i++) {
        // Check if the current number is even
        if (i % 2 == 0) {
            // Skip the rest of the loop and proceed to the next iteration
            continue;
        }
        // Print the current number (which is odd)
        printf("%d\n", i);
    }

    return 0;

}

