#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int ID, contact;
  char name[100];
} customer;

typedef struct node {
  customer c;
  struct node *left, *right;
} *NODE;

NODE getNode(customer c) {
  NODE temp = (NODE)malloc(sizeof(struct node));
  temp->c = c;
  temp->left = temp->right = NULL;
  return temp;
}

void insert(NODE *head, customer c) {
  NODE temp = getNode(c);
  if (*head == NULL) {
    temp->left = temp->right = temp;
    *head = temp;
    return;
  }
  NODE last = (*head)->left;
  last->right = temp;
  temp->left = last;
  temp->right = *head;
  (*head)->left = temp;
}

void lcs(NODE *head) {
  if (*head == NULL) {
    printf("No customers\n");
    return;
  }
  printf("%s issue is resolved, follow-up required\n", (*head)->c.name);
  *head = (*head)->right;
}

void rcs(NODE *head) {
  if (*head == NULL) {
    printf("No customers\n");
    return;
  }
  printf("%s needs attention immediately\n", (*head)->left->c.name);
  *head = (*head)->left;
}

void display(NODE head) {
  if (head == NULL) {
    printf("No customers\n");
    return;
  }
  NODE curr = head;
  do {
    printf("Name: %s, ID: %d, Contact: %d\n", curr->c.name, curr->c.ID, curr->c.contact);
    curr = curr->right;
  } while (curr != head);
}

int main() {
  NODE head = NULL;
  int choice;

  while (1) {
    printf("Enter 1 to insert, 2 for left circular shift, 3 for right circular shift, 4 to display, 5 to exit\n");
    printf("> ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
      case 1: {
        customer c;
        printf("Enter name: ");
        scanf("%[^\n]", c.name);
        getchar();

        printf("Enter ID: ");
        scanf("%d", &c.ID);
        getchar();

        printf("Enter contact: ");
        scanf("%d", &c.contact);
        getchar();

        insert(&head, c);
        break;
      }
      case 2:
        lcs(&head);
        break;
      case 3:
        rcs(&head);
        break;
      case 4:
        display(head);
        break;
      case 5:
        return 0;
      default:
        printf("Enter valid input\n");
    }
  }

  while (head != NULL) {
    NODE temp = head->right;
    free(head);
    head = temp;
  }

  return 0;
}
