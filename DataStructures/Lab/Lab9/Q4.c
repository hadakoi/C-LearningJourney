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

void deleteDuplicates(NODE head) {
    NODE current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            NODE temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
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

void display(NODE head) {
    NODE temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE head = NULL;
    int n, value;
    
    printf("Enter number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter elements in ascending order:\n");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }
    
    printf("Original List:\n");
    display(head);
    
    deleteDuplicates(head);
    
    printf("List after removing duplicates:\n");
    display(head);
    
    return 0;
}
