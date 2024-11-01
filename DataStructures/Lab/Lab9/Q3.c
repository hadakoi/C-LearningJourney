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

void insertEnd(NODE* head, int data) {
    NODE newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        NODE temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

NODE merge(NODE headA, NODE headB) {
    NODE mergedHead = NULL, last = NULL;
    while (headA != NULL && headB != NULL) {
        NODE newNode;
        if (headA->data < headB->data) {
            newNode = createNode(headA->data);
            headA = headA->next;
        } else {
            newNode = createNode(headB->data);
            headB = headB->next;
        }
        if (mergedHead == NULL) {
            mergedHead = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
    while (headA != NULL) {
        NODE newNode = createNode(headA->data);
        last->next = newNode;
        last = newNode;
        headA = headA->next;
    }
    while (headB != NULL) {
        NODE newNode = createNode(headB->data);
        last->next = newNode;
        last = newNode;
        headB = headB->next;
    }
    return mergedHead;
}

void display(NODE head) {
    NODE temp = head;
    while (temp != NULL) {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n1, n2, height;
    NODE classA = NULL, classB = NULL;

    scanf("%d %d", &n1, &n2);

    for (int i = 0; i < n1; i++) {
        scanf("%d", &height);
        insertEnd(&classA, height);
    }

    for (int i = 0; i < n2; i++) {
        scanf("%d", &height);
        insertEnd(&classB, height);
    }

    printf("Class A\n");
    display(classA);
    printf("Class B\n");
    display(classB);

    NODE jointClass = merge(classA, classB);
    printf("Joint Class\n");
    display(jointClass);

    return 0;
}
