#include <stdio.h>
#include <string.h>

void printBinary(int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int boothMultiplication(int M, int Q, int n) {
    int A = 0;          // Initialize Accumulator to 0
    int Q_1 = 0;        // Initialize Q_1 to 0
    int counter = n;    // Set counter to number of bits

    // Printing the initial values of A, Q and Q_1
    printf("Initial Values:\n");
    printf("A = ");
    printBinary(A, n);
    printf(" | Q = ");
    printBinary(Q, n);
    printf(" | Q_1 = %d\n\n", Q_1);

    while (counter > 0) {
        int Q0 = Q & 1;  // Get the least significant bit of Q

        // Apply Booth's Algorithm based on the values of Q_1 and Q0
        if (Q0 == 1 && Q_1 == 0) {
            // A = A - M
            A = A - M;
            printf("A = A - M: ");
        } else if (Q0 == 0 && Q_1 == 1) {
            // A = A + M
            A = A + M;
            printf("A = A + M: ");
        }

        // Print the value of A after the operation
        printBinary(A, n);
        printf(" | ");

        // Arithmetic Right Shift (A, Q, Q_1) as a combined unit
        int combined = (A << (n + 1)) | (Q << 1) | Q_1;  // Combine A, Q, and Q_1
        combined >>= 1;  // Perform arithmetic right shift

        // Extract the new values of A, Q, and Q_1
        A = combined >> (n + 1);   // Extract upper n bits for A
        Q = (combined >> 1) & ((1 << n) - 1);  // Extract middle n bits for Q
        Q_1 = combined & 1;  // Extract least significant bit for Q_1

        // Print the shifted values of A, Q, and Q_1
        printf("Shifted A: ");
        printBinary(A, n);
        printf(" | Q: ");
        printBinary(Q, n);
        printf(" | Q_1: %d\n\n", Q_1);

        counter--;  // Decrease the cycle counter
    }

    // Return the final value of A and Q combined (the result of multiplication)
    return (A << n) | Q;
}

int main() {
    int M = 0b110101;   // Multiplicand (M)
    int Q = 0b101010;   // Multiplier (Q)
    int n = 6;          // Number of bits

    printf("Booth's Multiplication Algorithm:\n\n");
    int result = boothMultiplication(M, Q, n);

    // Print the final result of the multiplication
    printf("Final Result: ");
    printBinary(result, n * 2);
    printf("\n");

    return 0;
}

