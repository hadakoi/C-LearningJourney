#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* title;
    char* author_name;
} Book;


void BooksEnter(Book **books, int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("Enter the title of book %d: ", i + 1);
    scanf("%[^\n]", books[i]->title);

    printf("Enter the author of book %d: ", i + 1);
    scanf("%[^\n]", books[i]->author_name);
  }
}

int main() {
  int n;
  printf("Enter the number of books: ");
  scanf("%d", &n);

  Book **books = (Book**)malloc(n * sizeof(Book*));


  for (int i = 0; i < n; i++) {
    books[i] = (Book*)malloc(sizeof(Book)); 
    books[i]->title = (char*)malloc(100 * sizeof(char)); 
    books[i]->author_name = (char*)malloc(100 * sizeof(char)); 

  if (books[i] == NULL || books[i]->title == NULL || books[i]->author_name == NULL) {
      printf("Memory allocation failed for book %d\n", i + 1);
      return 1;
    }
  }

  BooksEnter(books, n);

  printf("\nBooks entered:\n");
  for (int i = 0; i < n; i++) {
    printf("Book %d: Title = %s, Author = %s\n", i + 1, books[i]->title, books[i]->author_name);
  }

  for (int i = 0; i < n; i++) {
    free(books[i]->title); // Free the title
    free(books[i]->author_name); // Free the author name
    free(books[i]); // Free the Book structure itself
  }
  free(books); // Free the array of pointers

  return 0;
}
