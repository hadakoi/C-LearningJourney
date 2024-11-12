#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char cityName[50];
  int area;
} CITY;

typedef struct node{
  CITY c;
  struct node *rchild, *lchild;
} *NODE;

NODE CreateNode(CITY c){
  NODE NewNode = (NODE)malloc(sizeof(struct node));
  NewNode->c = c;
  NewNode->rchild = NewNode->lchild = NULL;
  return NewNode;
}

NODE InsertBinaryTree(NODE root, CITY a){
  if(root == NULL){
    return CreateNode(a);
  }

  if(root->c.area > a.area){
    root->lchild = InsertBinaryTree(root->lchild, a);
  }
  else if(root->c.area < a.area){
    root->rchild = InsertBinaryTree(root->rchild, a);
  }
  else{
    printf("No duplicates allowed\n");
  }
  return root;
}

void InOrder(NODE root){
  if(root == NULL) return;

  InOrder(root->lchild);
  printf("%d (%s)\n", root->c.area, root->c.cityName);
  InOrder(root->rchild);
}

void printKSmallestCities(NODE root, int k, int *count){
  if (root == NULL) return;

  printKSmallestCities(root->lchild, k, count);
  if (k  > *count) {
    (*count)++;
    printf("%d (%s, %s)\n", root->c.area, root->c.cityName);
  }
  printKSmallestCities(root->rchild, k, count);
}

NODE remSingle(NODE root, NODE root2){
  if(root == NULL || root->lchild == NULL || root->rchild == NULL) return NULL;
  root2 = InsertBinaryTree(root2, root->c);
  remSingle(root->lchild, root2);
  remSingle(root->rchild, root2);
  return root2;
}

int main(){
  int choice, k, count;
  CITY temp;
  NODE root = NULL;
  NODE root2 = NULL;
  while(1){
    printf("-------------------------------------\n");
    printf("Option1: Insert into Bin Tree\n");
    printf("Option2: Display BinaryTree\n");
    printf("Option3: Print k smallest cities based on area\n");
    printf("Option4: Remove nodes with one or no child\n");
    printf("Option5: Exit and stop\n");
    printf("Enter a choice: \n>");
    scanf("%d", &choice);
    getchar(); 

    switch(choice){
      case 1:
        printf("Enter cityName: ");
        scanf("%[^\n]", temp.cityName);
        getchar();
        printf("Enter area: ");
        scanf("%d", &temp.area);
        getchar();
        root = InsertBinaryTree(root, temp);
        break;
      case 2:
        printf("Binary Tree In-order traversal:\n");
        InOrder(root);
        break;
      case 3:
        printf("Enter the number of smallest cities to print: ");
        scanf("%d", &k);
        count = 0;
        printf("The %d smallest cities based on area are:\n", k);
        printKSmallestCities(root, k, &count);
        break;
      case 4:
        root2 = remSingle(root, root2);
        InOrder(root2);
        break;
      case 5:
        return 0; 
    }
  }
}
