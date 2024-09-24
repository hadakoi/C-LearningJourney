#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *link;
} *NODE;

NODE NewNode(int item) {
    NODE TempNode = (NODE)malloc(sizeof(struct node));
    TempNode->info = item;
    TempNode->link = NULL;
    return TempNode;
}

int isEmpty(NODE last) {
    return last == NULL;
}

void insertFront(NODE *last, NODE node) {
    if (isEmpty(*last)) {
        *last = node;
        node->link = node;
    } else {
        node->link = (*last)->link;
        (*last)->link = node;
    }
}

void insertRear(NODE *last, NODE node) {
    if (isEmpty(*last)) {
        *last = node;
        node->link = node;
    } else {
        node->link = (*last)->link;
        (*last)->link = node;
        *last = node;
    }
}

void DisplayNode(NODE last) {
    if (isEmpty(last)) {
        printf("List is empty.\n");
        return;
    }

    NODE temp = last->link;
    do {
        printf("%d ", temp->info);
        temp = temp->link;
    } while (temp != last->link);

    printf("\n");
}

int main() {
    NODE last = NULL;

    NODE node1 = NewNode(1);
    NODE node2 = NewNode(2);
    NODE node3 = NewNode(3);

    insertRear(&last, node1);
    insertRear(&last, node2);
    insertRear(&last, node3);

    printf("Circular Linked List after insertions at the rear:\n");
    DisplayNode(last);

    NODE temp = last->link;
    NODE nextNode;
    do {
        nextNode = temp->link;
        free(temp);
        temp = nextNode;
    } while (temp != last->link);

    return 0;
}
