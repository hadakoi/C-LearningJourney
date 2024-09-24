#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coef;
    int expon;
    struct node* link;
} *poly_pointer;

poly_pointer NewNode(int coef, int expon) {
    poly_pointer newNode = (poly_pointer)malloc(sizeof(struct node));
    newNode->coef = coef;
    newNode->expon = expon;
    newNode->link = NULL;
    return newNode;
}

int COMPARE(int a, int b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

void attach(int coef, int expon, poly_pointer* lastC) {
    poly_pointer newNode = NewNode(coef, expon);
    (*lastC)->link = newNode;
    *lastC = newNode;
}

poly_pointer padd(poly_pointer a, poly_pointer b) {
    poly_pointer c, lastC;
    int sum;
    int done = 0;

    lastC = (poly_pointer)malloc(sizeof(struct node));
    lastC->link = NULL;
    c = lastC;

    do {
        switch (COMPARE(a->expon, b->expon)) {
            case -1:
                attach(b->coef, b->expon, &lastC);
                b = b->link;
                break;
            case 0:
                sum = a->coef + b->coef;
                if (sum) {
                    attach(sum, a->expon, &lastC); // Attach only if the sum is non-zero
                }
                a = a->link;
                b = b->link;
                break;
            case 1:
                attach(a->coef, a->expon, &lastC);
                a = a->link;
                break;
        }
        
        if (a == NULL && b == NULL) {
            done = 1;
        }
    } while (!done);

    while (a) {
        attach(a->coef, a->expon, &lastC);
        a = a->link;
    }

    while (b) {
        attach(b->coef, b->expon, &lastC);
        b = b->link;
    }

    lastC->link = NULL;
    return c->link;
}

void displayPolynomial(poly_pointer poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coef, poly->expon);
        poly = poly->link;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

void insertTerm(poly_pointer* poly, int coef, int expon) {
    poly_pointer newNode = NewNode(coef, expon);
    if (*poly == NULL || (*poly)->expon < expon) {
        newNode->link = *poly;
        *poly = newNode;
    } else {
        poly_pointer current = *poly;
        while (current->link != NULL && current->link->expon >= expon) {
            if (current->link->expon == expon) {
                current->link->coef += coef;
                free(newNode);
                return;
            }
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}

int main() {
    poly_pointer poly1 = NULL;
    poly_pointer poly2 = NULL;

    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 5, 1);
    insertTerm(&poly1, 2, 0);
    insertTerm(&poly1, 4, 2);

    insertTerm(&poly2, 4, 1);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    poly_pointer result = padd(poly1, poly2);

    printf("Resulting Polynomial: ");
    displayPolynomial(result);

    return 0;
}
