#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} *NODE;

NODE createNode(int data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(NODE *head, int data) {
    NODE newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

int contains(NODE head, int data) {
    NODE current = head;
    while (current != NULL) {
        if (current->data == data) return 1;
        current = current->next;
    }
    return 0;
}

NODE unionSet(NODE head1, NODE head2) {
    NODE unionHead = NULL;
    NODE current = head1;
    while (current != NULL) {
        insert(&unionHead, current->data);
        current = current->next;
    }
    current = head2;
    while (current != NULL) {
        if (!contains(unionHead, current->data))
            insert(&unionHead, current->data);
        current = current->next;
    }
    return unionHead;
}

NODE intersectionSet(NODE head1, NODE head2) {
    NODE intersectHead = NULL;
    NODE current = head1;
    while (current != NULL) {
        if (contains(head2, current->data))
            insert(&intersectHead, current->data);
        current = current->next;
    }
    return intersectHead;
}

void display(NODE head) {
    NODE temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    NODE set1 = NULL, set2 = NULL;
    insert(&set1, 3);
    insert(&set1, 2);
    insert(&set1, 1);

    insert(&set2, 4);
    insert(&set2, 2);
    insert(&set2, 3);

    NODE unionResult = unionSet(set1, set2);
    NODE intersectionResult = intersectionSet(set1, set2);

    printf("Set 1: ");
    display(set1);
    printf("Set 2: ");
    display(set2);
    printf("Union: ");
    display(unionResult);
    printf("Intersection: ");
    display(intersectionResult);

    return 0;
}
