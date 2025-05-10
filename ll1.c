#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold book details
typedef struct BookDetails {
    char title[100];
    char author[100];
} BookDetails;

// Structure to hold book record
typedef struct Book {
    int bookID;
    BookDetails details;
    struct Book* next;
} Book;

// Function to insert a new book at the end of the list
void insertBook(Book** head, int bookID, char title[], char author[]) {
    // Create a new node
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->bookID = bookID;
    strcpy(newBook->details.title, title);
    strcpy(newBook->details.author, author);
    newBook->next = NULL;

    // If the list is empty, make the new book the head
    if (*head == NULL) {
        *head = newBook;
        return;
    }

    // Traverse to the end of the list
    Book* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert at the end
    temp->next = newBook;
}

// Function to delete a book record based on book ID
void deleteBook(Book** head, int bookID) {
    Book* temp = *head;
    Book* prev = NULL;

    // Check if the head node is to be deleted
    if (temp != NULL && temp->bookID == bookID) {
        *head = temp->next;
        free(temp);
        printf("Book with ID %d deleted successfully.\n", bookID);
        return;
    }

    // Search for the book to be deleted
    while (temp != NULL && temp->bookID != bookID) {
        prev = temp;
        temp = temp->next;
    }

    // If the book was not found
    if (temp == NULL) {
        printf("Book with ID %d not found in the catalog.\n", bookID);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Book with ID %d deleted successfully.\n", bookID);
}

// Function to display the entire book catalog
void displayCatalog(Book* head) {
    if (head == NULL) {
        printf("The catalog is empty.\n");
        return;
    }

    Book* temp = head;
    printf("\n===== Book Catalog =====\n");
    while (temp != NULL) {
        printf("Book ID: %d\n", temp->bookID);
        printf("Title: %s\n", temp->details.title);
        printf("Author: %s\n", temp->details.author);
        printf("------------------------\n");
        temp = temp->next;
    }
}

// Main function to manage the library catalog
int main() {
    Book* head = NULL; // Initialize an empty catalog
    int choice, bookID;
    char title[100], author[100];

    while (1) {
        printf("\n===== Library Catalog Management =====\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Display Catalog\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To handle the newline after scanf

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &bookID);
                getchar(); // To handle the newline after scanf
                printf("Enter Book Title: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0; // Remove trailing newline
                printf("Enter Author Name: ");
                fgets(author, 100, stdin);
                author[strcspn(author, "\n")] = 0; // Remove trailing newline
                insertBook(&head, bookID, title, author);
                printf("Book added successfully!\n");
                break;

            case 2:
                printf("Enter Book ID to delete: ");
                scanf("%d", &bookID);
                deleteBook(&head, bookID);
                break;

            case 3:
                displayCatalog(head);
                break;

            case 4:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
