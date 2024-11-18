#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} *TERM;

TERM create_term(int coefficient, int exponent) {
  TERM new_term = (TERM)malloc(sizeof(struct Term));
  new_term->coefficient = coefficient;
  new_term->exponent = exponent;
  new_term->next = NULL;
  return new_term;
}

void insert_term(TERM* header, int coefficient, int exponent) {
  TERM new_term = create_term(coefficient, exponent);

  if (*header == NULL || (*header)->exponent < exponent) {
    new_term->next = *header;
    *header = new_term;
    return;
  }

  TERM current = *header;
  while (current->next != NULL && current->next->exponent > exponent) {
    current = current->next;
  }

  if (current->exponent == exponent) {
    current->coefficient += coefficient;
  } else {
    new_term->next = current->next;
    current->next = new_term;
  }
}

double evaluate(TERM header, double x) {
    double result = 0.0;
    TERM current = header;
    while (current != NULL) {
        result += current->coefficient * pow(x, current->exponent);
        current = current->next;
    }
    return result;
}

TERM add_polynomials(TERM header1, TERM header2) {
    TERM result = NULL;
    TERM p1 = header1;
    TERM p2 = header2;
    
    while (p1 != NULL || p2 != NULL) {
        if (p1 == NULL) {
            insert_term(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else if (p2 == NULL) {
            insert_term(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent > p2->exponent) {
            insert_term(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            insert_term(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            insert_term(&result, p1->coefficient + p2->coefficient, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return result;
}

TERM multiply_polynomials(TERM header1, TERM header2) {
    TERM result = NULL;
    TERM p1 = header1;
    TERM p2 = header2;

    while (p1 != NULL) {
        p2 = header2;
        while (p2 != NULL) {
            int new_coefficient = p1->coefficient * p2->coefficient;
            int new_exponent = p1->exponent + p2->exponent;
            insert_term(&result, new_coefficient, new_exponent);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return result;
}

void display(TERM header) {
    TERM current = header;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    int i, m, n, x, c, e;
    TERM header1 = NULL, header2 = NULL;

    // Input for polynomial 1
    printf("Enter the number of terms in polynomial 1\n");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("Enter coefficient and exponent\n");
        scanf("%d%d", &c, &e);
        insert_term(&header1, c, e);
    }

    // Input for polynomial 2
    printf("Enter the number of terms in polynomial 2\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent\n");
        scanf("%d%d", &c, &e);
        insert_term(&header2, c, e);
    }

    // Display both polynomials
    printf("Polynomial 1: ");
    display(header1);
    printf("Polynomial 2: ");
    display(header2);

    // Multiply the two polynomials and display the result
    TERM product = multiply_polynomials(header1, header2);
    printf("Product of Polynomial 1 and Polynomial 2: ");
    display(product);

    // Evaluate the product at a given value of x
    printf("Enter the value of x\n");
    scanf("%d", &x);
    printf("Evaluation of Product at x = %d: %.2f\n", x, evaluate(product, x));

    return 0;
}
