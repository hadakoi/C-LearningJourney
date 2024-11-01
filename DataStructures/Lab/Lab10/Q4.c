#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node *next;
} *NODE;

NODE createNode(int coeff, int exp) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode; // Pointing to itself for circular structure
    return newNode;
}

void insertEnd(NODE *header, int coeff, int exp) {
    NODE newNode = createNode(coeff, exp);
    if ((*header) == NULL) {
        *header = newNode;
        return;
    }
    NODE temp = *header;
    while (temp->next != *header) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *header; // Maintain circular structure
}

void displayPoly(NODE header) {
    if (header == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    NODE temp = header;
    do {
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
    } while (temp != header);
    printf("\n");
}

NODE subtractPolys(NODE p1, NODE p2) {
    NODE result = NULL;
    NODE temp1 = p1;
    NODE temp2 = p2;
    
    do {
        NODE newNode = createNode(temp1->coeff, temp1->exp);
        if (result == NULL) {
            result = newNode;
        } else {
            insertEnd(&result, newNode->coeff, newNode->exp);
        }
        temp1 = temp1->next;
    } while (temp1 != p1);

    do {
        int found = 0;
        NODE tempResult = result;
        do {
            if (tempResult->exp == temp2->exp) {
                tempResult->coeff -= temp2->coeff;
                found = 1;
                break;
            }
            tempResult = tempResult->next;
        } while (tempResult != result);

        if (!found) {
            insertEnd(&result, -temp2->coeff, temp2->exp);
        }
        temp2 = temp2->next;
    } while (temp2 != p2);

    return result;
}

NODE multiplyPolys(NODE p1, NODE p2) {
    NODE result = NULL;
    NODE temp1 = p1;
    NODE temp2 = p2;

    do {
        NODE temp2Iterator = temp2;
        do {
            int coeff = temp1->coeff * temp2Iterator->coeff;
            int exp = temp1->exp + temp2Iterator->exp;
            insertEnd(&result, coeff, exp);
            temp2Iterator = temp2Iterator->next;
        } while (temp2Iterator != p2);
        temp1 = temp1->next;
    } while (temp1 != p1);

    return result;
}

void freePoly(NODE header) {
    if (header == NULL) return;
    NODE current = header;
    NODE temp;
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != header);
}

int main() {
    NODE poly1 = NULL, poly2 = NULL;
    int choice, coeff, exp;

    while (1) {
        printf("Menu:\n");
        printf("1. Input Polynomial 1\n");
        printf("2. Input Polynomial 2\n");
        printf("3. Display Polynomial 1\n");
        printf("4. Display Polynomial 2\n");
        printf("5. Subtract Polynomials\n");
        printf("6. Multiply Polynomials\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficients and exponents (Enter -1 for coefficient to stop):\n");
                while (1) {
                    printf("Coefficient: ");
                    scanf("%d", &coeff);
                    if (coeff == -1) break;
                    printf("Exponent: ");
                    scanf("%d", &exp);
                    insertEnd(&poly1, coeff, exp);
                }
                break;
            case 2:
                printf("Enter coefficients and exponents (Enter -1 for coefficient to stop):\n");
                while (1) {
                    printf("Coefficient: ");
                    scanf("%d", &coeff);
                    if (coeff == -1) break;
                    printf("Exponent: ");
                    scanf("%d", &exp);
                    insertEnd(&poly2, coeff, exp);
                }
                break;
            case 3:
                printf("Polynomial 1: ");
                displayPoly(poly1);
                break;
            case 4:
                printf("Polynomial 2: ");
                displayPoly(poly2);
                break;
            case 5: {
                NODE result = subtractPolys(poly1, poly2);
                printf("Result of Subtraction: ");
                displayPoly(result);
                freePoly(result);
                break;
            }
            case 6: {
                NODE result = multiplyPolys(poly1, poly2);
                printf("Result of Multiplication: ");
                displayPoly(result);
                freePoly(result);
                break;
            }
            case 7:
                freePoly(poly1);
                freePoly(poly2);
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
