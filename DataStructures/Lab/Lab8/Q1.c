#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[100], rear;
} ascPQ;

void initpq(ascPQ *apq) {
    apq->rear = -1;
}

void pqinsert(ascPQ *apq, int x) {
    if (apq->rear < 99) apq->arr[++apq->rear] = x;
    else printf("Queue is full.\n");
}

int pqmindelete(ascPQ *apq) {
    if (apq->rear == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    int minIndex = 0;
    for (int i = 1; i <= apq->rear; i++)
        if (apq->arr[i] < apq->arr[minIndex]) minIndex = i;

    int min = apq->arr[minIndex];
    for (int i = minIndex; i < apq->rear; i++) apq->arr[i] = apq->arr[i + 1];
    apq->rear--;
    return min;
}

void displaypq(ascPQ *apq) {
    if (apq->rear == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = 0; i <= apq->rear; i++)
        printf("%d\t", apq->arr[i]);
    printf("\n");
}

int main() {
    ascPQ *apq = malloc(sizeof(ascPQ));
    initpq(apq);
    int x, num;

    while (1) {
        printf("Enter 1 to insert, 2 to delete smallest element, 3 to display, 4 to exit:\n> ");
        scanf("%d", &x);
        if (x == 4) break;

        switch (x) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &num);
                pqinsert(apq, num);
                break;
            case 2:
                printf("%d removed\n", pqmindelete(apq));
                break;
            case 3:
                displaypq(apq);
                break;
            default:
                printf("Invalid input.\n");
        }
    }
    free(apq);
    return 0;
}
